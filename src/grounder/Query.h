#include "Atom.h"

class Query{
    private:
       Atom atom;
    
    public:
        Query();
        Query(Atom);
        Atom getAtom()const;
        setAtom(Atom);

};