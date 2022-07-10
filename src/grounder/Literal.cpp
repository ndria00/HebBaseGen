#include "Literal.h"

Literal::Literal(){
    negative = false;
}

Literal::Literal(std::string identifier, std::vector<Term*>& terms){
    this->identifier = identifier;
    this->terms = terms;
}
std::string Literal::getIdentifier()const{
    return this->identifier;
}
const std::vector<Term*>& Literal::getTerms()const{
    return this->terms;
}
void Literal::setIdentifier(std::string identifier){
    this->identifier = identifier;
}
void Literal::setTerms (std::vector<Term*> terms){
    this->terms = terms;
}

void Literal::addTerm(Term* term){
    terms.push_back(term);
}

void Literal::clear(){
    terms.clear();
}

bool Literal::isNegative()const{
    return negative == true;
}
void Literal::setNegative(bool value){
    negative = value;
}

void Literal::print()const{
    if(negative)
        std::cout<<"not ";
    std::cout<<""<<this->identifier<<"(";
    for(unsigned i = 0; i < terms.size(); ++i) {
        terms.at(i)->print();
        if(i != terms.size() -1)
            std::cout<<", ";
    }
    std::cout<<")";
}