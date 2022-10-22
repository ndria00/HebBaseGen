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

bool ChoiceRule::containsLiteralInHead(unsigned id)const{
    for(auto& choiceElem : choiceHead){
        if(choiceElem.first->getID() == id){
            return true;
        }
    }
    return false;
}

bool ChoiceRule::containsLiteralInHead(Literal* l1)const{
    for(auto& choiceElem : choiceHead){
        if(l1->getIDAndArity() == choiceElem.first->getIDAndArity())
            return true;
    }
    return false;
}

bool ChoiceRule::containsLiteralInBody(std::string& id)const{
    for(Literal* lit : body->getConjunction()){
        if(lit->getIdentifier() == id)
            return true; 
    }
    return false;
}

void ChoiceRule::getAllLiterals(std::unordered_set<unsigned>& allLiterals)const{
    for(auto& choiceElem : choiceHead){
        allLiterals.insert(choiceElem.first->getID());
        for(Literal* l : choiceElem.second->getConjunction()){
            allLiterals.insert(l->getID());
        }
    }
    for(Literal* l : body->getConjunction()){
        allLiterals.insert(l->getID());
    }
}

void ChoiceRule::sortLiteralsInBody(int starter = -1){
    std::vector<unsigned> orderedConjunction;
    std::unordered_set<unsigned> addedLiterals;
    std::unordered_set<std::string> boundVariables;
    if(starter != -1){
        addedLiterals.insert(starter);
        orderedConjunction.push_back(starter);
    }
    Literal* boundLiteral;
    Literal* positiveLiteral;
    unsigned jBound;
    unsigned jPos;
    unsigned currentIndex = 0;
    while(orderedConjunction.size() < body->getConjunction().size()){
        boundLiteral = nullptr;
        positiveLiteral = nullptr;
        //think to add all builtins ASAP and consider eventual assigned variables as bound
        std::unordered_set<unsigned> builtInTermAdded;
        for(unsigned j = 0; j < body->getBuiltInTerms().size(); ++j){
            if(builtInTermAdded.count(j) == 0){
                std::pair<std::string, bool> bindingResult = body->getBuiltInTerms().at(j)->canBind(boundVariables);
                if(body->getBuiltInTerms().at(j)->getMyOperator() != "=" && body->getBuiltInTerms().at(j)->getMyOperator() != "=="){
                        if(bindingResult.second && bindingResult.first == ""){
                            body->getBuiltInTerms().at(j)->getBuiltInVariables(boundVariables);
                            builtInTermAdded.insert(j);
                        }
                }
                else{
                    if(bindingResult.second){
                        body->getBuiltInTerms().at(j)->getBuiltInVariables(boundVariables);
                        builtInTermAdded.insert(j);
                    }
                }
            }
        }
        unsigned firstNotAddedPos = 0;
        bool foundFirstNotAdded = false;
        for(unsigned  j = 0; j < body->getConjunction().size(); ++j){
            if(body->getConjunction().at(j)->isBound(boundVariables) && !addedLiterals.count(j)){
                boundLiteral = body->getConjunction().at(j);
                jBound = j;
            }
            else if(!body->getConjunction().at(j)->isNegative() && positiveLiteral == nullptr && ! addedLiterals.count(j)){
                positiveLiteral = body->getConjunction().at(j); 
                jPos = j;
            }
            else if(!foundFirstNotAdded &&  !addedLiterals.count(j)){
                foundFirstNotAdded = true;
                firstNotAddedPos = j;
            }
        }
        //std::vector<Literal*>::const_iterator it = body->getConjunction().begin();
        if(boundLiteral != nullptr){
            orderedConjunction.push_back(jBound);
            addedLiterals.insert(jBound);
            //orderedConjunction.push_back(boundLiteral);
            //body->removeLiteralAt(it + jBound);
            boundLiteral->addVariablesToSet(boundVariables);
            //std::cout<<"adding bound lit\n";
        }
        else if(positiveLiteral != nullptr){
            //orderedConjunction.push_back(positiveLiteral);
            //body->removeLiteralAt(it + jPos);
            orderedConjunction.push_back(jPos);
            addedLiterals.insert(jPos);
            positiveLiteral->addVariablesToSet(boundVariables);
            //std::cout<<"adding positive lit\n";
        }
        else{//only negative literals are left
            Literal* lit = body->getConjunction().at(firstNotAddedPos);
            //orderedConjunction.push_back(lit);
            //body->removeLiteralAt(it);
            orderedConjunction.push_back(firstNotAddedPos);
            addedLiterals.insert(firstNotAddedPos);
            lit->addVariablesToSet(boundVariables);
            //std::cout<<"adding negative lit\n";
        }
        currentIndex++;
    }
    //if(starter != -1)
    starterToBodyIndexes[starter] = orderedConjunction;
    //body->setConjunction(orderedConjunction);
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

bool ChoiceRule::isClassicRule()const{
    return false;
}

bool ChoiceRule::isChoiceRule()const{
    return true;
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

