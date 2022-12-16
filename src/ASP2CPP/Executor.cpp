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
const int _minfl = 27;
const int _mvlabel = 25;
const int _sign = 24;
const int _coppo = 22;
const int _llabel = 20;
const int _bot = 23;
const int _reach = 17;
const int _inactive = 15;
const int _active = 14;
const int _last = 13;
const int _diff = 0;
const int _edge = 1;
const int _obs_elabel = 2;
const int _obs_vlabel = 3;
const int _vlabel = 19;
const int _nontriv = 4;
const int _vertex = 5;
const int _input = 6;
const int _trivial = 7;
const int _nlast = 11;
const int _btedge = 8;
const int _mllabel = 26;
const int _aedge = 18;
const int _singleton = 16;
const int _nfirst = 10;
const int _first = 12;
const int _oppo = 21;
const int _ntedge = 9;
AuxMap<0> pminfl_({});
AuxMap<0> uminfl_({});
AuxMap<0> pmvlabel_({});
AuxMap<0> umvlabel_({});
AuxMap<0> psign_({});
AuxMap<0> usign_({});
AuxMap<0> pcoppo_({});
AuxMap<0> ucoppo_({});
AuxMap<0> pllabel_({});
AuxMap<0> ullabel_({});
AuxMap<0> pbot_({});
AuxMap<0> ubot_({});
AuxMap<0> preach_({});
AuxMap<0> ureach_({});
AuxMap<0> pinactive_({});
AuxMap<0> uinactive_({});
AuxMap<0> pactive_({});
AuxMap<0> uactive_({});
AuxMap<0> plast_({});
AuxMap<0> ulast_({});
AuxMap<0> pdiff_({});
AuxMap<0> udiff_({});
AuxMap<0> pedge_({});
AuxMap<0> uedge_({});
AuxMap<0> pobs_elabel_({});
AuxMap<0> uobs_elabel_({});
AuxMap<0> pobs_vlabel_({});
AuxMap<0> uobs_vlabel_({});
AuxMap<0> pvlabel_({});
AuxMap<0> uvlabel_({});
AuxMap<0> pnontriv_({});
AuxMap<0> unontriv_({});
AuxMap<0> pvertex_({});
AuxMap<0> uvertex_({});
AuxMap<0> pinput_({});
AuxMap<0> uinput_({});
AuxMap<0> ptrivial_({});
AuxMap<0> utrivial_({});
AuxMap<0> pnlast_({});
AuxMap<0> unlast_({});
AuxMap<0> pbtedge_({});
AuxMap<0> ubtedge_({});
AuxMap<0> pmllabel_({});
AuxMap<0> umllabel_({});
AuxMap<0> paedge_({});
AuxMap<0> uaedge_({});
AuxMap<0> psingleton_({});
AuxMap<0> usingleton_({});
AuxMap<0> pnfirst_({});
AuxMap<0> unfirst_({});
AuxMap<0> pfirst_({});
AuxMap<0> ufirst_({});
AuxMap<0> poppo_({});
AuxMap<0> uoppo_({});
AuxMap<0> pntedge_({});
AuxMap<0> untedge_({});
AuxMap<32> pobs_vlabel_0_({0});
AuxMap<32> uobs_vlabel_0_({0});
AuxMap<32> pedge_1_({1});
AuxMap<32> uedge_1_({1});
AuxMap<32> preach_0_({0});
AuxMap<32> ureach_0_({0});
AuxMap<32> pedge_0_({0});
AuxMap<32> uedge_0_({0});
AuxMap<64> pobs_elabel_0_1_({0,1});
AuxMap<64> uobs_elabel_0_1_({0,1});
AuxMap<64> pllabel_1_2_({1,2});
AuxMap<64> ullabel_1_2_({1,2});
AuxMap<64> pllabel_0_2_({0,2});
AuxMap<64> ullabel_0_2_({0,2});
AuxMap<32> pllabel_2_({2});
AuxMap<32> ullabel_2_({2});
AuxMap<32> pvlabel_0_({0});
AuxMap<32> uvlabel_0_({0});
AuxMap<32> pcoppo_1_({1});
AuxMap<32> ucoppo_1_({1});
AuxMap<32> poppo_1_({1});
AuxMap<32> uoppo_1_({1});
AuxMap<96> pmllabel_0_1_3_({0,1,3});
AuxMap<96> umllabel_0_1_3_({0,1,3});
AuxMap<64> pmllabel_0_1_({0,1});
AuxMap<64> umllabel_0_1_({0,1});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"minfl", _minfl});
    factory.addPredicate();
    predicateToID.insert({"mvlabel", _mvlabel});
    factory.addPredicate();
    predicateToID.insert({"sign", _sign});
    factory.addPredicate();
    predicateToID.insert({"coppo", _coppo});
    factory.addPredicate();
    predicateToID.insert({"llabel", _llabel});
    factory.addPredicate();
    predicateToID.insert({"bot", _bot});
    factory.addPredicate();
    predicateToID.insert({"reach", _reach});
    factory.addPredicate();
    predicateToID.insert({"inactive", _inactive});
    factory.addPredicate();
    predicateToID.insert({"active", _active});
    factory.addPredicate();
    predicateToID.insert({"last", _last});
    factory.addPredicate();
    predicateToID.insert({"diff", _diff});
    factory.addPredicate();
    predicateToID.insert({"edge", _edge});
    factory.addPredicate();
    predicateToID.insert({"obs_elabel", _obs_elabel});
    factory.addPredicate();
    predicateToID.insert({"obs_vlabel", _obs_vlabel});
    factory.addPredicate();
    predicateToID.insert({"vlabel", _vlabel});
    factory.addPredicate();
    predicateToID.insert({"nontriv", _nontriv});
    factory.addPredicate();
    predicateToID.insert({"vertex", _vertex});
    factory.addPredicate();
    predicateToID.insert({"input", _input});
    factory.addPredicate();
    predicateToID.insert({"trivial", _trivial});
    factory.addPredicate();
    predicateToID.insert({"nlast", _nlast});
    factory.addPredicate();
    predicateToID.insert({"btedge", _btedge});
    factory.addPredicate();
    predicateToID.insert({"mllabel", _mllabel});
    factory.addPredicate();
    predicateToID.insert({"aedge", _aedge});
    factory.addPredicate();
    predicateToID.insert({"singleton", _singleton});
    factory.addPredicate();
    predicateToID.insert({"nfirst", _nfirst});
    factory.addPredicate();
    predicateToID.insert({"first", _first});
    factory.addPredicate();
    predicateToID.insert({"oppo", _oppo});
    factory.addPredicate();
    predicateToID.insert({"ntedge", _ntedge});
    factory.addPredicate();
    Executor::predicateIds.push_back("diff");
    Executor::predicateIds.push_back("edge");
    Executor::predicateIds.push_back("obs_elabel");
    Executor::predicateIds.push_back("obs_vlabel");
    Executor::predicateIds.push_back("nontriv");
    Executor::predicateIds.push_back("vertex");
    Executor::predicateIds.push_back("input");
    Executor::predicateIds.push_back("trivial");
    Executor::predicateIds.push_back("btedge");
    Executor::predicateIds.push_back("ntedge");
    Executor::predicateIds.push_back("nfirst");
    Executor::predicateIds.push_back("nlast");
    Executor::predicateIds.push_back("first");
    Executor::predicateIds.push_back("last");
    Executor::predicateIds.push_back("active");
    Executor::predicateIds.push_back("inactive");
    Executor::predicateIds.push_back("singleton");
    Executor::predicateIds.push_back("reach");
    Executor::predicateIds.push_back("aedge");
    Executor::predicateIds.push_back("vlabel");
    Executor::predicateIds.push_back("llabel");
    Executor::predicateIds.push_back("oppo");
    Executor::predicateIds.push_back("coppo");
    Executor::predicateIds.push_back("bot");
    Executor::predicateIds.push_back("sign");
    Executor::predicateIds.push_back("mvlabel");
    Executor::predicateIds.push_back("mllabel");
    Executor::predicateIds.push_back("minfl");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _ntedge){
        pntedge_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _oppo){
        poppo_.insert2Vec(*insertResult.first);
        poppo_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _first){
        pfirst_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nfirst){
        pnfirst_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _singleton){
        psingleton_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _aedge){
        paedge_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _mllabel){
        pmllabel_.insert2Vec(*insertResult.first);
        pmllabel_0_1_.insert2Vec(*insertResult.first);
        pmllabel_0_1_3_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _btedge){
        pbtedge_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nlast){
        pnlast_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _trivial){
        ptrivial_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _input){
        pinput_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _vertex){
        pvertex_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nontriv){
        pnontriv_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _vlabel){
        pvlabel_.insert2Vec(*insertResult.first);
        pvlabel_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _obs_vlabel){
        pobs_vlabel_.insert2Vec(*insertResult.first);
        pobs_vlabel_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _minfl){
        pminfl_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _llabel){
        pllabel_.insert2Vec(*insertResult.first);
        pllabel_0_2_.insert2Vec(*insertResult.first);
        pllabel_1_2_.insert2Vec(*insertResult.first);
        pllabel_2_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _mvlabel){
        pmvlabel_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _diff){
        pdiff_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _edge){
        pedge_.insert2Vec(*insertResult.first);
        pedge_0_.insert2Vec(*insertResult.first);
        pedge_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _sign){
        psign_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _active){
        pactive_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _coppo){
        pcoppo_.insert2Vec(*insertResult.first);
        pcoppo_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _bot){
        pbot_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _reach){
        preach_.insert2Vec(*insertResult.first);
        preach_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _inactive){
        pinactive_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _obs_elabel){
        pobs_elabel_.insert2Vec(*insertResult.first);
        pobs_elabel_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _last){
        plast_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _ntedge){
        untedge_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _oppo){
        uoppo_.insert2Vec(*insertResult.first);
        uoppo_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _first){
        ufirst_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nfirst){
        unfirst_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _singleton){
        usingleton_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _aedge){
        uaedge_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _mllabel){
        umllabel_.insert2Vec(*insertResult.first);
        umllabel_0_1_.insert2Vec(*insertResult.first);
        umllabel_0_1_3_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _btedge){
        ubtedge_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nlast){
        unlast_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _trivial){
        utrivial_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _input){
        uinput_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _vertex){
        uvertex_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nontriv){
        unontriv_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _vlabel){
        uvlabel_.insert2Vec(*insertResult.first);
        uvlabel_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _obs_vlabel){
        uobs_vlabel_.insert2Vec(*insertResult.first);
        uobs_vlabel_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _minfl){
        uminfl_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _llabel){
        ullabel_.insert2Vec(*insertResult.first);
        ullabel_0_2_.insert2Vec(*insertResult.first);
        ullabel_1_2_.insert2Vec(*insertResult.first);
        ullabel_2_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _mvlabel){
        umvlabel_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _diff){
        udiff_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _edge){
        uedge_.insert2Vec(*insertResult.first);
        uedge_0_.insert2Vec(*insertResult.first);
        uedge_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _sign){
        usign_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _active){
        uactive_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _coppo){
        ucoppo_.insert2Vec(*insertResult.first);
        ucoppo_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _bot){
        ubot_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _reach){
        ureach_.insert2Vec(*insertResult.first);
        ureach_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _inactive){
        uinactive_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _obs_elabel){
        uobs_elabel_.insert2Vec(*insertResult.first);
        uobs_elabel_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _last){
        ulast_.insert2Vec(*insertResult.first);
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
    auto start = std::chrono::high_resolution_clock::now();
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pvertex_.getValuesVec({});
            const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _input, true);
                    const Tuple* tuple1 = factory.find({V}, _input);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({V}, _active);
                        if(t->isUnknown()){
                            printTuple(t);
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else if(t->isUndef()){
                            insertResult = t->setStatus(TruthStatus::Undef);
                        }
                        t = factory.addNewInternalTuple({V}, _inactive);
                        if(t->isUnknown()){
                            printTuple(t);
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
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel, true);
                    const Tuple* tuple1 = factory.find({V, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple* tuple2 = factory.find({V, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                        if(tuple2!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({V,V}, _diff);
                            if(t->isUnknown()){
                                printTuple(t);
                                if(undefTuple2){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple2){
                                    factory.removeFromCollisionsList(t->getId());
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel, true);
                    const Tuple* tuple1 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple* tuple2 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pobs_vlabel_0_.getValuesVec({U});
                            const std::vector<int>* tuplesU = &uobs_vlabel_0_.getValuesVec({U});
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
                                    int S = (*tuple3)[1];
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple* tuple4 = factory.find({V, S}, _obs_vlabel);
                                    if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({U,V}, _diff);
                                        if(t->isUnknown()){
                                            printTuple(t);
                                            if(undefTuple4){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                insertUndef(insertResult);
                                            }
                                            else{
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                            }
                                        }
                                        else if(t->isUndef()){
                                            if(!undefTuple4){
                                                factory.removeFromCollisionsList(t->getId());
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
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
            const std::vector<int>* tuples;
            tuples = &pedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel, true);
                    const Tuple* tuple1 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple* tuple2 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pobs_vlabel_0_.getValuesVec({U});
                            const std::vector<int>* tuplesU = &uobs_vlabel_0_.getValuesVec({U});
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
                                    int S = (*tuple3)[1];
                                    bool undefTuple4 = undefTuple3;
                                    const std::vector<int>* tuples;
                                    tuples = &pobs_vlabel_0_.getValuesVec({V});
                                    const std::vector<int>* tuplesU = &uobs_vlabel_0_.getValuesVec({V});
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
                                            int T = (*tuple4)[1];
                                            if(S!=T){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({U,V}, _diff);
                                                if(t->isUnknown()){
                                                    printTuple(t);
                                                    if(undefTuple4){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple4){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
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
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pvertex_.getValuesVec({});
            const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _input, true);
                    const Tuple* tuple1 = factory.find({V}, _input);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pedge_1_.getValuesVec({V});
                        const std::vector<int>* tuplesU = &uedge_1_.getValuesVec({V});
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
                                int U = (*tuple2)[0];
                                bool undefTuple3 = undefTuple2;
                                const Tuple negativeTuple = Tuple({U, V}, _diff, true);
                                const Tuple* tuple3 = factory.find({U, V}, _diff);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple3 = true;
                                }
                                if(tuple3!= NULL){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({V}, _nontriv);
                                    if(t->isUnknown()){
                                        printTuple(t);
                                        if(undefTuple3){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple3){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                        }
                                    }
                                }//close par
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
        tuplesToRemove = &pdiff_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &udiff_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pdiff_.clear();
        udiff_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pvertex_.getValuesVec({});
            const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _nontriv, true);
                    const Tuple* tuple1 = factory.find({V}, _nontriv);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _input, true);
                        const Tuple* tuple2 = factory.find({V}, _input);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({V}, _trivial);
                            if(t->isUnknown()){
                                printTuple(t);
                                if(undefTuple2){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple2){
                                    factory.removeFromCollisionsList(t->getId());
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pnontriv_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &unontriv_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pnontriv_.clear();
        unontriv_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pvertex_.getValuesVec({});
            const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel, true);
                    const Tuple* tuple1 = factory.find({V, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel, true);
                        const Tuple* tuple2 = factory.find({V, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({V}, _trivial, true);
                            const Tuple* tuple3 = factory.find({V}, _trivial);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const Tuple negativeTuple = Tuple({V}, _input, true);
                                const Tuple* tuple4 = factory.find({V}, _input);
                                if(tuple4 == NULL){
                                    tuple4 = &negativeTuple;
                                }
                                else{
                                    if(tuple4->isTrue())    tuple4= NULL;
                                    else undefTuple4 = true;
                                }
                                if(tuple4!= NULL){
                                    bool undefTuple5 = undefTuple4;
                                    const std::vector<int>* tuples;
                                    tuples = &pactive_.getValuesVec({});
                                    const std::vector<int>* tuplesU = &uactive_.getValuesVec({});
                                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                        const Tuple * tuple5 = NULL;
                                        if(i < tuples->size()){
                                            tuple5 = factory.getTupleFromInternalID(tuples->at(i));
                                        }
                                        else {
                                            tuple5 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                            undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            int W = (*tuple5)[0];
                                            bool undefTuple6 = undefTuple5;
                                            const Tuple* tuple6 = factory.find({V, W}, _edge);
                                            if(tuple6 != NULL && tuple6->isUndef()) undefTuple6 = true;
                                            if(tuple6!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({V}, _aedge);
                                                if(t->isUnknown()){
                                                    printTuple(t);
                                                    if(undefTuple6){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple6){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
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
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &paedge_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uaedge_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        paedge_.clear();
        uaedge_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                    const Tuple* tuple1 = factory.find({V}, _trivial);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple* tuple2 = factory.find({V}, _active);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                        if(tuple2!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({U,V}, _reach);
                            if(t->isUnknown()){
                                printTuple(t);
                                if(undefTuple2){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple2){
                                    factory.removeFromCollisionsList(t->getId());
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel, true);
                    const Tuple* tuple1 = factory.find({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel, true);
                        const Tuple* tuple2 = factory.find({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({V}, _trivial, true);
                            const Tuple* tuple3 = factory.find({V}, _trivial);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const Tuple* tuple4 = factory.find({V}, _active);
                                if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                if(tuple4!= NULL){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({V,U}, _reach);
                                    if(t->isUnknown()){
                                        printTuple(t);
                                        if(undefTuple4){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple4){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
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
            tuples = &pedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                    const Tuple* tuple1 = factory.find({V}, _trivial);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple* tuple2 = factory.find({V}, _active);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &preach_0_.getValuesVec({V});
                            const std::vector<int>* tuplesU = &ureach_0_.getValuesVec({V});
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
                                    int W = (*tuple3)[1];
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple* tuple4 = factory.find({W}, _vertex);
                                    if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({U,W}, _reach);
                                        if(t->isUnknown()){
                                            printTuple(t);
                                            generatedStack.push_back(t->getId());
                                            if(undefTuple4){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                insertUndef(insertResult);
                                            }
                                            else{
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                            }
                                        }
                                        else if(t->isUndef()){
                                            if(!undefTuple4){
                                                factory.removeFromCollisionsList(t->getId());
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
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
            const std::vector<int>* tuples;
            tuples = &pedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel, true);
                    const Tuple* tuple1 = factory.find({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel, true);
                        const Tuple* tuple2 = factory.find({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({V}, _trivial, true);
                            const Tuple* tuple3 = factory.find({V}, _trivial);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const Tuple* tuple4 = factory.find({V}, _active);
                                if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                if(tuple4!= NULL){
                                    bool undefTuple5 = undefTuple4;
                                    const std::vector<int>* tuples;
                                    tuples = &preach_0_.getValuesVec({U});
                                    const std::vector<int>* tuplesU = &ureach_0_.getValuesVec({U});
                                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                        const Tuple * tuple5 = NULL;
                                        if(i < tuples->size()){
                                            tuple5 = factory.getTupleFromInternalID(tuples->at(i));
                                        }
                                        else {
                                            tuple5 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                            undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            int W = (*tuple5)[1];
                                            bool undefTuple6 = undefTuple5;
                                            const Tuple* tuple6 = factory.find({W}, _vertex);
                                            if(tuple6 != NULL && tuple6->isUndef()) undefTuple6 = true;
                                            if(tuple6!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({V,W}, _reach);
                                                if(t->isUnknown()){
                                                    printTuple(t);
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple6){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple6){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
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
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            bool recursiveTupleUndef = recursiveTuple->isUndef();
            if(literalName == _reach){
                {
                    bool undefTuple0= false;
                    int W = (*recursiveTuple)[1];
                    int V = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({W}, _vertex);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                        const Tuple* tuple2 = factory.find({V}, _trivial);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple* tuple3 = factory.find({V}, _active);
                            if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const std::vector<int>* tuples;
                                tuples = &pedge_1_.getValuesVec({V});
                                const std::vector<int>* tuplesU = &uedge_1_.getValuesVec({V});
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
                                        int U = (*tuple4)[0];
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({U,W}, _reach);
                                        if(t->isUnknown()){
                                            printTuple(t);
                                            generatedStack.push_back(t->getId());
                                            if(undefTuple4){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                insertUndef(insertResult);
                                            }
                                            else{
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                            }
                                        }
                                        else if(t->isUndef()){
                                            if(!undefTuple4){
                                                factory.removeFromCollisionsList(t->getId());
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
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
                    int W = (*recursiveTuple)[1];
                    int U = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel, true);
                    const Tuple* tuple1 = factory.find({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel, true);
                        const Tuple* tuple2 = factory.find({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple* tuple3 = factory.find({W}, _vertex);
                            if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const std::vector<int>* tuples;
                                tuples = &pedge_0_.getValuesVec({U});
                                const std::vector<int>* tuplesU = &uedge_0_.getValuesVec({U});
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
                                        int V = (*tuple4)[1];
                                        bool undefTuple5 = undefTuple4;
                                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                        const Tuple* tuple5 = factory.find({V}, _trivial);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            bool undefTuple6 = undefTuple5;
                                            const Tuple* tuple6 = factory.find({V}, _active);
                                            if(tuple6 != NULL && tuple6->isUndef()) undefTuple6 = true;
                                            if(tuple6!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({V,W}, _reach);
                                                if(t->isUnknown()){
                                                    printTuple(t);
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple6){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple6){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
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
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({V}, _active);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                        const Tuple* tuple2 = factory.find({V}, _trivial);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pactive_.getValuesVec({});
                            const std::vector<int>* tuplesU = &uactive_.getValuesVec({});
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
                                    int W = (*tuple3)[0];
                                    if(W!=V){
                                        bool undefTuple4 = undefTuple3;
                                        const Tuple* tuple4 = factory.find({W, V}, _reach);
                                        if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                        if(tuple4!= NULL){
                                            if(W!=V){
                                                bool undefTuple5 = undefTuple4;
                                                const Tuple* tuple5 = factory.find({V, W}, _reach);
                                                if(tuple5 != NULL && tuple5->isUndef()) undefTuple5 = true;
                                                if(tuple5!= NULL){
                                                    if(W!=V){
                                                        bool undefTuple6 = undefTuple5;
                                                        const Tuple negativeTuple = Tuple({W}, _trivial, true);
                                                        const Tuple* tuple6 = factory.find({W}, _trivial);
                                                        if(tuple6 == NULL){
                                                            tuple6 = &negativeTuple;
                                                        }
                                                        else{
                                                            if(tuple6->isTrue())    tuple6= NULL;
                                                            else undefTuple6 = true;
                                                        }
                                                        if(tuple6!= NULL){
                                                            if(W!=V){
                                                                //Rule is firing 
                                                                Tuple* t;
                                                                std::pair<const TupleLight *, bool> insertResult;
                                                                t = factory.addNewInternalTuple({W,U,V,ConstantsManager::getInstance().mapConstant("p")}, _mllabel);
                                                                if(t->isUnknown()){
                                                                    printTuple(t);
                                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                                    insertUndef(insertResult);
                                                                }
                                                                else if(t->isUndef()){
                                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                                }
                                                                t = factory.addNewInternalTuple({W,U,V,ConstantsManager::getInstance().mapConstant("m")}, _mllabel);
                                                                if(t->isUnknown()){
                                                                    printTuple(t);
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
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pobs_elabel_.getValuesVec({});
            const std::vector<int>* tuplesU = &uobs_elabel_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    int S = (*tuple0)[2];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _input, true);
                    const Tuple* tuple1 = factory.find({V}, _input);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                        const Tuple* tuple2 = factory.find({V}, _trivial);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple* tuple3 = factory.find({U, V}, _edge);
                            if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const std::vector<int>* tuples;
                                tuples = &pvertex_.getValuesVec({});
                                const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                                        int W = (*tuple4)[0];
                                        if(W!=V){
                                            bool undefTuple5 = undefTuple4;
                                            const Tuple negativeTuple = Tuple({W}, _input, true);
                                            const Tuple* tuple5 = factory.find({W}, _input);
                                            if(tuple5 == NULL){
                                                tuple5 = &negativeTuple;
                                            }
                                            else{
                                                if(tuple5->isTrue())    tuple5= NULL;
                                                else undefTuple5 = true;
                                            }
                                            if(tuple5!= NULL){
                                                if(W!=V){
                                                    bool undefTuple6 = undefTuple5;
                                                    const Tuple negativeTuple = Tuple({W}, _trivial, true);
                                                    const Tuple* tuple6 = factory.find({W}, _trivial);
                                                    if(tuple6 == NULL){
                                                        tuple6 = &negativeTuple;
                                                    }
                                                    else{
                                                        if(tuple6->isTrue())    tuple6= NULL;
                                                        else undefTuple6 = true;
                                                    }
                                                    if(tuple6!= NULL){
                                                        if(W!=V){
                                                            //Rule is firing 
                                                            Tuple* t;
                                                            std::pair<const TupleLight *, bool> insertResult;
                                                            t = factory.addNewInternalTuple({W,U,V,S}, _mllabel);
                                                            if(t->isUnknown()){
                                                                printTuple(t);
                                                                if(undefTuple6){
                                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                                    insertUndef(insertResult);
                                                                }
                                                                else{
                                                                    insertResult = t->setStatus(TruthStatus::True);
                                                                    insertTrue(insertResult);
                                                                }
                                                            }
                                                            else if(t->isUndef()){
                                                                if(!undefTuple6){
                                                                    factory.removeFromCollisionsList(t->getId());
                                                                    insertResult = t->setStatus(TruthStatus::True);
                                                                    insertTrue(insertResult);
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
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pactive_.getValuesVec({});
            const std::vector<int>* tuplesU = &uactive_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({V}, _trivial);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({}, _singleton);
                        if(t->isUnknown()){
                            printTuple(t);
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pvertex_.getValuesVec({});
            const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _input, true);
                    const Tuple* tuple1 = factory.find({V}, _input);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pactive_.getValuesVec({});
                        const std::vector<int>* tuplesU = &uactive_.getValuesVec({});
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
                                int W = (*tuple2)[0];
                                if(V!=W){
                                    bool undefTuple3 = undefTuple2;
                                    const Tuple* tuple3 = factory.find({W}, _trivial);
                                    if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                    if(tuple3!= NULL){
                                        if(V!=W){
                                            //Rule is firing 
                                            Tuple* t;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            t = factory.addNewInternalTuple({V}, _inactive);
                                            if(t->isUnknown()){
                                                printTuple(t);
                                                if(undefTuple3){
                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                    insertUndef(insertResult);
                                                }
                                                else{
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                }
                                            }
                                            else if(t->isUndef()){
                                                if(!undefTuple3){
                                                    factory.removeFromCollisionsList(t->getId());
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
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
            if(literalName == _active){
                {
                    bool undefTuple0= false;
                    int W = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({W}, _trivial);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pvertex_.getValuesVec({});
                        const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                                int V = (*tuple2)[0];
                                if(V!=W){
                                    bool undefTuple3 = undefTuple2;
                                    const Tuple negativeTuple = Tuple({V}, _input, true);
                                    const Tuple* tuple3 = factory.find({V}, _input);
                                    if(tuple3 == NULL){
                                        tuple3 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple3->isTrue())    tuple3= NULL;
                                        else undefTuple3 = true;
                                    }
                                    if(tuple3!= NULL){
                                        if(V!=W){
                                            //Rule is firing 
                                            Tuple* t;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            t = factory.addNewInternalTuple({V}, _inactive);
                                            if(t->isUnknown()){
                                                printTuple(t);
                                                if(undefTuple3){
                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                    insertUndef(insertResult);
                                                }
                                                else{
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                }
                                            }
                                            else if(t->isUndef()){
                                                if(!undefTuple3){
                                                    factory.removeFromCollisionsList(t->getId());
                                                    insertResult = t->setStatus(TruthStatus::True);
                                                    insertTrue(insertResult);
                                                }
                                            }
                                        }//close par
                                    }//close par
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
        }
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pinactive_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uinactive_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pinactive_.clear();
        uinactive_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pvertex_.getValuesVec({});
            const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                    const Tuple* tuple1 = factory.find({V}, _trivial);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _input, true);
                        const Tuple* tuple2 = factory.find({V}, _input);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pedge_1_.getValuesVec({V});
                            const std::vector<int>* tuplesU = &uedge_1_.getValuesVec({V});
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
                                    int W = (*tuple3)[0];
                                    bool undefTuple4 = undefTuple3;
                                    const std::vector<int>* tuples;
                                    tuples = &pedge_1_.getValuesVec({V});
                                    const std::vector<int>* tuplesU = &uedge_1_.getValuesVec({V});
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
                                            int U = (*tuple4)[0];
                                            bool undefTuple5 = undefTuple4;
                                            const std::vector<int>* tuples;
                                            tuples = &pedge_1_.getValuesVec({V});
                                            const std::vector<int>* tuplesU = &uedge_1_.getValuesVec({V});
                                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                                const Tuple * tuple5 = NULL;
                                                if(i < tuples->size()){
                                                    tuple5 = factory.getTupleFromInternalID(tuples->at(i));
                                                }
                                                else {
                                                    tuple5 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                                    undefTuple5 = true;
                                                }
                                                if(tuple5!= NULL){
                                                    int Z = (*tuple5)[0];
                                                    if(W<Z){
                                                        if(Z<U){
                                                            //Rule is firing 
                                                            Tuple* t;
                                                            std::pair<const TupleLight *, bool> insertResult;
                                                            t = factory.addNewInternalTuple({W,U,V}, _btedge);
                                                            if(t->isUnknown()){
                                                                printTuple(t);
                                                                if(undefTuple5){
                                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                                    insertUndef(insertResult);
                                                                }
                                                                else{
                                                                    insertResult = t->setStatus(TruthStatus::True);
                                                                    insertTrue(insertResult);
                                                                }
                                                            }
                                                            else if(t->isUndef()){
                                                                if(!undefTuple5){
                                                                    factory.removeFromCollisionsList(t->getId());
                                                                    insertResult = t->setStatus(TruthStatus::True);
                                                                    insertTrue(insertResult);
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
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pvertex_.getValuesVec({});
            const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                    const Tuple* tuple1 = factory.find({V}, _trivial);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _input, true);
                        const Tuple* tuple2 = factory.find({V}, _input);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pedge_1_.getValuesVec({V});
                            const std::vector<int>* tuplesU = &uedge_1_.getValuesVec({V});
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
                                    int W = (*tuple3)[0];
                                    bool undefTuple4 = undefTuple3;
                                    const std::vector<int>* tuples;
                                    tuples = &pedge_1_.getValuesVec({V});
                                    const std::vector<int>* tuplesU = &uedge_1_.getValuesVec({V});
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
                                            int U = (*tuple4)[0];
                                            if(W<U){
                                                bool undefTuple5 = undefTuple4;
                                                const Tuple negativeTuple = Tuple({W, U, V}, _btedge, true);
                                                const Tuple* tuple5 = factory.find({W, U, V}, _btedge);
                                                if(tuple5 == NULL){
                                                    tuple5 = &negativeTuple;
                                                }
                                                else{
                                                    if(tuple5->isTrue())    tuple5= NULL;
                                                    else undefTuple5 = true;
                                                }
                                                if(tuple5!= NULL){
                                                    if(W<U){
                                                        //Rule is firing 
                                                        Tuple* t;
                                                        std::pair<const TupleLight *, bool> insertResult;
                                                        t = factory.addNewInternalTuple({W,U,V}, _ntedge);
                                                        if(t->isUnknown()){
                                                            printTuple(t);
                                                            if(undefTuple5){
                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                                insertUndef(insertResult);
                                                            }
                                                            else{
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
                                                            }
                                                        }
                                                        else if(t->isUndef()){
                                                            if(!undefTuple5){
                                                                factory.removeFromCollisionsList(t->getId());
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
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
            }//close par
        }//close par
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pbtedge_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ubtedge_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pbtedge_.clear();
        ubtedge_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pntedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &untedge_.getValuesVec({});
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
                    int W = (*tuple0)[0];
                    int U = (*tuple0)[1];
                    int V = (*tuple0)[2];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({W,V}, _nlast);
                    if(t->isUnknown()){
                        printTuple(t);
                        if(undefTuple0){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple0){
                            factory.removeFromCollisionsList(t->getId());
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
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
            tuples = &pvertex_.getValuesVec({});
            const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                    const Tuple* tuple1 = factory.find({V}, _trivial);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _input, true);
                        const Tuple* tuple2 = factory.find({V}, _input);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pedge_1_.getValuesVec({V});
                            const std::vector<int>* tuplesU = &uedge_1_.getValuesVec({V});
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
                                    int U = (*tuple3)[0];
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple negativeTuple = Tuple({U, V}, _nlast, true);
                                    const Tuple* tuple4 = factory.find({U, V}, _nlast);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple4 = true;
                                    }
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({U,V}, _last);
                                        if(t->isUnknown()){
                                            printTuple(t);
                                            if(undefTuple4){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                insertUndef(insertResult);
                                            }
                                            else{
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                            }
                                        }
                                        else if(t->isUndef()){
                                            if(!undefTuple4){
                                                factory.removeFromCollisionsList(t->getId());
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
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
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pnlast_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &unlast_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pnlast_.clear();
        unlast_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pntedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &untedge_.getValuesVec({});
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
                    int W = (*tuple0)[0];
                    int U = (*tuple0)[1];
                    int V = (*tuple0)[2];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({U,V}, _nfirst);
                    if(t->isUnknown()){
                        printTuple(t);
                        if(undefTuple0){
                            insertResult = t->setStatus(TruthStatus::Undef);
                            insertUndef(insertResult);
                        }
                        else{
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                        }
                    }
                    else if(t->isUndef()){
                        if(!undefTuple0){
                            factory.removeFromCollisionsList(t->getId());
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
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
            tuples = &pvertex_.getValuesVec({});
            const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                    const Tuple* tuple1 = factory.find({V}, _trivial);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _input, true);
                        const Tuple* tuple2 = factory.find({V}, _input);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pedge_1_.getValuesVec({V});
                            const std::vector<int>* tuplesU = &uedge_1_.getValuesVec({V});
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
                                    int U = (*tuple3)[0];
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple negativeTuple = Tuple({U, V}, _nfirst, true);
                                    const Tuple* tuple4 = factory.find({U, V}, _nfirst);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple4 = true;
                                    }
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({U,V}, _first);
                                        if(t->isUnknown()){
                                            printTuple(t);
                                            if(undefTuple4){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                insertUndef(insertResult);
                                            }
                                            else{
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
                                            }
                                        }
                                        else if(t->isUndef()){
                                            if(!undefTuple4){
                                                factory.removeFromCollisionsList(t->getId());
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertTrue(insertResult);
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
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pnfirst_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &unfirst_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pnfirst_.clear();
        unfirst_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pactive_.getValuesVec({});
            const std::vector<int>* tuplesU = &uactive_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                    const Tuple* tuple1 = factory.find({V}, _trivial);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pedge_1_.getValuesVec({V});
                        const std::vector<int>* tuplesU = &uedge_1_.getValuesVec({V});
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
                                int U = (*tuple2)[0];
                                bool undefTuple3 = undefTuple2;
                                const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel, true);
                                const Tuple* tuple3 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple3 = true;
                                }
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel, true);
                                    const Tuple* tuple4 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple4 = true;
                                    }
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({U,V,ConstantsManager::getInstance().mapConstant("p")}, _llabel);
                                        if(t->isUnknown()){
                                            printTuple(t);
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else if(t->isUndef()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                        }
                                        t = factory.addNewInternalTuple({U,V,ConstantsManager::getInstance().mapConstant("m")}, _llabel);
                                        if(t->isUnknown()){
                                            printTuple(t);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _input, true);
                    const Tuple* tuple1 = factory.find({V}, _input);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                        const Tuple* tuple2 = factory.find({V}, _trivial);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pobs_elabel_0_1_.getValuesVec({U, V});
                            const std::vector<int>* tuplesU = &uobs_elabel_0_1_.getValuesVec({U, V});
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
                                    int S = (*tuple3)[2];
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({U,V,S}, _llabel);
                                    if(t->isUnknown()){
                                        printTuple(t);
                                        if(undefTuple3){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple3){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
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
            tuples = &pactive_.getValuesVec({});
            const std::vector<int>* tuplesU = &uactive_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel, true);
                    const Tuple* tuple1 = factory.find({V, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel, true);
                        const Tuple* tuple2 = factory.find({V, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({V}, _trivial, true);
                            const Tuple* tuple3 = factory.find({V}, _trivial);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({V,ConstantsManager::getInstance().mapConstant("p")}, _vlabel);
                                if(t->isUnknown()){
                                    printTuple(t);
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else if(t->isUndef()){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                }
                                t = factory.addNewInternalTuple({V,ConstantsManager::getInstance().mapConstant("m")}, _vlabel);
                                if(t->isUnknown()){
                                    printTuple(t);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pactive_.getValuesVec({});
            const std::vector<int>* tuplesU = &uactive_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                    const Tuple* tuple1 = factory.find({V}, _trivial);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pedge_1_.getValuesVec({V});
                        const std::vector<int>* tuplesU = &uedge_1_.getValuesVec({V});
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
                                int U = (*tuple2)[0];
                                bool undefTuple3 = undefTuple2;
                                const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel, true);
                                const Tuple* tuple3 = factory.find({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple3 = true;
                                }
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel, true);
                                    const Tuple* tuple4 = factory.find({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple4 = true;
                                    }
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({U,ConstantsManager::getInstance().mapConstant("p")}, _vlabel);
                                        if(t->isUnknown()){
                                            printTuple(t);
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else if(t->isUndef()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                        }
                                        t = factory.addNewInternalTuple({U,ConstantsManager::getInstance().mapConstant("m")}, _vlabel);
                                        if(t->isUnknown()){
                                            printTuple(t);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pvertex_.getValuesVec({});
            const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _input, true);
                    const Tuple* tuple1 = factory.find({V}, _input);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                        const Tuple* tuple2 = factory.find({V}, _trivial);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pobs_vlabel_0_.getValuesVec({V});
                            const std::vector<int>* tuplesU = &uobs_vlabel_0_.getValuesVec({V});
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
                                    int S = (*tuple3)[1];
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({V,S}, _vlabel);
                                    if(t->isUnknown()){
                                        printTuple(t);
                                        if(undefTuple3){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple3){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
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
            tuples = &pedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _input, true);
                    const Tuple* tuple1 = factory.find({V}, _input);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                        const Tuple* tuple2 = factory.find({V}, _trivial);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pobs_vlabel_0_.getValuesVec({U});
                            const std::vector<int>* tuplesU = &uobs_vlabel_0_.getValuesVec({U});
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
                                    int S = (*tuple3)[1];
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({U,S}, _vlabel);
                                    if(t->isUnknown()){
                                        printTuple(t);
                                        if(undefTuple3){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple3){
                                            factory.removeFromCollisionsList(t->getId());
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertTrue(insertResult);
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
            const Tuple* tuple0 = factory.find({}, _singleton);
            if(tuple0 != NULL && tuple0->isUndef()) undefTuple0 = true;
            if(tuple0!= NULL){
                //Rule is firing 
                Tuple* t;
                std::pair<const TupleLight *, bool> insertResult;
                t = factory.addNewInternalTuple({}, _bot);
                if(t->isUnknown()){
                    printTuple(t);
                    if(undefTuple0){
                        insertResult = t->setStatus(TruthStatus::Undef);
                        insertUndef(insertResult);
                    }
                    else{
                        insertResult = t->setStatus(TruthStatus::True);
                        insertTrue(insertResult);
                    }
                }
                else if(t->isUndef()){
                    if(!undefTuple0){
                        factory.removeFromCollisionsList(t->getId());
                        insertResult = t->setStatus(TruthStatus::True);
                        insertTrue(insertResult);
                    }
                }
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const Tuple* tuple0 = factory.find({}, _bot);
            if(tuple0 != NULL && tuple0->isUndef()) undefTuple0 = true;
            if(tuple0!= NULL){
                bool undefTuple1 = undefTuple0;
                const std::vector<int>* tuples;
                tuples = &pedge_.getValuesVec({});
                const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                        int U = (*tuple1)[0];
                        int V = (*tuple1)[1];
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel, true);
                        const Tuple* tuple2 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel, true);
                            const Tuple* tuple3 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const Tuple negativeTuple = Tuple({V}, _input, true);
                                const Tuple* tuple4 = factory.find({V}, _input);
                                if(tuple4 == NULL){
                                    tuple4 = &negativeTuple;
                                }
                                else{
                                    if(tuple4->isTrue())    tuple4= NULL;
                                    else undefTuple4 = true;
                                }
                                if(tuple4!= NULL){
                                    bool undefTuple5 = undefTuple4;
                                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                    const Tuple* tuple5 = factory.find({V}, _trivial);
                                    if(tuple5 == NULL){
                                        tuple5 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple5->isTrue())    tuple5= NULL;
                                        else undefTuple5 = true;
                                    }
                                    if(tuple5!= NULL){
                                        bool undefTuple6 = undefTuple5;
                                        const std::vector<int>* tuples;
                                        tuples = &psign_.getValuesVec({});
                                        const std::vector<int>* tuplesU = &usign_.getValuesVec({});
                                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                            const Tuple * tuple6 = NULL;
                                            if(i < tuples->size()){
                                                tuple6 = factory.getTupleFromInternalID(tuples->at(i));
                                            }
                                            else {
                                                tuple6 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                                undefTuple6 = true;
                                            }
                                            if(tuple6!= NULL){
                                                int S = (*tuple6)[0];
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({U,V,S}, _llabel);
                                                if(t->isUnknown()){
                                                    printTuple(t);
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple6){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple6){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
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
            tuples = &pllabel_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("m")});
            const std::vector<int>* tuplesU = &ullabel_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("m")});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({V}, _active);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel, true);
                        const Tuple* tuple2 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({V}, _input, true);
                            const Tuple* tuple3 = factory.find({V}, _input);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                const Tuple* tuple4 = factory.find({V}, _trivial);
                                if(tuple4 == NULL){
                                    tuple4 = &negativeTuple;
                                }
                                else{
                                    if(tuple4->isTrue())    tuple4= NULL;
                                    else undefTuple4 = true;
                                }
                                if(tuple4!= NULL){
                                    bool undefTuple5 = undefTuple4;
                                    const std::vector<int>* tuples;
                                    tuples = &pvlabel_0_.getValuesVec({U});
                                    const std::vector<int>* tuplesU = &uvlabel_0_.getValuesVec({U});
                                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                        const Tuple * tuple5 = NULL;
                                        if(i < tuples->size()){
                                            tuple5 = factory.getTupleFromInternalID(tuples->at(i));
                                        }
                                        else {
                                            tuple5 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                            undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            int S = (*tuple5)[1];
                                            bool undefTuple6 = undefTuple5;
                                            const Tuple* tuple6 = factory.find({V, S}, _vlabel);
                                            if(tuple6 != NULL && tuple6->isUndef()) undefTuple6 = true;
                                            if(tuple6!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({U,V}, _oppo);
                                                if(t->isUnknown()){
                                                    printTuple(t);
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple6){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple6){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
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
            tuples = &pllabel_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("p")});
            const std::vector<int>* tuplesU = &ullabel_2_.getValuesVec({ConstantsManager::getInstance().mapConstant("p")});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({V}, _active);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel, true);
                        const Tuple* tuple2 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({V}, _input, true);
                            const Tuple* tuple3 = factory.find({V}, _input);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                const Tuple* tuple4 = factory.find({V}, _trivial);
                                if(tuple4 == NULL){
                                    tuple4 = &negativeTuple;
                                }
                                else{
                                    if(tuple4->isTrue())    tuple4= NULL;
                                    else undefTuple4 = true;
                                }
                                if(tuple4!= NULL){
                                    bool undefTuple5 = undefTuple4;
                                    const std::vector<int>* tuples;
                                    tuples = &pvlabel_0_.getValuesVec({U});
                                    const std::vector<int>* tuplesU = &uvlabel_0_.getValuesVec({U});
                                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                        const Tuple * tuple5 = NULL;
                                        if(i < tuples->size()){
                                            tuple5 = factory.getTupleFromInternalID(tuples->at(i));
                                        }
                                        else {
                                            tuple5 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                            undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            int S = (*tuple5)[1];
                                            bool undefTuple6 = undefTuple5;
                                            const std::vector<int>* tuples;
                                            tuples = &pvlabel_0_.getValuesVec({V});
                                            const std::vector<int>* tuplesU = &uvlabel_0_.getValuesVec({V});
                                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                                const Tuple * tuple6 = NULL;
                                                if(i < tuples->size()){
                                                    tuple6 = factory.getTupleFromInternalID(tuples->at(i));
                                                }
                                                else {
                                                    tuple6 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                                    undefTuple6 = true;
                                                }
                                                if(tuple6!= NULL){
                                                    int T = (*tuple6)[1];
                                                    if(S!=T){
                                                        //Rule is firing 
                                                        Tuple* t;
                                                        std::pair<const TupleLight *, bool> insertResult;
                                                        t = factory.addNewInternalTuple({U,V}, _oppo);
                                                        if(t->isUnknown()){
                                                            printTuple(t);
                                                            generatedStack.push_back(t->getId());
                                                            if(undefTuple6){
                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                                insertUndef(insertResult);
                                                            }
                                                            else{
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
                                                            }
                                                        }
                                                        else if(t->isUndef()){
                                                            if(!undefTuple6){
                                                                factory.removeFromCollisionsList(t->getId());
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
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
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const Tuple* tuple0 = factory.find({}, _bot);
            if(tuple0 != NULL && tuple0->isUndef()) undefTuple0 = true;
            if(tuple0!= NULL){
                bool undefTuple1 = undefTuple0;
                const std::vector<int>* tuples;
                tuples = &pvertex_.getValuesVec({});
                const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                        int V = (*tuple1)[0];
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel, true);
                        const Tuple* tuple2 = factory.find({V, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({V, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel, true);
                            const Tuple* tuple3 = factory.find({V, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const Tuple negativeTuple = Tuple({V}, _input, true);
                                const Tuple* tuple4 = factory.find({V}, _input);
                                if(tuple4 == NULL){
                                    tuple4 = &negativeTuple;
                                }
                                else{
                                    if(tuple4->isTrue())    tuple4= NULL;
                                    else undefTuple4 = true;
                                }
                                if(tuple4!= NULL){
                                    bool undefTuple5 = undefTuple4;
                                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                    const Tuple* tuple5 = factory.find({V}, _trivial);
                                    if(tuple5 == NULL){
                                        tuple5 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple5->isTrue())    tuple5= NULL;
                                        else undefTuple5 = true;
                                    }
                                    if(tuple5!= NULL){
                                        bool undefTuple6 = undefTuple5;
                                        const std::vector<int>* tuples;
                                        tuples = &psign_.getValuesVec({});
                                        const std::vector<int>* tuplesU = &usign_.getValuesVec({});
                                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                            const Tuple * tuple6 = NULL;
                                            if(i < tuples->size()){
                                                tuple6 = factory.getTupleFromInternalID(tuples->at(i));
                                            }
                                            else {
                                                tuple6 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                                undefTuple6 = true;
                                            }
                                            if(tuple6!= NULL){
                                                int S = (*tuple6)[0];
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({V,S}, _vlabel);
                                                if(t->isUnknown()){
                                                    printTuple(t);
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple6){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple6){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
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
            const Tuple* tuple0 = factory.find({}, _bot);
            if(tuple0 != NULL && tuple0->isUndef()) undefTuple0 = true;
            if(tuple0!= NULL){
                bool undefTuple1 = undefTuple0;
                const std::vector<int>* tuples;
                tuples = &pedge_.getValuesVec({});
                const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                        int U = (*tuple1)[0];
                        int V = (*tuple1)[1];
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel, true);
                        const Tuple* tuple2 = factory.find({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel, true);
                            const Tuple* tuple3 = factory.find({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const Tuple negativeTuple = Tuple({V}, _input, true);
                                const Tuple* tuple4 = factory.find({V}, _input);
                                if(tuple4 == NULL){
                                    tuple4 = &negativeTuple;
                                }
                                else{
                                    if(tuple4->isTrue())    tuple4= NULL;
                                    else undefTuple4 = true;
                                }
                                if(tuple4!= NULL){
                                    bool undefTuple5 = undefTuple4;
                                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                    const Tuple* tuple5 = factory.find({V}, _trivial);
                                    if(tuple5 == NULL){
                                        tuple5 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple5->isTrue())    tuple5= NULL;
                                        else undefTuple5 = true;
                                    }
                                    if(tuple5!= NULL){
                                        bool undefTuple6 = undefTuple5;
                                        const std::vector<int>* tuples;
                                        tuples = &psign_.getValuesVec({});
                                        const std::vector<int>* tuplesU = &usign_.getValuesVec({});
                                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                            const Tuple * tuple6 = NULL;
                                            if(i < tuples->size()){
                                                tuple6 = factory.getTupleFromInternalID(tuples->at(i));
                                            }
                                            else {
                                                tuple6 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                                undefTuple6 = true;
                                            }
                                            if(tuple6!= NULL){
                                                int S = (*tuple6)[0];
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({U,S}, _vlabel);
                                                if(t->isUnknown()){
                                                    printTuple(t);
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple6){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple6){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
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
            tuples = &pactive_.getValuesVec({});
            const std::vector<int>* tuplesU = &uactive_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pcoppo_1_.getValuesVec({V});
                    const std::vector<int>* tuplesU = &ucoppo_1_.getValuesVec({V});
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
                            int U = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({U, V}, _last);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({}, _bot);
                                if(t->isUnknown()){
                                    printTuple(t);
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
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
            tuples = &poppo_.getValuesVec({});
            const std::vector<int>* tuplesU = &uoppo_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({U, V}, _first);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({U,V}, _coppo);
                        if(t->isUnknown()){
                            printTuple(t);
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &poppo_.getValuesVec({});
            const std::vector<int>* tuplesU = &uoppo_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pcoppo_1_.getValuesVec({V});
                    const std::vector<int>* tuplesU = &ucoppo_1_.getValuesVec({V});
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
                            int W = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({W, U, V}, _ntedge);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({U,V}, _coppo);
                                if(t->isUnknown()){
                                    printTuple(t);
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
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
            if(literalName == _bot){
                {
                    bool undefTuple0= false;
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pedge_.getValuesVec({});
                    const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                            int U = (*tuple1)[0];
                            int V = (*tuple1)[1];
                            bool undefTuple2 = undefTuple1;
                            const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel, true);
                            const Tuple* tuple2 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel);
                            if(tuple2 == NULL){
                                tuple2 = &negativeTuple;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel, true);
                                const Tuple* tuple3 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple3 = true;
                                }
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple negativeTuple = Tuple({V}, _input, true);
                                    const Tuple* tuple4 = factory.find({V}, _input);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple4 = true;
                                    }
                                    if(tuple4!= NULL){
                                        bool undefTuple5 = undefTuple4;
                                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                        const Tuple* tuple5 = factory.find({V}, _trivial);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            bool undefTuple6 = undefTuple5;
                                            const std::vector<int>* tuples;
                                            tuples = &psign_.getValuesVec({});
                                            const std::vector<int>* tuplesU = &usign_.getValuesVec({});
                                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                                const Tuple * tuple6 = NULL;
                                                if(i < tuples->size()){
                                                    tuple6 = factory.getTupleFromInternalID(tuples->at(i));
                                                }
                                                else {
                                                    tuple6 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                                    undefTuple6 = true;
                                                }
                                                if(tuple6!= NULL){
                                                    int S = (*tuple6)[0];
                                                    //Rule is firing 
                                                    Tuple* t;
                                                    std::pair<const TupleLight *, bool> insertResult;
                                                    t = factory.addNewInternalTuple({U,V,S}, _llabel);
                                                    if(t->isUnknown()){
                                                        printTuple(t);
                                                        generatedStack.push_back(t->getId());
                                                        if(undefTuple6){
                                                            insertResult = t->setStatus(TruthStatus::Undef);
                                                            insertUndef(insertResult);
                                                        }
                                                        else{
                                                            insertResult = t->setStatus(TruthStatus::True);
                                                            insertTrue(insertResult);
                                                        }
                                                    }
                                                    else if(t->isUndef()){
                                                        if(!undefTuple6){
                                                            factory.removeFromCollisionsList(t->getId());
                                                            insertResult = t->setStatus(TruthStatus::True);
                                                            insertTrue(insertResult);
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
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pvertex_.getValuesVec({});
                    const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                            int V = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple negativeTuple = Tuple({V, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel, true);
                            const Tuple* tuple2 = factory.find({V, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel);
                            if(tuple2 == NULL){
                                tuple2 = &negativeTuple;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const Tuple negativeTuple = Tuple({V, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel, true);
                                const Tuple* tuple3 = factory.find({V, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple3 = true;
                                }
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple negativeTuple = Tuple({V}, _input, true);
                                    const Tuple* tuple4 = factory.find({V}, _input);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple4 = true;
                                    }
                                    if(tuple4!= NULL){
                                        bool undefTuple5 = undefTuple4;
                                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                        const Tuple* tuple5 = factory.find({V}, _trivial);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            bool undefTuple6 = undefTuple5;
                                            const std::vector<int>* tuples;
                                            tuples = &psign_.getValuesVec({});
                                            const std::vector<int>* tuplesU = &usign_.getValuesVec({});
                                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                                const Tuple * tuple6 = NULL;
                                                if(i < tuples->size()){
                                                    tuple6 = factory.getTupleFromInternalID(tuples->at(i));
                                                }
                                                else {
                                                    tuple6 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                                    undefTuple6 = true;
                                                }
                                                if(tuple6!= NULL){
                                                    int S = (*tuple6)[0];
                                                    //Rule is firing 
                                                    Tuple* t;
                                                    std::pair<const TupleLight *, bool> insertResult;
                                                    t = factory.addNewInternalTuple({V,S}, _vlabel);
                                                    if(t->isUnknown()){
                                                        printTuple(t);
                                                        generatedStack.push_back(t->getId());
                                                        if(undefTuple6){
                                                            insertResult = t->setStatus(TruthStatus::Undef);
                                                            insertUndef(insertResult);
                                                        }
                                                        else{
                                                            insertResult = t->setStatus(TruthStatus::True);
                                                            insertTrue(insertResult);
                                                        }
                                                    }
                                                    else if(t->isUndef()){
                                                        if(!undefTuple6){
                                                            factory.removeFromCollisionsList(t->getId());
                                                            insertResult = t->setStatus(TruthStatus::True);
                                                            insertTrue(insertResult);
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
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pedge_.getValuesVec({});
                    const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                            int U = (*tuple1)[0];
                            int V = (*tuple1)[1];
                            bool undefTuple2 = undefTuple1;
                            const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel, true);
                            const Tuple* tuple2 = factory.find({U, ConstantsManager::getInstance().mapConstant("m")}, _obs_vlabel);
                            if(tuple2 == NULL){
                                tuple2 = &negativeTuple;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const Tuple negativeTuple = Tuple({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel, true);
                                const Tuple* tuple3 = factory.find({U, ConstantsManager::getInstance().mapConstant("p")}, _obs_vlabel);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple3 = true;
                                }
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple negativeTuple = Tuple({V}, _input, true);
                                    const Tuple* tuple4 = factory.find({V}, _input);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple4 = true;
                                    }
                                    if(tuple4!= NULL){
                                        bool undefTuple5 = undefTuple4;
                                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                        const Tuple* tuple5 = factory.find({V}, _trivial);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            bool undefTuple6 = undefTuple5;
                                            const std::vector<int>* tuples;
                                            tuples = &psign_.getValuesVec({});
                                            const std::vector<int>* tuplesU = &usign_.getValuesVec({});
                                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                                const Tuple * tuple6 = NULL;
                                                if(i < tuples->size()){
                                                    tuple6 = factory.getTupleFromInternalID(tuples->at(i));
                                                }
                                                else {
                                                    tuple6 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                                    undefTuple6 = true;
                                                }
                                                if(tuple6!= NULL){
                                                    int S = (*tuple6)[0];
                                                    //Rule is firing 
                                                    Tuple* t;
                                                    std::pair<const TupleLight *, bool> insertResult;
                                                    t = factory.addNewInternalTuple({U,S}, _vlabel);
                                                    if(t->isUnknown()){
                                                        printTuple(t);
                                                        generatedStack.push_back(t->getId());
                                                        if(undefTuple6){
                                                            insertResult = t->setStatus(TruthStatus::Undef);
                                                            insertUndef(insertResult);
                                                        }
                                                        else{
                                                            insertResult = t->setStatus(TruthStatus::True);
                                                            insertTrue(insertResult);
                                                        }
                                                    }
                                                    else if(t->isUndef()){
                                                        if(!undefTuple6){
                                                            factory.removeFromCollisionsList(t->getId());
                                                            insertResult = t->setStatus(TruthStatus::True);
                                                            insertTrue(insertResult);
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
            }
            if(literalName == _llabel){
                {
                    bool undefTuple0= false;
                    int V = (*recursiveTuple)[1];
                    int U = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({V}, _active);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel, true);
                        const Tuple* tuple2 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({V}, _input, true);
                            const Tuple* tuple3 = factory.find({V}, _input);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                const Tuple* tuple4 = factory.find({V}, _trivial);
                                if(tuple4 == NULL){
                                    tuple4 = &negativeTuple;
                                }
                                else{
                                    if(tuple4->isTrue())    tuple4= NULL;
                                    else undefTuple4 = true;
                                }
                                if(tuple4!= NULL){
                                    bool undefTuple5 = undefTuple4;
                                    const std::vector<int>* tuples;
                                    tuples = &pvlabel_0_.getValuesVec({U});
                                    const std::vector<int>* tuplesU = &uvlabel_0_.getValuesVec({U});
                                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                        const Tuple * tuple5 = NULL;
                                        if(i < tuples->size()){
                                            tuple5 = factory.getTupleFromInternalID(tuples->at(i));
                                        }
                                        else {
                                            tuple5 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                            undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            int S = (*tuple5)[1];
                                            bool undefTuple6 = undefTuple5;
                                            const Tuple* tuple6 = factory.find({V, S}, _vlabel);
                                            if(tuple6 != NULL && tuple6->isUndef()) undefTuple6 = true;
                                            if(tuple6!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({U,V}, _oppo);
                                                if(t->isUnknown()){
                                                    printTuple(t);
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple6){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple6){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
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
                    int V = (*recursiveTuple)[1];
                    int U = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({V}, _active);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel, true);
                        const Tuple* tuple2 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({V}, _input, true);
                            const Tuple* tuple3 = factory.find({V}, _input);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                const Tuple* tuple4 = factory.find({V}, _trivial);
                                if(tuple4 == NULL){
                                    tuple4 = &negativeTuple;
                                }
                                else{
                                    if(tuple4->isTrue())    tuple4= NULL;
                                    else undefTuple4 = true;
                                }
                                if(tuple4!= NULL){
                                    bool undefTuple5 = undefTuple4;
                                    const std::vector<int>* tuples;
                                    tuples = &pvlabel_0_.getValuesVec({U});
                                    const std::vector<int>* tuplesU = &uvlabel_0_.getValuesVec({U});
                                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                        const Tuple * tuple5 = NULL;
                                        if(i < tuples->size()){
                                            tuple5 = factory.getTupleFromInternalID(tuples->at(i));
                                        }
                                        else {
                                            tuple5 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                            undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            int S = (*tuple5)[1];
                                            bool undefTuple6 = undefTuple5;
                                            const std::vector<int>* tuples;
                                            tuples = &pvlabel_0_.getValuesVec({V});
                                            const std::vector<int>* tuplesU = &uvlabel_0_.getValuesVec({V});
                                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                                const Tuple * tuple6 = NULL;
                                                if(i < tuples->size()){
                                                    tuple6 = factory.getTupleFromInternalID(tuples->at(i));
                                                }
                                                else {
                                                    tuple6 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                                    undefTuple6 = true;
                                                }
                                                if(tuple6!= NULL){
                                                    int T = (*tuple6)[1];
                                                    if(S!=T){
                                                        //Rule is firing 
                                                        Tuple* t;
                                                        std::pair<const TupleLight *, bool> insertResult;
                                                        t = factory.addNewInternalTuple({U,V}, _oppo);
                                                        if(t->isUnknown()){
                                                            printTuple(t);
                                                            generatedStack.push_back(t->getId());
                                                            if(undefTuple6){
                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                                insertUndef(insertResult);
                                                            }
                                                            else{
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
                                                            }
                                                        }
                                                        else if(t->isUndef()){
                                                            if(!undefTuple6){
                                                                factory.removeFromCollisionsList(t->getId());
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
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
            }
            if(literalName == _vlabel){
                {
                    bool undefTuple0= false;
                    int S = (*recursiveTuple)[1];
                    int U = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pllabel_0_2_.getValuesVec({U, ConstantsManager::getInstance().mapConstant("m")});
                    const std::vector<int>* tuplesU = &ullabel_0_2_.getValuesVec({U, ConstantsManager::getInstance().mapConstant("m")});
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
                            int V = (*tuple1)[1];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({V, S}, _vlabel);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const Tuple* tuple3 = factory.find({V}, _active);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel, true);
                                    const Tuple* tuple4 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple4 = true;
                                    }
                                    if(tuple4!= NULL){
                                        bool undefTuple5 = undefTuple4;
                                        const Tuple negativeTuple = Tuple({V}, _input, true);
                                        const Tuple* tuple5 = factory.find({V}, _input);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            bool undefTuple6 = undefTuple5;
                                            const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                            const Tuple* tuple6 = factory.find({V}, _trivial);
                                            if(tuple6 == NULL){
                                                tuple6 = &negativeTuple;
                                            }
                                            else{
                                                if(tuple6->isTrue())    tuple6= NULL;
                                                else undefTuple6 = true;
                                            }
                                            if(tuple6!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({U,V}, _oppo);
                                                if(t->isUnknown()){
                                                    printTuple(t);
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple6){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple6){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
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
                    int S = (*recursiveTuple)[1];
                    int V = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({V}, _active);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _input, true);
                        const Tuple* tuple2 = factory.find({V}, _input);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({V}, _trivial, true);
                            const Tuple* tuple3 = factory.find({V}, _trivial);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const std::vector<int>* tuples;
                                tuples = &pllabel_1_2_.getValuesVec({V, ConstantsManager::getInstance().mapConstant("m")});
                                const std::vector<int>* tuplesU = &ullabel_1_2_.getValuesVec({V, ConstantsManager::getInstance().mapConstant("m")});
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
                                        int U = (*tuple4)[0];
                                        bool undefTuple5 = undefTuple4;
                                        const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel, true);
                                        const Tuple* tuple5 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("p")}, _obs_elabel);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            bool undefTuple6 = undefTuple5;
                                            const Tuple* tuple6 = factory.find({U, S}, _vlabel);
                                            if(tuple6 != NULL && tuple6->isUndef()) undefTuple6 = true;
                                            if(tuple6!= NULL){
                                                //Rule is firing 
                                                Tuple* t;
                                                std::pair<const TupleLight *, bool> insertResult;
                                                t = factory.addNewInternalTuple({U,V}, _oppo);
                                                if(t->isUnknown()){
                                                    printTuple(t);
                                                    generatedStack.push_back(t->getId());
                                                    if(undefTuple6){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertUndef(insertResult);
                                                    }
                                                    else{
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple6){
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
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
                    int S = (*recursiveTuple)[1];
                    int U = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pllabel_0_2_.getValuesVec({U, ConstantsManager::getInstance().mapConstant("p")});
                    const std::vector<int>* tuplesU = &ullabel_0_2_.getValuesVec({U, ConstantsManager::getInstance().mapConstant("p")});
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
                            int V = (*tuple1)[1];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({V}, _active);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel, true);
                                const Tuple* tuple3 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple3 = true;
                                }
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple negativeTuple = Tuple({V}, _input, true);
                                    const Tuple* tuple4 = factory.find({V}, _input);
                                    if(tuple4 == NULL){
                                        tuple4 = &negativeTuple;
                                    }
                                    else{
                                        if(tuple4->isTrue())    tuple4= NULL;
                                        else undefTuple4 = true;
                                    }
                                    if(tuple4!= NULL){
                                        bool undefTuple5 = undefTuple4;
                                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                        const Tuple* tuple5 = factory.find({V}, _trivial);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            bool undefTuple6 = undefTuple5;
                                            const std::vector<int>* tuples;
                                            tuples = &pvlabel_0_.getValuesVec({V});
                                            const std::vector<int>* tuplesU = &uvlabel_0_.getValuesVec({V});
                                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                                const Tuple * tuple6 = NULL;
                                                if(i < tuples->size()){
                                                    tuple6 = factory.getTupleFromInternalID(tuples->at(i));
                                                }
                                                else {
                                                    tuple6 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                                    undefTuple6 = true;
                                                }
                                                if(tuple6!= NULL){
                                                    int T = (*tuple6)[1];
                                                    if(S!=T){
                                                        //Rule is firing 
                                                        Tuple* t;
                                                        std::pair<const TupleLight *, bool> insertResult;
                                                        t = factory.addNewInternalTuple({U,V}, _oppo);
                                                        if(t->isUnknown()){
                                                            printTuple(t);
                                                            generatedStack.push_back(t->getId());
                                                            if(undefTuple6){
                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                                insertUndef(insertResult);
                                                            }
                                                            else{
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
                                                            }
                                                        }
                                                        else if(t->isUndef()){
                                                            if(!undefTuple6){
                                                                factory.removeFromCollisionsList(t->getId());
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
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
                    int T = (*recursiveTuple)[1];
                    int V = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({V}, _active);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _input, true);
                        const Tuple* tuple2 = factory.find({V}, _input);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple negativeTuple = Tuple({V}, _trivial, true);
                            const Tuple* tuple3 = factory.find({V}, _trivial);
                            if(tuple3 == NULL){
                                tuple3 = &negativeTuple;
                            }
                            else{
                                if(tuple3->isTrue())    tuple3= NULL;
                                else undefTuple3 = true;
                            }
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const std::vector<int>* tuples;
                                tuples = &pllabel_1_2_.getValuesVec({V, ConstantsManager::getInstance().mapConstant("p")});
                                const std::vector<int>* tuplesU = &ullabel_1_2_.getValuesVec({V, ConstantsManager::getInstance().mapConstant("p")});
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
                                        int U = (*tuple4)[0];
                                        bool undefTuple5 = undefTuple4;
                                        const Tuple negativeTuple = Tuple({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel, true);
                                        const Tuple* tuple5 = factory.find({U, V, ConstantsManager::getInstance().mapConstant("m")}, _obs_elabel);
                                        if(tuple5 == NULL){
                                            tuple5 = &negativeTuple;
                                        }
                                        else{
                                            if(tuple5->isTrue())    tuple5= NULL;
                                            else undefTuple5 = true;
                                        }
                                        if(tuple5!= NULL){
                                            bool undefTuple6 = undefTuple5;
                                            const std::vector<int>* tuples;
                                            tuples = &pvlabel_0_.getValuesVec({U});
                                            const std::vector<int>* tuplesU = &uvlabel_0_.getValuesVec({U});
                                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                                const Tuple * tuple6 = NULL;
                                                if(i < tuples->size()){
                                                    tuple6 = factory.getTupleFromInternalID(tuples->at(i));
                                                }
                                                else {
                                                    tuple6 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                                    undefTuple6 = true;
                                                }
                                                if(tuple6!= NULL){
                                                    int S = (*tuple6)[1];
                                                    if(S!=T){
                                                        //Rule is firing 
                                                        Tuple* t;
                                                        std::pair<const TupleLight *, bool> insertResult;
                                                        t = factory.addNewInternalTuple({U,V}, _oppo);
                                                        if(t->isUnknown()){
                                                            printTuple(t);
                                                            generatedStack.push_back(t->getId());
                                                            if(undefTuple6){
                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                                insertUndef(insertResult);
                                                            }
                                                            else{
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
                                                            }
                                                        }
                                                        else if(t->isUndef()){
                                                            if(!undefTuple6){
                                                                factory.removeFromCollisionsList(t->getId());
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
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
            }
            if(literalName == _coppo){
                {
                    bool undefTuple0= false;
                    int V = (*recursiveTuple)[1];
                    int U = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({U, V}, _last);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple* tuple2 = factory.find({V}, _active);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                        if(tuple2!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({}, _bot);
                            if(t->isUnknown()){
                                printTuple(t);
                                generatedStack.push_back(t->getId());
                                if(undefTuple2){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertUndef(insertResult);
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple2){
                                    factory.removeFromCollisionsList(t->getId());
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                            }
                        }//close par
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int V = (*recursiveTuple)[1];
                    int W = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &poppo_1_.getValuesVec({V});
                    const std::vector<int>* tuplesU = &uoppo_1_.getValuesVec({V});
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
                            int U = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({W, U, V}, _ntedge);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({U,V}, _coppo);
                                if(t->isUnknown()){
                                    printTuple(t);
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
            if(literalName == _oppo){
                {
                    bool undefTuple0= false;
                    int V = (*recursiveTuple)[1];
                    int U = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({U, V}, _first);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({U,V}, _coppo);
                        if(t->isUnknown()){
                            printTuple(t);
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertUndef(insertResult);
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                factory.removeFromCollisionsList(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }
                    }//close par
                }//close par
                {
                    bool undefTuple0= false;
                    int V = (*recursiveTuple)[1];
                    int U = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pcoppo_1_.getValuesVec({V});
                    const std::vector<int>* tuplesU = &ucoppo_1_.getValuesVec({V});
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
                            int W = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({W, U, V}, _ntedge);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({U,V}, _coppo);
                                if(t->isUnknown()){
                                    printTuple(t);
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertUndef(insertResult);
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple2){
                                        factory.removeFromCollisionsList(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }
        }
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &plast_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ulast_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        plast_.clear();
        ulast_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pobs_elabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uobs_elabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pobs_elabel_.clear();
        pobs_elabel_0_1_.clear();
        uobs_elabel_.clear();
        uobs_elabel_0_1_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pbot_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ubot_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pbot_.clear();
        ubot_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pllabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ullabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pllabel_.clear();
        pllabel_0_2_.clear();
        pllabel_1_2_.clear();
        pllabel_2_.clear();
        ullabel_.clear();
        ullabel_0_2_.clear();
        ullabel_1_2_.clear();
        ullabel_2_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &psign_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &usign_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        psign_.clear();
        usign_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pvlabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uvlabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pvlabel_.clear();
        pvlabel_0_.clear();
        uvlabel_.clear();
        uvlabel_0_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &psingleton_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &usingleton_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        psingleton_.clear();
        usingleton_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pfirst_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ufirst_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pfirst_.clear();
        ufirst_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &poppo_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uoppo_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        poppo_.clear();
        poppo_1_.clear();
        uoppo_.clear();
        uoppo_1_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pcoppo_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ucoppo_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pcoppo_.clear();
        pcoppo_1_.clear();
        ucoppo_.clear();
        ucoppo_1_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pntedge_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &untedge_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pntedge_.clear();
        untedge_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pactive_.getValuesVec({});
            const std::vector<int>* tuplesU = &uactive_.getValuesVec({});
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
                    int W = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({W}, _trivial, true);
                    const Tuple* tuple1 = factory.find({W}, _trivial);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const std::vector<int>* tuples;
                        tuples = &pactive_.getValuesVec({});
                        const std::vector<int>* tuplesU = &uactive_.getValuesVec({});
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
                                int V = (*tuple2)[0];
                                if(W!=V){
                                    bool undefTuple3 = undefTuple2;
                                    const Tuple* tuple3 = factory.find({W, V}, _reach);
                                    if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                    if(tuple3!= NULL){
                                        if(W!=V){
                                            bool undefTuple4 = undefTuple3;
                                            const Tuple* tuple4 = factory.find({V, W}, _reach);
                                            if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                            if(tuple4!= NULL){
                                                if(W!=V){
                                                    bool undefTuple5 = undefTuple4;
                                                    const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                                    const Tuple* tuple5 = factory.find({V}, _trivial);
                                                    if(tuple5 == NULL){
                                                        tuple5 = &negativeTuple;
                                                    }
                                                    else{
                                                        if(tuple5->isTrue())    tuple5= NULL;
                                                        else undefTuple5 = true;
                                                    }
                                                    if(tuple5!= NULL){
                                                        if(W!=V){
                                                            //Rule is firing 
                                                            Tuple* t;
                                                            std::pair<const TupleLight *, bool> insertResult;
                                                            t = factory.addNewInternalTuple({W,V,ConstantsManager::getInstance().mapConstant("p")}, _mvlabel);
                                                            if(t->isUnknown()){
                                                                printTuple(t);
                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                                insertUndef(insertResult);
                                                            }
                                                            else if(t->isUndef()){
                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                            }
                                                            t = factory.addNewInternalTuple({W,V,ConstantsManager::getInstance().mapConstant("m")}, _mvlabel);
                                                            if(t->isUnknown()){
                                                                printTuple(t);
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
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pedge_.getValuesVec({});
            const std::vector<int>* tuplesU = &uedge_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int V = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({V}, _active);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                        const Tuple* tuple2 = factory.find({V}, _trivial);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pactive_.getValuesVec({});
                            const std::vector<int>* tuplesU = &uactive_.getValuesVec({});
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
                                    int W = (*tuple3)[0];
                                    if(W!=V){
                                        bool undefTuple4 = undefTuple3;
                                        const Tuple* tuple4 = factory.find({W, V}, _reach);
                                        if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                        if(tuple4!= NULL){
                                            if(W!=V){
                                                bool undefTuple5 = undefTuple4;
                                                const Tuple* tuple5 = factory.find({V, W}, _reach);
                                                if(tuple5 != NULL && tuple5->isUndef()) undefTuple5 = true;
                                                if(tuple5!= NULL){
                                                    if(W!=V){
                                                        bool undefTuple6 = undefTuple5;
                                                        const Tuple negativeTuple = Tuple({W}, _trivial, true);
                                                        const Tuple* tuple6 = factory.find({W}, _trivial);
                                                        if(tuple6 == NULL){
                                                            tuple6 = &negativeTuple;
                                                        }
                                                        else{
                                                            if(tuple6->isTrue())    tuple6= NULL;
                                                            else undefTuple6 = true;
                                                        }
                                                        if(tuple6!= NULL){
                                                            if(W!=V){
                                                                //Rule is firing 
                                                                Tuple* t;
                                                                std::pair<const TupleLight *, bool> insertResult;
                                                                t = factory.addNewInternalTuple({W,U,ConstantsManager::getInstance().mapConstant("p")}, _mvlabel);
                                                                if(t->isUnknown()){
                                                                    printTuple(t);
                                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                                    insertUndef(insertResult);
                                                                }
                                                                else if(t->isUndef()){
                                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                                }
                                                                t = factory.addNewInternalTuple({W,U,ConstantsManager::getInstance().mapConstant("m")}, _mvlabel);
                                                                if(t->isUnknown()){
                                                                    printTuple(t);
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
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pobs_vlabel_.getValuesVec({});
            const std::vector<int>* tuplesU = &uobs_vlabel_.getValuesVec({});
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
                    int V = (*tuple0)[0];
                    int S = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({V}, _input, true);
                    const Tuple* tuple1 = factory.find({V}, _input);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple negativeTuple = Tuple({V}, _trivial, true);
                        const Tuple* tuple2 = factory.find({V}, _trivial);
                        if(tuple2 == NULL){
                            tuple2 = &negativeTuple;
                        }
                        else{
                            if(tuple2->isTrue())    tuple2= NULL;
                            else undefTuple2 = true;
                        }
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pvertex_.getValuesVec({});
                            const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                                    int W = (*tuple3)[0];
                                    if(W!=V){
                                        bool undefTuple4 = undefTuple3;
                                        const Tuple negativeTuple = Tuple({W}, _input, true);
                                        const Tuple* tuple4 = factory.find({W}, _input);
                                        if(tuple4 == NULL){
                                            tuple4 = &negativeTuple;
                                        }
                                        else{
                                            if(tuple4->isTrue())    tuple4= NULL;
                                            else undefTuple4 = true;
                                        }
                                        if(tuple4!= NULL){
                                            if(W!=V){
                                                bool undefTuple5 = undefTuple4;
                                                const Tuple negativeTuple = Tuple({W}, _trivial, true);
                                                const Tuple* tuple5 = factory.find({W}, _trivial);
                                                if(tuple5 == NULL){
                                                    tuple5 = &negativeTuple;
                                                }
                                                else{
                                                    if(tuple5->isTrue())    tuple5= NULL;
                                                    else undefTuple5 = true;
                                                }
                                                if(tuple5!= NULL){
                                                    if(W!=V){
                                                        //Rule is firing 
                                                        Tuple* t;
                                                        std::pair<const TupleLight *, bool> insertResult;
                                                        t = factory.addNewInternalTuple({W,V,S}, _mvlabel);
                                                        if(t->isUnknown()){
                                                            printTuple(t);
                                                            if(undefTuple5){
                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                                insertUndef(insertResult);
                                                            }
                                                            else{
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
                                                            }
                                                        }
                                                        else if(t->isUndef()){
                                                            if(!undefTuple5){
                                                                factory.removeFromCollisionsList(t->getId());
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertTrue(insertResult);
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
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pobs_vlabel_.getValuesVec({});
            const std::vector<int>* tuplesU = &uobs_vlabel_.getValuesVec({});
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
                    int U = (*tuple0)[0];
                    int S = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pedge_0_.getValuesVec({U});
                    const std::vector<int>* tuplesU = &uedge_0_.getValuesVec({U});
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
                            int V = (*tuple1)[1];
                            bool undefTuple2 = undefTuple1;
                            const Tuple negativeTuple = Tuple({V}, _input, true);
                            const Tuple* tuple2 = factory.find({V}, _input);
                            if(tuple2 == NULL){
                                tuple2 = &negativeTuple;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                const Tuple* tuple3 = factory.find({V}, _trivial);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                    else undefTuple3 = true;
                                }
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const std::vector<int>* tuples;
                                    tuples = &pvertex_.getValuesVec({});
                                    const std::vector<int>* tuplesU = &uvertex_.getValuesVec({});
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
                                            int W = (*tuple4)[0];
                                            if(W!=V){
                                                bool undefTuple5 = undefTuple4;
                                                const Tuple negativeTuple = Tuple({W}, _input, true);
                                                const Tuple* tuple5 = factory.find({W}, _input);
                                                if(tuple5 == NULL){
                                                    tuple5 = &negativeTuple;
                                                }
                                                else{
                                                    if(tuple5->isTrue())    tuple5= NULL;
                                                    else undefTuple5 = true;
                                                }
                                                if(tuple5!= NULL){
                                                    if(W!=V){
                                                        bool undefTuple6 = undefTuple5;
                                                        const Tuple negativeTuple = Tuple({W}, _trivial, true);
                                                        const Tuple* tuple6 = factory.find({W}, _trivial);
                                                        if(tuple6 == NULL){
                                                            tuple6 = &negativeTuple;
                                                        }
                                                        else{
                                                            if(tuple6->isTrue())    tuple6= NULL;
                                                            else undefTuple6 = true;
                                                        }
                                                        if(tuple6!= NULL){
                                                            if(W!=V){
                                                                //Rule is firing 
                                                                Tuple* t;
                                                                std::pair<const TupleLight *, bool> insertResult;
                                                                t = factory.addNewInternalTuple({W,U,S}, _mvlabel);
                                                                if(t->isUnknown()){
                                                                    printTuple(t);
                                                                    if(undefTuple6){
                                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                                        insertUndef(insertResult);
                                                                    }
                                                                    else{
                                                                        insertResult = t->setStatus(TruthStatus::True);
                                                                        insertTrue(insertResult);
                                                                    }
                                                                }
                                                                else if(t->isUndef()){
                                                                    if(!undefTuple6){
                                                                        factory.removeFromCollisionsList(t->getId());
                                                                        insertResult = t->setStatus(TruthStatus::True);
                                                                        insertTrue(insertResult);
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
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pedge_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uedge_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pedge_.clear();
        pedge_0_.clear();
        pedge_1_.clear();
        uedge_.clear();
        uedge_0_.clear();
        uedge_1_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pobs_vlabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uobs_vlabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pobs_vlabel_.clear();
        pobs_vlabel_0_.clear();
        uobs_vlabel_.clear();
        uobs_vlabel_0_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pvertex_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uvertex_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pvertex_.clear();
        uvertex_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pinput_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uinput_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pinput_.clear();
        uinput_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pmvlabel_.getValuesVec({});
            const std::vector<int>* tuplesU = &umvlabel_.getValuesVec({});
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
                    int W = (*tuple0)[0];
                    int U = (*tuple0)[1];
                    int S = (*tuple0)[2];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({W}, _trivial, true);
                    const Tuple* tuple1 = factory.find({W}, _trivial);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple* tuple2 = factory.find({W}, _active);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pmllabel_0_1_3_.getValuesVec({W, U, S});
                            const std::vector<int>* tuplesU = &umllabel_0_1_3_.getValuesVec({W, U, S});
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
                                    int V = (*tuple3)[2];
                                    if(W!=V){
                                        bool undefTuple4 = undefTuple3;
                                        const Tuple* tuple4 = factory.find({W, V}, _reach);
                                        if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                        if(tuple4!= NULL){
                                            if(W!=V){
                                                bool undefTuple5 = undefTuple4;
                                                const Tuple* tuple5 = factory.find({V, W}, _reach);
                                                if(tuple5 != NULL && tuple5->isUndef()) undefTuple5 = true;
                                                if(tuple5!= NULL){
                                                    if(W!=V){
                                                        bool undefTuple6 = undefTuple5;
                                                        const Tuple* tuple6 = factory.find({V}, _active);
                                                        if(tuple6 != NULL && tuple6->isUndef()) undefTuple6 = true;
                                                        if(tuple6!= NULL){
                                                            if(W!=V){
                                                                bool undefTuple7 = undefTuple6;
                                                                const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                                                const Tuple* tuple7 = factory.find({V}, _trivial);
                                                                if(tuple7 == NULL){
                                                                    tuple7 = &negativeTuple;
                                                                }
                                                                else{
                                                                    if(tuple7->isTrue())    tuple7= NULL;
                                                                    else undefTuple7 = true;
                                                                }
                                                                if(tuple7!= NULL){
                                                                    if(W!=V){
                                                                        //Rule is firing 
                                                                        Tuple* t;
                                                                        std::pair<const TupleLight *, bool> insertResult;
                                                                        t = factory.addNewInternalTuple({W,V,ConstantsManager::getInstance().mapConstant("p")}, _minfl);
                                                                        if(t->isUnknown()){
                                                                            printTuple(t);
                                                                            if(undefTuple7){
                                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                                                insertUndef(insertResult);
                                                                            }
                                                                            else{
                                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                                insertTrue(insertResult);
                                                                            }
                                                                        }
                                                                        else if(t->isUndef()){
                                                                            if(!undefTuple7){
                                                                                factory.removeFromCollisionsList(t->getId());
                                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                                insertTrue(insertResult);
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
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pmvlabel_.getValuesVec({});
            const std::vector<int>* tuplesU = &umvlabel_.getValuesVec({});
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
                    int W = (*tuple0)[0];
                    int U = (*tuple0)[1];
                    int S = (*tuple0)[2];
                    bool undefTuple1 = undefTuple0;
                    const Tuple negativeTuple = Tuple({W}, _trivial, true);
                    const Tuple* tuple1 = factory.find({W}, _trivial);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple* tuple2 = factory.find({W}, _active);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const std::vector<int>* tuples;
                            tuples = &pmllabel_0_1_.getValuesVec({W, U});
                            const std::vector<int>* tuplesU = &umllabel_0_1_.getValuesVec({W, U});
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
                                    int V = (*tuple3)[2];
                                    int T = (*tuple3)[3];
                                    if(W!=V){
                                        if(S!=T){
                                            bool undefTuple4 = undefTuple3;
                                            const Tuple* tuple4 = factory.find({W, V}, _reach);
                                            if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                            if(tuple4!= NULL){
                                                if(W!=V){
                                                    if(S!=T){
                                                        bool undefTuple5 = undefTuple4;
                                                        const Tuple* tuple5 = factory.find({V, W}, _reach);
                                                        if(tuple5 != NULL && tuple5->isUndef()) undefTuple5 = true;
                                                        if(tuple5!= NULL){
                                                            if(W!=V){
                                                                if(S!=T){
                                                                    bool undefTuple6 = undefTuple5;
                                                                    const Tuple* tuple6 = factory.find({V}, _active);
                                                                    if(tuple6 != NULL && tuple6->isUndef()) undefTuple6 = true;
                                                                    if(tuple6!= NULL){
                                                                        if(W!=V){
                                                                            if(S!=T){
                                                                                bool undefTuple7 = undefTuple6;
                                                                                const Tuple negativeTuple = Tuple({V}, _trivial, true);
                                                                                const Tuple* tuple7 = factory.find({V}, _trivial);
                                                                                if(tuple7 == NULL){
                                                                                    tuple7 = &negativeTuple;
                                                                                }
                                                                                else{
                                                                                    if(tuple7->isTrue())    tuple7= NULL;
                                                                                    else undefTuple7 = true;
                                                                                }
                                                                                if(tuple7!= NULL){
                                                                                    if(W!=V){
                                                                                        if(S!=T){
                                                                                            //Rule is firing 
                                                                                            Tuple* t;
                                                                                            std::pair<const TupleLight *, bool> insertResult;
                                                                                            t = factory.addNewInternalTuple({W,V,ConstantsManager::getInstance().mapConstant("m")}, _minfl);
                                                                                            if(t->isUnknown()){
                                                                                                printTuple(t);
                                                                                                if(undefTuple7){
                                                                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                                                                    insertUndef(insertResult);
                                                                                                }
                                                                                                else{
                                                                                                    insertResult = t->setStatus(TruthStatus::True);
                                                                                                    insertTrue(insertResult);
                                                                                                }
                                                                                            }
                                                                                            else if(t->isUndef()){
                                                                                                if(!undefTuple7){
                                                                                                    factory.removeFromCollisionsList(t->getId());
                                                                                                    insertResult = t->setStatus(TruthStatus::True);
                                                                                                    insertTrue(insertResult);
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
        }//close par
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
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        preach_.clear();
        preach_0_.clear();
        ureach_.clear();
        ureach_0_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pmvlabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &umvlabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pmvlabel_.clear();
        umvlabel_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pactive_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uactive_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pactive_.clear();
        uactive_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pminfl_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uminfl_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pminfl_.clear();
        uminfl_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &ptrivial_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &utrivial_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        ptrivial_.clear();
        utrivial_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pmllabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &umllabel_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pmllabel_.clear();
        pmllabel_0_1_.clear();
        pmllabel_0_1_3_.clear();
        umllabel_.clear();
        umllabel_0_1_.clear();
        umllabel_0_1_3_.clear();
    }
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
