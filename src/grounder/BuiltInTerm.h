#ifndef BUILTINTERM_H
#define BUILTINTERM_H

#include "ExpressionBase.h"
#include "SimpleFactor.h"
#include <iostream>
class BuiltInTerm{
    private:
        ExpressionBase* leftExpr;
        ExpressionBase* rightExpr;
        std::string myOperator;
    
    public:
        BuiltInTerm();
        ExpressionBase* getLeftExpr()const;
        ExpressionBase* getRightExpr()const;
        const std::string& getMyOperator()const;
        void setOperator(std::string&);
        void addExpression(ExpressionBase*);
        void addLeftExpression(ExpressionBase*);
        void addRightExpression(ExpressionBase*);
        void getBuiltInVariables(std::unordered_set<std::string>& );
        void removeSafeVariablesInBuiltIn(std::unordered_set<std::string>&);
        std::pair<std::string, bool> canBind(std::unordered_set<std::string>&)const;
        void print()const;
        std::string toString()const;
};
#endif