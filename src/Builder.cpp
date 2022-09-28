#include "Builder.h"

Builder::Builder(Program* program){
	buildingHead = false;
	buildingAggregate = false;
	buildingNegativeLiteral = false;
    buildingLeftWardAggregate = false;
    buildingRightWardAggregate = false;
	buildingAggregateLiterals = false;
	buildingChoiceElementLiterals = false;

	currentRule = nullptr;
    currentAtom = nullptr;
    currentAggregate = nullptr;
	currentTerm = nullptr;
	currentFactor = nullptr;
    currentExpression = nullptr;
	currentBuiltInTerm = nullptr;
	currentFuncTerm = nullptr;
    expressionNesting = std::vector<antlr4::ParserRuleContext*>();
	functionalTermsNesting = std::vector<antlr4::ParserRuleContext*>();
	currentChoiceRule = nullptr;
	
	allChoiceRules = std::vector<ChoiceRule*>();
	allRules = std::vector<Rule*>();
	allAtoms = std::vector<Literal*>();
	allTerms = std::vector<TermBase*>();
	allAggregates = std::vector<Aggregate*>();
	allExpressions = std::vector<ExpressionBase*>();
	allBuiltIn = std::vector<BuiltInTerm*>();
	allFacts = std::vector<std::pair<Literal*, bool>>();
	this->program = program;

	currentBuildingTerms = std::list<antlr4::ParserRuleContext*>();
	ruleID = 0;
	literalsId = 0;
}

void Builder::addCurrentChoiceRule(){
	if(currentChoiceRule != nullptr){
		allChoiceRules.push_back(currentChoiceRule);
		program->addChoiceRule(currentChoiceRule);	
	}
	buildingChoiceElementLiterals = false;
	currentChoiceRule = nullptr;
}

void Builder::addCurrentAtom(){
	allAtoms.push_back(currentAtom);
	if(!program->existsPredicate(currentAtom->getIDAndArity())){
		//predicateID[lit->getIDAndArity()] = literalsId;
		if(program->addPredicateWithID(currentAtom->getIdentifier(), literalsId)){
			++literalsId;
		}
		currentAtom->setID(program->getIDForPredicate(currentAtom));
		if(buildingHead){
			//appears in head => is idb
			currentAtom->setIDBPredicate(true);
			program->addIDBPredicate(currentAtom);
			//all occurrencies of the same literal are now idb predicates
			for(Literal* lit : allAtoms){
				if(lit->getIDAndArity() == currentAtom->getIDAndArity())
					lit->setIDBPredicate(true);
			}
		}
		else{
			// is idb if it had already appeared in a rule head
			currentAtom->setIDBPredicate(program->isIDBPredicate(currentAtom));
			if(currentAtom->isIDBPredicate())
				program->addIDBPredicate(currentAtom);
		}
	}
	currentAtom = nullptr;
}
void Builder::addCurrentTerm(){
	allTerms.push_back(currentTerm);
	currentTerm = nullptr;
}

void Builder::addCurrentRule(){
	if(currentRule == nullptr)
		return;
	currentRule->setID(ruleID);
	ruleID++;
	allRules.push_back(currentRule);
	program->addRule(currentRule);
	if(currentRule->isFact()){
		bool isDisjunctive = false;
		if(currentRule->getHead()->getDisjunction().size() > 1)
			isDisjunctive = true;

		for(Literal* lit : currentRule->getHead()->getDisjunction()){
			allFacts.push_back(std::make_pair(lit, isDisjunctive));
		}
	}
	//currentRule->sortLiteralsInBody();
	currentRule = nullptr;
}

void Builder::addCurrentAggregate(){
	allAggregates.push_back(currentAggregate);
	currentRule->addAggregateInBody(currentAggregate);
	buildingLeftWardAggregate = false;
	buildingAggregate = false;
	currentAggregate = nullptr;
	buildingAggregateLiterals = false;
}

void Builder::addCurrentBuiltIn(){
	allBuiltIn.push_back(currentBuiltInTerm);
	currentBuiltInTerm = nullptr;
}

Rule* Builder::getCurrentRule(){
	return currentRule;
}

Aggregate* Builder::getCurrentAggregate(){
	return currentAggregate;
}

void Builder::buildAtom(ASPCore2Parser::AtomContext * atom){
	//if atom is not also a classic literal here the pointer is null and
	// a new atom needs to be created
	if(currentAtom == nullptr)
		currentAtom = new Literal();
	currentAtom->setIdentifier(atom->identifier()->getText());
	if(currentChoiceRule != nullptr){
		if(buildingChoiceElementLiterals && buildingHead){//CHECK
			//adding atom after : of a choice element
			currentChoiceRule->addLiteralInChoice(currentAtom);
		}
		else if(buildingHead){
			//create a new choice element and add this atom before :
			//currentChoiceRule->addChoice(currentAtom, new Body());
			currentChoiceRule->setLiteral(currentAtom);
		}
	}
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
	if(currentAggregate != nullptr){
		currentAggregate->addLiteral(currentAtom);
	}
	else if(currentRule != nullptr && buildingHead){
		currentRule->addAtomInHead(currentAtom);
	}
	else if (currentRule != nullptr){
		currentRule->addAtomInBody(currentAtom);
	}
	else if(currentChoiceRule != nullptr && !buildingHead){
		currentChoiceRule->addLiteralInBody(currentAtom);
	}
}

void Builder::buildHead(ASPCore2Parser::HeadContext* headContext){
}

void Builder::buildSimpleRule(ASPCore2Parser::Simple_ruleContext* simpleRule){
	if(simpleRule->getStart()->getType() == ASPCore2Parser::WCONS){
		currentRule = new WeakConstraint();
	}
	else if (simpleRule->head() != NULL &&  simpleRule->head()->choice_atom() == NULL){
		currentRule = new Rule();
	}
}

void Builder::buildChoiceRule(ASPCore2Parser::Choice_atomContext*){
		currentChoiceRule = new ChoiceRule();
}

void Builder::buildTerm(ASPCore2Parser::TermContext* term){
	if(term->identifier() != NULL && term->children.size() == 1){
		std::string myString = term->getText(); 
		currentTerm = new Term(myString);
		if(term->getStart()->getType() == ASPCore2Parser::VARIABLE){
			currentTerm->setVariable(true);
		}
		if(currentAtom != nullptr){
			currentAtom->addTerm(currentTerm);
			addCurrentTerm();
		}
		else if(currentBuiltInTerm != nullptr){
			if(currentExpression == nullptr){
				currentExpression = new SimpleFactor(currentTerm);
				currentBuiltInTerm->addExpression(currentExpression);
				allExpressions.push_back(currentExpression);
				currentExpression = nullptr;
				addCurrentTerm();
			}
		}
		else if(buildingLeftWardAggregate){
			currentAggregate->setLeftTerm(currentTerm);
			addCurrentTerm();
		}
		else if(buildingRightWardAggregate){
			currentAggregate->setRightTerm(currentTerm);
			addCurrentTerm();
		}

	}	
}

void Builder::buildTerm_(ASPCore2Parser::Term_Context* term_){
		//N..M
		if(term_->children.size() == 3 && term_->getStart()->getType() == ASPCore2Parser::NUMBER && currentAtom != nullptr){
				std::string myString = term_->getText();
				currentTerm = new Term(myString);
				currentAtom->addTerm(currentTerm);
				addCurrentTerm();
		}else if(term_->children.size() == 4 && term_->getStop()->getType() == ASPCore2Parser::PARAM_CLOSE){
			//functional term
			FunctionalTerm* temp = new FunctionalTerm();
			if(currentFuncTerm != nullptr){
				currentFuncTerm->addTerm(temp);
			}//functional term is part of symbolic set of the current aggregate
			else if(buildingAggregate && !buildingAggregateLiterals){
				currentAggregate->addToSymbolicSet(currentFuncTerm);
			}else{
				currentAtom->addTerm(currentFuncTerm);
			}
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
		currentAggregate->addToSymbolicSet(currentTerm);
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
		if(terminal->getSymbol()->getType() == ASPCore2Parser::VARIABLE){
			currentTerm->setVariable(true);
		}
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
		else if(currentFuncTerm != nullptr){
			//TODO
			//currentFuncTerm->addTerm();
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

	for(ChoiceRule* rule : allChoiceRules){
		delete rule;
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
			//std::cout<<"ADDing expression to built in"<<std::endl;
			currentBuiltInTerm->addExpression(currentExpression);
		}
		else if(buildingLeftWardAggregate){
			currentAggregate->setLeftTerm(currentExpression);
		}
		else if(buildingRightWardAggregate){
			currentAggregate->setRightTerm(currentExpression);
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
		else if(buildingLeftWardAggregate){
			currentAggregate->setLeftTerm(currentExpression);
		}
		else if(buildingRightWardAggregate){
			currentAggregate->setRightTerm(currentExpression);
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

void Builder::buildChoiceElementLiterals(ASPCore2Parser::Choice_elements_literalsContext *){
	buildingChoiceElementLiterals = true;
}

void Builder::buildChoiceElement(ASPCore2Parser::Choice_elementContext*){
	buildingChoiceElementLiterals = false;
	currentChoiceRule->addChoice();
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
	expressionNesting.push_back(builtIn);
	currentBuiltInTerm = new BuiltInTerm();
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
	addCurrentBuiltIn();
}

void Builder::exitedSymbolicSet(){
	buildingAggregateLiterals = true;
}

std::vector<Rule*>& Builder::getAllRules(){
	return allRules;
}

Program* Builder::getProgram(){
	return program;
}

std::vector<Literal*>& Builder::getAllLiterals(){
	return allAtoms;
}

 std::vector<std::pair<Literal*, bool>>& Builder::getAllFacts(){
	 return allFacts;
 }

 ChoiceRule* Builder::getCurrentChoiceRule(){
	 return currentChoiceRule;
 }