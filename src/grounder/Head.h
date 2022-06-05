#ifndef HEAD_H_
#define HEAD_H_

#include "Atom.h"
class Head{
    private:
        std::vector<Atom*> disjunction;
    
    public:
        Head();
        Head(std::vector<Atom*>&);
        const std::vector<Atom*>& getDisjunction()const;
        void setDisjunction(std::vector<Atom*>&);
        void addAtom(Atom*);
        void clear();
        void print()const;
};

#endif