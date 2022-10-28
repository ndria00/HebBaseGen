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
const int _company = 5;
const int _non_strategic_pair = 4;
const int _controlled_by = 2;
const int _strategic_pair = 3;
const int _produced_by = 1;
const int _strategic = 0;
AuxMap<0> pcompany_({});
AuxMap<0> ucompany_({});
AuxMap<0> pnon_strategic_pair_({});
AuxMap<0> unon_strategic_pair_({});
AuxMap<0> pcontrolled_by_({});
AuxMap<0> ucontrolled_by_({});
AuxMap<0> pstrategic_pair_({});
AuxMap<0> ustrategic_pair_({});
AuxMap<0> pproduced_by_({});
AuxMap<0> uproduced_by_({});
AuxMap<0> pstrategic_({});
AuxMap<0> ustrategic_({});
AuxMap<32> pcontrolled_by_4_({4});
AuxMap<32> ucontrolled_by_4_({4});
AuxMap<32> pcontrolled_by_3_({3});
AuxMap<32> ucontrolled_by_3_({3});
AuxMap<32> pcontrolled_by_1_({1});
AuxMap<32> ucontrolled_by_1_({1});
AuxMap<32> pcontrolled_by_2_({2});
AuxMap<32> ucontrolled_by_2_({2});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"company", _company});
    factory.addPredicate();
    predicateToID.insert({"non_strategic_pair", _non_strategic_pair});
    factory.addPredicate();
    predicateToID.insert({"controlled_by", _controlled_by});
    factory.addPredicate();
    predicateToID.insert({"strategic_pair", _strategic_pair});
    factory.addPredicate();
    predicateToID.insert({"produced_by", _produced_by});
    factory.addPredicate();
    predicateToID.insert({"strategic", _strategic});
    factory.addPredicate();
    Executor::predicateIds.push_back("strategic");
    Executor::predicateIds.push_back("produced_by");
    Executor::predicateIds.push_back("controlled_by");
    Executor::predicateIds.push_back("strategic_pair");
    Executor::predicateIds.push_back("non_strategic_pair");
    Executor::predicateIds.push_back("company");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _strategic){
        pstrategic_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _produced_by){
        pproduced_by_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _strategic_pair){
        pstrategic_pair_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _controlled_by){
        pcontrolled_by_.insert2Vec(*insertResult.first);
        pcontrolled_by_1_.insert2Vec(*insertResult.first);
        pcontrolled_by_2_.insert2Vec(*insertResult.first);
        pcontrolled_by_3_.insert2Vec(*insertResult.first);
        pcontrolled_by_4_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _non_strategic_pair){
        pnon_strategic_pair_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _company){
        pcompany_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _strategic){
        ustrategic_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _produced_by){
        uproduced_by_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _strategic_pair){
        ustrategic_pair_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _controlled_by){
        ucontrolled_by_.insert2Vec(*insertResult.first);
        ucontrolled_by_1_.insert2Vec(*insertResult.first);
        ucontrolled_by_2_.insert2Vec(*insertResult.first);
        ucontrolled_by_3_.insert2Vec(*insertResult.first);
        ucontrolled_by_4_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _non_strategic_pair){
        unon_strategic_pair_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _company){
        ucompany_.insert2Vec(*insertResult.first);
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
