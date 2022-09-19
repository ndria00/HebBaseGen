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
        virtual void setOperator(std::string&) = 0;
        virtual std::string& getOperator() = 0;
        virtual ExpressionBase* getParent() = 0;
        virtual void addTerm(TermBase*) = 0;
        virtual const std::string& getValue()const = 0;
        virtual void setValue(std::string&) = 0;
        virtual void print()const = 0;
        virtual bool isVariable()const = 0;
        virtual void setVariable(bool ) = 0;
        virtual void getAllVariables(std::unordered_set<std::string>&) = 0;
        virtual void removeSafeVariables(std::unordered_set<std::string>&) = 0;
        virtual bool isBound(std::unordered_set<std::string>&)const = 0;
        virtual std::pair<std::string, bool> getUnboundedVar(std::unordered_set<std::string>&)const = 0;
        virtual std::string getRepresentation() const = 0;
        virtual bool isSimpleFactor() = 0;
        virtual ~ExpressionBase(){}
};
#endif