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
const int _f = 5;
const int _e = 4;
const int _c = 2;
const int _t = 6;
const int _b = 1;
const int _d = 3;
const int _a = 0;
AuxMap<0> pf_({});
AuxMap<0> uf_({});
AuxMap<0> pe_({});
AuxMap<0> ue_({});
AuxMap<0> pc_({});
AuxMap<0> uc_({});
AuxMap<0> pt_({});
AuxMap<0> ut_({});
AuxMap<0> pb_({});
AuxMap<0> ub_({});
AuxMap<0> pd_({});
AuxMap<0> ud_({});
AuxMap<0> pa_({});
AuxMap<0> ua_({});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"f", _f});
    factory.addPredicate();
    predicateToID.insert({"e", _e});
    factory.addPredicate();
    predicateToID.insert({"c", _c});
    factory.addPredicate();
    predicateToID.insert({"t", _t});
    factory.addPredicate();
    predicateToID.insert({"b", _b});
    factory.addPredicate();
    predicateToID.insert({"d", _d});
    factory.addPredicate();
    predicateToID.insert({"a", _a});
    factory.addPredicate();
    Executor::predicateIds.push_back("a");
    Executor::predicateIds.push_back("b");
    Executor::predicateIds.push_back("c");
    Executor::predicateIds.push_back("d");
    Executor::predicateIds.push_back("e");
    Executor::predicateIds.push_back("f");
    Executor::predicateIds.push_back("t");
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
    else if(insertResult.first->getPredicateName() == _t){
        pt_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c){
        pc_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _e){
        pe_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _f){
        pf_.insert2Vec(*insertResult.first);
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
    else if(insertResult.first->getPredicateName() == _t){
        ut_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c){
        uc_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _e){
        ue_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _f){
        uf_.insert2Vec(*insertResult.first);
    }
}
void Executor::OnLiteralTrueUndef(Tuple* t, bool disjunctiveFact){
    if(disjunctiveFact){
        const auto& insertResult = t->setStatus(TruthStatus::True);
        insertTrue(insertResult);
    }
    else{
        const auto& insertResult = t->setStatus(TruthStatus::Undef);
        insertUndef(insertResult);
    }
}
void Executor::executeProgram(){
    auto start = std::chrono::high_resolution_clock::now();
    //TODO
    //---------------------------------------Strongly connected component------------------------
    {
        {//adding already existing tuple for predicates involved in recursion
            const std::vector<int>* actualTuples;
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {//adding already existing tuple for predicates involved in recursion
            const std::vector<int>* actualTuples;
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {//adding already existing tuple for predicates involved in recursion
            const std::vector<int>* actualTuples;
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {//adding already existing tuple for predicates involved in recursion
            const std::vector<int>* actualTuples;
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        {
            const std::vector<int>* tuples;
            tuples = &pf_.getValuesVec({});
            const std::vector<int>* tuplesU = &uf_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X}, _e);
                    if(t->isUnknown()){
                        generatedStack.push_back(t->getId());
                        insertResult = t->setStatus(TruthStatus::True);
                        insertTrue(insertResult);
                    }
                    else if(t->isUndef()){
                        insertResult = t->setStatus(TruthStatus::True);
                        factory.removeFromCollisionsList(t->getId());
                        insertTrue(insertResult);
                    }
                    //negative literals saving
                }//close par
            }//close par
        }//close par
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            if(literalName == _e){
                {
                    int X = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pt_.getValuesVec({});
                    const std::vector<int>* tuplesU = &ut_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                        }
                        if(tuple1!= NULL){
                            int Y = (*tuple1)[0];
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X}, _e);
                            if(t->isUnknown()){
                                generatedStack.push_back(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                            else if(t->isUndef()){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                            //negative literals saving
                        }//close par
                    }//close par
                }//close par
            }
        }
    }
    printGeneratedBase();
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
void Executor::printGeneratedBase(){
    const std::vector<int>* tuples;
    tuples = &pf_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uf_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pe_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ue_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pc_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uc_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pt_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ut_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pb_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ub_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pd_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ud_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pa_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ua_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
}
