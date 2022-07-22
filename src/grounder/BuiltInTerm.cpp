#include "BuiltInTerm.h"

BuiltInTerm::BuiltInTerm(){
    leftExpr = nullptr;
    rightExpr = nullptr;
}
ExpressionBase* BuiltInTerm::getLeftExpr(){
    return leftExpr;
}
ExpressionBase* BuiltInTerm::getRightExpr(){
    return rightExpr;
}
const std::string& BuiltInTerm::getMyOperator()const{
    return myOperator;
}
void BuiltInTerm::addLeftExpression(ExpressionBase* expr){
    leftExpr = expr;
}
void BuiltInTerm::addRightExpression(ExpressionBase* expr){
    rightExpr = expr;
}
void BuiltInTerm::addExpression(ExpressionBase* expr){
    if(leftExpr == nullptr)
        leftExpr = expr;
    else if(rightExpr == nullptr)
        rightExpr = expr;
}

void BuiltInTerm::setOperator(std::string& myOperator){
    this->myOperator = myOperator;
}

void BuiltInTerm::print()const{
    if(leftExpr != nullptr)
        leftExpr->print();
    std::cout<<myOperator;
    if(rightExpr != nullptr)
        rightExpr->print();
}

void BuiltInTerm::getBuiltInVariables(std::set<std::string>& variables){
    leftExpr->getAllVariables(variables);
    rightExpr->getAllVariables(variables);
}

void BuiltInTerm::removeSafeVariablesInBuiltIn(std::set<std::string>& variables){
    //remove a signle variable only if the built in is an assignment
    if(myOperator == "=" || myOperator == "=="){
        SimpleFactor* temp;
        if(leftExpr->isSimpleFactor()){
            temp= dynamic_cast<SimpleFactor*>(leftExpr);
            if(variables.find(temp->getValue()) != variables.end()){
                variables.erase(temp->getValue());
                return;
            }
        }
        if(rightExpr->isSimpleFactor()){
            temp = dynamic_cast<SimpleFactor*>(rightExpr);
            if(variables.find(temp->getValue()) != variables.end()){
                variables.erase(temp->getValue());
                return;
            }
        }
    }
}