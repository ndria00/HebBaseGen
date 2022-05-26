#include "Body.h"

Body::Body(){

}

Body:: Body(std::vector<Atom*>& conjunction){
    this->conjunction = conjunction;
}
const std::vector<Atom*>& Body::getConjunction()const{
    return this->conjunction;
}
void Body::setConjunction(std::vector<Atom*>& conjunction){
    this->conjunction = conjunction;
}
void Body::print()const{
    for(Atom* a: this->conjunction){
        a->print();
    }
    std::cout<<" ";
}