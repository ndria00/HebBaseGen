#include "Body.h"

Body::Body(){
    aggregates = std::vector<Aggregate*>();
    conjunction = std::vector<Literal*>();
    builtInTerms = std::vector<BuiltInTerm*>();
}

const std::vector<Literal*>& Body::getConjunction()const{
    return this->conjunction;
}
void Body::setConjunction(std::vector<Literal*>& conjunction){
    this->conjunction = conjunction;
}

const std::vector<BuiltInTerm*>& Body::getBuiltInTerms()const{
    return builtInTerms;
}


void Body::removeBuiltInAt(const std::vector<BuiltInTerm*>::const_iterator& it){
    builtInTerms.erase(it);
}

void Body::removeLiteralAt(const std::vector<Literal*>::const_iterator& it){
    conjunction.erase(it);
}

void Body::addAtom(Literal* a){
    conjunction.push_back(a);
}

void Body::addBuiltIn(BuiltInTerm* builtIn){
    builtInTerms.push_back(builtIn);
}

void Body::print()const{
    for(unsigned int i = 0; i < conjunction.size(); ++i){
        conjunction.at(i)->print();
        if(i != conjunction.size() -1)
            std::cout<<", ";
    }
    if(aggregates.size() > 0){
        if(conjunction.size() > 0)
            std::cout<<", ";
        for(unsigned i = 0; i< aggregates.size(); ++i){
            aggregates.at(i)->print();
            if(i != aggregates.size() -1)
                std::cout<<", ";
        }
    }
    if(builtInTerms.size() > 0){
        std::cout<<", ";
        for(unsigned i = 0; i< builtInTerms.size(); ++i){
            builtInTerms.at(i)->print();
            if(i != builtInTerms.size() -1)
                std::cout<<", ";
        }
    }
}

const std::vector<Aggregate*>& Body::getAggregates()const{
    return aggregates;
}

void Body::addAggregate(Aggregate* aggregate){
    aggregates.push_back(aggregate);
}

void Body::getBodyVariables(std::unordered_set<std::string>& variables)const{
    for(Literal* literal : conjunction){
        literal->getLiteralVariables(variables);
    }
    for(BuiltInTerm* builtIn: builtInTerms){
        builtIn->getBuiltInVariables(variables);
    }
}

void Body::removeBodySafeVariables(std::unordered_set<std::string>& variables)const{
    for(Literal* literal : conjunction){
        literal->removeSafeLiteralVariables(variables);
    } 
    for(BuiltInTerm* builtIn: builtInTerms){
        builtIn->removeSafeVariablesInBuiltIn(variables);
    }
}

bool compareLiterals(const Literal* l1, const Literal* l2){
    if(l1->isNegative() && !l2->isNegative())
        return false;
    
    return true;
}

void Body::sortLiterals(){
    std::sort(conjunction.begin(), conjunction.end(), compareLiterals);
}

bool Body::isEmpty(){
    return conjunction.size() == 0 && aggregates.size() == 0 && builtInTerms.size() == 0;
}


unsigned Body::getNegativeSize()const{
    unsigned count = 0;
    for(Literal* l : getConjunction())
        if(l->isNegative())
            count++;
    return count;
}

void Body::reorderBodyLiterals(){
    std::sort(conjunction.begin(), conjunction.end(), [](Literal* left, Literal* right) {
    return true;
    });
}