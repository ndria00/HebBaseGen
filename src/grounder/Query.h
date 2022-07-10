#include "Literal.h"

class Query{
    private:
       Literal atom;
    
    public:
        Query();
        Query(Literal);
        Literal getAtom()const;
        setAtom(Literal);

};