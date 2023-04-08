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
AuxMap<32> pfield_0_({0});
AuxMap<32> ufield_0_({0});
AuxMap<32> pfield_1_({1});
AuxMap<32> ufield_1_({1});
AuxMap<32> pgoal_2_({2});
AuxMap<32> ugoal_2_({2});
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
AuxMap<64> pshift_0_1_({0,1});
AuxMap<64> ushift_0_1_({0,1});
AuxMap<32> pconn_2_({2});
AuxMap<32> uconn_2_({2});
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
        pgoal_2_.insert2Vec(*insertResult.first);
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
        pconn_2_.insert2Vec(*insertResult.first);
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
        ugoal_2_.insert2Vec(*insertResult.first);
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
        uconn_2_.insert2Vec(*insertResult.first);
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
        printTuple(t);
    }
    else{
        const auto& insertResult = t->setStatus(TruthStatus::Undef);
        insertUndef(insertResult);
    }
}
void Executor::executeProgram(){
    const Tuple dummyTuple = Tuple();
    auto start = std::chrono::high_resolution_clock::now();
    std::cout<<"True{\n";
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    int XX = X+1;
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({XX, Y}, _field);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("n"),X,Y,XX,Y}, _dneighbor);
                        if(t->isUnknown()){
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    int XX = X-1;
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({XX, Y}, _field);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("s"),X,Y,XX,Y}, _dneighbor);
                        if(t->isUnknown()){
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    int YY = Y+1;
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X, YY}, _field);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("e"),X,Y,X,YY}, _dneighbor);
                        if(t->isUnknown()){
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    int YY = Y-1;
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X, YY}, _field);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("w"),X,Y,X,YY}, _dneighbor);
                        if(t->isUnknown()){
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        std::vector<std::pair<int, int>>* propagationStack = new std::vector<std::pair<int, int>>();
        std::unordered_map<int, std::unordered_set<int>> tupleSupports;
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int S = (*tuple0)[0];
                    if(0<S){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({S}, _step);
                        if(t->isUnknown()){
                            if(undefTuple0){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple0){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pstep_.getValuesVec({});
            const std::vector<int>* tuplesU = &ustep_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int S = (*tuple0)[0];
                    int T = S-1;
                    if(1<S){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({T}, _step);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple0){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 8));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(8) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple0){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            bool recursiveTupleUndef = recursiveTuple->isUndef();
            if(literalName == _step){
                {
                    bool undefTuple0= false;
                    int S = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    int T = S-1;
                    if(1<S){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({T}, _step);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple0){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 8));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(8) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple0){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }
        }
        //---------------------------------------Strongly connected component propagation-----------------------
        {
            std::vector<std::pair<int, int>>* nextPropagationStack = new std::vector<std::pair<int, int>>();
            std::vector<std::pair<int, int>>* temp;
            int ruleId;
            bool propagated = true;
            while(propagated){
                propagated = false;
                while(!propagationStack->empty()){
                    Tuple* headTuple = factory.getTupleFromInternalID(propagationStack->back().first);
                    ruleId = propagationStack->back().second;
                    propagationStack->pop_back();
                    if(ruleId == 8){
                        {
                            bool maySupport = false;
                            int T = (*headTuple)[0];
                            bool undefTuple0= false;
                            const std::vector<int>* tuples;
                            tuples = &pstep_.getValuesVec({});
                            const std::vector<int>* tuplesU = &ustep_.getValuesVec({});
                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                const Tuple * tuple0 = NULL;
                                if(i < tuples->size()){
                                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                                }
                                else {
                                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                    undefTuple0 = true;
                                }
                                if(tuple0!= NULL){
                                    int S = (*tuple0)[0];
                                    if(1<S){
                                        //Rule is firing 
                                        maySupport = true;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        if(undefTuple0){
                                            nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 8));
                                        }
                                        else{
                                            factory.removeFromCollisionsList(headTuple->getId());
                                            insertResult = headTuple->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            propagated = true;
                                            std::cout << "Propagation Occurred to True ";
                                            printTuple(headTuple);
                                        }
                                    }//close par
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(8);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                }
                temp = propagationStack;
                propagationStack = nextPropagationStack;
                nextPropagationStack = temp;
                nextPropagationStack->clear();
            }
            delete nextPropagationStack;
            delete propagationStack;
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({Y}, _col);
                    if(t->isUnknown()){
                        if(undefTuple0){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            printTuple(t);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple0){
                            factory.removeFromCollisionsList(t->getId());
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            printTuple(t);
                        }
                    }
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int Y = (*tuple0)[0];
                    int YY = Y+1;
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({YY}, _col);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({Y}, _num_cols);
                        if(t->isUnknown()){
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X}, _row);
                    if(t->isUnknown()){
                        if(undefTuple0){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            printTuple(t);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple0){
                            factory.removeFromCollisionsList(t->getId());
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            printTuple(t);
                        }
                    }
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int XX = X+1;
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({XX}, _row);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X}, _num_rows);
                        if(t->isUnknown()){
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
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
                        if(undefTuple0){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            printTuple(t);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple0){
                            factory.removeFromCollisionsList(t->getId());
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            printTuple(t);
                        }
                    }
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X}, _num_rows);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("n"),X,Y,ConstantsManager::getInstance().mapConstant("1"),Y}, _neighbor);
                        if(t->isUnknown()){
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X}, _num_rows);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("s"),ConstantsManager::getInstance().mapConstant("1"),Y,X,Y}, _neighbor);
                        if(t->isUnknown()){
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({Y}, _num_cols);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("e"),X,Y,X,ConstantsManager::getInstance().mapConstant("1")}, _neighbor);
                        if(t->isUnknown()){
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({Y}, _num_cols);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("w"),X,ConstantsManager::getInstance().mapConstant("1"),X,Y}, _neighbor);
                        if(t->isUnknown()){
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        std::vector<std::pair<int, int>>* propagationStack = new std::vector<std::pair<int, int>>();
        std::unordered_map<int, std::unordered_set<int>> tupleSupports;
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X,Y,ConstantsManager::getInstance().mapConstant("0")}, _goal);
                    if(t->isUnknown()){
                        if(undefTuple0){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            printTuple(t);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple0){
                            factory.removeFromCollisionsList(t->getId());
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            generatedStack.push_back(t->getId());
                            printTuple(t);
                        }
                    }
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X,Y,ConstantsManager::getInstance().mapConstant("0")}, _reach);
                    if(t->isUnknown()){
                        if(undefTuple0){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            printTuple(t);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple0){
                            factory.removeFromCollisionsList(t->getId());
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            generatedStack.push_back(t->getId());
                            printTuple(t);
                        }
                    }
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
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
                        if(undefTuple0){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            printTuple(t);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple0){
                            factory.removeFromCollisionsList(t->getId());
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                            generatedStack.push_back(t->getId());
                            printTuple(t);
                        }
                    }
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pgoal_.getValuesVec({});
            const std::vector<int>* tuplesU = &ugoal_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int XX = (*tuple0)[0];
                    int YY = (*tuple0)[1];
                    int S = (*tuple0)[2];
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int X = (*tuple1)[2];
                            int Y = (*tuple1)[3];
                            int T = (*tuple1)[4];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y,T}, _goal);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 35));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(35) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int XX = (*tuple1)[0];
                            if(X!=XX){
                                bool undefTuple2 = undefTuple1;
                                const std::vector<int>* tuples;
                                tuples = &prpush_0_.getValuesVec({XX});
                                const std::vector<int>* tuplesU = &urpush_0_.getValuesVec({XX});
                                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                    const Tuple * tuple2 = NULL;
                                    if(i < tuples->size()){
                                        tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                                    }
                                    else {
                                        tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                        undefTuple2 = true;
                                    }
                                    if(tuple2!= NULL){
                                        int T = (*tuple2)[1];
                                        if(X!=XX){
                                            //Rule is firing 
                                            Tuple* t;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            t = factory.addNewInternalTuple({X,T}, _orpush);
                                            if(t->isUnknown()){
                                                generatedStack.push_back(t->getId());
                                                if(undefTuple2){
                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                    insertUndef(insertResult);
                                                    propagationStack->push_back(std::make_pair(t->getId(), 21));
                                                    if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                    tupleSupports[t->getId()].insert(21) ;
                                                }
                                                else{
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                    printTuple(t);
                                                }
                                            }
                                            else if(t->isUndef()){
                                                if(!undefTuple2){
                                                    factory.removeFromCollisionsList(t->getId());
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                    generatedStack.push_back(t->getId());
                                                    printTuple(t);
                                                }
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
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &prrpush_.getValuesVec({});
                    const std::vector<int>* tuplesU = &urrpush_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({X, T}, _orpush);
                            if(tuple2 == NULL){
                                tuple2 = &dummyTuple;
                                undefTuple2 = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,T}, _rpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 23));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(23) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &prpush_.getValuesVec({});
            const std::vector<int>* tuplesU = &urpush_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int T = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X,ConstantsManager::getInstance().mapConstant("e"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 25));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(25) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &prpush_.getValuesVec({});
            const std::vector<int>* tuplesU = &urpush_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int T = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X,ConstantsManager::getInstance().mapConstant("w"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 26));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(26) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pcpush_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucpush_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int Y = (*tuple0)[0];
                    int T = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({Y,ConstantsManager::getInstance().mapConstant("n"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 27));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(27) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pcpush_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucpush_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int Y = (*tuple0)[0];
                    int T = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({Y,ConstantsManager::getInstance().mapConstant("s"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 28));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(28) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int Y = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int YY = (*tuple1)[0];
                            if(Y!=YY){
                                bool undefTuple2 = undefTuple1;
                                const std::vector<int>* tuples;
                                tuples = &pcpush_0_.getValuesVec({YY});
                                const std::vector<int>* tuplesU = &ucpush_0_.getValuesVec({YY});
                                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                    const Tuple * tuple2 = NULL;
                                    if(i < tuples->size()){
                                        tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                                    }
                                    else {
                                        tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                        undefTuple2 = true;
                                    }
                                    if(tuple2!= NULL){
                                        int T = (*tuple2)[1];
                                        if(Y!=YY){
                                            //Rule is firing 
                                            Tuple* t;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            t = factory.addNewInternalTuple({Y,T}, _ocpush);
                                            if(t->isUnknown()){
                                                generatedStack.push_back(t->getId());
                                                if(undefTuple2){
                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                    insertUndef(insertResult);
                                                    propagationStack->push_back(std::make_pair(t->getId(), 22));
                                                    if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                    tupleSupports[t->getId()].insert(22) ;
                                                }
                                                else{
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                    printTuple(t);
                                                }
                                            }
                                            else if(t->isUndef()){
                                                if(!undefTuple2){
                                                    factory.removeFromCollisionsList(t->getId());
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                    generatedStack.push_back(t->getId());
                                                    printTuple(t);
                                                }
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
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int Y = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pccpush_.getValuesVec({});
                    const std::vector<int>* tuplesU = &uccpush_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({Y, T}, _ocpush);
                            if(tuple2 == NULL){
                                tuple2 = &dummyTuple;
                                undefTuple2 = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({Y,T}, _cpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 24));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(24) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pstep_.getValuesVec({});
            const std::vector<int>* tuplesU = &ustep_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int T = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _rrpush);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pneg_goal_.getValuesVec({});
                        const std::vector<int>* tuplesU = &uneg_goal_.getValuesVec({});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int S = (*tuple2)[0];
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({T}, _ccpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 20));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(20) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pstep_.getValuesVec({});
            const std::vector<int>* tuplesU = &ustep_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int T = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _ccpush);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pneg_goal_.getValuesVec({});
                        const std::vector<int>* tuplesU = &uneg_goal_.getValuesVec({});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int S = (*tuple2)[0];
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({T}, _rrpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 19));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(19) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pgoal_.getValuesVec({});
            const std::vector<int>* tuplesU = &ugoal_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    int T = (*tuple0)[2];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X, Y, T}, _reach);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({T}, _neg_goal);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 18));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(18) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &preach_.getValuesVec({});
            const std::vector<int>* tuplesU = &ureach_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int XX = (*tuple0)[0];
                    int YY = (*tuple0)[1];
                    int S = (*tuple0)[2];
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int X = (*tuple1)[2];
                            int Y = (*tuple1)[3];
                            int T = (*tuple1)[4];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 36));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(36) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &preach_.getValuesVec({});
            const std::vector<int>* tuplesU = &ureach_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int XX = (*tuple0)[0];
                    int YY = (*tuple0)[1];
                    int T = (*tuple0)[2];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pdneighbor_1_2_.getValuesVec({XX, YY});
                        const std::vector<int>* tuplesU = &udneighbor_1_2_.getValuesVec({XX, YY});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int D = (*tuple2)[0];
                                int X = (*tuple2)[3];
                                int Y = (*tuple2)[4];
                                bool undefTuple3 = undefTuple2;
                                const Tuple* tuple3 = factory.find({XX, YY, D, T}, _conn);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
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
                                            undefTuple4 = true;
                                        }
                                        if(tuple4!= NULL){
                                            int E = (*tuple4)[2];
                                            bool undefTuple5 = undefTuple4;
                                            const Tuple* tuple5 = factory.find({D, E}, _inverse);
                                            if(tuple5 != NULL && tuple5->isUndef()) undefTuple5 = true;
                                            if(tuple5!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                                if(t->isUnknown()){
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple5){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                        propagationStack->push_back(std::make_pair(t->getId(), 37));
                                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                        tupleSupports[t->getId()].insert(37) ;
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        printTuple(t);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple5){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        generatedStack.push_back(t->getId());
                                                        printTuple(t);
                                                    }
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
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pconn_.getValuesVec({});
            const std::vector<int>* tuplesU = &uconn_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int XX = (*tuple0)[0];
                    int YY = (*tuple0)[1];
                    int D = (*tuple0)[2];
                    int S = (*tuple0)[3];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({D}, _dir);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
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
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int X = (*tuple2)[2];
                                int Y = (*tuple2)[3];
                                int T = (*tuple2)[4];
                                bool undefTuple3 = undefTuple2;
                                const Tuple* tuple3 = factory.find({T}, _step);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                if(tuple3!= NULL){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({X,Y,D,T}, _conn);
                                    if(t->isUnknown()){
                                        generatedStack.push_back(t->getId());
                                        if(undefTuple3){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                            propagationStack->push_back(std::make_pair(t->getId(), 34));
                                            if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                            tupleSupports[t->getId()].insert(34) ;
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            printTuple(t);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple3){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            generatedStack.push_back(t->getId());
                                            printTuple(t);
                                        }
                                    }
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pneighbor_0_.getValuesVec({ConstantsManager::getInstance().mapConstant("e")});
            const std::vector<int>* tuplesU = &uneighbor_0_.getValuesVec({ConstantsManager::getInstance().mapConstant("e")});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int XX = (*tuple0)[1];
                    int YY = (*tuple0)[2];
                    int X = (*tuple0)[3];
                    int Y = (*tuple0)[4];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &ppush_0_1_.getValuesVec({XX, ConstantsManager::getInstance().mapConstant("e")});
                    const std::vector<int>* tuplesU = &upush_0_1_.getValuesVec({XX, ConstantsManager::getInstance().mapConstant("e")});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[2];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 29));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(29) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pneighbor_0_.getValuesVec({ConstantsManager::getInstance().mapConstant("w")});
            const std::vector<int>* tuplesU = &uneighbor_0_.getValuesVec({ConstantsManager::getInstance().mapConstant("w")});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int XX = (*tuple0)[1];
                    int YY = (*tuple0)[2];
                    int X = (*tuple0)[3];
                    int Y = (*tuple0)[4];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &ppush_0_1_.getValuesVec({XX, ConstantsManager::getInstance().mapConstant("w")});
                    const std::vector<int>* tuplesU = &upush_0_1_.getValuesVec({XX, ConstantsManager::getInstance().mapConstant("w")});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[2];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 30));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(30) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pneighbor_0_.getValuesVec({ConstantsManager::getInstance().mapConstant("n")});
            const std::vector<int>* tuplesU = &uneighbor_0_.getValuesVec({ConstantsManager::getInstance().mapConstant("n")});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int XX = (*tuple0)[1];
                    int YY = (*tuple0)[2];
                    int X = (*tuple0)[3];
                    int Y = (*tuple0)[4];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &ppush_0_1_.getValuesVec({YY, ConstantsManager::getInstance().mapConstant("n")});
                    const std::vector<int>* tuplesU = &upush_0_1_.getValuesVec({YY, ConstantsManager::getInstance().mapConstant("n")});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[2];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 31));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(31) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pneighbor_0_.getValuesVec({ConstantsManager::getInstance().mapConstant("s")});
            const std::vector<int>* tuplesU = &uneighbor_0_.getValuesVec({ConstantsManager::getInstance().mapConstant("s")});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int XX = (*tuple0)[1];
                    int YY = (*tuple0)[2];
                    int X = (*tuple0)[3];
                    int Y = (*tuple0)[4];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &ppush_0_1_.getValuesVec({YY, ConstantsManager::getInstance().mapConstant("s")});
                    const std::vector<int>* tuplesU = &upush_0_1_.getValuesVec({YY, ConstantsManager::getInstance().mapConstant("s")});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[2];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 32));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(32) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push);
                            if(tuple2 == NULL){
                                tuple2 = &dummyTuple;
                                undefTuple2 = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const Tuple* tuple3 = factory.find({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push);
                                if(tuple3 == NULL){
                                    tuple3 = &dummyTuple;
                                    undefTuple3 = true;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple3 = true;
                                }
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple* tuple4 = factory.find({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push);
                                    if(tuple4 == NULL){
                                        tuple4 = &dummyTuple;
                                        undefTuple4 = true;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple4 = true;
                                    }
                                    if(tuple4!= NULL){
                                        bool undefTuple5 = undefTuple4;
                                        const Tuple* tuple5 = factory.find({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push);
                                        if(tuple5 == NULL){
                                            tuple5 = &dummyTuple;
                                            undefTuple5 = true;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            //Rule is firing 
                                            Tuple* t;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            t = factory.addNewInternalTuple({X,Y,X,Y,T}, _shift);
                                            if(t->isUnknown()){
                                                generatedStack.push_back(t->getId());
                                                if(undefTuple5){
                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                    insertUndef(insertResult);
                                                    propagationStack->push_back(std::make_pair(t->getId(), 33));
                                                    if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                    tupleSupports[t->getId()].insert(33) ;
                                                }
                                                else{
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                    printTuple(t);
                                                }
                                            }
                                            else if(t->isUndef()){
                                                if(!undefTuple5){
                                                    factory.removeFromCollisionsList(t->getId());
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                    generatedStack.push_back(t->getId());
                                                    printTuple(t);
                                                }
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
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            bool recursiveTupleUndef = recursiveTuple->isUndef();
            if(literalName == _goal){
                {
                    bool undefTuple0= false;
                    int S = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[1];
                    int XX = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int X = (*tuple1)[2];
                            int Y = (*tuple1)[3];
                            int T = (*tuple1)[4];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y,T}, _goal);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 35));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(35) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int Y = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X, Y, T}, _reach);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({T}, _neg_goal);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 18));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(18) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }
            if(literalName == _shift){
                {
                    bool undefTuple0= false;
                    int Y = (*recursiveTuple)[3];
                    int YY = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[4];
                    int X = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pgoal_0_1_.getValuesVec({XX, YY});
                        const std::vector<int>* tuplesU = &ugoal_0_1_.getValuesVec({XX, YY});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int S = (*tuple2)[2];
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y,T}, _goal);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 35));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(35) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int Y = (*recursiveTuple)[3];
                    int YY = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[4];
                    int X = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &preach_0_1_.getValuesVec({XX, YY});
                        const std::vector<int>* tuplesU = &ureach_0_1_.getValuesVec({XX, YY});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int S = (*tuple2)[2];
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 36));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(36) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int Y = (*recursiveTuple)[3];
                    int YY = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[4];
                    int X = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pconn_0_1_.getValuesVec({XX, YY});
                        const std::vector<int>* tuplesU = &uconn_0_1_.getValuesVec({XX, YY});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int D = (*tuple2)[2];
                                int S = (*tuple2)[3];
                                bool undefTuple3 = undefTuple2;
                                const Tuple* tuple3 = factory.find({D}, _dir);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                if(tuple3!= NULL){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({X,Y,D,T}, _conn);
                                    if(t->isUnknown()){
                                        generatedStack.push_back(t->getId());
                                        if(undefTuple3){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                            propagationStack->push_back(std::make_pair(t->getId(), 34));
                                            if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                            tupleSupports[t->getId()].insert(34) ;
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            printTuple(t);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple3){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            generatedStack.push_back(t->getId());
                                            printTuple(t);
                                        }
                                    }
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _rpush){
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[1];
                    int XX = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({XX}, _row);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &prow_.getValuesVec({});
                        const std::vector<int>* tuplesU = &urow_.getValuesVec({});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int X = (*tuple2)[0];
                                if(X!=XX){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({X,T}, _orpush);
                                    if(t->isUnknown()){
                                        generatedStack.push_back(t->getId());
                                        if(undefTuple2){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                            propagationStack->push_back(std::make_pair(t->getId(), 21));
                                            if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                            tupleSupports[t->getId()].insert(21) ;
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            printTuple(t);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple2){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            generatedStack.push_back(t->getId());
                                            printTuple(t);
                                        }
                                    }
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[1];
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X,ConstantsManager::getInstance().mapConstant("e"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 25));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(25) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[1];
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X,ConstantsManager::getInstance().mapConstant("w"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 26));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(26) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }
            if(literalName == _rrpush){
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int X = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({X, T}, _orpush);
                            if(tuple2 == NULL){
                                tuple2 = &dummyTuple;
                                undefTuple2 = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,T}, _rpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 23));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(23) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({T}, _step);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            bool undefTuple2 = undefTuple1;
                            const std::vector<int>* tuples;
                            tuples = &pneg_goal_.getValuesVec({});
                            const std::vector<int>* tuplesU = &uneg_goal_.getValuesVec({});
                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                const Tuple * tuple2 = NULL;
                                if(i < tuples->size()){
                                    tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                                }
                                else {
                                    tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                    undefTuple2 = true;
                                }
                                if(tuple2!= NULL){
                                    int S = (*tuple2)[0];
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({T}, _ccpush);
                                    if(t->isUnknown()){
                                        generatedStack.push_back(t->getId());
                                        if(undefTuple2){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                            propagationStack->push_back(std::make_pair(t->getId(), 20));
                                            if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                            tupleSupports[t->getId()].insert(20) ;
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            printTuple(t);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple2){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            generatedStack.push_back(t->getId());
                                            printTuple(t);
                                        }
                                    }
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _orpush){
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[1];
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({T}, _rrpush);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({X}, _row);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,T}, _rpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 23));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(23) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _push){
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({X, T}, _rpush);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X,ConstantsManager::getInstance().mapConstant("e"),T}, _push);
                            if(t->isUnknown()){
                                generatedStack.push_back(t->getId());
                                if(undefTuple1){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                    propagationStack->push_back(std::make_pair(t->getId(), 25));
                                    if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                    tupleSupports[t->getId()].insert(25) ;
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                    printTuple(t);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple1){
                                    factory.removeFromCollisionsList(t->getId());
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                    generatedStack.push_back(t->getId());
                                    printTuple(t);
                                }
                            }
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({X, T}, _rpush);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X,ConstantsManager::getInstance().mapConstant("w"),T}, _push);
                            if(t->isUnknown()){
                                generatedStack.push_back(t->getId());
                                if(undefTuple1){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                    propagationStack->push_back(std::make_pair(t->getId(), 26));
                                    if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                    tupleSupports[t->getId()].insert(26) ;
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                    printTuple(t);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple1){
                                    factory.removeFromCollisionsList(t->getId());
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                    generatedStack.push_back(t->getId());
                                    printTuple(t);
                                }
                            }
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int Y = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({Y, T}, _cpush);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({Y,ConstantsManager::getInstance().mapConstant("n"),T}, _push);
                            if(t->isUnknown()){
                                generatedStack.push_back(t->getId());
                                if(undefTuple1){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                    propagationStack->push_back(std::make_pair(t->getId(), 27));
                                    if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                    tupleSupports[t->getId()].insert(27) ;
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                    printTuple(t);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple1){
                                    factory.removeFromCollisionsList(t->getId());
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                    generatedStack.push_back(t->getId());
                                    printTuple(t);
                                }
                            }
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int Y = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({Y, T}, _cpush);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({Y,ConstantsManager::getInstance().mapConstant("s"),T}, _push);
                            if(t->isUnknown()){
                                generatedStack.push_back(t->getId());
                                if(undefTuple1){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                    propagationStack->push_back(std::make_pair(t->getId(), 28));
                                    if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                    tupleSupports[t->getId()].insert(28) ;
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                    printTuple(t);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple1){
                                    factory.removeFromCollisionsList(t->getId());
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                    generatedStack.push_back(t->getId());
                                    printTuple(t);
                                }
                            }
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pneighbor_0_1_.getValuesVec({ConstantsManager::getInstance().mapConstant("e"), XX});
                        const std::vector<int>* tuplesU = &uneighbor_0_1_.getValuesVec({ConstantsManager::getInstance().mapConstant("e"), XX});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int YY = (*tuple2)[2];
                                int X = (*tuple2)[3];
                                int Y = (*tuple2)[4];
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 29));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(29) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pneighbor_0_1_.getValuesVec({ConstantsManager::getInstance().mapConstant("w"), XX});
                        const std::vector<int>* tuplesU = &uneighbor_0_1_.getValuesVec({ConstantsManager::getInstance().mapConstant("w"), XX});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int YY = (*tuple2)[2];
                                int X = (*tuple2)[3];
                                int Y = (*tuple2)[4];
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 30));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(30) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pneighbor_0_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("n"), YY});
                        const std::vector<int>* tuplesU = &uneighbor_0_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("n"), YY});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int XX = (*tuple2)[1];
                                int X = (*tuple2)[3];
                                int Y = (*tuple2)[4];
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 31));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(31) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pneighbor_0_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("s"), YY});
                        const std::vector<int>* tuplesU = &uneighbor_0_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("s"), YY});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int XX = (*tuple2)[1];
                                int X = (*tuple2)[3];
                                int Y = (*tuple2)[4];
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({XX,YY,X,Y,T}, _shift);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 32));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(32) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({T}, _step);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push);
                            if(tuple2 == NULL){
                                tuple2 = &dummyTuple;
                                undefTuple2 = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const std::vector<int>* tuples;
                                tuples = &pfield_0_.getValuesVec({X});
                                const std::vector<int>* tuplesU = &ufield_0_.getValuesVec({X});
                                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                    const Tuple * tuple3 = NULL;
                                    if(i < tuples->size()){
                                        tuple3 = factory.getTupleFromInternalID(tuples->at(i));
                                    }
                                    else {
                                        tuple3 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                        undefTuple3 = true;
                                    }
                                    if(tuple3!= NULL){
                                        int Y = (*tuple3)[1];
                                        bool undefTuple4 = undefTuple3;
                                        const Tuple* tuple4 = factory.find({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push);
                                        if(tuple4 == NULL){
                                            tuple4 = &dummyTuple;
                                            undefTuple4 = true;
                                        }
                                        else{
                                            if(tuple4->isTrue())    tuple4= NULL;
                                            else undefTuple4 = true;
                                        }
                                        if(tuple4!= NULL){
                                            bool undefTuple5 = undefTuple4;
                                            const Tuple* tuple5 = factory.find({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push);
                                            if(tuple5 == NULL){
                                                tuple5 = &dummyTuple;
                                                undefTuple5 = true;
                                            }
                                            else{
                                                if(tuple5->isTrue())    tuple5= NULL;
                                                else undefTuple5 = true;
                                            }
                                            if(tuple5!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({X,Y,X,Y,T}, _shift);
                                                if(t->isUnknown()){
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple5){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                        propagationStack->push_back(std::make_pair(t->getId(), 33));
                                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                        tupleSupports[t->getId()].insert(33) ;
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        printTuple(t);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple5){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        generatedStack.push_back(t->getId());
                                                        printTuple(t);
                                                    }
                                                }
                                            }//close par
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({T}, _step);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push);
                            if(tuple2 == NULL){
                                tuple2 = &dummyTuple;
                                undefTuple2 = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const std::vector<int>* tuples;
                                tuples = &pfield_0_.getValuesVec({X});
                                const std::vector<int>* tuplesU = &ufield_0_.getValuesVec({X});
                                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                    const Tuple * tuple3 = NULL;
                                    if(i < tuples->size()){
                                        tuple3 = factory.getTupleFromInternalID(tuples->at(i));
                                    }
                                    else {
                                        tuple3 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                        undefTuple3 = true;
                                    }
                                    if(tuple3!= NULL){
                                        int Y = (*tuple3)[1];
                                        bool undefTuple4 = undefTuple3;
                                        const Tuple* tuple4 = factory.find({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push);
                                        if(tuple4 == NULL){
                                            tuple4 = &dummyTuple;
                                            undefTuple4 = true;
                                        }
                                        else{
                                            if(tuple4->isTrue())    tuple4= NULL;
                                            else undefTuple4 = true;
                                        }
                                        if(tuple4!= NULL){
                                            bool undefTuple5 = undefTuple4;
                                            const Tuple* tuple5 = factory.find({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push);
                                            if(tuple5 == NULL){
                                                tuple5 = &dummyTuple;
                                                undefTuple5 = true;
                                            }
                                            else{
                                                if(tuple5->isTrue())    tuple5= NULL;
                                                else undefTuple5 = true;
                                            }
                                            if(tuple5!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({X,Y,X,Y,T}, _shift);
                                                if(t->isUnknown()){
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple5){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                        propagationStack->push_back(std::make_pair(t->getId(), 33));
                                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                        tupleSupports[t->getId()].insert(33) ;
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        printTuple(t);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple5){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        generatedStack.push_back(t->getId());
                                                        printTuple(t);
                                                    }
                                                }
                                            }//close par
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int Y = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({T}, _step);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push);
                            if(tuple2 == NULL){
                                tuple2 = &dummyTuple;
                                undefTuple2 = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const std::vector<int>* tuples;
                                tuples = &pfield_1_.getValuesVec({Y});
                                const std::vector<int>* tuplesU = &ufield_1_.getValuesVec({Y});
                                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                    const Tuple * tuple3 = NULL;
                                    if(i < tuples->size()){
                                        tuple3 = factory.getTupleFromInternalID(tuples->at(i));
                                    }
                                    else {
                                        tuple3 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                        undefTuple3 = true;
                                    }
                                    if(tuple3!= NULL){
                                        int X = (*tuple3)[0];
                                        bool undefTuple4 = undefTuple3;
                                        const Tuple* tuple4 = factory.find({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push);
                                        if(tuple4 == NULL){
                                            tuple4 = &dummyTuple;
                                            undefTuple4 = true;
                                        }
                                        else{
                                            if(tuple4->isTrue())    tuple4= NULL;
                                            else undefTuple4 = true;
                                        }
                                        if(tuple4!= NULL){
                                            bool undefTuple5 = undefTuple4;
                                            const Tuple* tuple5 = factory.find({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push);
                                            if(tuple5 == NULL){
                                                tuple5 = &dummyTuple;
                                                undefTuple5 = true;
                                            }
                                            else{
                                                if(tuple5->isTrue())    tuple5= NULL;
                                                else undefTuple5 = true;
                                            }
                                            if(tuple5!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({X,Y,X,Y,T}, _shift);
                                                if(t->isUnknown()){
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple5){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                        propagationStack->push_back(std::make_pair(t->getId(), 33));
                                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                        tupleSupports[t->getId()].insert(33) ;
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        printTuple(t);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple5){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        generatedStack.push_back(t->getId());
                                                        printTuple(t);
                                                    }
                                                }
                                            }//close par
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[2];
                    int Y = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({T}, _step);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push);
                            if(tuple2 == NULL){
                                tuple2 = &dummyTuple;
                                undefTuple2 = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const std::vector<int>* tuples;
                                tuples = &pfield_1_.getValuesVec({Y});
                                const std::vector<int>* tuplesU = &ufield_1_.getValuesVec({Y});
                                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                    const Tuple * tuple3 = NULL;
                                    if(i < tuples->size()){
                                        tuple3 = factory.getTupleFromInternalID(tuples->at(i));
                                    }
                                    else {
                                        tuple3 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                        undefTuple3 = true;
                                    }
                                    if(tuple3!= NULL){
                                        int X = (*tuple3)[0];
                                        bool undefTuple4 = undefTuple3;
                                        const Tuple* tuple4 = factory.find({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push);
                                        if(tuple4 == NULL){
                                            tuple4 = &dummyTuple;
                                            undefTuple4 = true;
                                        }
                                        else{
                                            if(tuple4->isTrue())    tuple4= NULL;
                                            else undefTuple4 = true;
                                        }
                                        if(tuple4!= NULL){
                                            bool undefTuple5 = undefTuple4;
                                            const Tuple* tuple5 = factory.find({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push);
                                            if(tuple5 == NULL){
                                                tuple5 = &dummyTuple;
                                                undefTuple5 = true;
                                            }
                                            else{
                                                if(tuple5->isTrue())    tuple5= NULL;
                                                else undefTuple5 = true;
                                            }
                                            if(tuple5!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({X,Y,X,Y,T}, _shift);
                                                if(t->isUnknown()){
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple5){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                        propagationStack->push_back(std::make_pair(t->getId(), 33));
                                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                        tupleSupports[t->getId()].insert(33) ;
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        printTuple(t);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple5){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        generatedStack.push_back(t->getId());
                                                        printTuple(t);
                                                    }
                                                }
                                            }//close par
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
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[1];
                    int Y = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({Y,ConstantsManager::getInstance().mapConstant("n"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 27));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(27) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[1];
                    int Y = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({Y,ConstantsManager::getInstance().mapConstant("s"),T}, _push);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                                propagationStack->push_back(std::make_pair(t->getId(), 28));
                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                tupleSupports[t->getId()].insert(28) ;
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[1];
                    int YY = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({YY}, _col);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pcol_.getValuesVec({});
                        const std::vector<int>* tuplesU = &ucol_.getValuesVec({});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int Y = (*tuple2)[0];
                                if(Y!=YY){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({Y,T}, _ocpush);
                                    if(t->isUnknown()){
                                        generatedStack.push_back(t->getId());
                                        if(undefTuple2){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                            propagationStack->push_back(std::make_pair(t->getId(), 22));
                                            if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                            tupleSupports[t->getId()].insert(22) ;
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            printTuple(t);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple2){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            generatedStack.push_back(t->getId());
                                            printTuple(t);
                                        }
                                    }
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _ccpush){
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int Y = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({Y, T}, _ocpush);
                            if(tuple2 == NULL){
                                tuple2 = &dummyTuple;
                                undefTuple2 = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({Y,T}, _cpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 24));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(24) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({T}, _step);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            bool undefTuple2 = undefTuple1;
                            const std::vector<int>* tuples;
                            tuples = &pneg_goal_.getValuesVec({});
                            const std::vector<int>* tuplesU = &uneg_goal_.getValuesVec({});
                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                const Tuple * tuple2 = NULL;
                                if(i < tuples->size()){
                                    tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                                }
                                else {
                                    tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                    undefTuple2 = true;
                                }
                                if(tuple2!= NULL){
                                    int S = (*tuple2)[0];
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({T}, _rrpush);
                                    if(t->isUnknown()){
                                        generatedStack.push_back(t->getId());
                                        if(undefTuple2){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                            propagationStack->push_back(std::make_pair(t->getId(), 19));
                                            if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                            tupleSupports[t->getId()].insert(19) ;
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            printTuple(t);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple2){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            generatedStack.push_back(t->getId());
                                            printTuple(t);
                                        }
                                    }
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _ocpush){
                {
                    bool undefTuple0= false;
                    int T = (*recursiveTuple)[1];
                    int Y = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({T}, _ccpush);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({Y}, _col);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({Y,T}, _cpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 24));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(24) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _neg_goal){
                {
                    bool undefTuple0= false;
                    int S = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({T}, _rrpush);
                            if(tuple2 == NULL){
                                tuple2 = &dummyTuple;
                                undefTuple2 = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({T}, _ccpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 20));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(20) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int S = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({T}, _ccpush);
                            if(tuple2 == NULL){
                                tuple2 = &dummyTuple;
                                undefTuple2 = true;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({T}, _rrpush);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 19));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(19) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _reach){
                {
                    bool undefTuple0= false;
                    int Y = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[2];
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({X, Y, T}, _goal);
                        if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                        if(tuple1!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({T}, _neg_goal);
                            if(t->isUnknown()){
                                generatedStack.push_back(t->getId());
                                if(undefTuple1){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                    propagationStack->push_back(std::make_pair(t->getId(), 18));
                                    if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                    tupleSupports[t->getId()].insert(18) ;
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                    printTuple(t);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple1){
                                    factory.removeFromCollisionsList(t->getId());
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                    generatedStack.push_back(t->getId());
                                    printTuple(t);
                                }
                            }
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int S = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[1];
                    int XX = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int X = (*tuple1)[2];
                            int Y = (*tuple1)[3];
                            int T = (*tuple1)[4];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({T}, _step);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                        propagationStack->push_back(std::make_pair(t->getId(), 36));
                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                        tupleSupports[t->getId()].insert(36) ;
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int YY = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[2];
                    int XX = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pdneighbor_1_2_.getValuesVec({XX, YY});
                        const std::vector<int>* tuplesU = &udneighbor_1_2_.getValuesVec({XX, YY});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int D = (*tuple2)[0];
                                int X = (*tuple2)[3];
                                int Y = (*tuple2)[4];
                                bool undefTuple3 = undefTuple2;
                                const Tuple* tuple3 = factory.find({XX, YY, D, T}, _conn);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
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
                                            undefTuple4 = true;
                                        }
                                        if(tuple4!= NULL){
                                            int E = (*tuple4)[2];
                                            bool undefTuple5 = undefTuple4;
                                            const Tuple* tuple5 = factory.find({D, E}, _inverse);
                                            if(tuple5 != NULL && tuple5->isUndef()) undefTuple5 = true;
                                            if(tuple5!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                                if(t->isUnknown()){
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple5){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                        propagationStack->push_back(std::make_pair(t->getId(), 37));
                                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                        tupleSupports[t->getId()].insert(37) ;
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        printTuple(t);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple5){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        generatedStack.push_back(t->getId());
                                                        printTuple(t);
                                                    }
                                                }
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
                    bool undefTuple0= false;
                    int D = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[3];
                    int XX = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple* tuple2 = factory.find({XX, YY, T}, _reach);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
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
                                    undefTuple3 = true;
                                }
                                if(tuple3!= NULL){
                                    int X = (*tuple3)[3];
                                    int Y = (*tuple3)[4];
                                    bool undefTuple4 = undefTuple3;
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
                                            undefTuple4 = true;
                                        }
                                        if(tuple4!= NULL){
                                            int E = (*tuple4)[2];
                                            bool undefTuple5 = undefTuple4;
                                            const Tuple* tuple5 = factory.find({D, E}, _inverse);
                                            if(tuple5 != NULL && tuple5->isUndef()) undefTuple5 = true;
                                            if(tuple5!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                                if(t->isUnknown()){
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple5){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                        propagationStack->push_back(std::make_pair(t->getId(), 37));
                                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                        tupleSupports[t->getId()].insert(37) ;
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        printTuple(t);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple5){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        generatedStack.push_back(t->getId());
                                                        printTuple(t);
                                                    }
                                                }
                                            }//close par
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int E = (*recursiveTuple)[2];
                    int Y = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[3];
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({T}, _step);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &preach_2_.getValuesVec({T});
                        const std::vector<int>* tuplesU = &ureach_2_.getValuesVec({T});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int XX = (*tuple2)[0];
                                int YY = (*tuple2)[1];
                                bool undefTuple3 = undefTuple2;
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
                                        undefTuple3 = true;
                                    }
                                    if(tuple3!= NULL){
                                        int D = (*tuple3)[0];
                                        bool undefTuple4 = undefTuple3;
                                        const Tuple* tuple4 = factory.find({D, E}, _inverse);
                                        if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                        if(tuple4!= NULL){
                                            bool undefTuple5 = undefTuple4;
                                            const Tuple* tuple5 = factory.find({XX, YY, D, T}, _conn);
                                            if(tuple5 != NULL && tuple5->isUndef()) undefTuple5 = true;
                                            if(tuple5!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({X,Y,T}, _reach);
                                                if(t->isUnknown()){
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple5){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                        propagationStack->push_back(std::make_pair(t->getId(), 37));
                                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                        tupleSupports[t->getId()].insert(37) ;
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        printTuple(t);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple5){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        generatedStack.push_back(t->getId());
                                                        printTuple(t);
                                                    }
                                                }
                                            }//close par
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int S = (*recursiveTuple)[3];
                    int D = (*recursiveTuple)[2];
                    int YY = (*recursiveTuple)[1];
                    int XX = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({D}, _dir);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
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
                                undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                int X = (*tuple2)[2];
                                int Y = (*tuple2)[3];
                                int T = (*tuple2)[4];
                                bool undefTuple3 = undefTuple2;
                                const Tuple* tuple3 = factory.find({T}, _step);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                if(tuple3!= NULL){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({X,Y,D,T}, _conn);
                                    if(t->isUnknown()){
                                        generatedStack.push_back(t->getId());
                                        if(undefTuple3){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                            propagationStack->push_back(std::make_pair(t->getId(), 34));
                                            if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                            tupleSupports[t->getId()].insert(34) ;
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            printTuple(t);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple3){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            generatedStack.push_back(t->getId());
                                            printTuple(t);
                                        }
                                    }
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
        }
        //---------------------------------------Strongly connected component propagation-----------------------
        {
            std::vector<std::pair<int, int>>* nextPropagationStack = new std::vector<std::pair<int, int>>();
            std::vector<std::pair<int, int>>* temp;
            int ruleId;
            bool propagated = true;
            while(propagated){
                std::cout <<"I should check "<< propagationStack->size()<<"\n";
                propagated = false;
                while(!propagationStack->empty()){
                    Tuple* headTuple = factory.getTupleFromInternalID(propagationStack->back().first);
                    ruleId = propagationStack->back().second;
                    propagationStack->pop_back();
                    if(ruleId == 35){
                        {
                            bool maySupport = false;
                            int X = (*headTuple)[0];
                            int Y = (*headTuple)[1];
                            int T = (*headTuple)[2];
                            bool undefTuple0= false;
                            const Tuple* tuple0 = factory.find({T}, _step);
                            if(tuple0 != NULL && tuple0->isUndef()) undefTuple0 = true;
                            if(tuple0!= NULL){
                                bool undefTuple1 = undefTuple0;
                                const std::vector<int>* tuples;
                                tuples = &pgoal_.getValuesVec({});
                                const std::vector<int>* tuplesU = &ugoal_.getValuesVec({});
                                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                    const Tuple * tuple1 = NULL;
                                    if(i < tuples->size()){
                                        tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                                    }
                                    else {
                                        tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                        undefTuple1 = true;
                                    }
                                    if(tuple1!= NULL){
                                        int XX = (*tuple1)[0];
                                        int YY = (*tuple1)[1];
                                        int S = (*tuple1)[2];
                                        bool undefTuple2 = undefTuple1;
                                        const Tuple* tuple2 = factory.find({XX, YY, X, Y, T}, _shift);
                                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                                        if(tuple2!= NULL){
                                            //Rule is firing 
                                            maySupport = true;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            if(undefTuple2){
                                                nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 35));
                                            }
                                            else{
                                                factory.removeFromCollisionsList(headTuple->getId());
                                                insertResult = headTuple->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                                propagated = true;
                                                std::cout << "Propagation Occurred to True ";
                                                printTuple(headTuple);
                                            }
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(35);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                    else if(ruleId == 21){
                        {
                            bool maySupport = false;
                            int X = (*headTuple)[0];
                            int T = (*headTuple)[1];
                            bool undefTuple0= false;
                            const Tuple* tuple0 = factory.find({X}, _row);
                            if(tuple0 != NULL && tuple0->isUndef()) undefTuple0 = true;
                            if(tuple0!= NULL){
                                bool undefTuple1 = undefTuple0;
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
                                        undefTuple1 = true;
                                    }
                                    if(tuple1!= NULL){
                                        int XX = (*tuple1)[0];
                                        if(X!=XX){
                                            bool undefTuple2 = undefTuple1;
                                            const Tuple* tuple2 = factory.find({XX, T}, _rpush);
                                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                                            if(tuple2!= NULL){
                                                if(X!=XX){
                                                    //Rule is firing 
                                                    maySupport = true;
                                                    std::pair<const TupleLight *, bool> insertResult;
                                                    if(undefTuple2){
                                                        nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 21));
                                                    }
                                                    else{
                                                        factory.removeFromCollisionsList(headTuple->getId());
                                                        insertResult = headTuple->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        propagated = true;
                                                        std::cout << "Propagation Occurred to True ";
                                                        printTuple(headTuple);
                                                    }
                                                }//close par
                                            }//close par
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(21);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                    else if(ruleId == 23){
                        {
                            bool maySupport = false;
                            int X = (*headTuple)[0];
                            int T = (*headTuple)[1];
                            bool undefTuple0= false;
                            const Tuple* tuple0 = factory.find({X, T}, _orpush);
                            if(tuple0 == NULL){
                                tuple0 = &dummyTuple;
                            }
                            else{
                                if(tuple0->isTrue()){
                                    tuple0= NULL;
                                }
                                else undefTuple0 = true;
                            }
                            if(tuple0!= NULL){
                                bool undefTuple1 = undefTuple0;
                                const Tuple* tuple1 = factory.find({T}, _rrpush);
                                if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                                if(tuple1!= NULL){
                                    bool undefTuple2 = undefTuple1;
                                    const Tuple* tuple2 = factory.find({X}, _row);
                                    if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                                    if(tuple2!= NULL){
                                        //Rule is firing 
                                        maySupport = true;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        if(undefTuple2){
                                            nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 23));
                                        }
                                        else{
                                            factory.removeFromCollisionsList(headTuple->getId());
                                            insertResult = headTuple->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            propagated = true;
                                            std::cout << "Propagation Occurred to True ";
                                            printTuple(headTuple);
                                        }
                                    }//close par
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(23);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                    else if(ruleId == 25){
                        {
                            bool maySupport = false;
                            int X = (*headTuple)[0];
                            int T = (*headTuple)[2];
                            bool undefTuple0= false;
                            const Tuple* tuple0 = factory.find({X, ConstantsManager::getInstance().mapConstant("w"), T}, _push);
                            if(tuple0 == NULL){
                                tuple0 = &dummyTuple;
                            }
                            else{
                                if(tuple0->isTrue()){
                                    tuple0= NULL;
                                }
                                else undefTuple0 = true;
                            }
                            if(tuple0!= NULL){
                                bool undefTuple1 = undefTuple0;
                                const Tuple* tuple1 = factory.find({X, T}, _rpush);
                                if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                                if(tuple1!= NULL){
                                    //Rule is firing 
                                    maySupport = true;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    if(undefTuple1){
                                        nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 25));
                                    }
                                    else{
                                        factory.removeFromCollisionsList(headTuple->getId());
                                        insertResult = headTuple->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        propagated = true;
                                        std::cout << "Propagation Occurred to True ";
                                        printTuple(headTuple);
                                    }
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(25);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                    else if(ruleId == 26){
                        {
                            bool maySupport = false;
                            int X = (*headTuple)[0];
                            int T = (*headTuple)[2];
                            bool undefTuple0= false;
                            const Tuple* tuple0 = factory.find({X, ConstantsManager::getInstance().mapConstant("e"), T}, _push);
                            if(tuple0 == NULL){
                                tuple0 = &dummyTuple;
                            }
                            else{
                                if(tuple0->isTrue()){
                                    tuple0= NULL;
                                }
                                else undefTuple0 = true;
                            }
                            if(tuple0!= NULL){
                                bool undefTuple1 = undefTuple0;
                                const Tuple* tuple1 = factory.find({X, T}, _rpush);
                                if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                                if(tuple1!= NULL){
                                    //Rule is firing 
                                    maySupport = true;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    if(undefTuple1){
                                        nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 26));
                                    }
                                    else{
                                        factory.removeFromCollisionsList(headTuple->getId());
                                        insertResult = headTuple->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        propagated = true;
                                        std::cout << "Propagation Occurred to True ";
                                        printTuple(headTuple);
                                    }
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(26);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                    else if(ruleId == 27){
                        {
                            bool maySupport = false;
                            int Y = (*headTuple)[0];
                            int T = (*headTuple)[2];
                            bool undefTuple0= false;
                            const Tuple* tuple0 = factory.find({Y, ConstantsManager::getInstance().mapConstant("s"), T}, _push);
                            if(tuple0 == NULL){
                                tuple0 = &dummyTuple;
                            }
                            else{
                                if(tuple0->isTrue()){
                                    tuple0= NULL;
                                }
                                else undefTuple0 = true;
                            }
                            if(tuple0!= NULL){
                                bool undefTuple1 = undefTuple0;
                                const Tuple* tuple1 = factory.find({Y, T}, _cpush);
                                if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                                if(tuple1!= NULL){
                                    //Rule is firing 
                                    maySupport = true;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    if(undefTuple1){
                                        nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 27));
                                    }
                                    else{
                                        factory.removeFromCollisionsList(headTuple->getId());
                                        insertResult = headTuple->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        propagated = true;
                                        std::cout << "Propagation Occurred to True ";
                                        printTuple(headTuple);
                                    }
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(27);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                    else if(ruleId == 28){
                        {
                            bool maySupport = false;
                            int Y = (*headTuple)[0];
                            int T = (*headTuple)[2];
                            bool undefTuple0= false;
                            const Tuple* tuple0 = factory.find({Y, ConstantsManager::getInstance().mapConstant("n"), T}, _push);
                            if(tuple0 == NULL){
                                tuple0 = &dummyTuple;
                            }
                            else{
                                if(tuple0->isTrue()){
                                    tuple0= NULL;
                                }
                                else undefTuple0 = true;
                            }
                            if(tuple0!= NULL){
                                bool undefTuple1 = undefTuple0;
                                const Tuple* tuple1 = factory.find({Y, T}, _cpush);
                                if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                                if(tuple1!= NULL){
                                    //Rule is firing 
                                    maySupport = true;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    if(undefTuple1){
                                        nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 28));
                                    }
                                    else{
                                        factory.removeFromCollisionsList(headTuple->getId());
                                        insertResult = headTuple->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                        propagated = true;
                                        std::cout << "Propagation Occurred to True ";
                                        printTuple(headTuple);
                                    }
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(28);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                    else if(ruleId == 22){
                        {
                            bool maySupport = false;
                            int Y = (*headTuple)[0];
                            int T = (*headTuple)[1];
                            bool undefTuple0= false;
                            const Tuple* tuple0 = factory.find({Y}, _col);
                            if(tuple0 != NULL && tuple0->isUndef()) undefTuple0 = true;
                            if(tuple0!= NULL){
                                bool undefTuple1 = undefTuple0;
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
                                        undefTuple1 = true;
                                    }
                                    if(tuple1!= NULL){
                                        int YY = (*tuple1)[0];
                                        if(Y!=YY){
                                            bool undefTuple2 = undefTuple1;
                                            const Tuple* tuple2 = factory.find({YY, T}, _cpush);
                                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                                            if(tuple2!= NULL){
                                                if(Y!=YY){
                                                    //Rule is firing 
                                                    maySupport = true;
                                                    std::pair<const TupleLight *, bool> insertResult;
                                                    if(undefTuple2){
                                                        nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 22));
                                                    }
                                                    else{
                                                        factory.removeFromCollisionsList(headTuple->getId());
                                                        insertResult = headTuple->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                        propagated = true;
                                                        std::cout << "Propagation Occurred to True ";
                                                        printTuple(headTuple);
                                                    }
                                                }//close par
                                            }//close par
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(22);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                    else if(ruleId == 24){
                        {
                            bool maySupport = false;
                            int Y = (*headTuple)[0];
                            int T = (*headTuple)[1];
                            bool undefTuple0= false;
                            const Tuple* tuple0 = factory.find({Y, T}, _ocpush);
                            if(tuple0 == NULL){
                                tuple0 = &dummyTuple;
                            }
                            else{
                                if(tuple0->isTrue()){
                                    tuple0= NULL;
                                }
                                else undefTuple0 = true;
                            }
                            if(tuple0!= NULL){
                                bool undefTuple1 = undefTuple0;
                                const Tuple* tuple1 = factory.find({T}, _ccpush);
                                if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                                if(tuple1!= NULL){
                                    bool undefTuple2 = undefTuple1;
                                    const Tuple* tuple2 = factory.find({Y}, _col);
                                    if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                                    if(tuple2!= NULL){
                                        //Rule is firing 
                                        maySupport = true;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        if(undefTuple2){
                                            nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 24));
                                        }
                                        else{
                                            factory.removeFromCollisionsList(headTuple->getId());
                                            insertResult = headTuple->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            propagated = true;
                                            std::cout << "Propagation Occurred to True ";
                                            printTuple(headTuple);
                                        }
                                    }//close par
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(24);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                    else if(ruleId == 20){
                        {
                            bool maySupport = false;
                            int T = (*headTuple)[0];
                            bool undefTuple0= false;
                            const Tuple* tuple0 = factory.find({T}, _rrpush);
                            if(tuple0 == NULL){
                                tuple0 = &dummyTuple;
                            }
                            else{
                                if(tuple0->isTrue()){
                                    tuple0= NULL;
                                }
                                else undefTuple0 = true;
                            }
                            if(tuple0!= NULL){
                                bool undefTuple1 = undefTuple0;
                                const Tuple* tuple1 = factory.find({T}, _step);
                                if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                                if(tuple1!= NULL){
                                    bool undefTuple2 = undefTuple1;
                                    const std::vector<int>* tuples;
                                    tuples = &pneg_goal_.getValuesVec({});
                                    const std::vector<int>* tuplesU = &uneg_goal_.getValuesVec({});
                                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                        const Tuple * tuple2 = NULL;
                                        if(i < tuples->size()){
                                            tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                                        }
                                        else {
                                            tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                            undefTuple2 = true;
                                        }
                                        if(tuple2!= NULL){
                                            int S = (*tuple2)[0];
                                            //Rule is firing 
                                            maySupport = true;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            if(undefTuple2){
                                                nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 20));
                                            }
                                            else{
                                                factory.removeFromCollisionsList(headTuple->getId());
                                                insertResult = headTuple->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                                propagated = true;
                                                std::cout << "Propagation Occurred to True ";
                                                printTuple(headTuple);
                                            }
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(20);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                    else if(ruleId == 19){
                        {
                            bool maySupport = false;
                            int T = (*headTuple)[0];
                            bool undefTuple0= false;
                            const Tuple* tuple0 = factory.find({T}, _ccpush);
                            if(tuple0 == NULL){
                                tuple0 = &dummyTuple;
                            }
                            else{
                                if(tuple0->isTrue()){
                                    tuple0= NULL;
                                }
                                else undefTuple0 = true;
                            }
                            if(tuple0!= NULL){
                                bool undefTuple1 = undefTuple0;
                                const Tuple* tuple1 = factory.find({T}, _step);
                                if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                                if(tuple1!= NULL){
                                    bool undefTuple2 = undefTuple1;
                                    const std::vector<int>* tuples;
                                    tuples = &pneg_goal_.getValuesVec({});
                                    const std::vector<int>* tuplesU = &uneg_goal_.getValuesVec({});
                                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                        const Tuple * tuple2 = NULL;
                                        if(i < tuples->size()){
                                            tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                                        }
                                        else {
                                            tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                            undefTuple2 = true;
                                        }
                                        if(tuple2!= NULL){
                                            int S = (*tuple2)[0];
                                            //Rule is firing 
                                            maySupport = true;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            if(undefTuple2){
                                                nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 19));
                                            }
                                            else{
                                                factory.removeFromCollisionsList(headTuple->getId());
                                                insertResult = headTuple->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                                propagated = true;
                                                std::cout << "Propagation Occurred to True ";
                                                printTuple(headTuple);
                                            }
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(19);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                    else if(ruleId == 18){
                        {
                            bool maySupport = false;
                            int T = (*headTuple)[0];
                            bool undefTuple0= false;
                            const std::vector<int>* tuples;
                            tuples = &pgoal_2_.getValuesVec({T});
                            const std::vector<int>* tuplesU = &ugoal_2_.getValuesVec({T});
                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                const Tuple * tuple0 = NULL;
                                if(i < tuples->size()){
                                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                                }
                                else {
                                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                    undefTuple0 = true;
                                }
                                if(tuple0!= NULL){
                                    int X = (*tuple0)[0];
                                    int Y = (*tuple0)[1];
                                    bool undefTuple1 = undefTuple0;
                                    const Tuple* tuple1 = factory.find({X, Y, T}, _reach);
                                    if(tuple1 == NULL){
                                        tuple1 = &dummyTuple;
                                    }
                                    else{
                                        if(tuple1->isTrue()){
                                            tuple1= NULL;
                                        }
                                        else undefTuple1 = true;
                                    }
                                    if(tuple1!= NULL){
                                        //Rule is firing 
                                        maySupport = true;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        if(undefTuple1){
                                            nextPropagationStack->push_back(std::make_pair(headTuple->getId(), 18));
                                        }
                                        else{
                                            factory.removeFromCollisionsList(headTuple->getId());
                                            insertResult = headTuple->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                            propagated = true;
                                            std::cout << "Propagation Occurred to True ";
                                            printTuple(headTuple);
                                        }
                                    }//close par
                                }//close par
                            }//close par
                            if(!maySupport){
                                tupleSupports[headTuple->getId()].erase(18);
                                if(tupleSupports[headTuple->getId()].size() == 0){
                                    //removing tuple from undef
                                    std::cout << "Propagation Occurred to false for tuple ";
                                    printTuple(headTuple);
                                    factory.removeFromCollisionsList(headTuple->getId());
                                    factory.destroyTuple(headTuple->getId());
                                }
                                propagated = true;
                            }
                        }//close par
                    }
                }
                temp = propagationStack;
                propagationStack = nextPropagationStack;
                nextPropagationStack = temp;
                nextPropagationStack->clear();
            }
            delete nextPropagationStack;
            delete propagationStack;
        }
    }
    std::cout<<"}\n";
    std::cout<<"\nUndef{\n";
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pmax_steps_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &umax_steps_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pmax_steps_.clear();
        umax_steps_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pconnect_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uconnect_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pconnect_.clear();
        uconnect_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pinit_on_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uinit_on_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pinit_on_.clear();
        uinit_on_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pocpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uocpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pocpush_.clear();
        uocpush_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &preach_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ureach_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        preach_.clear();
        preach_0_1_.clear();
        preach_2_.clear();
        ureach_.clear();
        ureach_0_1_.clear();
        ureach_2_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pccpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uccpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pccpush_.clear();
        uccpush_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pgoal_on_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ugoal_on_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pgoal_on_.clear();
        ugoal_on_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pstep_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ustep_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pstep_.clear();
        ustep_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pfield_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ufield_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pfield_.clear();
        pfield_0_.clear();
        pfield_1_.clear();
        ufield_.clear();
        ufield_0_.clear();
        ufield_1_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pnum_cols_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &unum_cols_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pnum_cols_.clear();
        unum_cols_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pnum_rows_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &unum_rows_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pnum_rows_.clear();
        unum_rows_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pgoal_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ugoal_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pgoal_.clear();
        pgoal_0_1_.clear();
        pgoal_2_.clear();
        ugoal_.clear();
        ugoal_0_1_.clear();
        ugoal_2_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pcol_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ucol_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pcol_.clear();
        ucol_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pinverse_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uinverse_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pinverse_.clear();
        uinverse_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pshift_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ushift_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pshift_.clear();
        pshift_0_1_.clear();
        ushift_.clear();
        ushift_0_1_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &ppush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &upush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        ppush_.clear();
        ppush_0_1_.clear();
        ppush_1_.clear();
        upush_.clear();
        upush_0_1_.clear();
        upush_1_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pconn_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uconn_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pconn_.clear();
        pconn_0_1_.clear();
        pconn_0_1_3_.clear();
        pconn_2_.clear();
        uconn_.clear();
        uconn_0_1_.clear();
        uconn_0_1_3_.clear();
        uconn_2_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &porpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uorpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        porpush_.clear();
        uorpush_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pcpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ucpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pcpush_.clear();
        pcpush_0_.clear();
        ucpush_.clear();
        ucpush_0_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &prrpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &urrpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        prrpush_.clear();
        urrpush_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pneg_goal_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uneg_goal_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pneg_goal_.clear();
        uneg_goal_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pneighbor_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uneighbor_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pneighbor_.clear();
        pneighbor_0_.clear();
        pneighbor_0_1_.clear();
        pneighbor_0_2_.clear();
        uneighbor_.clear();
        uneighbor_0_.clear();
        uneighbor_0_1_.clear();
        uneighbor_0_2_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pdneighbor_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &udneighbor_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pdneighbor_.clear();
        pdneighbor_0_1_2_.clear();
        pdneighbor_1_2_.clear();
        pdneighbor_1_2_3_4_.clear();
        udneighbor_.clear();
        udneighbor_0_1_2_.clear();
        udneighbor_1_2_.clear();
        udneighbor_1_2_3_4_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &prow_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &urow_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        prow_.clear();
        urow_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pdir_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &udir_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pdir_.clear();
        udir_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &prpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &urpush_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        prpush_.clear();
        prpush_0_.clear();
        urpush_.clear();
        urpush_0_.clear();
    }
    std::cout<<"\n}\n";
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
