#include "WeakConstraint.h"

WeakConstraint::WeakConstraint(){
}

int WeakConstraint::getLevelPayed()const{
    return this->levelPayed;
}

void WeakConstraint::setLevelPayed(int levelPayed){
    this->levelPayed = levelPayed;
}

const std::vector<Term*>& WeakConstraint::getWeightTerms()const{
    return this->weightTerms;
}

void WeakConstraint::setWeightTerms(std::vector<Term*>& weightTerms){
    this->weightTerms = weightTerms;
}