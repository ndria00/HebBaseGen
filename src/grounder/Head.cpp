#include "Head.h"

Head::Head(){

}

Head:: Head(std::vector<Literal*>& disjunction){
    this->disjunction = disjunction;
}

void Head::addAtom(Literal* a){
    disjunction.push_back(a);
}

const std::vector<Literal*>& Head::getDisjunction()const{
    return this->disjunction;
}
void Head::setDisjunction(std::vector<Literal*>& disjunction){
    this->disjunction = disjunction;
}

void Head::clear(){
    this->disjunction.clear();
}

void Head::print()const{
    //std::cout<<"{";
    for(unsigned i = 0; i< disjunction.size(); ++i){
        disjunction.at(i)->print();
        if(i != disjunction.size() -1)
            std::cout<<" | ";
    }
    //std::cout<<"}";
}