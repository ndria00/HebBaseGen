#include "Head.h"

Head::Head(){

}

Head:: Head(std::vector<Atom*>& disjunction){
    this->disjunction = disjunction;
}
const std::vector<Atom*>& Head::getDisjunction()const{
    return this->disjunction;
}
void Head::setDisjunction(std::vector<Atom*>& disjunction){
    this->disjunction = disjunction;
}

void Head::print()const{
    //std::cout<<"{";
    for(Atom* a : this->disjunction){
        a->print();
        std::cout<<" ";
    }
    //std::cout<<"}";
}