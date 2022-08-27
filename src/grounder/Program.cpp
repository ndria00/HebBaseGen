#include "Program.h"
   
Program::Program(){
    rules = std::vector<Rule*>();
    //predicateID = std::unordered_set<>();
}

const std::vector<Rule*>& Program::getRules()const{
    return this->rules;
}
void Program::setRules(std::vector<Rule*>& rules){
    this->rules = rules;
}

void Program::addRule(Rule* r){
    rules.push_back(r);
}

bool Program::checkSafety()const{
    for(Rule* rule: rules){
        if(!rule->isSafe()){
            std::cout<<"Safety error detected at rule: ";
            rule->print();
            std::cout<<std::endl;
            return false;
        }
    }
    return true;
}

void Program::print()const{
    for(Rule* r : this->rules){
        r->print();
    }
    std::cout<<std::endl;
}

std::unordered_map<std::string, unsigned>& Program::getPredicatesID(){
    return predicateID;
}

bool Program::existsPredicate(std::string repr)const{
    return predicateID.count(repr) > 0;
}

bool Program::addPredicateWithID(const std::string& predName, unsigned id){
    if(predicateID.count(predName) == 0){
        predicateID[predName] = id;
        return true;
    }
    return false;
}