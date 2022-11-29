#include "Indentation.h"

Indentation::Indentation(){
    steps = 0;
}

Indentation::Indentation(int steps){
    this->steps = steps;
}

Indentation::Indentation(const Indentation& ind) : steps(ind.steps){}

Indentation& Indentation::operator++(){
    steps++;
    return *this;
}
Indentation& Indentation::operator--(){
    steps--;
    return *this;
}

Indentation Indentation::operator++(int){
    Indentation ind(*this);
    steps++;
    return ind;
}

Indentation Indentation::operator--(int){
    Indentation ind(*this);
    steps--;
    return ind;
}

std::ostream& operator<<(std::ostream& out, const Indentation& ind){
    for(int i = 0; i < ind.steps; i++)
        out<<"    ";
    return out;
}