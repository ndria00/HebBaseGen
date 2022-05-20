#include "Atom.h"

Atom::Atom(){
    
}

Atom::Atom(std::string identifier, std::vector<std::string>terms){
    this->identifier = identifier;
    this->terms = terms;
}
std::string Atom::getIdentifier()const{
    return this->identifier;
}
std::vector<std::string> Atom::getTerms()const{
    return this->terms;
}
void Atom::setIdentifier(std::string identifier){
    this->identifier = identifier;
}
void Atom::setTerms (std::vector<std::string> terms){
    this->terms = terms;
}

void Atom::print()const{
    std::cout<<""<<this->identifier<<"(";
    for(std::string term : this->terms) {
        std::cout<<term<<", ";
    }
    std::cout<<")";
}