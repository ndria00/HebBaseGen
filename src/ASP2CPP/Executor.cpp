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
const int _d1 = 7;
const int _c4 = 6;
const int _c2 = 4;
const int _d2 = 8;
const int _c1 = 3;
const int _b2 = 2;
const int _c3 = 5;
const int _b1 = 1;
const int _a = 0;
AuxMap<0> pd1_({});
AuxMap<0> ud1_({});
AuxMap<0> pc4_({});
AuxMap<0> uc4_({});
AuxMap<0> pc2_({});
AuxMap<0> uc2_({});
AuxMap<0> pd2_({});
AuxMap<0> ud2_({});
AuxMap<0> pc1_({});
AuxMap<0> uc1_({});
AuxMap<0> pb2_({});
AuxMap<0> ub2_({});
AuxMap<0> pc3_({});
AuxMap<0> uc3_({});
AuxMap<0> pb1_({});
AuxMap<0> ub1_({});
AuxMap<0> pa_({});
AuxMap<0> ua_({});
AuxMap<32> pb2_0_({0});
AuxMap<32> ub2_0_({0});
AuxMap<32> pc2_0_({0});
AuxMap<32> uc2_0_({0});
AuxMap<32> pc4_0_({0});
AuxMap<32> uc4_0_({0});
AuxMap<32> pd2_0_({0});
AuxMap<32> ud2_0_({0});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"d1", _d1});
    factory.addPredicate();
    predicateToID.insert({"c4", _c4});
    factory.addPredicate();
    predicateToID.insert({"c2", _c2});
    factory.addPredicate();
    predicateToID.insert({"d2", _d2});
    factory.addPredicate();
    predicateToID.insert({"c1", _c1});
    factory.addPredicate();
    predicateToID.insert({"b2", _b2});
    factory.addPredicate();
    predicateToID.insert({"c3", _c3});
    factory.addPredicate();
    predicateToID.insert({"b1", _b1});
    factory.addPredicate();
    predicateToID.insert({"a", _a});
    factory.addPredicate();
    Executor::predicateIds.push_back("a");
    Executor::predicateIds.push_back("b1");
    Executor::predicateIds.push_back("b2");
    Executor::predicateIds.push_back("c1");
    Executor::predicateIds.push_back("c2");
    Executor::predicateIds.push_back("c3");
    Executor::predicateIds.push_back("c4");
    Executor::predicateIds.push_back("d1");
    Executor::predicateIds.push_back("d2");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _a){
        pa_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b1){
        pb1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c3){
        pc3_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b2){
        pb2_.insert2VecNoColl(*insertResult.first);
        pb2_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c1){
        pc1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d2){
        pd2_.insert2VecNoColl(*insertResult.first);
        pd2_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c2){
        pc2_.insert2VecNoColl(*insertResult.first);
        pc2_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c4){
        pc4_.insert2VecNoColl(*insertResult.first);
        pc4_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d1){
        pd1_.insert2VecNoColl(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _a){
        ua_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b1){
        ub1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c3){
        uc3_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b2){
        ub2_.insert2VecNoColl(*insertResult.first);
        ub2_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c1){
        uc1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d2){
        ud2_.insert2VecNoColl(*insertResult.first);
        ud2_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c2){
        uc2_.insert2VecNoColl(*insertResult.first);
        uc2_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c4){
        uc4_.insert2VecNoColl(*insertResult.first);
        uc4_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d1){
        ud1_.insert2VecNoColl(*insertResult.first);
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
