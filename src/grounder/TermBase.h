#ifndef TERMBASE_H
#define TERMBASE_H

#include <string>
#include <vector>
#include <unordered_set>
class TermBase{
        
    public:
        virtual const std::string& getValue()const = 0;
        virtual void setValue(std::string&) = 0;
        virtual void print() const= 0;
        virtual bool isVariable()const = 0;
        virtual void setVariable(bool) = 0;
        virtual void getAllVariables(std::unordered_set<std::string>&) = 0;
        virtual void removeSafeVariables(std::unordered_set<std::string>&) = 0;
        virtual bool isBound(std::unordered_set<std::string>&)const = 0;
        virtual std::string getRepresentation() const = 0;
        virtual bool operator==(const TermBase&)const{return false;}
        virtual ~TermBase(){}
};
#endif