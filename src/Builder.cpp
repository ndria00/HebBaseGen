#include "Builder.h"

Builder::Builder(){
	buildingHead = false;
	buildingAggregate = false;
	buildingNegativeLiteral = false;
    buildingLeftWardAggregate = false;
    buildingRightWardAggregate = false;
	buildingLiteral = false;
}

void Builder::addAtom(Literal* a){
	allAtoms.push_back(a);
	buildingLiteral = false;
}
void Builder::addTerm(Term* t){
	allTerms.push_back(t);
}

void Builder::addRule(Rule* r){
	allRules.push_back(r);
}

void Builder::addAggregate(Aggregate* a){
	allAggregates.push_back(a);
	buildingLeftWardAggregate = false;
	buildingAggregate = false;
}

Rule* Builder::getCurrentRule(){
	return currentRule;
}

Aggregate* Builder::getCurrentAggregate(){
	return currentAggregate;
}

void Builder::buildAtom(ASPCore2Parser::AtomContext * atom){
	buildingLiteral = true;
	currentAtom->setIdentifier(atom->identifier()->getText());
}

void Builder::buildNafLiteral(ASPCore2Parser::Naf_literalContext* nafLiteral){
	buildingLiteral = true;
	if(nafLiteral->getStart()->getText() == "not"){
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
	if(simpleRule->getStart()->getText() == ":~"){
		std::cout<<"FOUND A WEAK"<<std::endl;
		currentRule = new WeakConstraint();
	}
	else
		currentRule = new Rule();
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
	std::string  myString = term->getText();
	//std::cout<<"Here is a term: "<<myString<<std::endl;
	Term* t = new Term(myString);
	allTerms.push_back(t);

	if(buildingLiteral){
			currentAtom->addTerm(t);
	}
	else if(buildingRightWardAggregate){
		currentAggregate->setRightTerm(t);
	}
	else if(buildingAggregate){
		if(buildingLeftWardAggregate == true)
			currentAggregate->setLeftTerm(t);
	}
}

void Builder::buildTerm_(ASPCore2Parser::Term_Context* term){
	std::string  myString = term->getText();
	Term* t = new Term(myString);
	allTerms.push_back(t);

	if(buildingLiteral){
			currentAtom->addTerm(t);
	}
	else if(buildingRightWardAggregate){
		currentAggregate->setRightTerm(t);
	}
	else if(buildingAggregate){
		if(buildingLeftWardAggregate == true)
			currentAggregate->setLeftTerm(t);
	}
}

void Builder::buildTerm__(ASPCore2Parser::Term__Context* term){
	std::string  myString = term->getText();
	Term* t = new Term(myString);
	allTerms.push_back(t);
	currentAtom->addTerm(t);
}

void Builder::buildAggregateAtom(ASPCore2Parser::Aggregate_atomContext* aggregate){
	//std::cout<<"BUILDING AN AGGREGATE"<<std::endl;
	Aggregate* myAggregate = new Aggregate();
	currentAggregate = myAggregate;
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
	std::cout<<"HELLLOOOOOOOOO"<<std::endl;
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
	Term* t = new Term(myString);
	allTerms.push_back(t);
	if(buildingAggregate)
		currentAggregate->addTerm(t);
}


void Builder::clearMemory(){
	for (Term* term: allTerms){
		delete term;
	}

	for (Literal* rule: allAtoms){
		delete rule;
	}

	for(Aggregate* aggr: allAggregates){
			delete aggr;
	}
	
	for (Rule* rule: allRules){
		delete rule;
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
	std::cout<<"PRINTIG PARSERED PROGRAM: " << allRules.size() <<std::endl;
	for(Rule* r: allRules){
		r->print();
		std::cout<<std::endl;
	}
}