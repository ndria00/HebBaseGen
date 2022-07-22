#include "Literal.h"

Literal::Literal(){
    terms = std::vector<TermBase*>();
    identifier = "";
    negative = false;
}

Literal::Literal(std::string identifier, std::vector<TermBase*>& terms){
    this->identifier = identifier;
    this->terms = terms;
}
std::string Literal::getIdentifier()const{
    return this->identifier;
}
const std::vector<TermBase*>& Literal::getTerms()const{
    return this->terms;
}
void Literal::setIdentifier(std::string identifier){
    this->identifier = identifier;
}
void Literal::setTerms (std::vector<TermBase*>& terms){
    this->terms = terms;
}

void Literal::addTerm(TermBase* term){
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

void Literal::getLiteralVariables(std::set<std::string>& variables)const{
    for(TermBase* term : terms){
        term->getAllVariables(variables);
    }
}

void Literal::removeSafeLiteralVariables(std::set<std::string>& variables)const{
    if(isNegative())
        return;
    for(TermBase* term : terms){
        term->removeSafeVariables(variables);
    }
}