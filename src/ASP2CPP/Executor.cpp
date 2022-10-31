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
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _a){
        pa_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d){
        pd_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b){
        pb_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c){
        pc_.insert2VecNoColl(*insertResult.first);
        pc_0_.insert2VecNoColl(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _a){
        ua_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d){
        ud_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b){
        ub_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c){
        uc_.insert2VecNoColl(*insertResult.first);
        uc_0_.insert2VecNoColl(*insertResult.first);
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
    printTuple(t);
}
void Executor::executeProgram(){
}
