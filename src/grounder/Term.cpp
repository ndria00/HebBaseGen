#include "Term.h"
#include <iostream>

Term::Term(){
    value = "";
    variable = false;
}

Term::Term(std::string& value){
    this->value = value;
    variable = false;
}

const std::string& Term::getValue()const{
    return this->value;
}
void Term::setValue(std::string& value){
    this->value = value;
}

void Term::print()const{
    std::cout<<this->value;
}

bool Term::isVariable()const{
    return variable;
}

void Term::setVariable(bool variable){
    this->variable = variable;
}

void Term::getAllVariables(std::set<std::string>& variables){
    if(isVariable())
        variables.insert(value);
}

void Term::removeSafeVariables(std::set<std::string>& variables){
    if(isVariable())
        variables.erase(this->value);
}

Term::~Term(){

}