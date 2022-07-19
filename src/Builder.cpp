#include "Builder.h"

Builder::Builder(Program* program){
	buildingHead = false;
	buildingAggregate = false;
	buildingNegativeLiteral = false;
    buildingLeftWardAggregate = false;
    buildingRightWardAggregate = false;

	currentRule = nullptr;
    currentAtom = nullptr;
    currentAggregate = nullptr;
	currentTerm = nullptr;
	currentFactor = nullptr;
    currentExpression = nullptr;
	currentBuiltInTerm = nullptr;
    expressionNesting = std::vector<antlr4::ParserRuleContext*>();
	
	allRules = std::vector<Rule*>();
	allAtoms = std::vector<Literal*>();
	allTerms = std::vector<TermBase*>();
	allAggregates = std::vector<Aggregate*>();
	allExpressions = std::vector<ExpressionBase*>();
	allBuiltIn = std::vector<BuiltInTerm*>();
	this->program = program;

	currentBuildingTerms = std::list<antlr4::ParserRuleContext*>();
}

void Builder::addCurrentAtom(){
	allAtoms.push_back(currentAtom);
	currentAtom = nullptr;
}
void Builder::addCurrentTerm(){
	allTerms.push_back(currentTerm);
	currentTerm = nullptr;
}

void Builder::addCurrentRule(){
	allRules.push_back(currentRule);
	program->addRule(currentRule);
	currentRule = nullptr;
}

void Builder::addCurrentAggregate(){
	allAggregates.push_back(currentAggregate);
	currentRule->addAggregateInBody(currentAggregate);
	buildingLeftWardAggregate = false;
	buildingAggregate = false;
	currentAggregate = nullptr;
}

Rule* Builder::getCurrentRule(){
	return currentRule;
}

Aggregate* Builder::getCurrentAggregate(){
	return currentAggregate;
}

void Builder::buildAtom(ASPCore2Parser::AtomContext * atom){
	currentAtom->setIdentifier(atom->identifier()->getText());
}

void Builder::buildNafLiteral(ASPCore2Parser::Naf_literalContext* nafLiteral){
	if(nafLiteral->getStart()->getType() == ASPCore2Parser::NAF){
        buildingNegativeLiteral = true;
    }
}

void Builder::buildClassicLiteral(ASPCore2Parser::Classic_literalContext* classicLiteral){
	currentAtom =  new Literal();
	if(buildingNegativeLiteral == true)
		currentAtom->setNegative(true);
	buildingNegativeLiteral = false;

}

void Builder::buildHead(ASPCore2Parser::HeadContext* headContext){
}

void Builder::buildSimpleRule(ASPCore2Parser::Simple_ruleContext* simpleRule){
		if(simpleRule->getStart()->getType() == ASPCore2Parser::WCONS){
		currentRule = new WeakConstraint();
	}
	else{
		currentRule = new Rule();
	}
}

void Builder::buildRule(ASPCore2Parser::RuleContext* ruleContext){
		//currentRule = new Rule();
}

// void Builder::buildProgram(ASPCore2Parser::ProgramContext* programContext, Program& program){
// 	std::cout<<"Building program"<<std::endl;
// 	for(auto& ruleContext : programContext->rule_()){
// 		std::cout<<"Found something"<<std::endl;
// 		buildRule(ruleContext,program);
// 	}
// }

void Builder::buildTerm(ASPCore2Parser::TermContext* term){
	if(term->identifier() != NULL && term->children.size() == 1){
		std::string myString = term->getText(); 
		currentTerm = new Term(myString);
		addCurrentTerm();
		if(currentAtom != nullptr)
			currentAtom->addTerm(currentTerm);
		else if(currentBuiltInTerm != nullptr){
			if(currentExpression == nullptr){
				currentExpression = new SimpleFactor(currentTerm);
				currentBuiltInTerm->addExpression(currentExpression);
				allExpressions.push_back(currentExpression);
				currentExpression = nullptr;
			}
		}

	}	
}

void Builder::buildTerm_(ASPCore2Parser::Term_Context* term_){
		if(term_->children.size() == 3 && term_->getStart()->getType() == ASPCore2Parser::NUMBER && currentAtom != nullptr){
				std::string myString = term_->getText();
				currentTerm = new Term(myString);
				currentAtom->addTerm(currentTerm);
				addCurrentTerm();
		}
		else{
			currentBuildingTerms.push_back(term_);
		}
}

void Builder::buildTerm__(ASPCore2Parser::Term__Context* term){
	currentBuildingTerms.push_back(term);
}

void Builder::buildAggregateAtom(ASPCore2Parser::Aggregate_atomContext* aggregate){
	currentAggregate = new Aggregate();
	buildingAggregate = true;
	buildingLeftWardAggregate = true;
	
}

void Builder::buildAggregate(ASPCore2Parser::AggregateContext* aggregate){
	std::string aggregateType = aggregate->aggregate_function()->getText();
	currentAggregate->setType(aggregateType);
	buildingLeftWardAggregate = false;
}

void Builder::buildLeftwardOp(ASPCore2Parser::LeftwardopContext* leftwardop){
	std::string op = leftwardop->getText();
	if(buildingLeftWardAggregate){
		currentAggregate->setLeftOperator(op);
		buildingLeftWardAggregate = false;
	}
	else if(buildingRightWardAggregate)
		currentAggregate->setRightOperator(op);
}

void Builder::buildRightwardOp(ASPCore2Parser::RightwardopContext* rightwardop){
	std::string op = rightwardop->getText();
	if(buildingLeftWardAggregate){
		currentAggregate->setLeftOperator(op);
		buildingLeftWardAggregate = false;
	}
	else if(buildingRightWardAggregate)
		currentAggregate->setRightOperator(op);
}

void Builder::buildBasicTerm(ASPCore2Parser::Basic_termContext* basicTerm){
	std::string  myString = basicTerm->getText();
	currentTerm = new Term(myString);
	
	if(buildingAggregate)
		currentAggregate->addTerm(currentTerm);
	addCurrentTerm();
	
}

// do a single pop_back and construct a simple Term
// No matter if the terminal is a term or an identifier
// or a factor
// In a second time exit methods will push up all the terms created
// to their "container"
void Builder::buildTerminal(antlr4::tree::TerminalNode * terminal){
	if(currentBuildingTerms.size() == 0){
		return;
	}

	antlr4::ParserRuleContext* context = currentBuildingTerms.back();
	int index = context->getRuleIndex();
	if(index == ASPCore2Parser::RuleTerm_ || index == ASPCore2Parser::RuleTerm__){
		currentBuildingTerms.pop_back();
		std::string myString= terminal->getText();
		currentTerm = new Term(myString);
		if(currentExpression != nullptr){
			if(currentFactor != nullptr)
				currentFactor->addTerm(currentTerm);
			else{
				SimpleFactor* tempFactor = new SimpleFactor(currentTerm);
				currentExpression->addExpression(tempFactor);
				allExpressions.push_back(tempFactor);
			}
			//currentExpression->addExpression(currentFactor);
		}
		else
			currentAtom->addTerm(currentTerm);
		//std::cout<<"TERM OR TERM__"<<context->getRuleIndex()<<std::endl;
		addCurrentTerm();
	}
}

antlr4::ParserRuleContext* Builder::getParentContext(){
	if(currentBuildingTerms.size() == 0)
		return nullptr;
	antlr4::ParserRuleContext* context = currentBuildingTerms.back();
	//currentBuildingTerms.pop_back();
	return context;
}

void Builder::clearMemory(){
	// int len = 0;
	//std::cout<<"Len of terms:"<< allTerms.size()<<std::endl;
	for (TermBase* term: allTerms){
		// len++;
		// std::cout<<"deleting "<<len<<std::endl;
		delete term;
	}
	//std::cout<<"Len of atoms:"<< allAtoms.size()<<std::endl;
	// len = 0;
	for (Literal* rule: allAtoms){
		// len++;
		// std::cout<<"deleting "<<len<<std::endl;
		delete rule;
	}

	//std::cout<<"Len of aggregates:"<< allAggregates.size()<<std::endl;
	// len = 0;
	for(Aggregate* aggr: allAggregates){
		// len++;
		// std::cout<<"deleting "<<len<<std::endl;
		delete aggr;
	}
	
	// len=0;
	//std::cout<<"Len of rules:"<< allRules.size()<<std::endl;
	for (Rule* rule: allRules){
		// len++;
		// std::cout<<"deleting "<<len<<std::endl;
		delete rule;
	}
	//if(currentAggregate != nullptr || currentTerm != nullptr || currentAtom != nullptr || currentRule != nullptr)
	//	std::cout<<"SOMETHING WENT WRONG"<<std::endl;
	
	for(ExpressionBase* expression : allExpressions){
		delete expression;
	}
	
	for(BuiltInTerm* builtIn : allBuiltIn){
		delete builtIn;
	}
}

void Builder::buildCompareOperator(ASPCore2Parser::CompareopContext* compareop){
	std::string op = compareop->getText();
	if(buildingLeftWardAggregate){
		currentAggregate->setLeftOperator(op);
		buildingLeftWardAggregate = false;
	}
	else if(buildingRightWardAggregate)
		currentAggregate->setRightOperator(op);
}

void Builder::buildExpression(ASPCore2Parser::ExprContext* expression){
	//std::cout<<"Building expression"<<std::endl;
	std::string op = "";
	expressionNesting.push_back(expression);

	if(currentExpression != nullptr){
		ExpressionBase* tempExpression = new Expression(currentExpression);
		allExpressions.push_back(tempExpression);
		//tempExpression->setOperator(op);
		currentExpression->addExpression(tempExpression);
		//std::cout<<"adding expression to father"<<std::endl;
		currentExpression = tempExpression;

	}else{
		currentExpression = new Expression();
		allExpressions.push_back(currentExpression);
		if(currentAtom != nullptr){
			currentAtom->addTerm(currentExpression);
			//std::cout<<"adding expression to atom"<<std::endl;
		}
		else if(currentBuiltInTerm != nullptr){
			std::cout<<"ADDing expression to built in"<<std::endl;
			currentBuiltInTerm->addExpression(currentExpression);
		}
		//currentExpression->setOperator(op);
	}

	if(expression->arithop1() != NULL){
		op = expression->arithop1()->getText();
		currentExpression->setOperator(op);
	}

	// if(expression->arithop1() != NULL){
	// 	op = expression->arithop1()->getText();
	// 	if(currentExpression != nullptr){

	// 	}
	// 	else{ //this expression is going to be the outermost of a possible tree of expressions inside the atom
	// 		currentExpression = new Expression();
	// 		currentExpression->setOperator(op);
	// 		if(currentAtom != nullptr)
	// 			currentAtom->addExpression(currentExpression);
	// 			//else
	// 				//add to built-in
	// 		}
	// }
	// else{
	// 	currentExpression = new Expression();
	// 	if(currentAtom != nullptr)
	// 		currentAtom->addExpression(currentExpression);
	// }
}

void Builder::buildFactor(ASPCore2Parser::FactorContext* factor){
	//std::cout<<"Building factor"<<std::endl;
	std::string op = "";
	expressionNesting.push_back(factor);
	
	//add current expression to its parent one
	if(currentExpression != nullptr){
		if(factor->arithop2() != NULL){
			ExpressionBase* tempExpression = new Expression(currentExpression);
			allExpressions.push_back(tempExpression);
			currentExpression->addExpression(tempExpression);
			currentExpression = tempExpression;
			op = factor->arithop2()->getText();
			currentExpression->setOperator(op);
			//std::cout<<"adding expression to current expression"<<std::endl;
		}
		else{
			currentFactor = new SimpleFactor();
			currentExpression->addExpression(currentFactor);
			//std::cout<<"adding factor to current expression"<<std::endl;
			allExpressions.push_back(currentFactor);
		}
		
	}
	else{ //this expression is going to be the outermost of a possible tree of expressions inside the atom
		currentExpression = new Expression();
		allExpressions.push_back(currentExpression);
		if(currentAtom != nullptr)
			currentAtom->addTerm(currentExpression);
			//std::cout<<"adding factor to atom"<<std::endl;
		else if(currentBuiltInTerm != nullptr){
			currentBuiltInTerm->addExpression(currentExpression);
		}
	}
}

void Builder::setBuildingHead(bool buildingHead){
    this->buildingHead = buildingHead;
}

bool Builder::isBuildingHead(){
    return buildingHead;
}

bool Builder::isBuildingAggregate(){
    return buildingAggregate;
}
void Builder:: setBuildingAggregate(bool buildingAggregate){
    this->buildingAggregate = buildingAggregate;
}

void Builder::setBuildingRightWardAggregate(bool buildingRightWardAggregate){
	this->buildingRightWardAggregate = buildingRightWardAggregate;
}

Literal* Builder::getCurrentAtom(){
	return currentAtom;
}

void Builder::printProgram(){
	for(Rule* r: allRules){
		r->print();
		std::cout<<std::endl;
	}

	//for(Term* term: allTerms){
	// 	std::cout<<"HEY -> "<<term->getValue()<<std::endl;
	//}
}

void Builder::exitExprFact(){
	antlr4::ParserRuleContext* context = expressionNesting.back();
	//std::cout<<"Exit"<<std::endl;
	//when exiting from an expression currentFactor must be set to nullptr
	if(context->getRuleIndex() == ASPCore2Parser::RuleExpr){
		//std::cout<<"switching to parent"<<std::endl;
		currentExpression = currentExpression->getParent();
	}
	//when exiting a factor there are two possible scenarios
	//1) this factor was build as an espression, so the behaviour is just as above
	//2) this factor is a simple factor so current expression should remain to its current, but factor must be set to nullptr
	else if (context->getRuleIndex() == ASPCore2Parser::RuleFactor){
		ASPCore2Parser::FactorContext* factorContext = dynamic_cast<ASPCore2Parser::FactorContext*>(context);
		if(factorContext->arithop2() != NULL){ //factor was build as an expression
			currentExpression = currentExpression->getParent();
			//std::cout<<"switching to parent"<<std::endl;
		}
	}
	expressionNesting.pop_back();
	currentFactor = nullptr;
}

void Builder::buildBuiltInAtom(ASPCore2Parser::Builtin_atomContext* builtIn){
	std::cout<<"HELLO, BUILDING BUILT IN"<<std::endl;
	expressionNesting.push_back(builtIn);
	currentBuiltInTerm = new BuiltInTerm();
	allBuiltIn.push_back(currentBuiltInTerm);
	std::string myString = builtIn->binop()->getText();
	currentBuiltInTerm->setOperator(myString);
	currentRule->addBuiltInInBody(currentBuiltInTerm);

}

void Builder::exitBinop(){
	if(currentBuiltInTerm != nullptr){
		currentExpression = nullptr;
	}
}

void Builder::exitBuiltIn(){
	currentBuiltInTerm = nullptr;
}