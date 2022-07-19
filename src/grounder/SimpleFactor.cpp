#include "SimpleFactor.h"

SimpleFactor::SimpleFactor() : simpleTerm{nullptr}{
}

SimpleFactor::SimpleFactor(TermBase* t){
    simpleTerm = t;
}

 void SimpleFactor::addExpression(ExpressionBase*) {

}

 bool SimpleFactor::removeExpression(ExpressionBase*) {
    return false;
}

 std::vector<ExpressionBase*>& SimpleFactor::getChildren() {
}

 void SimpleFactor::setOperator(std::string&) {
}

 std::string& SimpleFactor::getOperator() {

}

const std::string& SimpleFactor::getAllVariables(){
    return simpleTerm->getValue();
}

void SimpleFactor::print()const {
    if(simpleTerm != nullptr)
        simpleTerm->print();
}

ExpressionBase* SimpleFactor::getParent(){
    return nullptr;
}

void SimpleFactor::addTerm(TermBase* t){
    simpleTerm = t;
}

SimpleFactor::~SimpleFactor(){
    
}

const std::string& SimpleFactor::getValue()const{

}

void SimpleFactor::setValue(std::string&){

}