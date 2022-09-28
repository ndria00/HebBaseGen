#include "ChoiceRule.h"

ChoiceRule::ChoiceRule(){
    body = new Body();
    choiceHead = std::vector<std::pair<Literal*, Body*>>();
    leftTerm = nullptr;
    rightTerm = nullptr;
}   

void ChoiceRule::setLiteral(Literal* lit){
    choiceHead.at(choiceHead.size()-1).first = lit;
}

void ChoiceRule::addLiteralInChoice(Literal* lit){
    choiceHead.at(choiceHead.size()-1).second->addAtom(lit);
}

void ChoiceRule::addLiteralInBody(Literal* lit){
    this->body->addAtom(lit);
}

void ChoiceRule::addChoice(){
    choiceHead.push_back(std::make_pair(nullptr, new Body()));
}

void ChoiceRule::setBody(Body* body){
    this->body = body;
}

ChoiceRule::~ChoiceRule(){
    if(body != nullptr)
        delete body;
    for(int i = 0; i< choiceHead.size(); ++i){
        delete choiceHead[i].second;
    }
}

