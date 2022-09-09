#include "Literal.h"

Literal::Literal(){
    terms = std::vector<TermBase*>();
    identifier = "";
    negative = false;
    id = 0;
}

Literal::Literal(std::string identifier, std::vector<TermBase*>& terms){
    this->identifier = identifier;
    this->terms = terms;
}
const std::string& Literal::getIdentifier()const{
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

const std::string& Literal::getTermAt(unsigned i)const{
    return terms.at(i)->getValue();
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

void Literal::getLiteralVariables(std::unordered_set<std::string>& variables)const{
    for(TermBase* term : terms){
        term->getAllVariables(variables);
    }
}

void Literal::removeSafeLiteralVariables(std::unordered_set<std::string>& variables)const{
    if(isNegative())
        return;
    for(TermBase* term : terms){
        term->removeSafeVariables(variables);
    }
}

unsigned Literal::getArity()const{
    return terms.size();
}

std::string Literal::getRepresentation() const{
    std::string representation = "";
    if(negative)
        representation+="not ";
    representation += this->identifier;
    representation += "(";
    for(unsigned i = 0; i < terms.size(); ++i) {
        //representation += terms.at(i)->getRepresentation();
        if(i != terms.size() -1)
            representation += ", ";
    }
    representation += ")";
    return representation;
}

bool Literal::operator==(const Literal& o)const{
    if(identifier != o.getIdentifier()){
        return false;
    }
    if(terms.size() != o.getArity()){
        return false;
    }

    for(TermBase *t : terms){
        for(TermBase* t1: o.getTerms()){
            if(!(*t == *t1)){
                return false;
            }
        }
    }
    return true;
}

bool Literal::isGround(){
    for(TermBase* t : terms)
        if(t->isVariable())
            return false;
    return true;
}

void Literal::setID(unsigned id){
    this->id = id;
}
unsigned Literal::getID()const{
    return id;
}

std::string Literal::getIDAndArity()const{
    std::string res = identifier +  "_" + std::to_string(terms.size());
    return res;
}

bool Literal::isBound(const std::unordered_set<std::string>& boundTerms)const{
    for(unsigned i = 0; i < getArity(); ++i){
        if(terms[i]->isVariable() && !boundTerms.count(getTermAt(i))){
            return false;
        }
    }
    return true;
}

bool Literal::isIDBPredicate()const{
    return idbPredicate;
}

void Literal::setIDBPredicate(bool idbPredicate){
    this->idbPredicate = idbPredicate;
}

void Literal::addVariablesToSet(std::unordered_set<std::string>& boundVariables)const{
    getLiteralVariables(boundVariables);
}

bool Literal::operator<(const Literal& l2)const{
    //if(!isNegative() && ! l2.isNegative())
    //    return 
    if(isNegative() && !l2.isNegative())
        return false;
    
    return true;
}