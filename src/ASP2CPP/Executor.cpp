#include <chrono>
#include "Executor.h"
#include "../DataStructures/ConstantsManager.h"
#include "../DataStructures/IndexedSet.h"
typedef TupleLight Tuple;
template<size_t S>
using AuxMap = AuxiliaryMapSmart<S> ;
const std::vector<int> EMPTY_TUPLES_VEC;
const IndexedSet EMPTY_TUPLES_SET;

std::vector<std::string> Executor::predicateIds;
const int _uncut = 5;
const int _cut = 3;
const int _edge = 4;
const int _node = 2;
const int _out = 1;
const int _in = 0;
AuxMap<0> puncut_({});
AuxMap<0> pcut_({});
AuxMap<0> pedge_({});
AuxMap<0> pnode_({});
AuxMap<0> pout_({});
AuxMap<0> pin_({});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"uncut", _uncut});
    factory.addPredicate();
    predicateToID.insert({"cut", _cut});
    factory.addPredicate();
    predicateToID.insert({"edge", _edge});
    factory.addPredicate();
    predicateToID.insert({"node", _node});
    factory.addPredicate();
    predicateToID.insert({"out", _out});
    factory.addPredicate();
    predicateToID.insert({"in", _in});
    factory.addPredicate();
    Executor::predicateIds.push_back("in");
    Executor::predicateIds.push_back("out");
    Executor::predicateIds.push_back("node");
    Executor::predicateIds.push_back("cut");
    Executor::predicateIds.push_back("edge");
    Executor::predicateIds.push_back("uncut");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _in){
        pin_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _out){
        pout_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _node){
        pnode_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _edge){
        pedge_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _cut){
        pcut_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _uncut){
        puncut_.insert2VecNoColl(*insertResult.first);
    }
}
void Executor::OnLiteralTrueUndef(Tuple* t, bool disjunctiveFact){
    if(!disjunctiveFact){
        const auto& insertResult = t->setStatus(TruthStatus::True);
        insertTrue(insertResult);
    }
    printTuple(t);
}
void Executor::executeProgram(){
    auto start = std::chrono::high_resolution_clock::now();
    //---------------------------------------Strongly connected component------------------------
    {
        {
            const std::vector<int>* tuples;
            tuples = &pnode_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size(); i++){
                const Tuple * tuple0 = NULL;
                tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X}, _in);
                    if(t->isUnknown()){
                        printTuple(t);
                        insertResult = t->setStatus(TruthStatus::True);
                        insertTrue(insertResult);
                    }
                    t = factory.addNewInternalTuple({X}, _out);
                    if(t->isUnknown()){
                        printTuple(t);
                        insertResult = t->setStatus(TruthStatus::True);
                        insertTrue(insertResult);
                    }
                }//close par
            }//close par
        }//close par
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pnode_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pnode_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            const std::vector<int>* tuples;
            tuples = &pin_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size(); i++){
                const Tuple * tuple0 = NULL;
                tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    const std::vector<int>* tuples;
                    tuples = &pout_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size(); i++){
                        const Tuple * tuple1 = NULL;
                        tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        if(tuple1!= NULL){
                            int Y = (*tuple1)[0];
                            const Tuple* tuple2 = factory.find({X, Y}, _edge);
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y}, _cut);
                                if(t->isUnknown()){
                                    printTuple(t);
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            const std::vector<int>* tuples;
            tuples = &pin_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size(); i++){
                const Tuple * tuple0 = NULL;
                tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    const std::vector<int>* tuples;
                    tuples = &pout_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size(); i++){
                        const Tuple * tuple1 = NULL;
                        tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        if(tuple1!= NULL){
                            int Y = (*tuple1)[0];
                            const Tuple* tuple2 = factory.find({X, Y}, _edge);
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({Y,X}, _cut);
                                if(t->isUnknown()){
                                    printTuple(t);
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pout_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pout_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pin_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pin_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            const std::vector<int>* tuples;
            tuples = &pedge_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size(); i++){
                const Tuple * tuple0 = NULL;
                tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    const Tuple negativeTuple = Tuple({X, Y}, _cut, true);
                    const Tuple* tuple1 = factory.find({X, Y}, _cut);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        tuple1= NULL;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X,Y}, _uncut);
                        if(t->isUnknown()){
                            printTuple(t);
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &puncut_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        puncut_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pcut_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pcut_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pedge_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pedge_.clear();
    }
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
