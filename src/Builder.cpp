#include "Builder.h"

void Builder::addAtom(Atom* a){
	allAtoms.push_back(a);
}
void Builder::addTerm(Term* t){
	allTerms.push_back(t);
}

void Builder::addRule(Rule* r){
	allRules.push_back(r);
}

Rule* Builder::getCurrentRule(){
	return currentRule;
}

void Builder::buildAtom(ASPCore2Parser::Classic_literalContext* lit){
	std::cout<<"Building atom"<<std::endl;
	currentAtom = new Atom();
	// a.setIdentifier(lit->atom()->identifier()->getText());
	// auto terms = lit->atom()->terms();
	// while (terms != NULL)
	// {
	// 	a.getTerms().push_back(terms->term()->getText());
	// 	terms = terms->terms();
	// }
}

void Builder::buildHead(ASPCore2Parser::HeadContext* headContext){
	std::cout<<"Building head"<<std::endl;
	// auto disjunction = headContext->disjunction();
	// while(disjunction != NULL){
	// 	auto lit = disjunction->classic_literal();
	// 	Atom a;
	// 	buildAtom(lit,a);
	// 	head.getDisjunction().push_back(a);
	// 	disjunction = disjunction->disjunction();
	// }
}

void Builder::buildSimpleRule(ASPCore2Parser::Simple_ruleContext* simpleRule){
	std::cout<<"Building simple rule"<<std::endl;
	// auto head = simpleRule->head();
	// auto body = simpleRule->body();
	// if(head == NULL){
	// 	if(simpleRule->WCONS() != NULL){
	// 	}else if(simpleRule->CONS() != NULL){
	// 	}
	// }else{
	// 	Head h;
	// 	if(body == NULL){
	// 	}else{
	// 		Body b;
	// 		buildHead(head,h);
	// 		rule.setHead(h);
	// 	}
	// }
}

void Builder::buildRule(ASPCore2Parser::RuleContext* ruleContext){
	std::cout<<"Building rule"<<std::endl;
	currentRule = new Rule();

	// auto simpleRule = ruleContext->simple_rule();
	// if(simpleRule != NULL){
	// 	Rule r;
	// 	buildSimpleRule(simpleRule,r);
	// 	program.getRules().push_back(r);
	// }else{
	// }
}

// void Builder::buildProgram(ASPCore2Parser::ProgramContext* programContext, Program& program){
// 	std::cout<<"Building program"<<std::endl;
// 	for(auto& ruleContext : programContext->rule_()){
// 		std::cout<<"Found something"<<std::endl;
// 		buildRule(ruleContext,program);
// 	}
// }


void Builder::clearMemory(){
	for (Term* term: allTerms){
		delete term;
	}
	for (Atom* rule: allAtoms){
		delete rule;
	} 

	for (Rule* rule: allRules){
		delete rule;
	}
}

bool Builder::isBuildingHead(){
    return buildingHead;
}
void Builder::setBuildingHead(bool buildingHead){
    this->buildingHead = buildingHead;
}

Atom* Builder::getCurrentAtom(){
	return currentAtom;
}