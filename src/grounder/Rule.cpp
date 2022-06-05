#include "Rule.h"

Rule::Rule(){

}

Rule::Rule(Head& head, Body& body){
    this->head = head;
    this->body = body;
}

Head Rule::getHead()const{
    return this->head;
}
Body Rule::getBody()const{
    return this->body;
}

void Rule::addAtomInHead(Atom* a){
    head.addAtom(a);
}

void Rule::addAtomInBody(Atom* a){
    body.addAtom(a);
}

void Rule::setHead(Head head){
    this->head = head;
}
void Rule::setBody(Body body){
    this->body = body;
}

void Rule::print()const{
    this->head.print();
    this->body.print();
}

void Rule::clearRule(){
    head.clear();
    body.clear();
}

Rule::~Rule(){

}