#include "ASPCore2ProgramListener.h"

ASPCore2ProgramListener::ASPCore2ProgramListener(Builder& builder): builder{builder}, ASPCore2BaseListener(){}

void ASPCore2ProgramListener::enterProgram(ASPCore2Parser::ProgramContext * program){
    std::cout<<"Entered program "<<program->getText() <<std::endl;
}

void ASPCore2ProgramListener::exitProgram(ASPCore2Parser::ProgramContext * program){
    std::cout<<"Exited program "<<program->getText()<<std::endl;
}

void ASPCore2ProgramListener::enterRule(ASPCore2Parser::RuleContext * rule){
    builder.buildRule(rule);
}
void ASPCore2ProgramListener::exitRule(ASPCore2Parser::RuleContext * rule){
    builder.addRule(builder.getCurrentRule());
}

void ASPCore2ProgramListener::enterHead(ASPCore2Parser::HeadContext * head){
    std::cout<<"Entered Head.... disjunction: "<<""<<std::endl;
    builder.setBuildingHead(true);
}
void ASPCore2ProgramListener::exitHead(ASPCore2Parser::HeadContext * head){
    std::cout<<"Exited Head "<<head->getText()<<std::endl;
    builder.setBuildingHead(false);
}

void ASPCore2ProgramListener::enterBody(ASPCore2Parser::BodyContext * body){
    std::cout<<"Entered body "<<body->getText() <<std::endl;
    builder.setBuildingHead(false);
}
void ASPCore2ProgramListener::exitBody(ASPCore2Parser::BodyContext * body){
    std::cout<<"Exited body "<<body->getText() <<std::endl;
    builder.setBuildingHead(false);
}

void ASPCore2ProgramListener::enterClassic_literal(ASPCore2Parser::Classic_literalContext *literal){
    builder.buildAtom(literal);

}
void ASPCore2ProgramListener::exitClassic_literal(ASPCore2Parser::Classic_literalContext *literal){
    if(builder.isBuildingHead())
        builder.getCurrentRule()->addAtomInHead(builder.getCurrentAtom());
    else
        builder.getCurrentRule()->addAtomInBody(builder.getCurrentAtom());
    
    builder.addAtom(builder.getCurrentAtom());
}

Builder ASPCore2ProgramListener::getBuilder(){
    return builder;
}
void ASPCore2ProgramListener::setBuilder(Builder& builder){
    this->builder = builder;
}
