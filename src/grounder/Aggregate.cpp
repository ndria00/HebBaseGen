#include "Aggregate.h"

void Aggregate::addTerm(Term* t){
    symbolicSet.push_back(t);
}

std::vector<Term*>& Aggregate::getSymbolicTerms(){
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
    for(Term* term : symbolicSet){
        term->print();
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

void Aggregate::setLeftTerm(Term* t){
    leftTerm = t;
}

Term* Aggregate::getLeftTerm()const{
    return leftTerm;
}

void Aggregate::setRightTerm(Term* t){
    rightTerm = t;
}

Term* Aggregate::getRightTerm()const{
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