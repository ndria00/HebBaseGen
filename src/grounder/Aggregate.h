#ifndef AGGREGATE_H
#define AGGREGATE_H
#include "Literal.h"
#include "Term.h"
#include <vector>


class Aggregate{
    private:
        Term* leftTerm = nullptr;
        Term* rightTerm = nullptr;
        std::string leftOperator;
        std::string rightOperator;
        std::vector<Term*> symbolicSet;
        std::vector<Literal*> localLiterals;
        std::string type;
    
    public:
        void addTerm(Term*);
        std::vector<Term*>& getSymbolicTerms();
        void addLiteral(Literal*);
        std::vector<Literal*>& getLiterals(); 
        std::string getType();
        void setType(std::string);
        void print()const;
        void setLeftTerm(Term*);
        Term* getLeftTerm()const;
        void setRightTerm(Term*);
        Term* getRightTerm()const;
        void setLeftOperator(std::string&);
        const std::string& getLeftOperator()const;
        void setRightOperator(std::string&);
        const std::string& getRightOperator()const;

};
#endif