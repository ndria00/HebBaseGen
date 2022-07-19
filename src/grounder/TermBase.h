#ifndef TERMBASE_H
#define TERMBASE_H

#include <string>
class TermBase{
        
    public:
        virtual const std::string& getValue()const = 0;
        virtual void setValue(std::string&) = 0;
        virtual void print() const= 0;
        virtual ~TermBase(){}
};
#endif