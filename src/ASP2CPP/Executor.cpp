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
const int _b = 4;
const int _h = 2;
const int _a = 3;
const int _d = 1;
const int _c = 0;
AuxMap<0> pb_({});
AuxMap<0> ub_({});
AuxMap<0> ph_({});
AuxMap<0> uh_({});
AuxMap<0> pa_({});
AuxMap<0> ua_({});
AuxMap<0> pd_({});
AuxMap<0> ud_({});
AuxMap<0> pc_({});
AuxMap<0> uc_({});
void Executor::init(){
    Executor::predicateIds.push_back("b");
    predicateToID.insert({"b", _b});
    factory.addPredicate();
    Executor::predicateIds.push_back("h");
    predicateToID.insert({"h", _h});
    factory.addPredicate();
    Executor::predicateIds.push_back("a");
    predicateToID.insert({"a", _a});
    factory.addPredicate();
    Executor::predicateIds.push_back("d");
    predicateToID.insert({"d", _d});
    factory.addPredicate();
    Executor::predicateIds.push_back("c");
    predicateToID.insert({"c", _c});
    factory.addPredicate();
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _c){
        pc_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d){
        pd_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _a){
        pa_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _h){
        ph_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b){
        pb_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _c){
        uc_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d){
        ud_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _a){
        ua_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _h){
        uh_.insert2Vec(*insertResult.first);
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
    {
        const std::vector<int>* tuples;
        tuples = &pd_.getValuesVec({});
        const std::vector<int>* tuplesU = &EMPTY_TUPLES_VEC;
        const Tuple* tupleU = NULL;
        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
            const Tuple * tuple0 = NULL;
            if(i < tuples->size()){
                tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                if(tuplesU != &EMPTY_TUPLES_VEC) {
                    tupleU = NULL;
                }
            }
            else {
                tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                tupleU = tuple0;
            }
            int X = (*tuple0)[0];
            const std::vector<int>* tuples;
            tuples = &ph_.getValuesVec({});
            const std::vector<int>* tuplesU = &EMPTY_TUPLES_VEC;
            const Tuple* tupleU = NULL;
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple1 = NULL;
                if(i < tuples->size()){
                    tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                    if(tuplesU != &EMPTY_TUPLES_VEC) {
                        tupleU = NULL;
                    }
                }
                else {
                    tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    tupleU = tuple1;
                }
                int Y = (*tuple1)[0];
                //Rule is firing 
                bool insertAsUndef = false;
                vector<int> terms;
                std::string representation = "";
                representation += "c";
                representation += "(";
                terms.push_back(X);
                representation += ConstantsManager::getInstance().unmapConstant(X);
                representation += ",";
                terms.push_back(Y);
                representation += ConstantsManager::getInstance().unmapConstant(Y);
                representation += ",";
                representation +=").";
                Tuple* t = factory.addNewInternalTuple(terms, predicateToID["c"]);
                const auto& insertResult = t->setStatus(TruthStatus::True);
                if(insertAsUndef){
                    insertUndef(insertResult);
                }
                else{
                    insertTrue(insertResult);
                    std::cout<< representation + " ";
                }
            }//close par
        }//close par
    }
    {
        const std::vector<int>* tuples;
        tuples = &pb_.getValuesVec({});
        const std::vector<int>* tuplesU = &EMPTY_TUPLES_VEC;
        const Tuple* tupleU = NULL;
        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
            const Tuple * tuple0 = NULL;
            if(i < tuples->size()){
                tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                if(tuplesU != &EMPTY_TUPLES_VEC) {
                    tupleU = NULL;
                }
            }
            else {
                tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                tupleU = tuple0;
            }
            int X = (*tuple0)[0];
            //Rule is firing 
            //{"X", 22}
            //{"Y", 33}
            bool insertAsUndef = false;
            vector<int> terms;
            std::string representation = "";
            representation += "a";
            representation += "(";
            terms.push_back(X);
            representation += ConstantsManager::getInstance().unmapConstant(X);
            representation += ",";
            representation +=").";
            Tuple* t = factory.addNewInternalTuple(terms, predicateToID["a"]);
            const auto& insertResult = t->setStatus(TruthStatus::True);
            if(insertAsUndef){
                insertUndef(insertResult);
            }
            else{
                insertTrue(insertResult);
                std::cout<< representation + " ";
            }
        }//close par
    }
}
