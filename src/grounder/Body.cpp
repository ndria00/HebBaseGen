#include "Body.h"

const std::vector<Literal*>& Body::getConjunction()const{
    return this->conjunction;
}
void Body::setConjunction(std::vector<Literal*>& conjunction){
    this->conjunction = conjunction;
}

void Body::addAtom(Literal* a){
    conjunction.push_back(a);
}

void Body::clear(){
    this->conjunction.clear();
}

void Body::print()const{
    for(unsigned int i = 0; i < conjunction.size(); ++i){
        conjunction.at(i)->print();
        if(i != conjunction.size() -1)
            std::cout<<", ";
    }
    if(aggregates.size() > 0){
        std::cout<<", ";
        for(unsigned i = 0; i< aggregates.size(); ++i){
            aggregates.at(i)->print();
            if(i != aggregates.size() -1)
                std::cout<<", ";
        }
    }
}

const std::vector<Aggregate*>& Body::getAggregates()const{
    return aggregates;
}

void Body::addAggregate(Aggregate* aggregate){
    aggregates.push_back(aggregate);
}