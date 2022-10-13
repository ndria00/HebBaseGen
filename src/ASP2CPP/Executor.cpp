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
}
void Executor::executeProgram(){
    auto start = std::chrono::high_resolution_clock::now();
    //TODO
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pfield_.getValuesVec({});
            const std::vector<int>* tuplesU = &ufield_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    int XX = X+1;
                    const Tuple* tuple1 = factory.find({XX, Y}, _field);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        if(XX == X+1){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("n"),X,Y,XX,Y}, _dneighbor);
                            if(t->isUnknown()){
                                if(undefTuple){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    factory.removeFromCollisionsList(t->getId());
                                    insertTrue(insertResult);
                                }
                            }
                            undefTuple = false;
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pfield_.getValuesVec({});
            const std::vector<int>* tuplesU = &ufield_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    int XX = X-1;
                    const Tuple* tuple1 = factory.find({XX, Y}, _field);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        if(XX == X-1){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("s"),X,Y,XX,Y}, _dneighbor);
                            if(t->isUnknown()){
                                if(undefTuple){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    factory.removeFromCollisionsList(t->getId());
                                    insertTrue(insertResult);
                                }
                            }
                            undefTuple = false;
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pfield_.getValuesVec({});
            const std::vector<int>* tuplesU = &ufield_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    int YY = Y+1;
                    const Tuple* tuple1 = factory.find({X, YY}, _field);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        if(YY == Y+1){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("e"),X,Y,X,YY}, _dneighbor);
                            if(t->isUnknown()){
                                if(undefTuple){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    factory.removeFromCollisionsList(t->getId());
                                    insertTrue(insertResult);
                                }
                            }
                            undefTuple = false;
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pfield_.getValuesVec({});
            const std::vector<int>* tuplesU = &ufield_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    int YY = Y-1;
                    const Tuple* tuple1 = factory.find({X, YY}, _field);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        if(YY == Y-1){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("w"),X,Y,X,YY}, _dneighbor);
                            if(t->isUnknown()){
                                if(undefTuple){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    factory.removeFromCollisionsList(t->getId());
                                    insertTrue(insertResult);
                                }
                            }
                            undefTuple = false;
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pmax_steps_.getValuesVec({});
            const std::vector<int>* tuplesU = &umax_steps_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int S = (*tuple0)[0];
                    if(0<S){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({S}, _step);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
            }//close par
        }//close par
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            if(literalName == _step){
                {
                    bool undefTuple = false;
                    int S = (*recursiveTuple)[0];
                    int T = S-1;
                    if(1<S){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({T}, _step);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
            }
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pfield_.getValuesVec({});
            const std::vector<int>* tuplesU = &ufield_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({Y}, _col);
                    if(t->isUnknown()){
                        if(undefTuple){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple){
                            insertResult = t->setStatus(TruthStatus::True);
                            factory.removeFromCollisionsList(t->getId());
                            insertTrue(insertResult);
                        }
                    }
                    undefTuple = false;
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pcol_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucol_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int Y = (*tuple0)[0];
                    int YY = Y+1;
                    const Tuple negativeTuple = Tuple({YY}, _col, true);
                    const Tuple* tuple1 = factory.find({YY}, _col);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                        undefTuple = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple = true;
                    }
                    if(tuple1!= NULL){
                        if(YY == Y+1){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({Y}, _num_cols);
                            if(t->isUnknown()){
                                if(undefTuple){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    factory.removeFromCollisionsList(t->getId());
                                    insertTrue(insertResult);
                                }
                            }
                            undefTuple = false;
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pfield_.getValuesVec({});
            const std::vector<int>* tuplesU = &ufield_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X}, _row);
                    if(t->isUnknown()){
                        if(undefTuple){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple){
                            insertResult = t->setStatus(TruthStatus::True);
                            factory.removeFromCollisionsList(t->getId());
                            insertTrue(insertResult);
                        }
                    }
                    undefTuple = false;
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &prow_.getValuesVec({});
            const std::vector<int>* tuplesU = &urow_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int XX = X+1;
                    const Tuple negativeTuple = Tuple({XX}, _row, true);
                    const Tuple* tuple1 = factory.find({XX}, _row);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                        undefTuple = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple = true;
                    }
                    if(tuple1!= NULL){
                        if(XX == X+1){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X}, _num_rows);
                            if(t->isUnknown()){
                                if(undefTuple){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    factory.removeFromCollisionsList(t->getId());
                                    insertTrue(insertResult);
                                }
                            }
                            undefTuple = false;
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pdneighbor_.getValuesVec({});
            const std::vector<int>* tuplesU = &udneighbor_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int D = (*tuple0)[0];
                    int X = (*tuple0)[1];
                    int Y = (*tuple0)[2];
                    int XX = (*tuple0)[3];
                    int YY = (*tuple0)[4];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({D,X,Y,XX,YY}, _neighbor);
                    if(t->isUnknown()){
                        if(undefTuple){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple){
                            insertResult = t->setStatus(TruthStatus::True);
                            factory.removeFromCollisionsList(t->getId());
                            insertTrue(insertResult);
                        }
                    }
                    undefTuple = false;
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pfield_.getValuesVec({});
            const std::vector<int>* tuplesU = &ufield_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    const Tuple* tuple1 = factory.find({X}, _num_rows);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("n"),X,Y,ConstantsManager::getInstance().mapConstant("1"),Y}, _neighbor);
                        if(t->isUnknown()){
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pfield_.getValuesVec({});
            const std::vector<int>* tuplesU = &ufield_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    const Tuple* tuple1 = factory.find({X}, _num_rows);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("s"),ConstantsManager::getInstance().mapConstant("1"),Y,X,Y}, _neighbor);
                        if(t->isUnknown()){
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pfield_.getValuesVec({});
            const std::vector<int>* tuplesU = &ufield_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    const Tuple* tuple1 = factory.find({Y}, _num_cols);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("e"),X,Y,X,ConstantsManager::getInstance().mapConstant("1")}, _neighbor);
                        if(t->isUnknown()){
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pfield_.getValuesVec({});
            const std::vector<int>* tuplesU = &ufield_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    const Tuple* tuple1 = factory.find({Y}, _num_cols);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("w"),X,ConstantsManager::getInstance().mapConstant("1"),X,Y}, _neighbor);
                        if(t->isUnknown()){
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pgoal_on_.getValuesVec({});
            const std::vector<int>* tuplesU = &ugoal_on_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X,Y,ConstantsManager::getInstance().mapConstant("0")}, _goal);
                    if(t->isUnknown()){
                        generatedStack.push_back(t->getId());
                        if(undefTuple){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple){
                            insertResult = t->setStatus(TruthStatus::True);
                            factory.removeFromCollisionsList(t->getId());
                            insertTrue(insertResult);
                        }
                    }
                    undefTuple = false;
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pinit_on_.getValuesVec({});
            const std::vector<int>* tuplesU = &uinit_on_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X,Y,ConstantsManager::getInstance().mapConstant("0")}, _reach);
                    if(t->isUnknown()){
                        generatedStack.push_back(t->getId());
                        if(undefTuple){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple){
                            insertResult = t->setStatus(TruthStatus::True);
                            factory.removeFromCollisionsList(t->getId());
                            insertTrue(insertResult);
                        }
                    }
                    undefTuple = false;
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pconnect_.getValuesVec({});
            const std::vector<int>* tuplesU = &uconnect_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    int D = (*tuple0)[2];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X,Y,D,ConstantsManager::getInstance().mapConstant("0")}, _conn);
                    if(t->isUnknown()){
                        generatedStack.push_back(t->getId());
                        if(undefTuple){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple){
                            insertResult = t->setStatus(TruthStatus::True);
                            factory.removeFromCollisionsList(t->getId());
                            insertTrue(insertResult);
                        }
                    }
                    undefTuple = false;
                }//close par
            }//close par
        }//close par
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            if(literalName == _goal){
                {
                    bool undefTuple = false;
                    int S = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[1];
                    int XX = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pshift_0_1_.getValuesVec({XX, YY});
                    const std::vector<int>* tuplesU = &ushift_0_1_.getValuesVec({XX, YY});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int X = (*tuple1)[2];
                            int Y = (*tuple1)[3];
                            int T = (*tuple1)[4];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y,T}, _goal);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int Y = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    const Tuple negativeTuple = Tuple({X, Y, T}, _reach, true);
                    const Tuple* tuple1 = factory.find({X, Y, T}, _reach);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                        undefTuple = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({T}, _neg_goal);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
            }
            if(literalName == _shift){
                {
                    bool undefTuple = false;
                    int Y = (*recursiveTuple)[3];
                    int YY = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[4];
                    int X = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pgoal_0_1_.getValuesVec({XX, YY});
                    const std::vector<int>* tuplesU = &ugoal_0_1_.getValuesVec({XX, YY});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int S = (*tuple1)[2];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y,T}, _goal);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int Y = (*recursiveTuple)[3];
                    int YY = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[4];
                    int X = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &preach_0_1_.getValuesVec({XX, YY});
                    const std::vector<int>* tuplesU = &ureach_0_1_.getValuesVec({XX, YY});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int S = (*tuple1)[2];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int Y = (*recursiveTuple)[3];
                    int YY = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[4];
                    int X = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pconn_0_1_.getValuesVec({XX, YY});
                    const std::vector<int>* tuplesU = &uconn_0_1_.getValuesVec({XX, YY});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int D = (*tuple1)[2];
                            int S = (*tuple1)[3];
                            const Tuple* tuple2 = factory.find({D}, _dir);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                const Tuple* tuple3 = factory.find({T}, _step);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple = true;
                                if(tuple3!= NULL){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({X,Y,D,T}, _conn);
                                    if(t->isUnknown()){
                                        generatedStack.push_back(t->getId());
                                        if(undefTuple){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple){
                                            insertResult = t->setStatus(TruthStatus::True);
                                            factory.removeFromCollisionsList(t->getId());
                                            insertTrue(insertResult);
                                        }
                                    }
                                    undefTuple = false;
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _rpush){
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[1];
                    int XX = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &prow_.getValuesVec({});
                    const std::vector<int>* tuplesU = &urow_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int X = (*tuple1)[0];
                            if(X!=XX){
                                const Tuple* tuple2 = factory.find({XX}, _row);
                                if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                                if(tuple2!= NULL){
                                    if(X!=XX){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({X,T}, _orpush);
                                        if(t->isUnknown()){
                                            generatedStack.push_back(t->getId());
                                            if(undefTuple){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                insertUndef(insertResult);
                                            }
                                            else{
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                            }
                                        }
                                        else if(t->isUndef()){
                                            if(!undefTuple){
                                                insertResult = t->setStatus(TruthStatus::True);
                                                factory.removeFromCollisionsList(t->getId());
                                                insertTrue(insertResult);
                                            }
                                        }
                                        undefTuple = false;
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[1];
                    int X = (*recursiveTuple)[0];
                    const Tuple negativeTuple = Tuple({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push, true);
                    const Tuple* tuple1 = factory.find({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                        undefTuple = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X,ConstantsManager::getInstance().mapConstant("e"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[1];
                    int X = (*recursiveTuple)[0];
                    const Tuple negativeTuple = Tuple({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push, true);
                    const Tuple* tuple1 = factory.find({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                        undefTuple = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X,ConstantsManager::getInstance().mapConstant("w"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
            }
            if(literalName == _rrpush){
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &prow_.getValuesVec({});
                    const std::vector<int>* tuplesU = &urow_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int X = (*tuple1)[0];
                            const Tuple negativeTuple = Tuple({X, T}, _orpush, true);
                            const Tuple* tuple2 = factory.find({X, T}, _orpush);
                            if(tuple2 == NULL){
                                tuple2 = &negativeTuple;
                                undefTuple = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple = true;
                            }
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,T}, _rpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        int S = T-1;
                        const Tuple* tuple2 = factory.find({S}, _neg_goal);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                        if(tuple2!= NULL){
                            if(S == T-1){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({T}, _ccpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _orpush){
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[1];
                    int X = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({X}, _row);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        const Tuple* tuple2 = factory.find({T}, _rrpush);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                        if(tuple2!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X,T}, _rpush);
                            if(t->isUnknown()){
                                generatedStack.push_back(t->getId());
                                if(undefTuple){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    factory.removeFromCollisionsList(t->getId());
                                    insertTrue(insertResult);
                                }
                            }
                            undefTuple = false;
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _push){
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({X, T}, _rpush);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X,ConstantsManager::getInstance().mapConstant("e"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({X, T}, _rpush);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X,ConstantsManager::getInstance().mapConstant("w"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int Y = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({Y, T}, _cpush);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({Y,ConstantsManager::getInstance().mapConstant("n"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int Y = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({Y, T}, _cpush);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({Y,ConstantsManager::getInstance().mapConstant("s"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pneighbor_0_1_.getValuesVec({ConstantsManager::getInstance().mapConstant("e"), XX});
                    const std::vector<int>* tuplesU = &uneighbor_0_1_.getValuesVec({ConstantsManager::getInstance().mapConstant("e"), XX});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int YY = (*tuple1)[2];
                            int X = (*tuple1)[3];
                            int Y = (*tuple1)[4];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pneighbor_0_1_.getValuesVec({ConstantsManager::getInstance().mapConstant("w"), XX});
                    const std::vector<int>* tuplesU = &uneighbor_0_1_.getValuesVec({ConstantsManager::getInstance().mapConstant("w"), XX});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int YY = (*tuple1)[2];
                            int X = (*tuple1)[3];
                            int Y = (*tuple1)[4];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pneighbor_0_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("n"), YY});
                    const std::vector<int>* tuplesU = &uneighbor_0_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("n"), YY});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int XX = (*tuple1)[1];
                            int X = (*tuple1)[3];
                            int Y = (*tuple1)[4];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pneighbor_0_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("s"), YY});
                    const std::vector<int>* tuplesU = &uneighbor_0_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("s"), YY});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int XX = (*tuple1)[1];
                            int X = (*tuple1)[3];
                            int Y = (*tuple1)[4];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pfield_0_.getValuesVec({X});
                    const std::vector<int>* tuplesU = &ufield_0_.getValuesVec({X});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int Y = (*tuple1)[1];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                const Tuple negativeTuple = Tuple({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push, true);
                                const Tuple* tuple3 = factory.find({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                    undefTuple = true;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple = true;
                                }
                                if(tuple3!= NULL){
                                    const Tuple negativeTuple = Tuple({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push, true);
                                    const Tuple* tuple4 = factory.find({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                        undefTuple = true;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple = true;
                                    }
                                    if(tuple4!= NULL){
                                        const Tuple negativeTuple = Tuple({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push, true);
                                        const Tuple* tuple5 = factory.find({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                            undefTuple = true;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple = true;
                                        }
                                        if(tuple5!= NULL){
                                            //Rule is firing 
                                            Tuple* t;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            t = factory.addNewInternalTuple({X,Y,X,Y,T}, _shift);
                                            if(t->isUnknown()){
                                                generatedStack.push_back(t->getId());
                                                if(undefTuple){
                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                    insertUndef(insertResult);
                                                }
                                                else{
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                }
                                            }
                                            else if(t->isUndef()){
                                                if(!undefTuple){
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    factory.removeFromCollisionsList(t->getId());
                                                    insertTrue(insertResult);
                                                }
                                            }
                                            undefTuple = false;
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pfield_0_.getValuesVec({X});
                    const std::vector<int>* tuplesU = &ufield_0_.getValuesVec({X});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int Y = (*tuple1)[1];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                const Tuple negativeTuple = Tuple({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push, true);
                                const Tuple* tuple3 = factory.find({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                    undefTuple = true;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple = true;
                                }
                                if(tuple3!= NULL){
                                    const Tuple negativeTuple = Tuple({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push, true);
                                    const Tuple* tuple4 = factory.find({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                        undefTuple = true;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple = true;
                                    }
                                    if(tuple4!= NULL){
                                        const Tuple negativeTuple = Tuple({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push, true);
                                        const Tuple* tuple5 = factory.find({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                            undefTuple = true;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple = true;
                                        }
                                        if(tuple5!= NULL){
                                            //Rule is firing 
                                            Tuple* t;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            t = factory.addNewInternalTuple({X,Y,X,Y,T}, _shift);
                                            if(t->isUnknown()){
                                                generatedStack.push_back(t->getId());
                                                if(undefTuple){
                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                    insertUndef(insertResult);
                                                }
                                                else{
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                }
                                            }
                                            else if(t->isUndef()){
                                                if(!undefTuple){
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    factory.removeFromCollisionsList(t->getId());
                                                    insertTrue(insertResult);
                                                }
                                            }
                                            undefTuple = false;
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int Y = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pfield_1_.getValuesVec({Y});
                    const std::vector<int>* tuplesU = &ufield_1_.getValuesVec({Y});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int X = (*tuple1)[0];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                const Tuple negativeTuple = Tuple({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push, true);
                                const Tuple* tuple3 = factory.find({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                    undefTuple = true;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple = true;
                                }
                                if(tuple3!= NULL){
                                    const Tuple negativeTuple = Tuple({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push, true);
                                    const Tuple* tuple4 = factory.find({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                        undefTuple = true;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple = true;
                                    }
                                    if(tuple4!= NULL){
                                        const Tuple negativeTuple = Tuple({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push, true);
                                        const Tuple* tuple5 = factory.find({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                            undefTuple = true;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple = true;
                                        }
                                        if(tuple5!= NULL){
                                            //Rule is firing 
                                            Tuple* t;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            t = factory.addNewInternalTuple({X,Y,X,Y,T}, _shift);
                                            if(t->isUnknown()){
                                                generatedStack.push_back(t->getId());
                                                if(undefTuple){
                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                    insertUndef(insertResult);
                                                }
                                                else{
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                }
                                            }
                                            else if(t->isUndef()){
                                                if(!undefTuple){
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    factory.removeFromCollisionsList(t->getId());
                                                    insertTrue(insertResult);
                                                }
                                            }
                                            undefTuple = false;
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[2];
                    int Y = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pfield_1_.getValuesVec({Y});
                    const std::vector<int>* tuplesU = &ufield_1_.getValuesVec({Y});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int X = (*tuple1)[0];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                const Tuple negativeTuple = Tuple({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push, true);
                                const Tuple* tuple3 = factory.find({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                    undefTuple = true;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple = true;
                                }
                                if(tuple3!= NULL){
                                    const Tuple negativeTuple = Tuple({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push, true);
                                    const Tuple* tuple4 = factory.find({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                        undefTuple = true;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple = true;
                                    }
                                    if(tuple4!= NULL){
                                        const Tuple negativeTuple = Tuple({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push, true);
                                        const Tuple* tuple5 = factory.find({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                            undefTuple = true;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple = true;
                                        }
                                        if(tuple5!= NULL){
                                            //Rule is firing 
                                            Tuple* t;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            t = factory.addNewInternalTuple({X,Y,X,Y,T}, _shift);
                                            if(t->isUnknown()){
                                                generatedStack.push_back(t->getId());
                                                if(undefTuple){
                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                    insertUndef(insertResult);
                                                }
                                                else{
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                }
                                            }
                                            else if(t->isUndef()){
                                                if(!undefTuple){
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    factory.removeFromCollisionsList(t->getId());
                                                    insertTrue(insertResult);
                                                }
                                            }
                                            undefTuple = false;
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _cpush){
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[1];
                    int Y = (*recursiveTuple)[0];
                    const Tuple negativeTuple = Tuple({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push, true);
                    const Tuple* tuple1 = factory.find({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                        undefTuple = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({Y,ConstantsManager::getInstance().mapConstant("n"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[1];
                    int Y = (*recursiveTuple)[0];
                    const Tuple negativeTuple = Tuple({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push, true);
                    const Tuple* tuple1 = factory.find({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                        undefTuple = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({Y,ConstantsManager::getInstance().mapConstant("s"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[1];
                    int YY = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pcol_.getValuesVec({});
                    const std::vector<int>* tuplesU = &ucol_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int Y = (*tuple1)[0];
                            if(Y!=YY){
                                const Tuple* tuple2 = factory.find({YY}, _col);
                                if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                                if(tuple2!= NULL){
                                    if(Y!=YY){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({Y,T}, _ocpush);
                                        if(t->isUnknown()){
                                            generatedStack.push_back(t->getId());
                                            if(undefTuple){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                insertUndef(insertResult);
                                            }
                                            else{
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                            }
                                        }
                                        else if(t->isUndef()){
                                            if(!undefTuple){
                                                insertResult = t->setStatus(TruthStatus::True);
                                                factory.removeFromCollisionsList(t->getId());
                                                insertTrue(insertResult);
                                            }
                                        }
                                        undefTuple = false;
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _ccpush){
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pcol_.getValuesVec({});
                    const std::vector<int>* tuplesU = &ucol_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int Y = (*tuple1)[0];
                            const Tuple negativeTuple = Tuple({Y, T}, _ocpush, true);
                            const Tuple* tuple2 = factory.find({Y, T}, _ocpush);
                            if(tuple2 == NULL){
                                tuple2 = &negativeTuple;
                                undefTuple = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple = true;
                            }
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({Y,T}, _cpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        int S = T-1;
                        const Tuple* tuple2 = factory.find({S}, _neg_goal);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                        if(tuple2!= NULL){
                            if(S == T-1){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({T}, _rrpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _ocpush){
                {
                    bool undefTuple = false;
                    int T = (*recursiveTuple)[1];
                    int Y = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({Y}, _col);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        const Tuple* tuple2 = factory.find({T}, _ccpush);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                        if(tuple2!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({Y,T}, _cpush);
                            if(t->isUnknown()){
                                generatedStack.push_back(t->getId());
                                if(undefTuple){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    factory.removeFromCollisionsList(t->getId());
                                    insertTrue(insertResult);
                                }
                            }
                            undefTuple = false;
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _neg_goal){
                {
                    bool undefTuple = false;
                    int S = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pstep_.getValuesVec({});
                    const std::vector<int>* tuplesU = &ustep_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[0];
                            if(S == T-1){
                                const Tuple negativeTuple = Tuple({T}, _rrpush, true);
                                const Tuple* tuple2 = factory.find({T}, _rrpush);
                                if(tuple2 == NULL){
                                    tuple2 = &negativeTuple;
                                    undefTuple = true;
                                }
                                else{
                                    if(tuple2->isTrue())    tuple2= NULL;
                                    else undefTuple = true;
                                }
                                if(tuple2!= NULL){
                                    if(S == T-1){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({T}, _ccpush);
                                        if(t->isUnknown()){
                                            generatedStack.push_back(t->getId());
                                            if(undefTuple){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                insertUndef(insertResult);
                                            }
                                            else{
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                            }
                                        }
                                        else if(t->isUndef()){
                                            if(!undefTuple){
                                                insertResult = t->setStatus(TruthStatus::True);
                                                factory.removeFromCollisionsList(t->getId());
                                                insertTrue(insertResult);
                                            }
                                        }
                                        undefTuple = false;
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int S = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pstep_.getValuesVec({});
                    const std::vector<int>* tuplesU = &ustep_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[0];
                            if(S == T-1){
                                const Tuple negativeTuple = Tuple({T}, _ccpush, true);
                                const Tuple* tuple2 = factory.find({T}, _ccpush);
                                if(tuple2 == NULL){
                                    tuple2 = &negativeTuple;
                                    undefTuple = true;
                                }
                                else{
                                    if(tuple2->isTrue())    tuple2= NULL;
                                    else undefTuple = true;
                                }
                                if(tuple2!= NULL){
                                    if(S == T-1){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({T}, _rrpush);
                                        if(t->isUnknown()){
                                            generatedStack.push_back(t->getId());
                                            if(undefTuple){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                insertUndef(insertResult);
                                            }
                                            else{
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                            }
                                        }
                                        else if(t->isUndef()){
                                            if(!undefTuple){
                                                insertResult = t->setStatus(TruthStatus::True);
                                                factory.removeFromCollisionsList(t->getId());
                                                insertTrue(insertResult);
                                            }
                                        }
                                        undefTuple = false;
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _reach){
                {
                    bool undefTuple = false;
                    int Y = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({X, Y, T}, _goal);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({T}, _neg_goal);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }
                        undefTuple = false;
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int S = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[1];
                    int XX = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pshift_0_1_.getValuesVec({XX, YY});
                    const std::vector<int>* tuplesU = &ushift_0_1_.getValuesVec({XX, YY});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int X = (*tuple1)[2];
                            int Y = (*tuple1)[3];
                            int T = (*tuple1)[4];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }
                                undefTuple = false;
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int YY = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pdneighbor_1_2_.getValuesVec({XX, YY});
                    const std::vector<int>* tuplesU = &udneighbor_1_2_.getValuesVec({XX, YY});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int D = (*tuple1)[0];
                            int X = (*tuple1)[3];
                            int Y = (*tuple1)[4];
                            const Tuple* tuple2 = factory.find({XX, YY, D, T}, _conn);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                const Tuple* tuple3 = factory.find({T}, _step);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple = true;
                                if(tuple3!= NULL){
                                    const std::vector<int>* tuples;
                                    tuples = &pconn_0_1_3_.getValuesVec({X, Y, T});
                                    const std::vector<int>* tuplesU = &uconn_0_1_3_.getValuesVec({X, Y, T});
                                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                        const Tuple * tuple4 = NULL;
                                        if(i < tuples->size()){
                                            tuple4 = factory.getTupleFromInternalID(tuples->at(i));
                                        }
                                        else {
                                            tuple4 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                            undefTuple = true;
                                        }
                                        if(tuple4!= NULL){
                                            int E = (*tuple4)[2];
                                            const Tuple* tuple5 = factory.find({D, E}, _inverse);
                                            if(tuple5 != NULL && tuple5->isUndef()) undefTuple = true;
                                            if(tuple5!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                                if(t->isUnknown()){
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple){
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                undefTuple = false;
                                            }//close par
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _conn){
                {
                    bool undefTuple = false;
                    int D = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[3];
                    int XX = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({XX, YY, T}, _reach);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        const Tuple* tuple2 = factory.find({T}, _step);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                        if(tuple2!= NULL){
                            const std::vector<int>* tuples;
                            tuples = &pdneighbor_0_1_2_.getValuesVec({D, XX, YY});
                            const std::vector<int>* tuplesU = &udneighbor_0_1_2_.getValuesVec({D, XX, YY});
                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                const Tuple * tuple3 = NULL;
                                if(i < tuples->size()){
                                    tuple3 = factory.getTupleFromInternalID(tuples->at(i));
                                }
                                else {
                                    tuple3 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                    undefTuple = true;
                                }
                                if(tuple3!= NULL){
                                    int X = (*tuple3)[3];
                                    int Y = (*tuple3)[4];
                                    const std::vector<int>* tuples;
                                    tuples = &pconn_0_1_3_.getValuesVec({X, Y, T});
                                    const std::vector<int>* tuplesU = &uconn_0_1_3_.getValuesVec({X, Y, T});
                                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                        const Tuple * tuple4 = NULL;
                                        if(i < tuples->size()){
                                            tuple4 = factory.getTupleFromInternalID(tuples->at(i));
                                        }
                                        else {
                                            tuple4 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                            undefTuple = true;
                                        }
                                        if(tuple4!= NULL){
                                            int E = (*tuple4)[2];
                                            const Tuple* tuple5 = factory.find({D, E}, _inverse);
                                            if(tuple5 != NULL && tuple5->isUndef()) undefTuple = true;
                                            if(tuple5!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                                if(t->isUnknown()){
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple){
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                undefTuple = false;
                                            }//close par
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int E = (*recursiveTuple)[2];
                    int Y = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[3];
                    int X = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &preach_2_.getValuesVec({T});
                    const std::vector<int>* tuplesU = &ureach_2_.getValuesVec({T});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int XX = (*tuple1)[0];
                            int YY = (*tuple1)[1];
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                const std::vector<int>* tuples;
                                tuples = &pdneighbor_1_2_3_4_.getValuesVec({XX, YY, X, Y});
                                const std::vector<int>* tuplesU = &udneighbor_1_2_3_4_.getValuesVec({XX, YY, X, Y});
                                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                    const Tuple * tuple3 = NULL;
                                    if(i < tuples->size()){
                                        tuple3 = factory.getTupleFromInternalID(tuples->at(i));
                                    }
                                    else {
                                        tuple3 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                        undefTuple = true;
                                    }
                                    if(tuple3!= NULL){
                                        int D = (*tuple3)[0];
                                        const Tuple* tuple4 = factory.find({XX, YY, D, T}, _conn);
                                        if(tuple4 != NULL && tuple4->isUndef()) undefTuple = true;
                                        if(tuple4!= NULL){
                                            const Tuple* tuple5 = factory.find({D, E}, _inverse);
                                            if(tuple5 != NULL && tuple5->isUndef()) undefTuple = true;
                                            if(tuple5!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                                if(t->isUnknown()){
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple){
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                undefTuple = false;
                                            }//close par
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple = false;
                    int S = (*recursiveTuple)[3];
                    int D = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[1];
                    int XX = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({D}, _dir);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        const std::vector<int>* tuples;
                        tuples = &pshift_0_1_.getValuesVec({XX, YY});
                        const std::vector<int>* tuplesU = &ushift_0_1_.getValuesVec({XX, YY});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple = true;
                            }
                            if(tuple2!= NULL){
                                int X = (*tuple2)[2];
                                int Y = (*tuple2)[3];
                                int T = (*tuple2)[4];
                                const Tuple* tuple3 = factory.find({T}, _step);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple = true;
                                if(tuple3!= NULL){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({X,Y,D,T}, _conn);
                                    if(t->isUnknown()){
                                        generatedStack.push_back(t->getId());
                                        if(undefTuple){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple){
                                            insertResult = t->setStatus(TruthStatus::True);
                                            factory.removeFromCollisionsList(t->getId());
                                            insertTrue(insertResult);
                                        }
                                    }
                                    undefTuple = false;
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
        }
    }
    printGeneratedBase();
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
void Executor::printGeneratedBase(){
    const std::vector<int>* tuples;
    tuples = &pinverse_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uinverse_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pshift_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ushift_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ppush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &upush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &porpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uorpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pcpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ucpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &prrpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &urrpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pneg_goal_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uneg_goal_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pneighbor_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uneighbor_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pdneighbor_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &udneighbor_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &prow_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &urow_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pdir_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &udir_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pconn_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uconn_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &prpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &urpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pcol_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ucol_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pgoal_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ugoal_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pnum_rows_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &unum_rows_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pnum_cols_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &unum_cols_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pfield_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ufield_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pstep_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ustep_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pgoal_on_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ugoal_on_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pccpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uccpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &preach_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ureach_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pocpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uocpush_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pinit_on_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uinit_on_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pconnect_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uconnect_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pmax_steps_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &umax_steps_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
}
