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

std::vector<unsigned>& RuleBase::getOrderedBodyByStarter(int starter){
    return starterToBodyIndexes[starter];
}

std::unordered_map<int, std::vector<unsigned>>& RuleBase::getStartersAndBody(){
    return starterToBodyIndexes;
}
