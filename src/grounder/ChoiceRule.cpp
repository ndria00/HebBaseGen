#include "ChoiceRule.h"

ChoiceRule::ChoiceRule(){
    body = new Body();
    choiceHead = std::vector<std::pair<Literal*, Body*>>();
    leftTerm = nullptr;
    rightTerm = nullptr;
}   

const std::vector<std::pair<Literal*, Body*>>& ChoiceRule::getChoiceHead()const{
    return choiceHead;
}

void ChoiceRule::setLiteral(Literal* lit){
    choiceHead.at(choiceHead.size()-1).first = lit;
}

void ChoiceRule::addLiteralInChoice(Literal* lit){
    choiceHead.at(choiceHead.size()-1).second->addAtom(lit);
}

void ChoiceRule::addBuiltInInChoice(BuiltInTerm* term){
    choiceHead.at(choiceHead.size()-1).second->addBuiltIn(term);
}

void ChoiceRule::addLiteralInBody(Literal* lit){
    this->body->addAtom(lit);
}

void ChoiceRule::addChoice(){
    choiceHead.push_back(std::make_pair(nullptr, new Body()));
}

const Head* ChoiceRule::getHead(){
    return nullptr;
}
const Body* ChoiceRule::getBody(){
    return body;
}
void ChoiceRule::addAtomInHead(Literal*){

}
void ChoiceRule::addAtomInBody(Literal* lit){
    body->addAtom(lit);
}
void ChoiceRule::addBuiltInInBody(BuiltInTerm* builtIn){
    body->addBuiltIn(builtIn);
}
void ChoiceRule::addAggregateInBody(Aggregate* aggregate){
    body->addAggregate(aggregate);
}
void ChoiceRule::setHead(Head*){

}
void ChoiceRule::setBody(Body* body){
    this->body = body;
}
bool ChoiceRule::isSafe()const{
    //TODO (ANON_VAR in negative literals)
    std::unordered_set<std::string> variables = std::unordered_set<std::string>();
    //head->getHeadVariables(variables);
    //getting all variables in 
    for(auto& choice: choiceHead){
        choice.first->getLiteralVariables(variables);
        choice.second->getBodyVariables(variables);
    }
    body->getBodyVariables(variables);
    //std::cout<<"Number of variables for rule: "<<variables.size()<<std::endl;
    for(auto& choice: choiceHead){
        choice.second->removeBodySafeVariables(variables);
    }
    body->removeBodySafeVariables(variables);

    return variables.size() == 0;
}

bool ChoiceRule::isFact()const{
    return body->isEmpty();
}
void ChoiceRule::removeBuiltInAt(const std::vector<BuiltInTerm*>::const_iterator& it){
    body->removeBuiltInAt(it);
}

void ChoiceRule::print()const{
    std::cout << "{";
    for(unsigned i = 0; i < choiceHead.size(); ++i){
        choiceHead[i].first->print();
        if(!choiceHead[i].second->isEmpty()){
            std::cout <<":";
            choiceHead[i].second->print();
        }
        if(i != choiceHead.size() -1)
            std::cout << "; ";
    }
    std::cout << "}";
    if(!body->isEmpty()){
        std::cout << ":-";
        body->print();
    }
    std::cout << ".\n";
}

ChoiceRule::~ChoiceRule(){
    if(body != nullptr)
        delete body;
    for(int i = 0; i< choiceHead.size(); ++i){
        delete choiceHead[i].second;
    }
}

