#include "Builder.h"

Builder::Builder(){

}
/*
void Builder::buildAtom(ASPCore2Parser::Classic_literalContext* lit, Atom& a){
	std::cout<<"Building atom"<<std::endl;
	a.setIdentifier(lit->atom()->identifier()->getText());
	auto terms = lit->atom()->terms();
	while (terms != NULL)
	{
		a.getTerms().push_back(terms->term()->getText());
		terms = terms->terms();
	}
}

void Builder::buildHead(ASPCore2Parser::HeadContext* headContext, Head& head){
	std::cout<<"Building head"<<std::endl;
	auto disjunction = headContext->disjunction();
	while(disjunction != NULL){
		auto lit = disjunction->classic_literal();
		Atom a;
		buildAtom(lit,a);
		head.getDisjunction().push_back(a);
		disjunction = disjunction->disjunction();
	}
}

void Builder::buildSimpleRule(ASPCore2Parser::Simple_ruleContext* simpleRule,Rule& rule){
		std::cout<<"Building simple rule"<<std::endl;
	auto head = simpleRule->head();
	auto body = simpleRule->body();
	if(head == NULL){
		if(simpleRule->WCONS() != NULL){
		}else if(simpleRule->CONS() != NULL){
		}
	}else{
		Head h;
		if(body == NULL){
		}else{
			Body b;
			buildHead(head,h);
			rule.setHead(h);
		}
	}
}

void Builder::buildRule(ASPCore2Parser::RuleContext* ruleContext, Program& program){
	std::cout<<"Building rule"<<std::endl;
	auto simpleRule = ruleContext->simple_rule();
	if(simpleRule != NULL){
		Rule r;
		buildSimpleRule(simpleRule,r);
		program.getRules().push_back(r);
	}else{
	}
}

void Builder::buildProgram(ASPCore2Parser::ProgramContext* programContext, Program& program){
	std::cout<<"Building program"<<std::endl;
	for(auto& ruleContext : programContext->rule_()){
		std::cout<<"Found something"<<std::endl;
		buildRule(ruleContext,program);
	}
}
*/