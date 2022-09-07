#include "Executor.h"
#include "../DataStructures/ConstantsManager.h"
#include "../DataStructures/AuxiliaryMapSmart.h"
#include "../DataStructures/TupleFactory.h"
#include "../DataStructures/IndexedSet.h"
typedef TupleLight Tuple;
template<size_t S>
using AuxMap = AuxiliaryMapSmart<S> ;
const std::vector<int> EMPTY_TUPLES_VEC;
const IndexedSet EMPTY_TUPLES_SET;

TupleFactory factory;
std::vector<std::string> Executor::predicateIds;
const int _b = 3;
const int _a = 2;
const int _arc = 1;
const int _reach = 0;
AuxMap<0> pb_({});
AuxMap<0> ub_({});
AuxMap<0> pa_({});
AuxMap<0> ua_({});
AuxMap<0> parc_({});
AuxMap<0> uarc_({});
AuxMap<0> preach_({});
AuxMap<0> ureach_({});
AuxMap<32> parc_0_({0});
AuxMap<32> uarc_0_({0});
void printGeneratedFromRule(vector<std::pair<std::string, vector<std::pair<std::string, int>>>>& );

void Executor::init(){
    Executor::predicateIds.push_back("b");
    predicateToID.insert({"b", _b});
    factory.addPredicate();
    Executor::predicateIds.push_back("a");
    predicateToID.insert({"a", _a});
    factory.addPredicate();
    Executor::predicateIds.push_back("arc");
    predicateToID.insert({"arc", _arc});
    factory.addPredicate();
    Executor::predicateIds.push_back("reach");
    predicateToID.insert({"reach", _reach});
    factory.addPredicate();
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _reach){
        preach_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _arc){
        parc_.insert2Vec(*insertResult.first);
        parc_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _a){
        pa_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b){
        pb_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _reach){
        ureach_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _arc){
        uarc_.insert2Vec(*insertResult.first);
        uarc_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _a){
        ua_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b){
        ub_.insert2Vec(*insertResult.first);
    }
}
void Executor::insertFactIntoFactory(const Literal& lit, bool disjunctiveFact){
    vector<int> terms;
    for(TermBase* term : lit.getTerms()){
        if(!term->isVariable()){
            int mappedValue = ConstantsManager::getInstance().mapConstant(term->getRepresentation());
            terms.push_back(mappedValue);
        }
    }
    Tuple* t = factory.addNewInternalTuple(terms, predicateToID[lit.getIdentifier()]);
    const auto& insertResult = t->setStatus(TruthStatus::True);
    insertTrue(insertResult);
}
void Executor::executeProgram(){
    //TODO
    //---------------------------------------Strongly connected component------------------------
    {
        {
            const std::vector<int>* tuples;
            tuples = &pb_.getValuesVec({});
            const std::vector<int>* tuplesU = &ub_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                }
                int X = (*tuple0)[0];
                //Rule is firing 
                vector<int> terms;
                vector<std::pair<std::string, vector<std::pair<std::string, int>>>> literalsAndVariables;
                Tuple* t;
                std::pair<const TupleLight *, bool> insertResult;
                bool alreadyInFactory = false;
                vector<std::pair<std::string, int>> variableNameToID_0;
                terms.push_back(X);
                variableNameToID_0.push_back(std::make_pair("X", X));
                if(!alreadyInFactory){
                    t = factory.addNewInternalTuple(terms, predicateToID["a"]);
                    insertResult = t->setStatus(TruthStatus::True);
                    literalsAndVariables.push_back(std::make_pair("a", variableNameToID_0));
                    insertTrue(insertResult);
                }
                terms.clear();
                printGeneratedFromRule(literalsAndVariables);
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        {
            const std::vector<int>* tuples;
            tuples = &parc_.getValuesVec({});
            const std::vector<int>* tuplesU = &uarc_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                }
                int X = (*tuple0)[0];
                int Y = (*tuple0)[1];
                //Rule is firing 
                vector<int> terms;
                vector<std::pair<std::string, vector<std::pair<std::string, int>>>> literalsAndVariables;
                Tuple* t;
                std::pair<const TupleLight *, bool> insertResult;
                bool alreadyInFactory = false;
                vector<std::pair<std::string, int>> variableNameToID_0;
                terms.push_back(X);
                variableNameToID_0.push_back(std::make_pair("X", X));
                terms.push_back(Y);
                variableNameToID_0.push_back(std::make_pair("Y", Y));
                if(factory.find(terms, predicateToID["reach"]) != NULL){
                    alreadyInFactory = true;
                }
                if(!alreadyInFactory){
                    t = factory.addNewInternalTuple(terms, predicateToID["reach"]);
                    insertResult = t->setStatus(TruthStatus::True);
                    generatedStack.push_back(t->getId());
                    literalsAndVariables.push_back(std::make_pair("reach", variableNameToID_0));
                    insertTrue(insertResult);
                }
                terms.clear();
                printGeneratedFromRule(literalsAndVariables);
            }//close par
        }//close par
        while(! generatedStack.empty()){
            generatedStack.pop_back();
            {
                const std::vector<int>* tuples;
                tuples = &preach_.getValuesVec({});
                const std::vector<int>* tuplesU = &ureach_.getValuesVec({});
                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                    const Tuple * tuple0 = NULL;
                    if(i < tuples->size()){
                        tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                    }
                    else {
                        tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    }
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    const std::vector<int>* tuples;
                    tuples = &parc_0_.getValuesVec({Y});
                    const std::vector<int>* tuplesU = &uarc_0_.getValuesVec({Y});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                        }
                        int Z = (*tuple1)[1];
                        //Rule is firing 
                        vector<int> terms;
                        vector<std::pair<std::string, vector<std::pair<std::string, int>>>> literalsAndVariables;
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        bool alreadyInFactory = false;
                        vector<std::pair<std::string, int>> variableNameToID_0;
                        terms.push_back(X);
                        variableNameToID_0.push_back(std::make_pair("X", X));
                        terms.push_back(Z);
                        variableNameToID_0.push_back(std::make_pair("Z", Z));
                        if(factory.find(terms, predicateToID["reach"]) != NULL){
                            alreadyInFactory = true;
                        }
                        if(!alreadyInFactory){
                            t = factory.addNewInternalTuple(terms, predicateToID["reach"]);
                            insertResult = t->setStatus(TruthStatus::True);
                            generatedStack.push_back(t->getId());
                            literalsAndVariables.push_back(std::make_pair("reach", variableNameToID_0));
                            insertTrue(insertResult);
                        }
                        terms.clear();
                        printGeneratedFromRule(literalsAndVariables);
                    }//close par
                }//close par
            }//close par
        }
    }
}
void printGeneratedFromRule(vector<std::pair<std::string, vector<std::pair<std::string, int>>>>& literalsVariables){
    for(unsigned i  = 0; i < literalsVariables.size(); ++i){
        std::cout<<literalsVariables[i].first;
        for(unsigned j = 0; j < literalsVariables[i].second.size(); ++j){
            if(j== 0 && literalsVariables[i].second.size() > 0){
                std::cout<< "(";
            }
            std::cout << ConstantsManager::getInstance().unmapConstant(literalsVariables[i].second[j].second);
            if(literalsVariables[i].second.size() > 1 && j < literalsVariables[i].second.size() - 1){
                std::cout << ",";
            }
            if(j == literalsVariables[i].second.size() - 1 && literalsVariables[i].second.size() > 0){
                std::cout << ")";
            }
        }
        if(literalsVariables.size() > 1 && i < literalsVariables.size() - 1){
            std::cout << "|";
        }
        if(i == literalsVariables.size() -1){
            std::cout<<". ";
        }
    }
}
