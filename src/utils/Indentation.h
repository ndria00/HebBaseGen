#ifndef INDENTATION_H
#define INDENTATION_H
#include <iostream>

class Indentation{
    private:
        int steps;
    public:    
    Indentation();
    Indentation(int);
    Indentation(const Indentation&);
    //prefix
    Indentation& operator++();
    Indentation& operator--();
    //postfix
    Indentation operator++(int);
    Indentation operator--(int);
    friend std::ostream& operator<<(std::ostream&, const Indentation&);
};

#endif /*INDENTATION_H*/