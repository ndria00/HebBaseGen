#ifndef HEAD_H_
#define HEAD_H_

#include "Literal.h"
class Head{
    private:
        std::vector<Literal*> disjunction;
    
    public:
        Head();
        Head(std::vector<Literal*>&);
        const std::vector<Literal*>& getDisjunction()const;
        void setDisjunction(std::vector<Literal*>&);
        void addAtom(Literal*);
        void clear();
        void print()const;
};

#endif