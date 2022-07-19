#ifndef AGGREGATE_H
#define AGGREGATE_H
#include "Literal.h"
#include "Term.h"
#include <vector>


class Aggregate{
    private:
        TermBase* leftTerm = nullptr;
        TermBase* rightTerm = nullptr;
        std::string leftOperator;
        std::string rightOperator;
        std::vector<TermBase*> symbolicSet;
        std::vector<Literal*> localLiterals;
        std::string type;
    
    public:
        Aggregate();
        Aggregate(const Aggregate&);
        void addTerm(TermBase*);
        std::vector<TermBase*>& getSymbolicTerms();
        void addLiteral(Literal*);
        std::vector<Literal*>& getLiterals(); 
        std::string getType();
        void setType(std::string);
        void print()const;
        void setLeftTerm(TermBase*);
        TermBase* getLeftTerm()const;
        void setRightTerm(TermBase*);
        TermBase* getRightTerm()const;
        void setLeftOperator(std::string&);
        const std::string& getLeftOperator()const;
        void setRightOperator(std::string&);
        const std::string& getRightOperator()const;

};
#endif