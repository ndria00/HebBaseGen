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
        pntedge_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _oppo){
        poppo_.insert2VecNoColl(*insertResult.first);
        poppo_1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _first){
        pfirst_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nfirst){
        pnfirst_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _singleton){
        psingleton_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _aedge){
        paedge_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _mllabel){
        pmllabel_.insert2VecNoColl(*insertResult.first);
        pmllabel_0_1_.insert2VecNoColl(*insertResult.first);
        pmllabel_0_1_3_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _btedge){
        pbtedge_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nlast){
        pnlast_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _trivial){
        ptrivial_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _input){
        pinput_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _vertex){
        pvertex_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nontriv){
        pnontriv_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _vlabel){
        pvlabel_.insert2VecNoColl(*insertResult.first);
        pvlabel_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _obs_vlabel){
        pobs_vlabel_.insert2VecNoColl(*insertResult.first);
        pobs_vlabel_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _minfl){
        pminfl_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _llabel){
        pllabel_.insert2VecNoColl(*insertResult.first);
        pllabel_0_2_.insert2VecNoColl(*insertResult.first);
        pllabel_1_2_.insert2VecNoColl(*insertResult.first);
        pllabel_2_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _mvlabel){
        pmvlabel_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _diff){
        pdiff_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _edge){
        pedge_.insert2VecNoColl(*insertResult.first);
        pedge_0_.insert2VecNoColl(*insertResult.first);
        pedge_1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _sign){
        psign_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _active){
        pactive_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _coppo){
        pcoppo_.insert2VecNoColl(*insertResult.first);
        pcoppo_1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _bot){
        pbot_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _reach){
        preach_.insert2VecNoColl(*insertResult.first);
        preach_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _inactive){
        pinactive_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _obs_elabel){
        pobs_elabel_.insert2VecNoColl(*insertResult.first);
        pobs_elabel_0_1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _last){
        plast_.insert2VecNoColl(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _ntedge){
        untedge_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _oppo){
        uoppo_.insert2VecNoColl(*insertResult.first);
        uoppo_1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _first){
        ufirst_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nfirst){
        unfirst_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _singleton){
        usingleton_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _aedge){
        uaedge_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _mllabel){
        umllabel_.insert2VecNoColl(*insertResult.first);
        umllabel_0_1_.insert2VecNoColl(*insertResult.first);
        umllabel_0_1_3_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _btedge){
        ubtedge_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nlast){
        unlast_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _trivial){
        utrivial_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _input){
        uinput_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _vertex){
        uvertex_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nontriv){
        unontriv_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _vlabel){
        uvlabel_.insert2VecNoColl(*insertResult.first);
        uvlabel_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _obs_vlabel){
        uobs_vlabel_.insert2VecNoColl(*insertResult.first);
        uobs_vlabel_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _minfl){
        uminfl_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _llabel){
        ullabel_.insert2VecNoColl(*insertResult.first);
        ullabel_0_2_.insert2VecNoColl(*insertResult.first);
        ullabel_1_2_.insert2VecNoColl(*insertResult.first);
        ullabel_2_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _mvlabel){
        umvlabel_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _diff){
        udiff_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _edge){
        uedge_.insert2VecNoColl(*insertResult.first);
        uedge_0_.insert2VecNoColl(*insertResult.first);
        uedge_1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _sign){
        usign_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _active){
        uactive_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _coppo){
        ucoppo_.insert2VecNoColl(*insertResult.first);
        ucoppo_1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _bot){
        ubot_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _reach){
        ureach_.insert2VecNoColl(*insertResult.first);
        ureach_0_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _inactive){
        uinactive_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _obs_elabel){
        uobs_elabel_.insert2VecNoColl(*insertResult.first);
        uobs_elabel_0_1_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _last){
        ulast_.insert2VecNoColl(*insertResult.first);
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
