#include "Rule.h"


Head Rule::getHead()const{
    return this->head;
}
Body Rule::getBody()const{
    return this->body;
}

void Rule::addAtomInHead(Literal* a){
    head.addAtom(a);
}

void Rule::addAtomInBody(Literal* a){
    body.addAtom(a);
}

void Rule::addAggregateInBody(Aggregate* a){
    body.addAggregate(a);
}

void Rule::setHead(Head head){
    this->head = head;
}
void Rule::setBody(Body body){
    this->body = body;
}

void Rule::print()const{
    this->head.print();
    if(body.getConjunction().size() > 0 || body.getAggregates().size() > 0){
        std::cout<<" :- ";
        this->body.print();
    }
    std::cout<<".";
}

void Rule::clearRule(){
    head.clear();
    body.clear();
}