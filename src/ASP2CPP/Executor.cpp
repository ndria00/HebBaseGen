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
const int _merge = 8;
const int _drop = 6;
const int _delta = 5;
const int _symbol = 4;
const int _accept = 3;
const int _dist = 2;
const int _state = 1;
const int _keep = 7;
const int _pair = 0;
AuxMap<0> pmerge_({});
AuxMap<0> umerge_({});
AuxMap<0> pdrop_({});
AuxMap<0> udrop_({});
AuxMap<0> pdelta_({});
AuxMap<0> udelta_({});
AuxMap<0> psymbol_({});
AuxMap<0> usymbol_({});
AuxMap<0> paccept_({});
AuxMap<0> uaccept_({});
AuxMap<0> pdist_({});
AuxMap<0> udist_({});
AuxMap<0> pstate_({});
AuxMap<0> ustate_({});
AuxMap<0> pkeep_({});
AuxMap<0> ukeep_({});
AuxMap<0> ppair_({});
AuxMap<0> upair_({});
AuxMap<64> pdelta_0_1_({0,1});
AuxMap<64> udelta_0_1_({0,1});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"merge", _merge});
    factory.addPredicate();
    predicateToID.insert({"drop", _drop});
    factory.addPredicate();
    predicateToID.insert({"delta", _delta});
    factory.addPredicate();
    predicateToID.insert({"symbol", _symbol});
    factory.addPredicate();
    predicateToID.insert({"accept", _accept});
    factory.addPredicate();
    predicateToID.insert({"dist", _dist});
    factory.addPredicate();
    predicateToID.insert({"state", _state});
    factory.addPredicate();
    predicateToID.insert({"keep", _keep});
    factory.addPredicate();
    predicateToID.insert({"pair", _pair});
    factory.addPredicate();
    Executor::predicateIds.push_back("pair");
    Executor::predicateIds.push_back("state");
    Executor::predicateIds.push_back("dist");
    Executor::predicateIds.push_back("accept");
    Executor::predicateIds.push_back("symbol");
    Executor::predicateIds.push_back("delta");
    Executor::predicateIds.push_back("drop");
    Executor::predicateIds.push_back("keep");
    Executor::predicateIds.push_back("merge");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _pair){
        ppair_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _keep){
        pkeep_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _state){
        pstate_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _dist){
        pdist_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _accept){
        paccept_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _symbol){
        psymbol_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _delta){
        pdelta_.insert2Vec(*insertResult.first);
        pdelta_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _drop){
        pdrop_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _merge){
        pmerge_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _pair){
        upair_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _keep){
        ukeep_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _state){
        ustate_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _dist){
        udist_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _accept){
        uaccept_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _symbol){
        usymbol_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _delta){
        udelta_.insert2Vec(*insertResult.first);
        udelta_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _drop){
        udrop_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _merge){
        umerge_.insert2Vec(*insertResult.first);
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
            const std::vector<int>* tuples;
            tuples = &pstate_.getValuesVec({});
            const std::vector<int>* tuplesU = &ustate_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                }
                if(tuple0!= NULL){
                    int S = (*tuple0)[0];
                    const std::vector<int>* tuples;
                    tuples = &pstate_.getValuesVec({});
                    const std::vector<int>* tuplesU = &ustate_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                        }
                        if(tuple1!= NULL){
                            int T = (*tuple1)[0];
                            if(S<T){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({S,T}, _pair);
                                if(t->isUnknown()){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertTrue(insertResult);
                                }
                                else if(t->isUndef()){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    factory.removeFromCollisionsList(t->getId());
                                    insertTrue(insertResult);
                                }
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
            const std::vector<int>* tuples;
            tuples = &pstate_.getValuesVec({});
            const std::vector<int>* tuplesU = &ustate_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                }
                if(tuple0!= NULL){
                    int S = (*tuple0)[0];
                    const Tuple* tuple1 = factory.find({S}, _accept);
                    if(tuple1!= NULL){
                        const std::vector<int>* tuples;
                        tuples = &pstate_.getValuesVec({});
                        const std::vector<int>* tuplesU = &ustate_.getValuesVec({});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            }
                            if(tuple2!= NULL){
                                int T = (*tuple2)[0];
                                const Tuple negativeTuple = Tuple({T}, _accept, true);
                                const Tuple* tuple3 = factory.find({T}, _accept);
                                if(tuple3 == NULL){
                                    tuple3 = &negativeTuple;
                                }
                                else{
                                    if(tuple3->isTrue())    tuple3= NULL;
                                }
                                if(tuple3!= NULL){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({S,T}, _dist);
                                    if(t->isUnknown()){
                                        generatedStack.push_back(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                    else if(t->isUndef()){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
                                }//close par
                            }//close par
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        {
            const std::vector<int>* tuples;
            tuples = &pstate_.getValuesVec({});
            const std::vector<int>* tuplesU = &ustate_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                }
                if(tuple0!= NULL){
                    int S = (*tuple0)[0];
                    const Tuple negativeTuple = Tuple({S}, _accept, true);
                    const Tuple* tuple1 = factory.find({S}, _accept);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                    }
                    if(tuple1!= NULL){
                        const std::vector<int>* tuples;
                        tuples = &pstate_.getValuesVec({});
                        const std::vector<int>* tuplesU = &ustate_.getValuesVec({});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple2 = NULL;
                            if(i < tuples->size()){
                                tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            }
                            if(tuple2!= NULL){
                                int T = (*tuple2)[0];
                                const Tuple* tuple3 = factory.find({T}, _accept);
                                if(tuple3!= NULL){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({S,T}, _dist);
                                    if(t->isUnknown()){
                                        generatedStack.push_back(t->getId());
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertTrue(insertResult);
                                    }
                                    else if(t->isUndef()){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        factory.removeFromCollisionsList(t->getId());
                                        insertTrue(insertResult);
                                    }
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
            if(literalName == _dist){
                {
                    int Y = (*recursiveTuple)[1];
                    int X = (*recursiveTuple)[0];
                    const std::vector<int>* tuples;
                    tuples = &pstate_.getValuesVec({});
                    const std::vector<int>* tuplesU = &ustate_.getValuesVec({});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                        }
                        if(tuple1!= NULL){
                            int S = (*tuple1)[0];
                            const std::vector<int>* tuples;
                            tuples = &pstate_.getValuesVec({});
                            const std::vector<int>* tuplesU = &ustate_.getValuesVec({});
                            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                const Tuple * tuple2 = NULL;
                                if(i < tuples->size()){
                                    tuple2 = factory.getTupleFromInternalID(tuples->at(i));
                                }
                                else {
                                    tuple2 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                }
                                if(tuple2!= NULL){
                                    int T = (*tuple2)[0];
                                    const std::vector<int>* tuples;
                                    tuples = &psymbol_.getValuesVec({});
                                    const std::vector<int>* tuplesU = &usymbol_.getValuesVec({});
                                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                        const Tuple * tuple3 = NULL;
                                        if(i < tuples->size()){
                                            tuple3 = factory.getTupleFromInternalID(tuples->at(i));
                                        }
                                        else {
                                            tuple3 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                        }
                                        if(tuple3!= NULL){
                                            int A = (*tuple3)[0];
                                            const Tuple* tuple4 = factory.find({S, A, X}, _delta);
                                            if(tuple4!= NULL){
                                                const Tuple* tuple5 = factory.find({T, A, Y}, _delta);
                                                if(tuple5!= NULL){
                                                    //Rule is firing 
                                                    Tuple* t;
                                                    std::pair<const TupleLight *, bool> insertResult;
                                                    t = factory.addNewInternalTuple({S,T}, _dist);
                                                    if(t->isUnknown()){
                                                        generatedStack.push_back(t->getId());
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        insertTrue(insertResult);
                                                    }
                                                    else if(t->isUndef()){
                                                        insertResult = t->setStatus(TruthStatus::True);
                                                        factory.removeFromCollisionsList(t->getId());
                                                        insertTrue(insertResult);
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
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            const std::vector<int>* tuples;
            tuples = &ppair_.getValuesVec({});
            const std::vector<int>* tuplesU = &upair_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                }
                if(tuple0!= NULL){
                    int S = (*tuple0)[0];
                    int T = (*tuple0)[1];
                    const Tuple negativeTuple = Tuple({S, T}, _dist, true);
                    const Tuple* tuple1 = factory.find({S, T}, _dist);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({T}, _drop);
                        if(t->isUnknown()){
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                        }
                        else if(t->isUndef()){
                            insertResult = t->setStatus(TruthStatus::True);
                            factory.removeFromCollisionsList(t->getId());
                            insertTrue(insertResult);
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            const std::vector<int>* tuples;
            tuples = &pstate_.getValuesVec({});
            const std::vector<int>* tuplesU = &ustate_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                }
                if(tuple0!= NULL){
                    int S = (*tuple0)[0];
                    const Tuple negativeTuple = Tuple({S}, _drop, true);
                    const Tuple* tuple1 = factory.find({S}, _drop);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                    }
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({S}, _keep);
                        if(t->isUnknown()){
                            insertResult = t->setStatus(TruthStatus::True);
                            insertTrue(insertResult);
                        }
                        else if(t->isUndef()){
                            insertResult = t->setStatus(TruthStatus::True);
                            factory.removeFromCollisionsList(t->getId());
                            insertTrue(insertResult);
                        }
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            const std::vector<int>* tuples;
            tuples = &ppair_.getValuesVec({});
            const std::vector<int>* tuplesU = &upair_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                }
                if(tuple0!= NULL){
                    int S = (*tuple0)[0];
                    int T = (*tuple0)[1];
                    const Tuple negativeTuple = Tuple({S, T}, _dist, true);
                    const Tuple* tuple1 = factory.find({S, T}, _dist);
                    if(tuple1 == NULL){
                        tuple1 = &negativeTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                    }
                    if(tuple1!= NULL){
                        const Tuple* tuple2 = factory.find({S}, _keep);
                        if(tuple2!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({S,T}, _merge);
                            if(t->isUnknown()){
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                            else if(t->isUndef()){
                                insertResult = t->setStatus(TruthStatus::True);
                                factory.removeFromCollisionsList(t->getId());
                                insertTrue(insertResult);
                            }
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
    }
    printGeneratedBase();
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
void Executor::printGeneratedBase(){
    const std::vector<int>* tuples;
    tuples = &pmerge_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &umerge_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pdrop_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &udrop_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pdelta_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &udelta_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &psymbol_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &usymbol_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &paccept_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uaccept_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pdist_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &udist_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pstate_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ustate_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pkeep_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ukeep_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ppair_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &upair_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
}
