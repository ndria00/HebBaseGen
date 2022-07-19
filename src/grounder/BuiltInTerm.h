#ifndef BUILTINTERM_H
#define BUILTINTERM_H

#include "ExpressionBase.h"
#include <iostream>
class BuiltInTerm{
    private:
        ExpressionBase* leftExpr;
        ExpressionBase* rightExpr;
        std::string myOperator;
    
    public:
        BuiltInTerm();
        ExpressionBase* getLeftExpr();
        ExpressionBase* getRightExpr();
        const std::string& getMyOperator()const;
        void setOperator(std::string&);
        void addExpression(ExpressionBase*);
        void addLeftExpression(ExpressionBase*);
        void addRightExpression(ExpressionBase*);
        void print()const;
};
#endif