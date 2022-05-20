#ifndef BODY_H_
#define BODY_H_
#include "Atom.h"

class Body{
    private: 
        std::vector<Atom> conjunction;
    
    public:
        Body();
        Body(std::vector<Atom>);
        std::vector<Atom> getConjunction()const;
        void setConjunction(std::vector<Atom>);
        void print()const;
};

#endif