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
    if(simpleTerm != nullptr)
        return simpleTerm->getValue();
}

void SimpleFactor::setValue(std::string&){

}

bool SimpleFactor::isVariable()const{
    return simpleTerm->isVariable();
}
void SimpleFactor::setVariable(bool ) {

}

void SimpleFactor::getAllVariables(std::unordered_set<std::string>& variables){
    if(simpleTerm->isVariable()){
        std::string myString = simpleTerm->getValue();
        variables.insert(myString);
    }
}

void SimpleFactor::removeSafeVariables(std::unordered_set<std::string>& variables){
    simpleTerm->removeSafeVariables(variables);
}

bool SimpleFactor::isBound(std::unordered_set<std::string>& boundVariables)const{
    if(!isVariable())
        return true;
    return boundVariables.count(this->getValue()) > 0;
}

std::pair<std::string, bool> SimpleFactor::getUnboundedVar(std::unordered_set<std::string>& boundVariables)const{
    return std::make_pair(this->getValue(), boundVariables.count(this->getValue()) > 0);
}

bool SimpleFactor::isSimpleFactor(){
    return true;
}

std::string SimpleFactor::getRepresentation() const{
    std::string representation = "";
    if(simpleTerm != nullptr)
        representation += simpleTerm->getRepresentation();
    return representation;
}