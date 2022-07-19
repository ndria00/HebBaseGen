#include "Expression.h"

Expression::Expression(){
    //terms = std::vector<ExpressionBase*>();
    first = nullptr;
    second = nullptr;
    parent = nullptr;
}

Expression::Expression(ExpressionBase* parent){
    first = nullptr;
    second = nullptr;
    this->parent = parent;
}

//returns true if the expression contains
//an arithmetic term with a single term inside it
// bool Expression::isElementary(){
//     if(terms.empty())
//         return true;
//     return terms.size() == 1 && terms.at(0)->isLeaf();
// }

void Expression::addExpression(ExpressionBase* expr){
    if(first == nullptr)
        first = expr;
    else if(second == nullptr)
        second = expr;
}

bool Expression::removeExpression(ExpressionBase* expr){
    return false;
}

std::vector<ExpressionBase*>& Expression::getChildren(){
    std::vector<ExpressionBase*> v = std::vector<ExpressionBase*>();
    v.push_back(first);
    v.push_back(second);
    return v;
}

void Expression::setOperator(std::string& op){
    myOperator = op;
}

std::string& Expression::getOperator(){
    return myOperator;
}
        
const std::string& Expression::getAllVariables(){
    std::string variables = "";   
    variables += first->getAllVariables();
    variables += second->getAllVariables();
    return variables;
}

void Expression::print()const{
    std::cout<<"(";
    if(first != nullptr)
        first->print();
    std::cout<<myOperator;
    if(second != nullptr){
        second->print();
    }
    std::cout<<")";
}

ExpressionBase* Expression::getParent(){
    return parent;
}

void Expression::addTerm(TermBase*){

}

const std::string& Expression::getValue()const{

}

void Expression::setValue(std::string&){

}

Expression::~Expression(){
    
}