#include "Program.h"
   
Program::Program(){
    rules = std::vector<Rule*>();
    choiceRules = std::vector<ChoiceRule*>();
    //predicateID = std::unordered_set<>();
}

const std::vector<Rule*>& Program::getRules()const{
    return this->rules;
}

const std::vector<ChoiceRule*>& Program::getChoiceRules()const{
    return this->choiceRules;
}
void Program::setRules(std::vector<Rule*>& rules){
    this->rules = rules;
}


void Program::addRule(Rule* r){
    rules.push_back(r);
}

void Program::addChoiceRule(ChoiceRule* rule){
    choiceRules.push_back(rule);
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
    //check safety of choice rules
    for(ChoiceRule* rule : choiceRules){
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

unsigned Program::getIDForPredicate(Literal* lit){
    if(predicateID.count(lit->getIdentifier()) != 0)
        return predicateID[lit->getIdentifier()];
    return 0;
}

void Program::getRulesByID(std::vector<unsigned>& rulesID, std::vector<Rule*>& componentRules){
    componentRules;
    for(unsigned i = 0; i < rulesID.size(); ++i){
        for(unsigned j = 0; j < this->rules.size(); ++j){
            if(rules[j]->getID() == rulesID[i])
                componentRules.push_back(rules[j]);
        }
    }
}

Rule* Program::getRuleByID(unsigned index){
    for(Rule* r : rules)
        if(r->getID() == index)
            return r;
    return nullptr;
}

void Program::addIDBPredicate(Literal* lit){
    iDBPredicates[lit->getIdentifier()] = lit->getID();
}

bool Program::isIDBPredicate(Literal* lit) const{
    if(iDBPredicates.count(lit->getIdentifier()) != 0)
        return true;
    return false;
}

std::unordered_map<std::string, unsigned>& Program::getIDBPredicates(){
    return iDBPredicates;
}

bool Program::containsAggregates()const{
    for(Rule* rule : rules){
        if(rule->getBody()->getAggregates().size() > 0)
            return true;
    }
    return false;
}

bool Program::containsUnsupportedBuiltIn()const{
    // for(Rule* rule : rules){
    //     for(BuiltInTerm* builtIn : rule->getBody()->getBuiltInTerms()){
    //         if(BuiltInTerm->)
    //     }
    // }
    return false;
}