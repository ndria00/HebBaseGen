#include "Atom.h"

Atom::Atom(){
    
}

Atom::Atom(std::string identifier, std::vector<Term*>& terms){
    this->identifier = identifier;
    this->terms = terms;
}
std::string Atom::getIdentifier()const{
    return this->identifier;
}
const std::vector<Term*>& Atom::getTerms()const{
    return this->terms;
}
void Atom::setIdentifier(std::string identifier){
    this->identifier = identifier;
}
void Atom::setTerms (std::vector<Term*> terms){
    this->terms = terms;
}

void Atom::print()const{
    std::cout<<""<<this->identifier<<"(";
    for(Term* term : this->terms) {
        term->print();
        std::cout<<", ";
    }
    std::cout<<")";
}