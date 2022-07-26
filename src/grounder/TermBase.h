#ifndef TERMBASE_H
#define TERMBASE_H

#include <string>
#include <vector>
#include <set>
class TermBase{
        
    public:
        virtual const std::string& getValue()const = 0;
        virtual void setValue(std::string&) = 0;
        virtual void print() const= 0;
        virtual bool isVariable()const = 0;
        virtual void setVariable(bool) = 0;
        virtual void getAllVariables(std::set<std::string>&) = 0;
        virtual void removeSafeVariables(std::set<std::string>&) = 0;
        // virtual void saveInConstantsManager()const = 0;
        virtual ~TermBase(){}
};
#endif