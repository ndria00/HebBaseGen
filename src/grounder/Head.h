#ifndef HEAD_H_
#define HEAD_H_

#include "Literal.h"
class Head{
    private:
        std::vector<Literal*> disjunction;
    
    public:
        Head();
        const std::vector<Literal*>& getDisjunction()const;
        void setDisjunction(std::vector<Literal*>&);
        void addAtom(Literal*);
        void getHeadVariables(std::unordered_set<std::string>&)const;
        void print()const;
};

#endif