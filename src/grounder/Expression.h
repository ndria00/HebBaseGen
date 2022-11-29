#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "ExpressionBase.h"
#include <iostream>
class Expression : public ExpressionBase{
    private:
        //std::vector<ExpressionBase*> terms;
        ExpressionBase* first;
        ExpressionBase* second;
        std::string myOperator;
        ExpressionBase* parent;

    public:
        Expression();
        Expression(ExpressionBase*);
        virtual void addExpression(ExpressionBase*) override;
        virtual bool removeExpression(ExpressionBase*) override;
        virtual std::vector<ExpressionBase*>& getChildren() override;
        virtual void setOperator(std::string&) override;
        virtual std::string& getOperator() override;
        virtual ExpressionBase* getParent() override;
        virtual void addTerm(TermBase*) override;
        virtual const std::string& getValue()const override;
        virtual void setValue(std::string&) override;
        virtual void print()const override;
        virtual bool isVariable()const override;
        virtual void setVariable(bool ) override;
        virtual bool isAnonVar()const override;
        virtual void getAllVariables(std::unordered_set<std::string>&) override;
        virtual void removeSafeVariables(std::unordered_set<std::string>&) override;
        virtual bool isBound(std::unordered_set<std::string>&)const;
        virtual std::pair<std::string, bool> getUnboundedVar(std::unordered_set<std::string>&)const override;
        virtual std::string getRepresentation()const override;
        virtual bool isSimpleFactor() override;
        ~Expression();

};
#endif