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
        virtual const std::string& getAllVariables() override;
        virtual ExpressionBase* getParent() override;
        virtual void addTerm(TermBase*) override;
        virtual const std::string& getValue()const override;
        virtual void setValue(std::string&) override;
        virtual void print()const override;
        ~Expression();

};
#endif