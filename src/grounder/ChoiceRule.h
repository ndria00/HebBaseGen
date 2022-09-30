#ifndef CHOICERULE_H
#define CHOICERULE_H

#include "Body.h"
#include "RuleBase.h"
class ChoiceRule : public RuleBase{
    private:
        Body* body;
        std::vector<std::pair<Literal*, Body*>> choiceHead;
        TermBase* leftTerm;
        TermBase* rightTerm;
        std::string leftOperator;
        std::string rightOperator;

    public:
        ChoiceRule();
        const std::vector<std::pair<Literal*, Body*>>& getChoiceHead()const;
        void setLiteral(Literal*);
        void addLiteralInChoice(Literal*);
        void addBuiltInInChoice(BuiltInTerm*);
        void addLiteralInBody(Literal*);
        void addChoice();
        const Head* getHead() override;
        const Body* getBody() override;
        void addAtomInHead(Literal*) override;
        void addAtomInBody(Literal*) override;
        void addBuiltInInBody(BuiltInTerm*) override;
        void addAggregateInBody(Aggregate*) override;
        void setHead(Head*) override;
        void setBody(Body*) override;
        bool isSafe()const override;
        bool isFact()const override;
        void removeBuiltInAt(const std::vector<BuiltInTerm*>::const_iterator& ) override;
        void print()const;
        ~ChoiceRule();
};
#endif /*CHOICERULE_H*/