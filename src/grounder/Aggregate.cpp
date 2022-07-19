#include "Aggregate.h"

Aggregate::Aggregate(){
    leftTerm = nullptr;
    rightTerm = nullptr;
    symbolicSet = std::vector<TermBase*>();
    localLiterals = std::vector<Literal*>();
    type = "";
}

Aggregate::Aggregate(const Aggregate& a){
}

void Aggregate::addTerm(TermBase* t){
    symbolicSet.push_back(t);
}

std::vector<TermBase*>& Aggregate::getSymbolicTerms(){
    return symbolicSet;
}

void Aggregate::addLiteral(Literal* l){
    localLiterals.push_back(l);
}

std::vector<Literal*>& Aggregate::getLiterals(){
    return localLiterals;
}

std::string Aggregate::getType(){
    return type;
}

void Aggregate::setType(std::string type){
    this->type = type;
}

void Aggregate::print()const{
    if(leftTerm != nullptr){
        leftTerm->print();
        std::cout<<leftOperator;
    }
    std::cout<<type<<"{";
    for(unsigned i = 0; i< symbolicSet.size(); ++i){
        symbolicSet.at(i)->print();
        if(i != symbolicSet.size() -1 )
            std::cout<<", ";
    }
    std::cout<<" : ";
    for(Literal* literal : localLiterals){
        literal->print();
    }
    std::cout<<"}";
    if(rightTerm != nullptr){
        std::cout<<rightOperator;
        rightTerm->print();

    }
}

void Aggregate::setLeftTerm(TermBase* t){
    leftTerm = t;
}

TermBase* Aggregate::getLeftTerm()const{
    return leftTerm;
}

void Aggregate::setRightTerm(TermBase* t){
    rightTerm = t;
}

TermBase* Aggregate::getRightTerm()const{
    return rightTerm;
}
void Aggregate::setLeftOperator(std::string& leftOp){
    leftOperator = leftOp;
}

const std::string& Aggregate::getLeftOperator()const{
   return  leftOperator;
}

void Aggregate::setRightOperator(std::string& rightOp){
    rightOperator = rightOp;
}

const std::string& Aggregate::getRightOperator()const{
    return rightOperator;
}