#ifndef BODY_H_
#define BODY_H_
#include "Atom.h"

class Body{
    private: 
        std::vector<Atom*> conjunction;
    
    public:
        Body();
        Body(std::vector<Atom*>&);
        const std::vector<Atom*>& getConjunction()const;
        void addAtom(Atom*);
        void setConjunction(std::vector<Atom*>&);
        void clear();
        void print()const;
};

#endif