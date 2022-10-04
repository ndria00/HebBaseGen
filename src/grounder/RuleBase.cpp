#include"RuleBase.h"

RuleBase::RuleBase() : alreadyCompiled{false}{}

bool RuleBase::isAlreadyCompiled()const{
    return alreadyCompiled;
}
void RuleBase::setAlreadyCompiled(bool status){
    this->alreadyCompiled = status;
}

void RuleBase::setID(unsigned id){
    this->id = id;
}

unsigned RuleBase::getID()const{
    return id;
}
