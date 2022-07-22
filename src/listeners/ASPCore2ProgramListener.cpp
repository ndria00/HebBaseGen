#include "ASPCore2ProgramListener.h"

ASPCore2ProgramListener::ASPCore2ProgramListener(Builder* builder): builder{builder}, ASPCore2BaseListener(){}

void ASPCore2ProgramListener::enterProgram(ASPCore2Parser::ProgramContext * program){
    //std::cout<<"Entered program "<<program->getText() <<std::endl;
}

void ASPCore2ProgramListener::exitProgram(ASPCore2Parser::ProgramContext * program){
    //std::cout<<"Exited program "<<program->getText()<<std::endl;
}

void ASPCore2ProgramListener::enterSimple_rule(ASPCore2Parser::Simple_ruleContext * simpleRule){
    builder->buildSimpleRule(simpleRule);
}

void ASPCore2ProgramListener::exitSimple_rule(ASPCore2Parser::Simple_ruleContext * simpleRule){
    //std::cout<<"Exited rule "<<std::endl;
    builder->addCurrentRule();
}

void ASPCore2ProgramListener::enterHead(ASPCore2Parser::HeadContext * head){
    //std::cout<<"Entered Head.... disjunction: "<<""<<std::endl;
    builder->setBuildingHead(true);
}
void ASPCore2ProgramListener::exitHead(ASPCore2Parser::HeadContext * head){
    //std::cout<<"Exited Head "<<head->getText()<<std::endl;
    builder->setBuildingHead(false);
}

void ASPCore2ProgramListener::enterBody(ASPCore2Parser::BodyContext * body){
    //std::cout<<"Entered body "<<body->getText() <<std::endl;
    builder->setBuildingHead(false);
}
void ASPCore2ProgramListener::exitBody(ASPCore2Parser::BodyContext * body){
    //std::cout<<"Exited body "<<body->getText() <<std::endl;
    builder->setBuildingHead(false);
}

void ASPCore2ProgramListener::enterClassic_literal(ASPCore2Parser::Classic_literalContext *literal){
    builder->buildClassicLiteral(literal);

}

void ASPCore2ProgramListener::exitClassic_literal(ASPCore2Parser::Classic_literalContext *literal){
}

void ASPCore2ProgramListener::enterAtom(ASPCore2Parser::AtomContext * atom){
    builder->buildAtom(atom);
}

void ASPCore2ProgramListener::exitAtom(ASPCore2Parser::AtomContext * atom){
    builder->addCurrentAtom();
}


void ASPCore2ProgramListener::enterTerm_(ASPCore2Parser::Term_Context * term_){
    builder->buildTerm_(term_);
}
    
void ASPCore2ProgramListener::enterTerm__(ASPCore2Parser::Term__Context * term__){
    builder->buildTerm__(term__);
}

void ASPCore2ProgramListener::enterTerm(ASPCore2Parser::TermContext * term){
    builder->buildTerm(term);
}

void ASPCore2ProgramListener::exitTerm_(ASPCore2Parser::Term_Context * term_){
    // antlr4::ParserRuleContext* context = builder->getParentContext();
    // if(context->getRuleIndex() == ASPCore2Parser::RuleIdentifier)
    //     std::cout<<"Found an identifier"<<std::endl;
}

void ASPCore2ProgramListener::exitTerm__(ASPCore2Parser::Term__Context * term__){
    // antlr4::ParserRuleContext* context = builder->getParentContext();
}

void ASPCore2ProgramListener::exitTerm(ASPCore2Parser::TermContext * term){
    // antlr4::ParserRuleContext* context = builder->getParentContext();
}


void ASPCore2ProgramListener::enterAggregate(ASPCore2Parser::AggregateContext * aggregate){
    builder->buildAggregate(aggregate);

}

void ASPCore2ProgramListener::exitAggregate(ASPCore2Parser::AggregateContext * aggregate){
    builder->setBuildingRightWardAggregate(true);
}

void ASPCore2ProgramListener::enterAggregate_atom(ASPCore2Parser::Aggregate_atomContext * aggregateAtom){
    builder->buildAggregateAtom(aggregateAtom);

}

void ASPCore2ProgramListener::exitAggregate_atom(ASPCore2Parser::Aggregate_atomContext * aggregateAtom){
    builder->setBuildingRightWardAggregate(false);
    builder->addCurrentAggregate();
}

void ASPCore2ProgramListener::enterLeftwardop(ASPCore2Parser::LeftwardopContext * leftwardop){
    builder->buildLeftwardOp(leftwardop);
}

void ASPCore2ProgramListener::enterRightwardop(ASPCore2Parser::RightwardopContext * rightwardop){
    builder->buildRightwardOp(rightwardop);
}

void ASPCore2ProgramListener::enterNaf_literal(ASPCore2Parser::Naf_literalContext * nafLiteral){
    builder->buildNafLiteral(nafLiteral);
}

void ASPCore2ProgramListener::exitNaf_literal(ASPCore2Parser::Naf_literalContext * nafLiteral){

}

void ASPCore2ProgramListener::enterBasic_term(ASPCore2Parser::Basic_termContext * basicTerm){
    builder->buildBasicTerm(basicTerm);
}

void ASPCore2ProgramListener::exitBasic_term(ASPCore2Parser::Basic_termContext * /*ctx*/){

}

void ASPCore2ProgramListener::enterCompareop(ASPCore2Parser::CompareopContext * compareop){
    builder->buildCompareOperator(compareop);
}

void ASPCore2ProgramListener::visitTerminal(antlr4::tree::TerminalNode * terminal){
    builder->buildTerminal(terminal);
}

void ASPCore2ProgramListener::enterExpr(ASPCore2Parser::ExprContext * expression){
    builder->buildExpression(expression);
}

void ASPCore2ProgramListener::enterFactor(ASPCore2Parser::FactorContext * factor){
    builder->buildFactor(factor);
}

void ASPCore2ProgramListener::exitExpr(ASPCore2Parser::ExprContext * expression){
    builder->exitExprFact();
}

void ASPCore2ProgramListener::exitFactor(ASPCore2Parser::FactorContext * factor){
    builder->exitExprFact();
}

void ASPCore2ProgramListener::enterBuiltin_atom(ASPCore2Parser::Builtin_atomContext * builtIn) {
    builder->buildBuiltInAtom(builtIn);
}

void ASPCore2ProgramListener::enterBinop(ASPCore2Parser::BinopContext * binop){
}
void ASPCore2ProgramListener::exitBuiltin_atom(ASPCore2Parser::Builtin_atomContext * builtIn){
    builder->exitBuiltIn();
}

Builder* ASPCore2ProgramListener::getBuilder(){
    return builder;
}

void ASPCore2ProgramListener::setBuilder(Builder* builder){
    this->builder = builder;
}
