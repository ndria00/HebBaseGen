#include "Rule.h"

Rule::Rule(){
    head = new Head();
    body = new Body();
    safe = true;
    starterToBodyIndexes = std::unordered_map<int, std::vector<unsigned>>();
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

bool Rule::containsLiteralInBody(std::string& id)const{
    for(Literal* lit : body->getConjunction()){
        if(lit->getIdentifier() == id)
            return true; 
    }
    return false;
}

void Rule::sortLiteralsInBody(int starter =-1){
    
    std::vector<unsigned> orderedConjunction;
    std::unordered_set<unsigned> addedLiterals;
    std::unordered_set<std::string> boundVariables;
    if(starter != -1){
        addedLiterals.insert(starter);
        orderedConjunction.push_back(starter);
    }
    Literal* boundLiteral;
    Literal* positiveLiteral;
    unsigned jBound;
    unsigned jPos;
    unsigned currentIndex = 0;
    while(orderedConjunction.size() < body->getConjunction().size()){
        boundLiteral = nullptr;
        positiveLiteral = nullptr;
        for(unsigned  j = 0; j < body->getConjunction().size(); ++j){
            if(body->getConjunction().at(j)->isBound(boundVariables) && !addedLiterals.count(j)){
                boundLiteral = body->getConjunction().at(j);
                jBound = j;
            }
            else if(!body->getConjunction().at(j)->isNegative() && positiveLiteral == nullptr && ! addedLiterals.count(j)){
                positiveLiteral = body->getConjunction().at(j); 
                jPos = j;
            }
        }
        //std::vector<Literal*>::const_iterator it = body->getConjunction().begin();
        if(boundLiteral != nullptr){
            orderedConjunction.push_back(jBound);
            addedLiterals.insert(jBound);
            //orderedConjunction.push_back(boundLiteral);
            //body->removeLiteralAt(it + jBound);
            boundLiteral->addVariablesToSet(boundVariables);
            //std::cout<<"adding bound lit\n";
        }
        else if(positiveLiteral != nullptr){
            //orderedConjunction.push_back(positiveLiteral);
            //body->removeLiteralAt(it + jPos);
            orderedConjunction.push_back(jPos);
            addedLiterals.insert(jPos);
            positiveLiteral->addVariablesToSet(boundVariables);
            //std::cout<<"adding positive lit\n";
        }
        else{//only negative literals are left
            Literal* lit = body->getConjunction().at(currentIndex);
            //orderedConjunction.push_back(lit);
            //body->removeLiteralAt(it);
            orderedConjunction.push_back(currentIndex);
            addedLiterals.insert(currentIndex);
            lit->addVariablesToSet(boundVariables);
            //std::cout<<"adding negative lit\n";
        }
        currentIndex++;
    }
    //if(starter != -1)
    starterToBodyIndexes[starter] = orderedConjunction;
    //body->setConjunction(orderedConjunction);
}

std::vector<unsigned>& Rule::getOrderedBodyByStarter(int starter){
    return starterToBodyIndexes[starter];
}

std::unordered_map<int, std::vector<unsigned>>& Rule::getStartersAndBody(){
    return starterToBodyIndexes;
}

void Rule::removeBuiltInAt(const std::vector<BuiltInTerm*>::const_iterator& it){
    body->removeBuiltInAt((it));
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