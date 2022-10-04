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
const int _e = 4;
const int _c = 2;
const int _b = 1;
const int _d = 3;
const int _a = 0;
AuxMap<0> pe_({});
AuxMap<0> ue_({});
AuxMap<0> pc_({});
AuxMap<0> uc_({});
AuxMap<0> pb_({});
AuxMap<0> ub_({});
AuxMap<0> pd_({});
AuxMap<0> ud_({});
AuxMap<0> pa_({});
AuxMap<0> ua_({});
AuxMap<32> pc_0_({0});
AuxMap<32> uc_0_({0});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"e", _e});
    factory.addPredicate();
    predicateToID.insert({"c", _c});
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
        pc_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _e){
        pe_.insert2Vec(*insertResult.first);
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
        uc_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _e){
        ue_.insert2Vec(*insertResult.first);
    }
}
void Executor::OnLiteralTrueUndef(Tuple* t, bool disjunctiveFact){
    if(!disjunctiveFact){
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
        {
            const std::vector<int>* tuples;
            tuples = &pe_.getValuesVec({});
            const std::vector<int>* tuplesU = &ue_.getValuesVec({});
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
                            if(tuple0!= NULL){
                                int X = (*tuple0)[0];
                                const std::vector<int>* tuples;
                                tuples = &pc_0_.getValuesVec({X});
                                const std::vector<int>* tuplesU = &uc_0_.getValuesVec({X});
                                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                    const Tuple * tuple1 = NULL;
                                    if(i < tuples->size()){
                                        tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                                    }
                                    else {
                                        tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                    }
                                    if(tuple1!= NULL){
                                        int Y = (*tuple1)[1];
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({X}, _a);
                                        if(t->isUnknown()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else if(t->isUndef()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                        }
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
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
                            if(tuple0!= NULL){
                                int X = (*tuple0)[0];
                                const std::vector<int>* tuples;
                                tuples = &pc_0_.getValuesVec({X});
                                const std::vector<int>* tuplesU = &uc_0_.getValuesVec({X});
                                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                    const Tuple * tuple1 = NULL;
                                    if(i < tuples->size()){
                                        tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                                    }
                                    else {
                                        tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                    }
                                    if(tuple1!= NULL){
                                        int Y = (*tuple1)[1];
                                        if(X<Y){
                                            //Rule is firing 
                                            Tuple* t;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            t = factory.addNewInternalTuple({X}, _d);
                                            if(t->isUnknown()){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                insertUndef(insertResult);
                                            }
                                            else if(t->isUndef()){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                            }
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {//adding already existing tuple for predicates involved in recursion
            const std::vector<int>* actualTuples;
        }
    }
    printGeneratedBase();
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
void Executor::printGeneratedBase(){
    const std::vector<int>* tuples;
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
