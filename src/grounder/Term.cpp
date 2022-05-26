#include "Term.h"
#include <iostream>

Term::Term(){
}
Term::Term(std::string& value){
    this->value = value;
}

const std::string& Term::getValue()const{
    return this->value;
}
void Term::setValue(std::string& value){
    this->value = value;
}

void Term::print(){
    std::cout<<this->value;
}
