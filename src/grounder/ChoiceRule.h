#ifndef CHOICERULE_H
#define CHOICERULE_H

#include "Body.h"
class ChoiceRule{
    private:
        Body* body;
        std::vector<std::pair<Literal*, Body*>> choiceHead;
        TermBase* leftTerm;
        TermBase* rightTerm;
        std::string leftOperator;
        std::string rightOperator;

    public:
        ChoiceRule();
        void setLiteral(Literal*);
        void addLiteralInChoice(Literal*);
        void addLiteralInBody(Literal*);
        void setBody(Body*);
        void addChoice();
        ~ChoiceRule();
};
#endif /*CHOICERULE_H*/