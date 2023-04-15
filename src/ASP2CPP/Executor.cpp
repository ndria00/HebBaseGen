#include <chrono>
#include "Executor.h"
#include "../DataStructures/ConstantsManager.h"
#include "../DataStructures/IndexedSet.h"
typedef TupleLight Tuple;
template<size_t S>
using AuxMap = AuxiliaryMapSmart<S> ;
const std::vector<int> EMPTY_TUPLES_VEC;
const IndexedSet EMPTY_TUPLES_SET;
// Hash function
struct hashFunction{
     size_t operator()(const pair<int, int> &x) const{
        return x.first ^ x.second;
    }
};

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
AuxMap<32> pmove_0_({0});
AuxMap<32> umove_0_({0});
AuxMap<32> pwhere_0_({0});
AuxMap<32> uwhere_0_({0});
AuxMap<32> pmove_1_({1});
AuxMap<32> umove_1_({1});
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
void printTuple(const Tuple* t, bool dummy){
    std::cout << Executor::predicateIds[t->getPredicateName()];
    std::cout <<std::endl;
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
        pmove_0_.insert2Vec(*insertResult.first);
        pmove_1_.insert2Vec(*insertResult.first);
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
        umove_0_.insert2Vec(*insertResult.first);
        umove_1_.insert2Vec(*insertResult.first);
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
        if(t->size() == 0)         printTuple(t, false);
        else printTuple(t);
    }
    else{
        const auto& insertResult = t->setStatus(TruthStatus::Undef);
        insertUndef(insertResult);
    }
}
void Executor::executeProgram(){
    const Tuple dummyTuple = Tuple();
    auto start = std::chrono::high_resolution_clock::now();
    //---------------------------------------Strongly connected component------------------------
    {
        {
            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
            bool undefTuple0= false;
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
                    undefTuple0 = true;
                }
                if(tuple0!= NULL){
                    int N = (*tuple0)[0];
                    int N1 = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
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
                            undefTuple1 = true;
                        }
                        if(tuple1!= NULL){
                            int K = (*tuple1)[0];
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({K,N1,N}, _onG);
                            if(t->isUnknown()){
                                if(undefTuple1){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertResults.push_back(std::make_pair(insertResult, 0));
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertResults.push_back(std::make_pair(insertResult, 1));
                                    printTuple(t);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple1){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertResults.push_back(std::make_pair(insertResult, 2));
                                    printTuple(t);
                                }
                            }
                        }//close par
                    }//close par
                }//close par
            }//close par
            for(unsigned i = 0; i< insertResults.size(); ++i){
                if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                else if(insertResults[i].second == 2){
                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                    insertTrue(insertResults[i].first);
                    }
                }
            }//close par
            {
                std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                bool undefTuple0= false;
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
                        undefTuple0 = true;
                    }
                    if(tuple0!= NULL){
                        int N = (*tuple0)[0];
                        int N1 = (*tuple0)[1];
                        bool undefTuple1 = undefTuple0;
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
                                undefTuple1 = true;
                            }
                            if(tuple1!= NULL){
                                int K = (*tuple1)[0];
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({K,N1,N}, _onG);
                                if(t->isUnknown()){
                                    if(undefTuple1){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertResults.push_back(std::make_pair(insertResult, 0));
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertResults.push_back(std::make_pair(insertResult, 1));
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple1){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertResults.push_back(std::make_pair(insertResult, 2));
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                }//close par
                for(unsigned i = 0; i< insertResults.size(); ++i){
                    if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                    else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                    else if(insertResults[i].second == 2){
                        factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                        insertTrue(insertResults[i].first);
                        }
                    }
                }//close par
            }
            //---------------------------------------Strongly connected component------------------------
            {
                {
                    std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                    bool undefTuple0= false;
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
                            undefTuple0 = true;
                        }
                        if(tuple0!= NULL){
                            int N = (*tuple0)[0];
                            bool undefTuple1 = undefTuple0;
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
                                    undefTuple1 = true;
                                }
                                if(tuple1!= NULL){
                                    int T = (*tuple1)[0];
                                    bool undefTuple2 = undefTuple1;
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
                                            undefTuple2 = true;
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
                                                    insertResults.push_back(std::make_pair(insertResult, 0));
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple2){
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertResults.push_back(std::make_pair(insertResult, 2));
                                                        printTuple(t);
                                                    }
                                                }
                                                t = factory.addNewInternalTuple({T,N}, _noMove);
                                                if(t->isUnknown()){
                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                    insertResults.push_back(std::make_pair(insertResult, 0));
                                                }
                                                else if(t->isUndef()){
                                                    if(!undefTuple2){
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertResults.push_back(std::make_pair(insertResult, 2));
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
                    for(unsigned i = 0; i< insertResults.size(); ++i){
                        if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                        else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                        else if(insertResults[i].second == 2){
                            factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                            insertTrue(insertResults[i].first);
                            }
                        }
                    }//close par
                    {
                        std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                        bool undefTuple0= false;
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
                                undefTuple0 = true;
                            }
                            if(tuple0!= NULL){
                                int N = (*tuple0)[0];
                                bool undefTuple1 = undefTuple0;
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
                                        undefTuple1 = true;
                                    }
                                    if(tuple1!= NULL){
                                        int T = (*tuple1)[0];
                                        bool undefTuple2 = undefTuple1;
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
                                                undefTuple2 = true;
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
                                                        insertResults.push_back(std::make_pair(insertResult, 0));
                                                    }
                                                    else if(t->isUndef()){
                                                        if(!undefTuple2){
                                                            insertResult = t->setStatus(TruthStatus::True);
                                                            insertResults.push_back(std::make_pair(insertResult, 2));
                                                            printTuple(t);
                                                        }
                                                    }
                                                    t = factory.addNewInternalTuple({T,N}, _noMove);
                                                    if(t->isUnknown()){
                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                        insertResults.push_back(std::make_pair(insertResult, 0));
                                                    }
                                                    else if(t->isUndef()){
                                                        if(!undefTuple2){
                                                            insertResult = t->setStatus(TruthStatus::True);
                                                            insertResults.push_back(std::make_pair(insertResult, 2));
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
                        for(unsigned i = 0; i< insertResults.size(); ++i){
                            if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                            else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                            else if(insertResults[i].second == 2){
                                factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                insertTrue(insertResults[i].first);
                                }
                            }
                        }//close par
                    }
                    //---------------------------------------Strongly connected component------------------------
                    {
                    }
                    //---------------------------------------Strongly connected component------------------------
                    {
                        {
                            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                            bool undefTuple0= false;
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
                                    undefTuple0 = true;
                                }
                                if(tuple0!= NULL){
                                    int T = (*tuple0)[0];
                                    int Fv1 = (*tuple0)[1];
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({T}, _diskMoved);
                                    if(t->isUnknown()){
                                        if(undefTuple0){
                                            insertResult = t->setStatus(TruthStatus::Undef);
                                            insertResults.push_back(std::make_pair(insertResult, 0));
                                        }
                                        else{
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertResults.push_back(std::make_pair(insertResult, 1));
                                            printTuple(t);
                                        }
                                    }
                                    else if(t->isUndef()){
                                        if(!undefTuple0){
                                            insertResult = t->setStatus(TruthStatus::True);
                                            insertResults.push_back(std::make_pair(insertResult, 2));
                                            printTuple(t);
                                        }
                                    }
                                }//close par
                            }//close par
                            for(unsigned i = 0; i< insertResults.size(); ++i){
                                if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                else if(insertResults[i].second == 2){
                                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                    insertTrue(insertResults[i].first);
                                    }
                                }
                            }//close par
                            {
                                std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                bool undefTuple0= false;
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
                                        undefTuple0 = true;
                                    }
                                    if(tuple0!= NULL){
                                        int T = (*tuple0)[0];
                                        int Fv1 = (*tuple0)[1];
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({T}, _diskMoved);
                                        if(t->isUnknown()){
                                            if(undefTuple0){
                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                insertResults.push_back(std::make_pair(insertResult, 0));
                                            }
                                            else{
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertResults.push_back(std::make_pair(insertResult, 1));
                                                printTuple(t);
                                            }
                                        }
                                        else if(t->isUndef()){
                                            if(!undefTuple0){
                                                insertResult = t->setStatus(TruthStatus::True);
                                                insertResults.push_back(std::make_pair(insertResult, 2));
                                                printTuple(t);
                                            }
                                        }
                                    }//close par
                                }//close par
                                for(unsigned i = 0; i< insertResults.size(); ++i){
                                    if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                    else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                    else if(insertResults[i].second == 2){
                                        factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                        insertTrue(insertResults[i].first);
                                        }
                                    }
                                }//close par
                            }
                            //---------------------------------------Strongly connected component------------------------
                            {
                                {
                                    std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                    bool undefTuple0= false;
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
                                            undefTuple0 = true;
                                        }
                                        if(tuple0!= NULL){
                                            int N = (*tuple0)[0];
                                            bool undefTuple1 = undefTuple0;
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
                                                    undefTuple1 = true;
                                                }
                                                if(tuple1!= NULL){
                                                    int T = (*tuple1)[0];
                                                    bool undefTuple2 = undefTuple1;
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
                                                            undefTuple2 = true;
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
                                                                    insertResults.push_back(std::make_pair(insertResult, 0));
                                                                }
                                                                else if(t->isUndef()){
                                                                    if(!undefTuple2){
                                                                        insertResult = t->setStatus(TruthStatus::True);
                                                                        insertResults.push_back(std::make_pair(insertResult, 2));
                                                                        printTuple(t);
                                                                    }
                                                                }
                                                                t = factory.addNewInternalTuple({T,N}, _noWhere);
                                                                if(t->isUnknown()){
                                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                                    insertResults.push_back(std::make_pair(insertResult, 0));
                                                                }
                                                                else if(t->isUndef()){
                                                                    if(!undefTuple2){
                                                                        insertResult = t->setStatus(TruthStatus::True);
                                                                        insertResults.push_back(std::make_pair(insertResult, 2));
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
                                    for(unsigned i = 0; i< insertResults.size(); ++i){
                                        if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                        else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                        else if(insertResults[i].second == 2){
                                            factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                            insertTrue(insertResults[i].first);
                                            }
                                        }
                                    }//close par
                                    {
                                        std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                        bool undefTuple0= false;
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
                                                undefTuple0 = true;
                                            }
                                            if(tuple0!= NULL){
                                                int N = (*tuple0)[0];
                                                bool undefTuple1 = undefTuple0;
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
                                                        undefTuple1 = true;
                                                    }
                                                    if(tuple1!= NULL){
                                                        int T = (*tuple1)[0];
                                                        bool undefTuple2 = undefTuple1;
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
                                                                undefTuple2 = true;
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
                                                                        insertResults.push_back(std::make_pair(insertResult, 0));
                                                                    }
                                                                    else if(t->isUndef()){
                                                                        if(!undefTuple2){
                                                                            insertResult = t->setStatus(TruthStatus::True);
                                                                            insertResults.push_back(std::make_pair(insertResult, 2));
                                                                            printTuple(t);
                                                                        }
                                                                    }
                                                                    t = factory.addNewInternalTuple({T,N}, _noWhere);
                                                                    if(t->isUnknown()){
                                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                                        insertResults.push_back(std::make_pair(insertResult, 0));
                                                                    }
                                                                    else if(t->isUndef()){
                                                                        if(!undefTuple2){
                                                                            insertResult = t->setStatus(TruthStatus::True);
                                                                            insertResults.push_back(std::make_pair(insertResult, 2));
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
                                        for(unsigned i = 0; i< insertResults.size(); ++i){
                                            if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                            else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                            else if(insertResults[i].second == 2){
                                                factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                insertTrue(insertResults[i].first);
                                                }
                                            }
                                        }//close par
                                    }
                                    //---------------------------------------Strongly connected component------------------------
                                    {
                                        std::vector<int> generatedStack;
                                        std::unordered_set<std::pair<int, int>, hashFunction>* propagationStack = new std::unordered_set<std::pair<int, int>, hashFunction>();
                                        std::unordered_map<int, std::unordered_set<int>> tupleSupports;
                                        {
                                            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                            bool undefTuple0= false;
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
                                                    undefTuple0 = true;
                                                }
                                                if(tuple0!= NULL){
                                                    int N = (*tuple0)[0];
                                                    int N1 = (*tuple0)[1];
                                                    //Rule is firing 
                                                    Tuple* t;
                                                    std::pair<const TupleLight *, bool> insertResult;
                                                    t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("0"),N1,N}, _on);
                                                    if(t->isUnknown()){
                                                        if(undefTuple0){
                                                            insertResult = t->setStatus(TruthStatus::Undef);
                                                            insertResults.push_back(std::make_pair(insertResult, 0));
                                                        }
                                                        else{
                                                            insertResult = t->setStatus(TruthStatus::True);
                                                            insertResults.push_back(std::make_pair(insertResult, 1));
                                                            printTuple(t);
                                                        }
                                                    }
                                                    else if(t->isUndef()){
                                                        if(!undefTuple0){
                                                            insertResult = t->setStatus(TruthStatus::True);
                                                            insertResults.push_back(std::make_pair(insertResult, 2));
                                                            generatedStack.push_back(t->getId());
                                                            printTuple(t);
                                                        }
                                                    }
                                                }//close par
                                            }//close par
                                            for(unsigned i = 0; i< insertResults.size(); ++i){
                                                if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                else if(insertResults[i].second == 2){
                                                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                    insertTrue(insertResults[i].first);
                                                    }
                                                }
                                            }//close par
                                            {
                                                std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                                bool undefTuple0= false;
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
                                                        undefTuple0 = true;
                                                    }
                                                    if(tuple0!= NULL){
                                                        int N = (*tuple0)[0];
                                                        int N1 = (*tuple0)[1];
                                                        //Rule is firing 
                                                        Tuple* t;
                                                        std::pair<const TupleLight *, bool> insertResult;
                                                        t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("0"),N1,N}, _on);
                                                        if(t->isUnknown()){
                                                            if(undefTuple0){
                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                                insertResults.push_back(std::make_pair(insertResult, 0));
                                                            }
                                                            else{
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertResults.push_back(std::make_pair(insertResult, 1));
                                                                printTuple(t);
                                                            }
                                                        }
                                                        else if(t->isUndef()){
                                                            if(!undefTuple0){
                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                insertResults.push_back(std::make_pair(insertResult, 2));
                                                                generatedStack.push_back(t->getId());
                                                                printTuple(t);
                                                            }
                                                        }
                                                    }//close par
                                                }//close par
                                                for(unsigned i = 0; i< insertResults.size(); ++i){
                                                    if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                    else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                    else if(insertResults[i].second == 2){
                                                        factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                        insertTrue(insertResults[i].first);
                                                        }
                                                    }
                                                }//close par
                                                {
                                                    std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                                    bool undefTuple0= false;
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
                                                            undefTuple0 = true;
                                                        }
                                                        if(tuple0!= NULL){
                                                            int T = (*tuple0)[0];
                                                            int N = (*tuple0)[1];
                                                            int TP1 = T+1;
                                                            bool undefTuple1 = undefTuple0;
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
                                                                    undefTuple1 = true;
                                                                }
                                                                if(tuple1!= NULL){
                                                                    int N1 = (*tuple1)[1];
                                                                    //Rule is firing 
                                                                    Tuple* t;
                                                                    std::pair<const TupleLight *, bool> insertResult;
                                                                    t = factory.addNewInternalTuple({TP1,N1,N}, _on);
                                                                    if(t->isUnknown()){
                                                                        if(undefTuple1){
                                                                            insertResult = t->setStatus(TruthStatus::Undef);
                                                                            insertResults.push_back(std::make_pair(insertResult, 0));
                                                                        }
                                                                        else{
                                                                            insertResult = t->setStatus(TruthStatus::True);
                                                                            insertResults.push_back(std::make_pair(insertResult, 1));
                                                                            printTuple(t);
                                                                        }
                                                                    }
                                                                    else if(t->isUndef()){
                                                                        if(!undefTuple1){
                                                                            insertResult = t->setStatus(TruthStatus::True);
                                                                            insertResults.push_back(std::make_pair(insertResult, 2));
                                                                            generatedStack.push_back(t->getId());
                                                                            printTuple(t);
                                                                        }
                                                                    }
                                                                }//close par
                                                            }//close par
                                                        }//close par
                                                    }//close par
                                                    for(unsigned i = 0; i< insertResults.size(); ++i){
                                                        if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                        else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                        else if(insertResults[i].second == 2){
                                                            factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                            insertTrue(insertResults[i].first);
                                                            }
                                                        }
                                                    }//close par
                                                    {
                                                        std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                                        bool undefTuple0= false;
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
                                                                undefTuple0 = true;
                                                            }
                                                            if(tuple0!= NULL){
                                                                int T = (*tuple0)[0];
                                                                int N = (*tuple0)[1];
                                                                int TP1 = T+1;
                                                                bool undefTuple1 = undefTuple0;
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
                                                                        undefTuple1 = true;
                                                                    }
                                                                    if(tuple1!= NULL){
                                                                        int N1 = (*tuple1)[1];
                                                                        //Rule is firing 
                                                                        Tuple* t;
                                                                        std::pair<const TupleLight *, bool> insertResult;
                                                                        t = factory.addNewInternalTuple({TP1,N1,N}, _on);
                                                                        if(t->isUnknown()){
                                                                            if(undefTuple1){
                                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                                                insertResults.push_back(std::make_pair(insertResult, 0));
                                                                            }
                                                                            else{
                                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                                insertResults.push_back(std::make_pair(insertResult, 1));
                                                                                printTuple(t);
                                                                            }
                                                                        }
                                                                        else if(t->isUndef()){
                                                                            if(!undefTuple1){
                                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                                insertResults.push_back(std::make_pair(insertResult, 2));
                                                                                generatedStack.push_back(t->getId());
                                                                                printTuple(t);
                                                                            }
                                                                        }
                                                                    }//close par
                                                                }//close par
                                                            }//close par
                                                        }//close par
                                                        for(unsigned i = 0; i< insertResults.size(); ++i){
                                                            if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                            else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                            else if(insertResults[i].second == 2){
                                                                factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                                insertTrue(insertResults[i].first);
                                                                }
                                                            }
                                                        }//close par
                                                        {
                                                            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                                            bool undefTuple0= false;
                                                            const std::vector<int>* tuples;
                                                            tuples = &ptime_.getValuesVec({});
                                                            const std::vector<int>* tuplesU = &utime_.getValuesVec({});
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
                                                                    int TP1 = T+1;
                                                                    bool undefTuple1 = undefTuple0;
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
                                                                            undefTuple1 = true;
                                                                        }
                                                                        if(tuple1!= NULL){
                                                                            int K = (*tuple1)[0];
                                                                            if(T<K){
                                                                                bool undefTuple2 = undefTuple1;
                                                                                const std::vector<int>* tuples;
                                                                                tuples = &pon_0_.getValuesVec({T});
                                                                                const std::vector<int>* tuplesU = &uon_0_.getValuesVec({T});
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
                                                                                        int N = (*tuple2)[1];
                                                                                        int N1 = (*tuple2)[2];
                                                                                        if(T<K){
                                                                                            bool undefTuple3 = undefTuple2;
                                                                                            const Tuple* tuple3 = factory.find({T, N1}, _move);
                                                                                            if(tuple3 == NULL){
                                                                                                tuple3 = &dummyTuple;
                                                                                            }
                                                                                            else{
                                                                                                if(tuple3->isTrue())    tuple3= NULL;
                                                                                                else undefTuple3 = true;
                                                                                            }
                                                                                            if(tuple3!= NULL){
                                                                                                if(T<K){
                                                                                                    //Rule is firing 
                                                                                                    Tuple* t;
                                                                                                    std::pair<const TupleLight *, bool> insertResult;
                                                                                                    t = factory.addNewInternalTuple({TP1,N,N1}, _on);
                                                                                                    if(t->isUnknown()){
                                                                                                        generatedStack.push_back(t->getId());
                                                                                                        if(undefTuple3){
                                                                                                            insertResult = t->setStatus(TruthStatus::Undef);
                                                                                                            insertResults.push_back(std::make_pair(insertResult, 0));
                                                                                                            propagationStack->insert(std::make_pair(t->getId(), 8));
                                                                                                            if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                                                                            tupleSupports[t->getId()].insert(8) ;
                                                                                                        }
                                                                                                        else{
                                                                                                            insertResult = t->setStatus(TruthStatus::True);
                                                                                                            insertResults.push_back(std::make_pair(insertResult, 1));
                                                                                                            printTuple(t);
                                                                                                        }
                                                                                                    }
                                                                                                    else if(t->isUndef()){
                                                                                                        if(!undefTuple3){
                                                                                                            propagationStack->erase(std::make_pair(t->getId(), 8));
                                                                                                            insertResult = t->setStatus(TruthStatus::True);
                                                                                                            insertResults.push_back(std::make_pair(insertResult, 2));
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
                                                            for(unsigned i = 0; i< insertResults.size(); ++i){
                                                                if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                                else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                                else if(insertResults[i].second == 2){
                                                                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                                    insertTrue(insertResults[i].first);
                                                                    }
                                                                }
                                                            }//close par
                                                            {
                                                                std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                                                bool undefTuple0= false;
                                                                const std::vector<int>* tuples;
                                                                tuples = &ptime_.getValuesVec({});
                                                                const std::vector<int>* tuplesU = &utime_.getValuesVec({});
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
                                                                        int TP1 = T+1;
                                                                        bool undefTuple1 = undefTuple0;
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
                                                                                undefTuple1 = true;
                                                                            }
                                                                            if(tuple1!= NULL){
                                                                                int K = (*tuple1)[0];
                                                                                if(T<K){
                                                                                    bool undefTuple2 = undefTuple1;
                                                                                    const std::vector<int>* tuples;
                                                                                    tuples = &pon_0_.getValuesVec({T});
                                                                                    const std::vector<int>* tuplesU = &uon_0_.getValuesVec({T});
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
                                                                                            int N = (*tuple2)[1];
                                                                                            int N1 = (*tuple2)[2];
                                                                                            if(T<K){
                                                                                                bool undefTuple3 = undefTuple2;
                                                                                                const Tuple* tuple3 = factory.find({T, N1}, _move);
                                                                                                if(tuple3 == NULL){
                                                                                                    tuple3 = &dummyTuple;
                                                                                                }
                                                                                                else{
                                                                                                    if(tuple3->isTrue())    tuple3= NULL;
                                                                                                    else undefTuple3 = true;
                                                                                                }
                                                                                                if(tuple3!= NULL){
                                                                                                    if(T<K){
                                                                                                        //Rule is firing 
                                                                                                        Tuple* t;
                                                                                                        std::pair<const TupleLight *, bool> insertResult;
                                                                                                        t = factory.addNewInternalTuple({TP1,N,N1}, _on);
                                                                                                        if(t->isUnknown()){
                                                                                                            generatedStack.push_back(t->getId());
                                                                                                            if(undefTuple3){
                                                                                                                insertResult = t->setStatus(TruthStatus::Undef);
                                                                                                                insertResults.push_back(std::make_pair(insertResult, 0));
                                                                                                                propagationStack->insert(std::make_pair(t->getId(), 16));
                                                                                                                if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                                                                                tupleSupports[t->getId()].insert(16) ;
                                                                                                            }
                                                                                                            else{
                                                                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                                                                insertResults.push_back(std::make_pair(insertResult, 1));
                                                                                                                printTuple(t);
                                                                                                            }
                                                                                                        }
                                                                                                        else if(t->isUndef()){
                                                                                                            if(!undefTuple3){
                                                                                                                propagationStack->erase(std::make_pair(t->getId(), 16));
                                                                                                                insertResult = t->setStatus(TruthStatus::True);
                                                                                                                insertResults.push_back(std::make_pair(insertResult, 2));
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
                                                                for(unsigned i = 0; i< insertResults.size(); ++i){
                                                                    if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                                    else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                                    else if(insertResults[i].second == 2){
                                                                        factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                                        insertTrue(insertResults[i].first);
                                                                        }
                                                                    }
                                                                }//close par
                                                                while(! generatedStack.empty()){
                                                                    const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
                                                                    generatedStack.pop_back();
                                                                    unsigned literalName = recursiveTuple->getPredicateName();
                                                                    bool recursiveTupleUndef = recursiveTuple->isUndef();
                                                                    if(literalName == _on){
                                                                        {
                                                                            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                                                            bool undefTuple0= false;
                                                                            int N1 = (*recursiveTuple)[2];
                                                                            int N = (*recursiveTuple)[1];
                                                                            int T = (*recursiveTuple)[0];
                                                                            if(recursiveTupleUndef){
                                                                                undefTuple0 = true;
                                                                            }
                                                                            bool undefTuple1 = undefTuple0;
                                                                            const Tuple* tuple1 = factory.find({T, N1}, _move);
                                                                            if(tuple1 == NULL){
                                                                                tuple1 = &dummyTuple;
                                                                            }
                                                                            else{
                                                                                if(tuple1->isTrue())    tuple1= NULL;
                                                                                else undefTuple1 = true;
                                                                            }
                                                                            if(tuple1!= NULL){
                                                                                int TP1 = T+1;
                                                                                bool undefTuple2 = undefTuple1;
                                                                                const Tuple* tuple2 = factory.find({T}, _time);
                                                                                if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                                                                                if(tuple2!= NULL){
                                                                                    bool undefTuple3 = undefTuple2;
                                                                                    const std::vector<int>* tuples;
                                                                                    tuples = &psteps_.getValuesVec({});
                                                                                    const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                                                                                            int K = (*tuple3)[0];
                                                                                            if(T<K){
                                                                                                //Rule is firing 
                                                                                                Tuple* t;
                                                                                                std::pair<const TupleLight *, bool> insertResult;
                                                                                                t = factory.addNewInternalTuple({TP1,N,N1}, _on);
                                                                                                if(t->isUnknown()){
                                                                                                    generatedStack.push_back(t->getId());
                                                                                                    if(undefTuple3){
                                                                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                                                                        insertResults.push_back(std::make_pair(insertResult, 0));
                                                                                                        propagationStack->insert(std::make_pair(t->getId(), 8));
                                                                                                        if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                                                                        tupleSupports[t->getId()].insert(8) ;
                                                                                                    }
                                                                                                    else{
                                                                                                        insertResult = t->setStatus(TruthStatus::True);
                                                                                                        insertResults.push_back(std::make_pair(insertResult, 1));
                                                                                                        printTuple(t);
                                                                                                    }
                                                                                                }
                                                                                                else if(t->isUndef()){
                                                                                                    if(!undefTuple3){
                                                                                                        propagationStack->erase(std::make_pair(t->getId(), 8));
                                                                                                        insertResult = t->setStatus(TruthStatus::True);
                                                                                                        insertResults.push_back(std::make_pair(insertResult, 2));
                                                                                                        generatedStack.push_back(t->getId());
                                                                                                        printTuple(t);
                                                                                                    }
                                                                                                }
                                                                                            }//close par
                                                                                        }//close par
                                                                                    }//close par
                                                                                }//close par
                                                                            }//close par
                                                                            for(unsigned i = 0; i< insertResults.size(); ++i){
                                                                                if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                                                else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                                                else if(insertResults[i].second == 2){
                                                                                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                                                    insertTrue(insertResults[i].first);
                                                                                    }
                                                                                }
                                                                            }//close par
                                                                            {
                                                                                std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                                                                bool undefTuple0= false;
                                                                                int N1 = (*recursiveTuple)[2];
                                                                                int N = (*recursiveTuple)[1];
                                                                                int T = (*recursiveTuple)[0];
                                                                                if(recursiveTupleUndef){
                                                                                    undefTuple0 = true;
                                                                                }
                                                                                bool undefTuple1 = undefTuple0;
                                                                                const Tuple* tuple1 = factory.find({T, N1}, _move);
                                                                                if(tuple1 == NULL){
                                                                                    tuple1 = &dummyTuple;
                                                                                }
                                                                                else{
                                                                                    if(tuple1->isTrue())    tuple1= NULL;
                                                                                    else undefTuple1 = true;
                                                                                }
                                                                                if(tuple1!= NULL){
                                                                                    int TP1 = T+1;
                                                                                    bool undefTuple2 = undefTuple1;
                                                                                    const Tuple* tuple2 = factory.find({T}, _time);
                                                                                    if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                                                                                    if(tuple2!= NULL){
                                                                                        bool undefTuple3 = undefTuple2;
                                                                                        const std::vector<int>* tuples;
                                                                                        tuples = &psteps_.getValuesVec({});
                                                                                        const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                                                                                                int K = (*tuple3)[0];
                                                                                                if(T<K){
                                                                                                    //Rule is firing 
                                                                                                    Tuple* t;
                                                                                                    std::pair<const TupleLight *, bool> insertResult;
                                                                                                    t = factory.addNewInternalTuple({TP1,N,N1}, _on);
                                                                                                    if(t->isUnknown()){
                                                                                                        generatedStack.push_back(t->getId());
                                                                                                        if(undefTuple3){
                                                                                                            insertResult = t->setStatus(TruthStatus::Undef);
                                                                                                            insertResults.push_back(std::make_pair(insertResult, 0));
                                                                                                            propagationStack->insert(std::make_pair(t->getId(), 16));
                                                                                                            if(tupleSupports.find(t->getId()) == tupleSupports.end()) tupleSupports.insert({t->getId(), std::unordered_set<int>()});
                                                                                                            tupleSupports[t->getId()].insert(16) ;
                                                                                                        }
                                                                                                        else{
                                                                                                            insertResult = t->setStatus(TruthStatus::True);
                                                                                                            insertResults.push_back(std::make_pair(insertResult, 1));
                                                                                                            printTuple(t);
                                                                                                        }
                                                                                                    }
                                                                                                    else if(t->isUndef()){
                                                                                                        if(!undefTuple3){
                                                                                                            propagationStack->erase(std::make_pair(t->getId(), 16));
                                                                                                            insertResult = t->setStatus(TruthStatus::True);
                                                                                                            insertResults.push_back(std::make_pair(insertResult, 2));
                                                                                                            generatedStack.push_back(t->getId());
                                                                                                            printTuple(t);
                                                                                                        }
                                                                                                    }
                                                                                                }//close par
                                                                                            }//close par
                                                                                        }//close par
                                                                                    }//close par
                                                                                }//close par
                                                                                for(unsigned i = 0; i< insertResults.size(); ++i){
                                                                                    if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                                                    else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                                                    else if(insertResults[i].second == 2){
                                                                                        factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                                                        insertTrue(insertResults[i].first);
                                                                                        }
                                                                                    }
                                                                                }//close par
                                                                            }
                                                                        }
                                                                        //---------------------------------------Strongly connected component propagation-----------------------
                                                                        {
                                                                            std::unordered_set<std::pair<int, int>, hashFunction>* nextPropagationStack = new std::unordered_set<std::pair<int, int>, hashFunction>();
                                                                            std::unordered_set<std::pair<int, int>, hashFunction>* temp;
                                                                            int ruleId;
                                                                            bool propagated = true;
                                                                            while(propagated){
                                                                                propagated = false;
                                                                                for(auto& tupleRule: *propagationStack){
                                                                                    Tuple* headTuple = factory.getTupleFromInternalID(tupleRule.first);
                                                                                    ruleId = tupleRule.second;
                                                                                    if(ruleId == 8){
                                                                                        {
                                                                                            std::vector< std::pair<std::pair<const TupleLight *, bool>, bool>> insertResults;
                                                                                            bool maySupport = false;
                                                                                            int TP1 = (*headTuple)[0];
                                                                                            int N = (*headTuple)[1];
                                                                                            int N1 = (*headTuple)[2];
                                                                                            bool undefTuple0= false;
                                                                                            const std::vector<int>* tuples;
                                                                                            tuples = &ptime_.getValuesVec({});
                                                                                            const std::vector<int>* tuplesU = &utime_.getValuesVec({});
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
                                                                                                    const Tuple* tuple1 = factory.find({T, N1}, _move);
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
                                                                                                        bool undefTuple2 = undefTuple1;
                                                                                                        const Tuple* tuple2 = factory.find({T, N, N1}, _on);
                                                                                                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                                                                                                        if(tuple2!= NULL){
                                                                                                            bool undefTuple3 = undefTuple2;
                                                                                                            const std::vector<int>* tuples;
                                                                                                            tuples = &psteps_.getValuesVec({});
                                                                                                            const std::vector<int>* tuplesU = &usteps_.getValuesVec({});
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
                                                                                                                    int K = (*tuple3)[0];
                                                                                                                    if(T<K){
                                                                                                                        //Rule is firing 
                                                                                                                        maySupport = true;
                                                                                                                        std::pair<const TupleLight *, bool> insertResult;
                                                                                                                        if(undefTuple3){
                                                                                                                            nextPropagationStack->insert(std::make_pair(headTuple->getId(), 8));
                                                                                                                        }
                                                                                                                        else{
                                                                                                                            insertResult = headTuple->setStatus(TruthStatus::True);
                                                                                                                            insertResults.push_back(std::make_pair(insertResult, 2));
                                                                                                                            propagated = true;
                                                                                                                            printTuple(headTuple);
                                                                                                                        }
                                                                                                                    }//close par
                                                                                                                }//close par
                                                                                                            }//close par
                                                                                                        }//close par
                                                                                                    }//close par
                                                                                                }//close par
                                                                                            }//close par
                                                                                            for(unsigned i = 0; i< insertResults.size(); ++i){
                                                                                                if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                                                                else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                                                                else if(insertResults[i].second == 2){
                                                                                                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                                                                    insertTrue(insertResults[i].first);
                                                                                                    }
                                                                                                }
                                                                                                if(!maySupport){
                                                                                                    tupleSupports[headTuple->getId()].erase(8);
                                                                                                    if(tupleSupports[headTuple->getId()].size() == 0){
                                                                                                        //removing tuple from undef
                                                                                                        printTuple(headTuple);
                                                                                                        factory.removeFromCollisionsList(headTuple->getId());
                                                                                                        factory.destroyTuple(headTuple->getId());
                                                                                                    }
                                                                                                    propagated = true;
                                                                                                }
                                                                                            }//close par
                                                                                        }
                                                                                    }
                                                                                    propagationStack->clear();
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
                                                                                std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                                                                bool undefTuple0= false;
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
                                                                                        undefTuple0 = true;
                                                                                    }
                                                                                    if(tuple0!= NULL){
                                                                                        int T = (*tuple0)[0];
                                                                                        int N = (*tuple0)[1];
                                                                                        bool undefTuple1 = undefTuple0;
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
                                                                                                undefTuple1 = true;
                                                                                            }
                                                                                            if(tuple1!= NULL){
                                                                                                int M = (*tuple1)[1];
                                                                                                bool undefTuple2 = undefTuple1;
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
                                                                                                        undefTuple2 = true;
                                                                                                    }
                                                                                                    if(tuple2!= NULL){
                                                                                                        int K = (*tuple2)[0];
                                                                                                        if(T<K){
                                                                                                            //Rule is firing 
                                                                                                            Tuple* t;
                                                                                                            std::pair<const TupleLight *, bool> insertResult;
                                                                                                            t = factory.addNewInternalTuple({T,M,N}, _put);
                                                                                                            if(t->isUnknown()){
                                                                                                                if(undefTuple2){
                                                                                                                    insertResult = t->setStatus(TruthStatus::Undef);
                                                                                                                    insertResults.push_back(std::make_pair(insertResult, 0));
                                                                                                                }
                                                                                                                else{
                                                                                                                    insertResult = t->setStatus(TruthStatus::True);
                                                                                                                    insertResults.push_back(std::make_pair(insertResult, 1));
                                                                                                                    printTuple(t);
                                                                                                                }
                                                                                                            }
                                                                                                            else if(t->isUndef()){
                                                                                                                if(!undefTuple2){
                                                                                                                    insertResult = t->setStatus(TruthStatus::True);
                                                                                                                    insertResults.push_back(std::make_pair(insertResult, 2));
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
                                                                                for(unsigned i = 0; i< insertResults.size(); ++i){
                                                                                    if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                                                    else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                                                    else if(insertResults[i].second == 2){
                                                                                        factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                                                        insertTrue(insertResults[i].first);
                                                                                        }
                                                                                    }
                                                                                }//close par
                                                                                {
                                                                                    std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                                                                    bool undefTuple0= false;
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
                                                                                            undefTuple0 = true;
                                                                                        }
                                                                                        if(tuple0!= NULL){
                                                                                            int T = (*tuple0)[0];
                                                                                            int N = (*tuple0)[1];
                                                                                            bool undefTuple1 = undefTuple0;
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
                                                                                                    undefTuple1 = true;
                                                                                                }
                                                                                                if(tuple1!= NULL){
                                                                                                    int M = (*tuple1)[1];
                                                                                                    bool undefTuple2 = undefTuple1;
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
                                                                                                            undefTuple2 = true;
                                                                                                        }
                                                                                                        if(tuple2!= NULL){
                                                                                                            int K = (*tuple2)[0];
                                                                                                            if(T<K){
                                                                                                                //Rule is firing 
                                                                                                                Tuple* t;
                                                                                                                std::pair<const TupleLight *, bool> insertResult;
                                                                                                                t = factory.addNewInternalTuple({T,M,N}, _put);
                                                                                                                if(t->isUnknown()){
                                                                                                                    if(undefTuple2){
                                                                                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                                                                                        insertResults.push_back(std::make_pair(insertResult, 0));
                                                                                                                    }
                                                                                                                    else{
                                                                                                                        insertResult = t->setStatus(TruthStatus::True);
                                                                                                                        insertResults.push_back(std::make_pair(insertResult, 1));
                                                                                                                        printTuple(t);
                                                                                                                    }
                                                                                                                }
                                                                                                                else if(t->isUndef()){
                                                                                                                    if(!undefTuple2){
                                                                                                                        insertResult = t->setStatus(TruthStatus::True);
                                                                                                                        insertResults.push_back(std::make_pair(insertResult, 2));
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
                                                                                    for(unsigned i = 0; i< insertResults.size(); ++i){
                                                                                        if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                                                        else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                                                        else if(insertResults[i].second == 2){
                                                                                            factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                                                            insertTrue(insertResults[i].first);
                                                                                            }
                                                                                        }
                                                                                    }//close par
                                                                                }
                                                                                //---------------------------------------Strongly connected component------------------------
                                                                                {
                                                                                }
                                                                                //---------------------------------------Strongly connected component------------------------
                                                                                {
                                                                                    {
                                                                                        std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                                                                        bool undefTuple0= false;
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
                                                                                                undefTuple0 = true;
                                                                                            }
                                                                                            if(tuple0!= NULL){
                                                                                                int T = (*tuple0)[0];
                                                                                                int Fv1 = (*tuple0)[1];
                                                                                                //Rule is firing 
                                                                                                Tuple* t;
                                                                                                std::pair<const TupleLight *, bool> insertResult;
                                                                                                t = factory.addNewInternalTuple({T}, _diskWhere);
                                                                                                if(t->isUnknown()){
                                                                                                    if(undefTuple0){
                                                                                                        insertResult = t->setStatus(TruthStatus::Undef);
                                                                                                        insertResults.push_back(std::make_pair(insertResult, 0));
                                                                                                    }
                                                                                                    else{
                                                                                                        insertResult = t->setStatus(TruthStatus::True);
                                                                                                        insertResults.push_back(std::make_pair(insertResult, 1));
                                                                                                        printTuple(t);
                                                                                                    }
                                                                                                }
                                                                                                else if(t->isUndef()){
                                                                                                    if(!undefTuple0){
                                                                                                        insertResult = t->setStatus(TruthStatus::True);
                                                                                                        insertResults.push_back(std::make_pair(insertResult, 2));
                                                                                                        printTuple(t);
                                                                                                    }
                                                                                                }
                                                                                            }//close par
                                                                                        }//close par
                                                                                        for(unsigned i = 0; i< insertResults.size(); ++i){
                                                                                            if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                                                            else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                                                            else if(insertResults[i].second == 2){
                                                                                                factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                                                                insertTrue(insertResults[i].first);
                                                                                                }
                                                                                            }
                                                                                        }//close par
                                                                                        {
                                                                                            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                                                                            bool undefTuple0= false;
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
                                                                                                    undefTuple0 = true;
                                                                                                }
                                                                                                if(tuple0!= NULL){
                                                                                                    int T = (*tuple0)[0];
                                                                                                    int Fv1 = (*tuple0)[1];
                                                                                                    //Rule is firing 
                                                                                                    Tuple* t;
                                                                                                    std::pair<const TupleLight *, bool> insertResult;
                                                                                                    t = factory.addNewInternalTuple({T}, _diskWhere);
                                                                                                    if(t->isUnknown()){
                                                                                                        if(undefTuple0){
                                                                                                            insertResult = t->setStatus(TruthStatus::Undef);
                                                                                                            insertResults.push_back(std::make_pair(insertResult, 0));
                                                                                                        }
                                                                                                        else{
                                                                                                            insertResult = t->setStatus(TruthStatus::True);
                                                                                                            insertResults.push_back(std::make_pair(insertResult, 1));
                                                                                                            printTuple(t);
                                                                                                        }
                                                                                                    }
                                                                                                    else if(t->isUndef()){
                                                                                                        if(!undefTuple0){
                                                                                                            insertResult = t->setStatus(TruthStatus::True);
                                                                                                            insertResults.push_back(std::make_pair(insertResult, 2));
                                                                                                            printTuple(t);
                                                                                                        }
                                                                                                    }
                                                                                                }//close par
                                                                                            }//close par
                                                                                            for(unsigned i = 0; i< insertResults.size(); ++i){
                                                                                                if(insertResults[i].second == 1) insertTrue(insertResults[i].first);
                                                                                                else if(insertResults[i].second == 0) insertUndef(insertResults[i].first);
                                                                                                else if(insertResults[i].second == 2){
                                                                                                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                                                                                    insertTrue(insertResults[i].first);
                                                                                                    }
                                                                                                }
                                                                                            }//close par
                                                                                        }
                                                                                        std::cout<<"}\n";
                                                                                        std::cout<<"\nUndefined: {\n";
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &pdiskWhere_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &udiskWhere_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            pdiskWhere_.clear();
                                                                                            udiskWhere_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &pput_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &uput_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            pput_.clear();
                                                                                            uput_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &pon_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &uon_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            pon_.clear();
                                                                                            pon_0_.clear();
                                                                                            uon_.clear();
                                                                                            uon_0_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &pon0_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &uon0_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            pon0_.clear();
                                                                                            uon0_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &pongoal_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &uongoal_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            pongoal_.clear();
                                                                                            uongoal_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &pmove_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &umove_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            pmove_.clear();
                                                                                            pmove_0_.clear();
                                                                                            pmove_1_.clear();
                                                                                            umove_.clear();
                                                                                            umove_0_.clear();
                                                                                            umove_1_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &psteps_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &usteps_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            psteps_.clear();
                                                                                            usteps_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &ptime_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &utime_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            ptime_.clear();
                                                                                            utime_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &pnoMove_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &unoMove_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            pnoMove_.clear();
                                                                                            unoMove_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &ponG_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &uonG_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            ponG_.clear();
                                                                                            uonG_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &pdisk_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &udisk_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            pdisk_.clear();
                                                                                            udisk_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &pdiskMoved_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &udiskMoved_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            pdiskMoved_.clear();
                                                                                            udiskMoved_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &pwhere_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &uwhere_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            pwhere_.clear();
                                                                                            pwhere_0_.clear();
                                                                                            uwhere_.clear();
                                                                                            uwhere_0_.clear();
                                                                                        }
                                                                                        //Removing tuples of predicates that have been completely defined
                                                                                        {
                                                                                            const std::vector<int>* tuplesToRemove;
                                                                                            tuplesToRemove = &pnoWhere_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            tuplesToRemove = &unoWhere_.getValuesVec({});
                                                                                            for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
                                                                                                printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
                                                                                                factory.destroyTuple(tuplesToRemove->at(i));
                                                                                            }
                                                                                            pnoWhere_.clear();
                                                                                            unoWhere_.clear();
                                                                                        }
                                                                                        std::cout<<"\n}\n";
                                                                                        auto finish = std::chrono::high_resolution_clock::now();
                                                                                        //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
                                                                                    }
