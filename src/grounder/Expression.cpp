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

void Expression::print()const{
    //std::cout<<"(";
    if(first != nullptr)
        first->print();
    std::cout<<myOperator;
    if(second != nullptr){
        second->print();
    }
    //std::cout<<")";
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

bool Expression::isVariable()const{
    return false;
}
void Expression::setVariable(bool ) {

}

bool Expression::isAnonVar()const{
    return false;
}

void Expression::getAllVariables(std::unordered_set<std::string>& variables){
    if(first != nullptr){
        first->getAllVariables(variables);
    }
    if(second != nullptr){
        second->getAllVariables(variables);
    }
}

void Expression::removeSafeVariables(std::unordered_set<std::string>& variables){
    if(first != nullptr)
        first->removeSafeVariables(variables);
    if(second != nullptr)
        second->removeSafeVariables(variables);
}

bool Expression::isBound(std::unordered_set<std::string>& boundVariables)const{
    bool firstBound = first->isBound(boundVariables);
    if(second == nullptr){
        return firstBound;
    }
    bool secondBound = second->isBound(boundVariables);
    if(firstBound && secondBound)
        return true;
    // //check if expression is an assignment
    // if(first->isSimpleFactor() && secondBound){
    //     return true;
    // }
    // else if(firstBound && second->isSimpleFactor()){
    //     return true;
    // }

    return false;
}

std::pair<std::string, bool> Expression::getUnboundedVar(std::unordered_set<std::string>& boundVariables)const{
    if(first == nullptr && second == nullptr)
        return std::make_pair("", false);
    if(first != nullptr){
        std::pair<std::string, bool> firstUbounded = first->getUnboundedVar(boundVariables); 
        if(firstUbounded.second)
            return firstUbounded;
    }
    if(second != nullptr){
        std::pair<std::string, bool> secondUbounded = second->getUnboundedVar(boundVariables);
        if(secondUbounded.second)
            return secondUbounded;
    }
    return std::make_pair("", true);
}


bool Expression::isSimpleFactor(){
    if(second != nullptr)
        return false;
    return first->isSimpleFactor();
}

std::string Expression::getRepresentation()const{
    std::string representation = "";
    //representation += "(";
    if(first != nullptr)
        representation += first->getRepresentation();
    representation += myOperator;
    if(second != nullptr){
        representation += second->getRepresentation();
    }
    //representation += ")";
    return representation;
}