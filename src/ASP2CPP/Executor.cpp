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
const int _inverse = 25;
const int _shift = 23;
const int _push = 22;
const int _orpush = 18;
const int _cpush = 21;
const int _rrpush = 16;
const int _neg_goal = 15;
const int _neighbor = 14;
const int _dneighbor = 13;
const int _row = 0;
const int _dir = 24;
const int _conn = 9;
const int _rpush = 19;
const int _col = 2;
const int _goal = 5;
const int _num_rows = 3;
const int _num_cols = 4;
const int _field = 1;
const int _step = 11;
const int _goal_on = 6;
const int _ccpush = 17;
const int _reach = 7;
const int _ocpush = 20;
const int _init_on = 8;
const int _connect = 10;
const int _max_steps = 12;
AuxMap<0> pinverse_({});
AuxMap<0> uinverse_({});
AuxMap<0> pshift_({});
AuxMap<0> ushift_({});
AuxMap<0> ppush_({});
AuxMap<0> upush_({});
AuxMap<0> porpush_({});
AuxMap<0> uorpush_({});
AuxMap<0> pcpush_({});
AuxMap<0> ucpush_({});
AuxMap<0> prrpush_({});
AuxMap<0> urrpush_({});
AuxMap<0> pneg_goal_({});
AuxMap<0> uneg_goal_({});
AuxMap<0> pneighbor_({});
AuxMap<0> uneighbor_({});
AuxMap<0> pdneighbor_({});
AuxMap<0> udneighbor_({});
AuxMap<0> prow_({});
AuxMap<0> urow_({});
AuxMap<0> pdir_({});
AuxMap<0> udir_({});
AuxMap<0> pconn_({});
AuxMap<0> uconn_({});
AuxMap<0> prpush_({});
AuxMap<0> urpush_({});
AuxMap<0> pcol_({});
AuxMap<0> ucol_({});
AuxMap<0> pgoal_({});
AuxMap<0> ugoal_({});
AuxMap<0> pnum_rows_({});
AuxMap<0> unum_rows_({});
AuxMap<0> pnum_cols_({});
AuxMap<0> unum_cols_({});
AuxMap<0> pfield_({});
AuxMap<0> ufield_({});
AuxMap<0> pstep_({});
AuxMap<0> ustep_({});
AuxMap<0> pgoal_on_({});
AuxMap<0> ugoal_on_({});
AuxMap<0> pccpush_({});
AuxMap<0> uccpush_({});
AuxMap<0> preach_({});
AuxMap<0> ureach_({});
AuxMap<0> pocpush_({});
AuxMap<0> uocpush_({});
AuxMap<0> pinit_on_({});
AuxMap<0> uinit_on_({});
AuxMap<0> pconnect_({});
AuxMap<0> uconnect_({});
AuxMap<0> pmax_steps_({});
AuxMap<0> umax_steps_({});
AuxMap<32> prpush_0_({0});
AuxMap<32> urpush_0_({0});
AuxMap<32> pcpush_0_({0});
AuxMap<32> ucpush_0_({0});
AuxMap<32> ppush_1_({1});
AuxMap<32> upush_1_({1});
AuxMap<64> pneighbor_0_1_({0,1});
AuxMap<64> uneighbor_0_1_({0,1});
AuxMap<32> pneighbor_0_({0});
AuxMap<32> uneighbor_0_({0});
AuxMap<64> ppush_0_1_({0,1});
AuxMap<64> upush_0_1_({0,1});
AuxMap<64> pneighbor_0_2_({0,2});
AuxMap<64> uneighbor_0_2_({0,2});
AuxMap<32> pfield_1_({1});
AuxMap<32> ufield_1_({1});
AuxMap<32> pfield_0_({0});
AuxMap<32> ufield_0_({0});
AuxMap<64> pshift_0_1_({0,1});
AuxMap<64> ushift_0_1_({0,1});
AuxMap<64> pconn_0_1_({0,1});
AuxMap<64> uconn_0_1_({0,1});
AuxMap<64> pgoal_0_1_({0,1});
AuxMap<64> ugoal_0_1_({0,1});
AuxMap<64> preach_0_1_({0,1});
AuxMap<64> ureach_0_1_({0,1});
AuxMap<32> preach_2_({2});
AuxMap<32> ureach_2_({2});
AuxMap<128> pdneighbor_1_2_3_4_({1,2,3,4});
AuxMap<128> udneighbor_1_2_3_4_({1,2,3,4});
AuxMap<64> pdneighbor_1_2_({1,2});
AuxMap<64> udneighbor_1_2_({1,2});
AuxMap<96> pconn_0_1_3_({0,1,3});
AuxMap<96> uconn_0_1_3_({0,1,3});
AuxMap<96> pdneighbor_0_1_2_({0,1,2});
AuxMap<96> udneighbor_0_1_2_({0,1,2});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"inverse", _inverse});
    factory.addPredicate();
    predicateToID.insert({"shift", _shift});
    factory.addPredicate();
    predicateToID.insert({"push", _push});
    factory.addPredicate();
    predicateToID.insert({"orpush", _orpush});
    factory.addPredicate();
    predicateToID.insert({"cpush", _cpush});
    factory.addPredicate();
    predicateToID.insert({"rrpush", _rrpush});
    factory.addPredicate();
    predicateToID.insert({"neg_goal", _neg_goal});
    factory.addPredicate();
    predicateToID.insert({"neighbor", _neighbor});
    factory.addPredicate();
    predicateToID.insert({"dneighbor", _dneighbor});
    factory.addPredicate();
    predicateToID.insert({"row", _row});
    factory.addPredicate();
    predicateToID.insert({"dir", _dir});
    factory.addPredicate();
    predicateToID.insert({"conn", _conn});
    factory.addPredicate();
    predicateToID.insert({"rpush", _rpush});
    factory.addPredicate();
    predicateToID.insert({"col", _col});
    factory.addPredicate();
    predicateToID.insert({"goal", _goal});
    factory.addPredicate();
    predicateToID.insert({"num_rows", _num_rows});
    factory.addPredicate();
    predicateToID.insert({"num_cols", _num_cols});
    factory.addPredicate();
    predicateToID.insert({"field", _field});
    factory.addPredicate();
    predicateToID.insert({"step", _step});
    factory.addPredicate();
    predicateToID.insert({"goal_on", _goal_on});
    factory.addPredicate();
    predicateToID.insert({"ccpush", _ccpush});
    factory.addPredicate();
    predicateToID.insert({"reach", _reach});
    factory.addPredicate();
    predicateToID.insert({"ocpush", _ocpush});
    factory.addPredicate();
    predicateToID.insert({"init_on", _init_on});
    factory.addPredicate();
    predicateToID.insert({"connect", _connect});
    factory.addPredicate();
    predicateToID.insert({"max_steps", _max_steps});
    factory.addPredicate();
    Executor::predicateIds.push_back("row");
    Executor::predicateIds.push_back("field");
    Executor::predicateIds.push_back("col");
    Executor::predicateIds.push_back("num_rows");
    Executor::predicateIds.push_back("num_cols");
    Executor::predicateIds.push_back("goal");
    Executor::predicateIds.push_back("goal_on");
    Executor::predicateIds.push_back("reach");
    Executor::predicateIds.push_back("init_on");
    Executor::predicateIds.push_back("conn");
    Executor::predicateIds.push_back("connect");
    Executor::predicateIds.push_back("step");
    Executor::predicateIds.push_back("max_steps");
    Executor::predicateIds.push_back("dneighbor");
    Executor::predicateIds.push_back("neighbor");
    Executor::predicateIds.push_back("neg_goal");
    Executor::predicateIds.push_back("rrpush");
    Executor::predicateIds.push_back("ccpush");
    Executor::predicateIds.push_back("orpush");
    Executor::predicateIds.push_back("rpush");
    Executor::predicateIds.push_back("ocpush");
    Executor::predicateIds.push_back("cpush");
    Executor::predicateIds.push_back("push");
    Executor::predicateIds.push_back("shift");
    Executor::predicateIds.push_back("dir");
    Executor::predicateIds.push_back("inverse");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _max_steps){
        pmax_steps_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _connect){
        pconnect_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _init_on){
        pinit_on_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _ocpush){
        pocpush_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _reach){
        preach_.insert2Vec(*insertResult.first);
        preach_0_1_.insert2Vec(*insertResult.first);
        preach_2_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _ccpush){
        pccpush_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _goal_on){
        pgoal_on_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _step){
        pstep_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _field){
        pfield_.insert2Vec(*insertResult.first);
        pfield_0_.insert2Vec(*insertResult.first);
        pfield_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _num_cols){
        pnum_cols_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _num_rows){
        pnum_rows_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _goal){
        pgoal_.insert2Vec(*insertResult.first);
        pgoal_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _inverse){
        pinverse_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _shift){
        pshift_.insert2Vec(*insertResult.first);
        pshift_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _orpush){
        porpush_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _push){
        ppush_.insert2Vec(*insertResult.first);
        ppush_0_1_.insert2Vec(*insertResult.first);
        ppush_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _cpush){
        pcpush_.insert2Vec(*insertResult.first);
        pcpush_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _rrpush){
        prrpush_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _neighbor){
        pneighbor_.insert2Vec(*insertResult.first);
        pneighbor_0_.insert2Vec(*insertResult.first);
        pneighbor_0_1_.insert2Vec(*insertResult.first);
        pneighbor_0_2_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _row){
        prow_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _neg_goal){
        pneg_goal_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _dneighbor){
        pdneighbor_.insert2Vec(*insertResult.first);
        pdneighbor_0_1_2_.insert2Vec(*insertResult.first);
        pdneighbor_1_2_.insert2Vec(*insertResult.first);
        pdneighbor_1_2_3_4_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _dir){
        pdir_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _conn){
        pconn_.insert2Vec(*insertResult.first);
        pconn_0_1_.insert2Vec(*insertResult.first);
        pconn_0_1_3_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _col){
        pcol_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _rpush){
        prpush_.insert2Vec(*insertResult.first);
        prpush_0_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _max_steps){
        umax_steps_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _connect){
        uconnect_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _init_on){
        uinit_on_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _ocpush){
        uocpush_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _reach){
        ureach_.insert2Vec(*insertResult.first);
        ureach_0_1_.insert2Vec(*insertResult.first);
        ureach_2_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _ccpush){
        uccpush_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _goal_on){
        ugoal_on_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _step){
        ustep_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _field){
        ufield_.insert2Vec(*insertResult.first);
        ufield_0_.insert2Vec(*insertResult.first);
        ufield_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _num_cols){
        unum_cols_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _num_rows){
        unum_rows_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _goal){
        ugoal_.insert2Vec(*insertResult.first);
        ugoal_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _inverse){
        uinverse_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _shift){
        ushift_.insert2Vec(*insertResult.first);
        ushift_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _orpush){
        uorpush_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _push){
        upush_.insert2Vec(*insertResult.first);
        upush_0_1_.insert2Vec(*insertResult.first);
        upush_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _cpush){
        ucpush_.insert2Vec(*insertResult.first);
        ucpush_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _rrpush){
        urrpush_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _neighbor){
        uneighbor_.insert2Vec(*insertResult.first);
        uneighbor_0_.insert2Vec(*insertResult.first);
        uneighbor_0_1_.insert2Vec(*insertResult.first);
        uneighbor_0_2_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _row){
        urow_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _neg_goal){
        uneg_goal_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _dneighbor){
        udneighbor_.insert2Vec(*insertResult.first);
        udneighbor_0_1_2_.insert2Vec(*insertResult.first);
        udneighbor_1_2_.insert2Vec(*insertResult.first);
        udneighbor_1_2_3_4_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _dir){
        udir_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _conn){
        uconn_.insert2Vec(*insertResult.first);
        uconn_0_1_.insert2Vec(*insertResult.first);
        uconn_0_1_3_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _col){
        ucol_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _rpush){
        urpush_.insert2Vec(*insertResult.first);
        urpush_0_.insert2Vec(*insertResult.first);
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
