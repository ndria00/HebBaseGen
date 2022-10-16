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
const int _put = 13;
const int _on = 0;
const int _on0 = 1;
const int _ongoal = 3;
const int _move = 5;
const int _steps = 4;
const int _time = 8;
const int _noMove = 6;
const int _onG = 2;
const int _disk = 7;
const int _diskMoved = 9;
const int _where = 10;
const int _noWhere = 11;
const int _diskWhere = 12;
AuxMap<0> pput_({});
AuxMap<0> uput_({});
AuxMap<0> pon_({});
AuxMap<0> uon_({});
AuxMap<0> pon0_({});
AuxMap<0> uon0_({});
AuxMap<0> pongoal_({});
AuxMap<0> uongoal_({});
AuxMap<0> pmove_({});
AuxMap<0> umove_({});
AuxMap<0> psteps_({});
AuxMap<0> usteps_({});
AuxMap<0> ptime_({});
AuxMap<0> utime_({});
AuxMap<0> pnoMove_({});
AuxMap<0> unoMove_({});
AuxMap<0> ponG_({});
AuxMap<0> uonG_({});
AuxMap<0> pdisk_({});
AuxMap<0> udisk_({});
AuxMap<0> pdiskMoved_({});
AuxMap<0> udiskMoved_({});
AuxMap<0> pwhere_({});
AuxMap<0> uwhere_({});
AuxMap<0> pnoWhere_({});
AuxMap<0> unoWhere_({});
AuxMap<0> pdiskWhere_({});
AuxMap<0> udiskWhere_({});
AuxMap<32> pwhere_0_({0});
AuxMap<32> uwhere_0_({0});
AuxMap<32> pon_0_({0});
AuxMap<32> uon_0_({0});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"put", _put});
    factory.addPredicate();
    predicateToID.insert({"on", _on});
    factory.addPredicate();
    predicateToID.insert({"on0", _on0});
    factory.addPredicate();
    predicateToID.insert({"ongoal", _ongoal});
    factory.addPredicate();
    predicateToID.insert({"move", _move});
    factory.addPredicate();
    predicateToID.insert({"steps", _steps});
    factory.addPredicate();
    predicateToID.insert({"time", _time});
    factory.addPredicate();
    predicateToID.insert({"noMove", _noMove});
    factory.addPredicate();
    predicateToID.insert({"onG", _onG});
    factory.addPredicate();
    predicateToID.insert({"disk", _disk});
    factory.addPredicate();
    predicateToID.insert({"diskMoved", _diskMoved});
    factory.addPredicate();
    predicateToID.insert({"where", _where});
    factory.addPredicate();
    predicateToID.insert({"noWhere", _noWhere});
    factory.addPredicate();
    predicateToID.insert({"diskWhere", _diskWhere});
    factory.addPredicate();
    Executor::predicateIds.push_back("on");
    Executor::predicateIds.push_back("on0");
    Executor::predicateIds.push_back("onG");
    Executor::predicateIds.push_back("ongoal");
    Executor::predicateIds.push_back("steps");
    Executor::predicateIds.push_back("move");
    Executor::predicateIds.push_back("noMove");
    Executor::predicateIds.push_back("disk");
    Executor::predicateIds.push_back("time");
    Executor::predicateIds.push_back("diskMoved");
    Executor::predicateIds.push_back("where");
    Executor::predicateIds.push_back("noWhere");
    Executor::predicateIds.push_back("diskWhere");
    Executor::predicateIds.push_back("put");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _diskWhere){
        pdiskWhere_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _put){
        pput_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _diskMoved){
        pdiskMoved_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _where){
        pwhere_.insert2Vec(*insertResult.first);
        pwhere_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _on){
        pon_.insert2Vec(*insertResult.first);
        pon_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _on0){
        pon0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _ongoal){
        pongoal_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _move){
        pmove_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _steps){
        psteps_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _time){
        ptime_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _noMove){
        pnoMove_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _onG){
        ponG_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _disk){
        pdisk_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _noWhere){
        pnoWhere_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _diskWhere){
        udiskWhere_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _put){
        uput_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _diskMoved){
        udiskMoved_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _where){
        uwhere_.insert2Vec(*insertResult.first);
        uwhere_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _on){
        uon_.insert2Vec(*insertResult.first);
        uon_0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _on0){
        uon0_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _ongoal){
        uongoal_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _move){
        umove_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _steps){
        usteps_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _time){
        utime_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _noMove){
        unoMove_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _onG){
        uonG_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _disk){
        udisk_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _noWhere){
        unoWhere_.insert2Vec(*insertResult.first);
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
            tuples = &pongoal_.getValuesVec({});
            const std::vector<int>* tuplesU = &uongoal_.getValuesVec({});
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
                    int N = (*tuple0)[0];
                    int N1 = (*tuple0)[1];
                    const std::vector<int>* tuples;
                    tuples = &psteps_.getValuesVec({});
                    const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                            int K = (*tuple1)[0];
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({K,N1,N}, _onG);
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
            tuples = &pongoal_.getValuesVec({});
            const std::vector<int>* tuplesU = &uongoal_.getValuesVec({});
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
                    int N = (*tuple0)[0];
                    int N1 = (*tuple0)[1];
                    const std::vector<int>* tuples;
                    tuples = &psteps_.getValuesVec({});
                    const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                            int K = (*tuple1)[0];
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({K,N1,N}, _onG);
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
            tuples = &pdisk_.getValuesVec({});
            const std::vector<int>* tuplesU = &udisk_.getValuesVec({});
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
                    int N = (*tuple0)[0];
                    const std::vector<int>* tuples;
                    tuples = &ptime_.getValuesVec({});
                    const std::vector<int>* tuplesU = &utime_.getValuesVec({});
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
                            const std::vector<int>* tuples;
                            tuples = &psteps_.getValuesVec({});
                            const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                                    int K = (*tuple2)[0];
                                    if(T<K){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({T,N}, _move);
                                        if(t->isUnknown()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else if(t->isUndef()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                        }
                                        t = factory.addNewInternalTuple({T,N}, _noMove);
                                        if(t->isUnknown()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else if(t->isUndef()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
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
            const std::vector<int>* tuples;
            tuples = &pdisk_.getValuesVec({});
            const std::vector<int>* tuplesU = &udisk_.getValuesVec({});
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
                    int N = (*tuple0)[0];
                    const std::vector<int>* tuples;
                    tuples = &ptime_.getValuesVec({});
                    const std::vector<int>* tuplesU = &utime_.getValuesVec({});
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
                            const std::vector<int>* tuples;
                            tuples = &psteps_.getValuesVec({});
                            const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                                    int K = (*tuple2)[0];
                                    if(T<K){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({T,N}, _move);
                                        if(t->isUnknown()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else if(t->isUndef()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                        }
                                        t = factory.addNewInternalTuple({T,N}, _noMove);
                                        if(t->isUnknown()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else if(t->isUndef()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
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
    //---------------------------------------Strongly connected component------------------------
    {
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pmove_.getValuesVec({});
            const std::vector<int>* tuplesU = &umove_.getValuesVec({});
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
                    int T = (*tuple0)[0];
                    int Fv1 = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({T}, _diskMoved);
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
            tuples = &pmove_.getValuesVec({});
            const std::vector<int>* tuplesU = &umove_.getValuesVec({});
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
                    int T = (*tuple0)[0];
                    int Fv1 = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({T}, _diskMoved);
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
            tuples = &pdisk_.getValuesVec({});
            const std::vector<int>* tuplesU = &udisk_.getValuesVec({});
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
                    int N = (*tuple0)[0];
                    const std::vector<int>* tuples;
                    tuples = &ptime_.getValuesVec({});
                    const std::vector<int>* tuplesU = &utime_.getValuesVec({});
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
                            const std::vector<int>* tuples;
                            tuples = &psteps_.getValuesVec({});
                            const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                                    int K = (*tuple2)[0];
                                    if(T<K){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({T,N}, _where);
                                        if(t->isUnknown()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else if(t->isUndef()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                        }
                                        t = factory.addNewInternalTuple({T,N}, _noWhere);
                                        if(t->isUnknown()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else if(t->isUndef()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
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
            const std::vector<int>* tuples;
            tuples = &pdisk_.getValuesVec({});
            const std::vector<int>* tuplesU = &udisk_.getValuesVec({});
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
                    int N = (*tuple0)[0];
                    const std::vector<int>* tuples;
                    tuples = &ptime_.getValuesVec({});
                    const std::vector<int>* tuplesU = &utime_.getValuesVec({});
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
                            const std::vector<int>* tuples;
                            tuples = &psteps_.getValuesVec({});
                            const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                                    int K = (*tuple2)[0];
                                    if(T<K){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({T,N}, _where);
                                        if(t->isUnknown()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else if(t->isUndef()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                        }
                                        t = factory.addNewInternalTuple({T,N}, _noWhere);
                                        if(t->isUnknown()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertUndef(insertResult);
                                        }
                                        else if(t->isUndef()){
                                            insertResult = t->setStatus(TruthStatus::Undef);
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
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pon0_.getValuesVec({});
            const std::vector<int>* tuplesU = &uon0_.getValuesVec({});
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
                    int N = (*tuple0)[0];
                    int N1 = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("0"),N1,N}, _on);
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
            tuples = &pon0_.getValuesVec({});
            const std::vector<int>* tuplesU = &uon0_.getValuesVec({});
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
                    int N = (*tuple0)[0];
                    int N1 = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("0"),N1,N}, _on);
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
            tuples = &pmove_.getValuesVec({});
            const std::vector<int>* tuplesU = &umove_.getValuesVec({});
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
                    int T = (*tuple0)[0];
                    int N = (*tuple0)[1];
                    int TP1 = T+1;
                    const std::vector<int>* tuples;
                    tuples = &pwhere_0_.getValuesVec({T});
                    const std::vector<int>* tuplesU = &uwhere_0_.getValuesVec({T});
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
                            int N1 = (*tuple1)[1];
                            if(TP1 == T+1){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({TP1,N1,N}, _on);
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
            const std::vector<int>* tuples;
            tuples = &pmove_.getValuesVec({});
            const std::vector<int>* tuplesU = &umove_.getValuesVec({});
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
                    int T = (*tuple0)[0];
                    int N = (*tuple0)[1];
                    int TP1 = T+1;
                    const std::vector<int>* tuples;
                    tuples = &pwhere_0_.getValuesVec({T});
                    const std::vector<int>* tuplesU = &uwhere_0_.getValuesVec({T});
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
                            int N1 = (*tuple1)[1];
                            if(TP1 == T+1){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({TP1,N1,N}, _on);
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
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            if(literalName == _on){
                {
                    bool undefTuple = false;
                    int N1 = (*recursiveTuple)[2];
                    int N = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({T}, _time);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        int TP1 = T+1;
                        const std::vector<int>* tuples;
                        tuples = &psteps_.getValuesVec({});
                        const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                                int K = (*tuple2)[0];
                                if(T<K){
                                    if(TP1 == T+1){
                                        const Tuple negativeTuple = Tuple({T, N1}, _move, true);
                                        const Tuple* tuple3 = factory.find({T, N1}, _move);
                                        if(tuple3 == NULL){
                                            tuple3 = &negativeTuple;
                                            undefTuple = true;
                                        }
                                        else{
                                            if(tuple3->isTrue())    tuple3= NULL;
                                            else undefTuple = true;
                                        }
                                        if(tuple3!= NULL){
                                            if(T<K){
                                                if(TP1 == T+1){
                                                    //Rule is firing 
                                                    Tuple* t;
                                                    std::pair<const TupleLight *, bool> insertResult;
                                                    t = factory.addNewInternalTuple({TP1,N,N1}, _on);
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
                }//close par
                {
                    bool undefTuple = false;
                    int N1 = (*recursiveTuple)[2];
                    int N = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({T}, _time);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple = true;
                    if(tuple1!= NULL){
                        int TP1 = T+1;
                        const std::vector<int>* tuples;
                        tuples = &psteps_.getValuesVec({});
                        const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                                int K = (*tuple2)[0];
                                if(T<K){
                                    if(TP1 == T+1){
                                        const Tuple negativeTuple = Tuple({T, N1}, _move, true);
                                        const Tuple* tuple3 = factory.find({T, N1}, _move);
                                        if(tuple3 == NULL){
                                            tuple3 = &negativeTuple;
                                            undefTuple = true;
                                        }
                                        else{
                                            if(tuple3->isTrue())    tuple3= NULL;
                                            else undefTuple = true;
                                        }
                                        if(tuple3!= NULL){
                                            if(T<K){
                                                if(TP1 == T+1){
                                                    //Rule is firing 
                                                    Tuple* t;
                                                    std::pair<const TupleLight *, bool> insertResult;
                                                    t = factory.addNewInternalTuple({TP1,N,N1}, _on);
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
                }//close par
            }
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pmove_.getValuesVec({});
            const std::vector<int>* tuplesU = &umove_.getValuesVec({});
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
                    int T = (*tuple0)[0];
                    int N = (*tuple0)[1];
                    const std::vector<int>* tuples;
                    tuples = &pwhere_0_.getValuesVec({T});
                    const std::vector<int>* tuplesU = &uwhere_0_.getValuesVec({T});
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
                            int M = (*tuple1)[1];
                            const std::vector<int>* tuples;
                            tuples = &psteps_.getValuesVec({});
                            const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                                    int K = (*tuple2)[0];
                                    if(T<K){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({T,M,N}, _put);
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
                }//close par
            }//close par
        }//close par
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pmove_.getValuesVec({});
            const std::vector<int>* tuplesU = &umove_.getValuesVec({});
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
                    int T = (*tuple0)[0];
                    int N = (*tuple0)[1];
                    const std::vector<int>* tuples;
                    tuples = &pwhere_0_.getValuesVec({T});
                    const std::vector<int>* tuplesU = &uwhere_0_.getValuesVec({T});
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
                            int M = (*tuple1)[1];
                            const std::vector<int>* tuples;
                            tuples = &psteps_.getValuesVec({});
                            const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                                    int K = (*tuple2)[0];
                                    if(T<K){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({T,M,N}, _put);
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
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &pwhere_.getValuesVec({});
            const std::vector<int>* tuplesU = &uwhere_.getValuesVec({});
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
                    int T = (*tuple0)[0];
                    int Fv1 = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({T}, _diskWhere);
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
            tuples = &pwhere_.getValuesVec({});
            const std::vector<int>* tuplesU = &uwhere_.getValuesVec({});
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
                    int T = (*tuple0)[0];
                    int Fv1 = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({T}, _diskWhere);
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
    printGeneratedBase();
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
void Executor::printGeneratedBase(){
    const std::vector<int>* tuples;
    tuples = &pput_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uput_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pon_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uon_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pon0_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uon0_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pongoal_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uongoal_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pmove_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &umove_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &psteps_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &usteps_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ptime_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &utime_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pnoMove_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &unoMove_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ponG_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uonG_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pdisk_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &udisk_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pdiskMoved_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &udiskMoved_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pwhere_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uwhere_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pnoWhere_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &unoWhere_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pdiskWhere_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &udiskWhere_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
}
