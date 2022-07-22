#include "Head.h"

Head::Head(){
        disjunction = std::vector<Literal*>();
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

void Head::getHeadVariables(std::set<std::string>& variables)const{
    for(Literal* literal : disjunction){
            literal->getLiteralVariables(variables);
    }
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