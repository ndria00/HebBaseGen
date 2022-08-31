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

Executor::Executor(){
}
TupleFactory factory;
std::vector<std::string> Executor::predicateIds;
const int _c = 2;
const int _b = 1;
const int _d = 3;
const int _a = 0;
AuxMap<0> pc_({});
AuxMap<0> uc_({});
AuxMap<0> pb_({});
AuxMap<0> ub_({});
AuxMap<0> pd_({});
AuxMap<0> ud_({});
AuxMap<0> pa_({});
AuxMap<0> ua_({});
void printGeneratedFromRule(vector<std::pair<std::string, vector<std::pair<std::string, int>>>>& );

void Executor::init(){
    Executor::predicateIds.push_back("c");
    predicateToID.insert({"c", _c});
    factory.addPredicate();
    Executor::predicateIds.push_back("b");
    predicateToID.insert({"b", _b});
    factory.addPredicate();
    Executor::predicateIds.push_back("d");
    predicateToID.insert({"d", _d});
    factory.addPredicate();
    Executor::predicateIds.push_back("a");
    predicateToID.insert({"a", _a});
    factory.addPredicate();
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _a){
        pa_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d){
        pd_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b){
        pb_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c){
        pc_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _a){
        ua_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d){
        ud_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b){
        ub_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c){
        uc_.insert2Vec(*insertResult.first);
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
    {
        const std::vector<int>* tuples;
        tuples = &pc_.getValuesVec({});
        const std::vector<int>* tuplesU = &uc_.getValuesVec({});
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
            vector<std::pair<std::string, int>> variableNameToID_0;
            terms.push_back(X);
            variableNameToID_0.push_back(std::make_pair("X", X));
            terms.push_back(Y);
            variableNameToID_0.push_back(std::make_pair("Y", Y));
            t = factory.addNewInternalTuple(terms, predicateToID["a"]);
            insertResult = t->setStatus(TruthStatus::True);
            insertUndef(insertResult);
            terms.clear();
            literalsAndVariables.push_back(std::make_pair("a", variableNameToID_0));
            vector<std::pair<std::string, int>> variableNameToID_1;
            terms.push_back(X);
            variableNameToID_1.push_back(std::make_pair("X", X));
            t = factory.addNewInternalTuple(terms, predicateToID["b"]);
            insertResult = t->setStatus(TruthStatus::True);
            insertUndef(insertResult);
            terms.clear();
            literalsAndVariables.push_back(std::make_pair("b", variableNameToID_1));
            printGeneratedFromRule(literalsAndVariables);
        }//close par
    }
    {
        const std::vector<int>* tuples;
        tuples = &pa_.getValuesVec({});
        const std::vector<int>* tuplesU = &ua_.getValuesVec({});
        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
            const Tuple * tuple0 = NULL;
            if(i < tuples->size()){
                tuple0 = factory.getTupleFromInternalID(tuples->at(i));
            }
            else {
                tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
            }
            int Y = (*tuple0)[0];
            int Z = (*tuple0)[1];
            //Rule is firing 
            vector<int> terms;
            vector<std::pair<std::string, vector<std::pair<std::string, int>>>> literalsAndVariables;
            Tuple* t;
            std::pair<const TupleLight *, bool> insertResult;
            vector<std::pair<std::string, int>> variableNameToID_0;
            terms.push_back(Y);
            variableNameToID_0.push_back(std::make_pair("Y", Y));
            terms.push_back(Z);
            variableNameToID_0.push_back(std::make_pair("Z", Z));
            t = factory.addNewInternalTuple(terms, predicateToID["d"]);
            insertResult = t->setStatus(TruthStatus::True);
            insertTrue(insertResult);
            terms.clear();
            literalsAndVariables.push_back(std::make_pair("d", variableNameToID_0));
            printGeneratedFromRule(literalsAndVariables);
        }//close par
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
    }
    std::cout<<". ";
}
