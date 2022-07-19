#ifndef EXPRESSIONBASE_H_
#define EXPRESSIONBASE_H_
#include <vector>
#include <string>
#include "TermBase.h"

class ExpressionBase : public TermBase{
    public:
        virtual void addExpression(ExpressionBase*) = 0;
        virtual bool removeExpression(ExpressionBase*) = 0;
        virtual std::vector<ExpressionBase*>& getChildren() = 0;
        virtual const std::string& getAllVariables() = 0;
        virtual void setOperator(std::string&) = 0;
        virtual std::string& getOperator() = 0;
        virtual ExpressionBase* getParent() = 0;
        virtual void addTerm(TermBase*) = 0;
        virtual const std::string& getValue()const = 0;
        virtual void setValue(std::string&) = 0;
        virtual void print()const = 0;
        virtual ~ExpressionBase(){}
};
#endif