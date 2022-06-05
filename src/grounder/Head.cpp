#include "Head.h"

Head::Head(){

}

Head:: Head(std::vector<Atom*>& disjunction){
    this->disjunction = disjunction;
}

void Head::addAtom(Atom* a){
    disjunction.push_back(a);
}

const std::vector<Atom*>& Head::getDisjunction()const{
    return this->disjunction;
}
void Head::setDisjunction(std::vector<Atom*>& disjunction){
    this->disjunction = disjunction;
}

void Head::clear(){
    this->disjunction.clear();
}

void Head::print()const{
    //std::cout<<"{";
    for(Atom* a : this->disjunction){
        a->print();
        std::cout<<" ";
    }
    //std::cout<<"}";
}