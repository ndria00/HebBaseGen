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

void Rule::sortLiteralsInBody(){
    
    std::vector<Literal*> orderedConjunction;
    std::unordered_set<std::string> boundVariables;
   
    Literal* boundLiteral;
    Literal* positiveLiteral;
    unsigned jBound;
    unsigned jPos;
    while(body->getConjunction().size() > 0){
        boundLiteral = nullptr;
        positiveLiteral = nullptr;
        for(unsigned  j = 0; j < body->getConjunction().size(); ++j){
            if(body->getConjunction().at(j)->isBound(boundVariables)){
                boundLiteral = body->getConjunction().at(j);
                jBound = j;
            }
            else if(!body->getConjunction().at(j)->isNegative() && positiveLiteral == nullptr){
                positiveLiteral = body->getConjunction().at(j); 
                jPos = j;
            }
        }
        std::vector<Literal*>::const_iterator it = body->getConjunction().begin();
        if(boundLiteral != nullptr){
            orderedConjunction.push_back(boundLiteral);
            body->removeLiteralAt(it + jBound);
            boundLiteral->addVariablesToSet(boundVariables);
            //std::cout<<"adding bound lit\n";
        }
        else if(positiveLiteral != nullptr){
            orderedConjunction.push_back(positiveLiteral);
            body->removeLiteralAt(it + jPos);
            positiveLiteral->addVariablesToSet(boundVariables);
            //std::cout<<"adding positive lit\n";
        }
        else{//only negative literals are left
            Literal* lit = body->getConjunction().at(0);
            orderedConjunction.push_back(lit);
            body->removeLiteralAt(it);
            lit->addVariablesToSet(boundVariables);
            //std::cout<<"adding negative lit\n";
        }
    }
    body->setConjunction(orderedConjunction);
}

void Rule::getRecursiveIndexes(std::vector<unsigned>& recursiveDepIndex)const{
    for(unsigned  i = 0; i < body->getConjunction().size(); ++i){
        for(unsigned j = 0; j < head->getDisjunction().size(); ++j){
            if(body->getConjunction().at(i)->getID() == head->getDisjunction().at(j)->getID())
                recursiveDepIndex.push_back(i);
        }
    }
}

Rule::~Rule(){
    delete head;
    delete body;  
}