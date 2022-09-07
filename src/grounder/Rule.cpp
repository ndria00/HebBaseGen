#include "Rule.h"

Rule::Rule(){
    head = new Head();
    body = new Body();
    safe = true;
}

const Head* Rule::getHead(){
    return this->head;
}
const Body* Rule::getBody(){
    return this->body;
}

void Rule::addAtomInHead(Literal* a){
    head->addAtom(a);
}

void Rule::addAtomInBody(Literal* a){
    body->addAtom(a);
}

void Rule::addAggregateInBody(Aggregate* a){
    body->addAggregate(a);
}

void Rule::addBuiltInInBody(BuiltInTerm* b){
    body->addBuiltIn(b);
}

void Rule::setHead(Head* head){
    this->head = head;
}
void Rule::setBody(Body* body){
    this->body = body;
}

void Rule::setSafetyStatus(bool safe){
    this->safe = safe;
}

bool Rule::isSafe()const{
    //TODO (ANON_VAR in negative literals)
    std::unordered_set<std::string> variables = std::unordered_set<std::string>();
    head->getHeadVariables(variables);
    body->getBodyVariables(variables);
    //std::cout<<"Number of variables for rule: "<<variables.size()<<std::endl;
    body->removeBodySafeVariables(variables);

    return variables.size() == 0;
}

bool Rule::isFact()const{
    //CHECK
    //a(1):-b(1). is actually a fact
    if(!body->isEmpty())
        return false;
    
    for(Literal* lit : head->getDisjunction()){
        if( !lit->isGround()){
            return false;
        }
    }
    return true;
}

void Rule::print()const{
    head->print();
    if(body->getConjunction().size() > 0 || body->getAggregates().size() > 0){
        std::cout<<" :- ";
        body->print();
    }
    std::cout<<".";
}

void Rule::setID(unsigned id){
    this->id = id;
}
unsigned Rule::getID()const{
    return id;
}

bool Rule::containsLiteralInHead(Literal* l)const{
    for(Literal* l1 : head->getDisjunction()){
        if(l1->getIDAndArity() == l->getIDAndArity())
            return true;
    }
    return false;
}
bool Rule::containsLiteralInHead(unsigned id)const{
    for(Literal* l1 : head->getDisjunction()){
        if(l1->getID() == id)
            return true;
    }
    return false;
}

Rule::~Rule(){
    delete head;
    delete body;  
}