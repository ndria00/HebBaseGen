#include <chrono>
#include "Executor.h"
#include "../DataStructures/ConstantsManager.h"
#include "../DataStructures/IndexedSet.h"
typedef TupleLight Tuple;
template<size_t S>
using AuxMap = AuxiliaryMapSmart<S> ;
const std::vector<int> EMPTY_TUPLES_VEC;
const IndexedSet EMPTY_TUPLES_SET;
int INSERT_AS_UNDEF = 0;
int INSERT_AS_TRUE = 1;
int REMOVE_FROM_UNDEF = 2;
// Hash function
struct hashFunction{
     size_t operator()(const pair<int, int> &x) const{
        return x.first ^ x.second;
    }
};

std::vector<std::string> Executor::predicateIds;
const int _womanAssignsScore = 4;
const int _matched = 3;
const int _nonMatch = 2;
const int _manAssignsScore = 1;
const int _match = 0;
AuxMap<0> pwomanAssignsScore_({});
AuxMap<0> uwomanAssignsScore_({});
AuxMap<0> pmatched_({});
AuxMap<0> umatched_({});
AuxMap<0> pnonMatch_({});
AuxMap<0> unonMatch_({});
AuxMap<0> pmanAssignsScore_({});
AuxMap<0> umanAssignsScore_({});
AuxMap<0> pmatch_({});
AuxMap<0> umatch_({});
AuxMap<64> pmanAssignsScore_0_1_({0,1});
AuxMap<64> umanAssignsScore_0_1_({0,1});
AuxMap<32> pmatch_0_({0});
AuxMap<32> umatch_0_({0});
AuxMap<32> pmatch_1_({1});
AuxMap<32> umatch_1_({1});
AuxMap<64> pwomanAssignsScore_0_1_({0,1});
AuxMap<64> uwomanAssignsScore_0_1_({0,1});
AuxMap<64> pmatched_0_1_({0,1});
AuxMap<64> umatched_0_1_({0,1});
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
    predicateToID.insert({"womanAssignsScore", _womanAssignsScore});
    factory.addPredicate();
    predicateToID.insert({"matched", _matched});
    factory.addPredicate();
    predicateToID.insert({"nonMatch", _nonMatch});
    factory.addPredicate();
    predicateToID.insert({"manAssignsScore", _manAssignsScore});
    factory.addPredicate();
    predicateToID.insert({"match", _match});
    factory.addPredicate();
    Executor::predicateIds.push_back("match");
    Executor::predicateIds.push_back("manAssignsScore");
    Executor::predicateIds.push_back("nonMatch");
    Executor::predicateIds.push_back("matched");
    Executor::predicateIds.push_back("womanAssignsScore");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _match){
        pmatch_.insert2Vec(*insertResult.first);
        pmatch_0_.insert2Vec(*insertResult.first);
        pmatch_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _manAssignsScore){
        pmanAssignsScore_.insert2Vec(*insertResult.first);
        pmanAssignsScore_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nonMatch){
        pnonMatch_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _matched){
        pmatched_.insert2Vec(*insertResult.first);
        pmatched_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _womanAssignsScore){
        pwomanAssignsScore_.insert2Vec(*insertResult.first);
        pwomanAssignsScore_0_1_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _match){
        umatch_.insert2Vec(*insertResult.first);
        umatch_0_.insert2Vec(*insertResult.first);
        umatch_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _manAssignsScore){
        umanAssignsScore_.insert2Vec(*insertResult.first);
        umanAssignsScore_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nonMatch){
        unonMatch_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _matched){
        umatched_.insert2Vec(*insertResult.first);
        umatched_0_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _womanAssignsScore){
        uwomanAssignsScore_.insert2Vec(*insertResult.first);
        uwomanAssignsScore_0_1_.insert2Vec(*insertResult.first);
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
bool Executor::saveSourcePointAndSupports(int headTuple, int bodyTuple){
    bool toCheck= true;
    if(sourcePointers.find(bodyTuple) != sourcePointers.end()) toCheck = false;
    if(bodyTuple != TupleLight::DUMMY_TUPLE_ID){
        sourcePointers.at(headTuple).insert(bodyTuple);
        if(supportedByUndef.find(bodyTuple) == supportedByUndef.end()) supportedByUndef.insert({bodyTuple, std::unordered_set<int>()});
        else supportedByUndef.at(bodyTuple).insert(headTuple);
    }
    return toCheck;
}
void Executor::executeProgram(){
    const Tuple dummyTuple = Tuple();
    auto start = std::chrono::high_resolution_clock::now();
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        sourcePointers.clear();
        supportedByUndef.clear();
        std::unordered_set<int>* propagationSet = new std::unordered_set<int>();
        {
            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
            bool undefTuple0 = false;
            const std::vector<int>* tuples;
            tuples = &pmanAssignsScore_.getValuesVec({});
            const std::vector<int>* tuplesU = &umanAssignsScore_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0 != NULL){
                    int M = (*tuple0)[0];
                    int W = (*tuple0)[1];
                    int S = (*tuple0)[2];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({M, W}, _nonMatch);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1 != NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({M,W}, _match);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                bool toCheck = true;
                                if(sourcePointers.find(t->getId()) == sourcePointers.end()){
                                    sourcePointers.insert({t->getId(), std::unordered_set<int>()});
                                    toCheck = saveSourcePointAndSupports(t->getId(), tuple0->getId());
                                    toCheck = saveSourcePointAndSupports(t->getId(), tuple1->getId());
                                    if(toCheck) propagationSet->insert(t->getId());
                                }
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertResults.push_back(std::make_pair(insertResult, INSERT_AS_TRUE));
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                insertResult = t->setStatus(TruthStatus::True);
                                insertResults.push_back(std::make_pair(insertResult, REMOVE_FROM_UNDEF));
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
            for(unsigned i = 0; i< insertResults.size(); ++i){
                if(insertResults[i].second == INSERT_AS_TRUE) insertTrue(insertResults[i].first);
                else if(insertResults[i].second == INSERT_AS_UNDEF) insertUndef(insertResults[i].first);
                else if(insertResults[i].second == REMOVE_FROM_UNDEF){
                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                    insertTrue(insertResults[i].first);
                }
            }
        }//close par
        {
            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
            bool undefTuple0 = false;
            const std::vector<int>* tuples;
            tuples = &pmanAssignsScore_.getValuesVec({});
            const std::vector<int>* tuplesU = &umanAssignsScore_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0 != NULL){
                    int M = (*tuple0)[0];
                    int W = (*tuple0)[1];
                    int S = (*tuple0)[2];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({M, W}, _match);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                        undefTuple1 = true;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1 != NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({M,W}, _nonMatch);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                bool toCheck = true;
                                if(sourcePointers.find(t->getId()) == sourcePointers.end()){
                                    sourcePointers.insert({t->getId(), std::unordered_set<int>()});
                                    toCheck = saveSourcePointAndSupports(t->getId(), tuple0->getId());
                                    toCheck = saveSourcePointAndSupports(t->getId(), tuple1->getId());
                                    if(toCheck) propagationSet->insert(t->getId());
                                }
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertResults.push_back(std::make_pair(insertResult, INSERT_AS_TRUE));
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple1){
                                insertResult = t->setStatus(TruthStatus::True);
                                insertResults.push_back(std::make_pair(insertResult, REMOVE_FROM_UNDEF));
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
            for(unsigned i = 0; i< insertResults.size(); ++i){
                if(insertResults[i].second == INSERT_AS_TRUE) insertTrue(insertResults[i].first);
                else if(insertResults[i].second == INSERT_AS_UNDEF) insertUndef(insertResults[i].first);
                else if(insertResults[i].second == REMOVE_FROM_UNDEF){
                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                    insertTrue(insertResults[i].first);
                }
            }
        }//close par
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            const Tuple* tuple0 = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            bool recursiveTupleUndef = recursiveTuple->isUndef();
            if(literalName == _nonMatch){
                {
                    std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                    bool undefTuple0 = false;
                    int W = (*recursiveTuple)[1];
                    int M = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const std::vector<int>* tuples;
                        tuples = &pmanAssignsScore_0_1_.getValuesVec({M, W});
                        const std::vector<int>* tuplesU = &umanAssignsScore_0_1_.getValuesVec({M, W});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple1 = NULL;
                            if(i < tuples->size()){
                                tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple1 = true;
                            }
                            if(tuple1 != NULL){
                                int S = (*tuple1)[2];
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({M,W}, _match);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple1){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                        bool toCheck = true;
                                        if(sourcePointers.find(t->getId()) == sourcePointers.end()){
                                            sourcePointers.insert({t->getId(), std::unordered_set<int>()});
                                            toCheck = saveSourcePointAndSupports(t->getId(), tuple0->getId());
                                            toCheck = saveSourcePointAndSupports(t->getId(), tuple1->getId());
                                            if(toCheck) propagationSet->insert(t->getId());
                                        }
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertResults.push_back(std::make_pair(insertResult, INSERT_AS_TRUE));
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple1){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertResults.push_back(std::make_pair(insertResult, REMOVE_FROM_UNDEF));
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                    for(unsigned i = 0; i< insertResults.size(); ++i){
                        if(insertResults[i].second == INSERT_AS_TRUE) insertTrue(insertResults[i].first);
                        else if(insertResults[i].second == INSERT_AS_UNDEF) insertUndef(insertResults[i].first);
                        else if(insertResults[i].second == REMOVE_FROM_UNDEF){
                            factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                            insertTrue(insertResults[i].first);
                        }
                    }
                }//close par
            }
            if(literalName == _match){
                {
                    std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                    bool undefTuple0 = false;
                    int W = (*recursiveTuple)[1];
                    int M = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const std::vector<int>* tuples;
                        tuples = &pmanAssignsScore_0_1_.getValuesVec({M, W});
                        const std::vector<int>* tuplesU = &umanAssignsScore_0_1_.getValuesVec({M, W});
                        for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                            const Tuple * tuple1 = NULL;
                            if(i < tuples->size()){
                                tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                            }
                            else {
                                tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                undefTuple1 = true;
                            }
                            if(tuple1 != NULL){
                                int S = (*tuple1)[2];
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({M,W}, _nonMatch);
                                if(t->isUnknown()){
                                    generatedStack.push_back(t->getId());
                                    if(undefTuple1){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                        bool toCheck = true;
                                        if(sourcePointers.find(t->getId()) == sourcePointers.end()){
                                            sourcePointers.insert({t->getId(), std::unordered_set<int>()});
                                            toCheck = saveSourcePointAndSupports(t->getId(), tuple0->getId());
                                            toCheck = saveSourcePointAndSupports(t->getId(), tuple1->getId());
                                            if(toCheck) propagationSet->insert(t->getId());
                                        }
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertResults.push_back(std::make_pair(insertResult, INSERT_AS_TRUE));
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple1){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertResults.push_back(std::make_pair(insertResult, REMOVE_FROM_UNDEF));
                                        generatedStack.push_back(t->getId());
                                        printTuple(t);
                                    }
                                }
                            }//close par
                        }//close par
                    }//close par
                    for(unsigned i = 0; i< insertResults.size(); ++i){
                        if(insertResults[i].second == INSERT_AS_TRUE) insertTrue(insertResults[i].first);
                        else if(insertResults[i].second == INSERT_AS_UNDEF) insertUndef(insertResults[i].first);
                        else if(insertResults[i].second == REMOVE_FROM_UNDEF){
                            factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                            insertTrue(insertResults[i].first);
                        }
                    }
                }//close par
            }
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        sourcePointers.clear();
        supportedByUndef.clear();
        std::unordered_set<int>* propagationSet = new std::unordered_set<int>();
        {
            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
            bool undefTuple0 = false;
            const std::vector<int>* tuples;
            tuples = &pmatch_.getValuesVec({});
            const std::vector<int>* tuplesU = &umatch_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0 != NULL){
                    int M = (*tuple0)[0];
                    int W = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pmanAssignsScore_0_1_.getValuesVec({M, W});
                    const std::vector<int>* tuplesU = &umanAssignsScore_0_1_.getValuesVec({M, W});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple1 = true;
                        }
                        if(tuple1 != NULL){
                            int S = (*tuple1)[2];
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("m"),M,S}, _matched);
                            if(t->isUnknown()){
                                if(undefTuple1){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                }
                                else{
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertResults.push_back(std::make_pair(insertResult, INSERT_AS_TRUE));
                                    printTuple(t);
                                }
                            }
                            else if(t->isUndef()){
                                if(!undefTuple1){
                                    insertResult = t->setStatus(TruthStatus::True);
                                    insertResults.push_back(std::make_pair(insertResult, REMOVE_FROM_UNDEF));
                                    generatedStack.push_back(t->getId());
                                    printTuple(t);
                                }
                            }
                        }//close par
                    }//close par
                }//close par
            }//close par
            for(unsigned i = 0; i< insertResults.size(); ++i){
                if(insertResults[i].second == INSERT_AS_TRUE) insertTrue(insertResults[i].first);
                else if(insertResults[i].second == INSERT_AS_UNDEF) insertUndef(insertResults[i].first);
                else if(insertResults[i].second == REMOVE_FROM_UNDEF){
                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                    insertTrue(insertResults[i].first);
                }
            }
        }//close par
        {
            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
            bool undefTuple0 = false;
            const std::vector<int>* tuples;
            tuples = &pmatch_.getValuesVec({});
            const std::vector<int>* tuplesU = &umatch_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0 != NULL){
                    int M = (*tuple0)[0];
                    int W = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pwomanAssignsScore_0_1_.getValuesVec({W, M});
                    const std::vector<int>* tuplesU = &uwomanAssignsScore_0_1_.getValuesVec({W, M});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                            undefTuple1 = true;
                        }
                        if(tuple1 != NULL){
                            int S = (*tuple1)[2];
                            int S1 = S-1;
                            if(1<S){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({ConstantsManager::getInstance().mapConstant("w"),W,S1}, _matched);
                                if(t->isUnknown()){
                                    if(undefTuple1){
                                        insertResult = t->setStatus(TruthStatus::Undef);
                                        insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                    }
                                    else{
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertResults.push_back(std::make_pair(insertResult, INSERT_AS_TRUE));
                                        printTuple(t);
                                    }
                                }
                                else if(t->isUndef()){
                                    if(!undefTuple1){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertResults.push_back(std::make_pair(insertResult, REMOVE_FROM_UNDEF));
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
                if(insertResults[i].second == INSERT_AS_TRUE) insertTrue(insertResults[i].first);
                else if(insertResults[i].second == INSERT_AS_UNDEF) insertUndef(insertResults[i].first);
                else if(insertResults[i].second == REMOVE_FROM_UNDEF){
                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                    insertTrue(insertResults[i].first);
                }
            }
        }//close par
        {
            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
            bool undefTuple0 = false;
            const std::vector<int>* tuples;
            tuples = &pmatched_.getValuesVec({});
            const std::vector<int>* tuplesU = &umatched_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                    undefTuple0 = true;
                }
                if(tuple0 != NULL){
                    int T = (*tuple0)[0];
                    int P = (*tuple0)[1];
                    int S = (*tuple0)[2];
                    int S1 = S-1;
                    if(1<S){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({T,P,S1}, _matched);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple0){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                bool toCheck = true;
                                if(sourcePointers.find(t->getId()) == sourcePointers.end()){
                                    sourcePointers.insert({t->getId(), std::unordered_set<int>()});
                                    toCheck = saveSourcePointAndSupports(t->getId(), tuple0->getId());
                                    if(toCheck) propagationSet->insert(t->getId());
                                }
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertResults.push_back(std::make_pair(insertResult, INSERT_AS_TRUE));
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple0){
                                insertResult = t->setStatus(TruthStatus::True);
                                insertResults.push_back(std::make_pair(insertResult, REMOVE_FROM_UNDEF));
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                }//close par
            }//close par
            for(unsigned i = 0; i< insertResults.size(); ++i){
                if(insertResults[i].second == INSERT_AS_TRUE) insertTrue(insertResults[i].first);
                else if(insertResults[i].second == INSERT_AS_UNDEF) insertUndef(insertResults[i].first);
                else if(insertResults[i].second == REMOVE_FROM_UNDEF){
                    factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                    insertTrue(insertResults[i].first);
                }
            }
        }//close par
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            const Tuple* tuple0 = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            bool recursiveTupleUndef = recursiveTuple->isUndef();
            if(literalName == _matched){
                {
                    std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                    bool undefTuple0 = false;
                    int S = (*recursiveTuple)[2];
                    int P = (*recursiveTuple)[1];
                    int T = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    int S1 = S-1;
                    if(1<S){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({T,P,S1}, _matched);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple0){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                bool toCheck = true;
                                if(sourcePointers.find(t->getId()) == sourcePointers.end()){
                                    sourcePointers.insert({t->getId(), std::unordered_set<int>()});
                                    toCheck = saveSourcePointAndSupports(t->getId(), tuple0->getId());
                                    if(toCheck) propagationSet->insert(t->getId());
                                }
                            }
                            else{
                                insertResult = t->setStatus(TruthStatus::True);
                                insertResults.push_back(std::make_pair(insertResult, INSERT_AS_TRUE));
                                printTuple(t);
                            }
                        }
                        else if(t->isUndef()){
                            if(!undefTuple0){
                                insertResult = t->setStatus(TruthStatus::True);
                                insertResults.push_back(std::make_pair(insertResult, REMOVE_FROM_UNDEF));
                                generatedStack.push_back(t->getId());
                                printTuple(t);
                            }
                        }
                    }//close par
                    for(unsigned i = 0; i< insertResults.size(); ++i){
                        if(insertResults[i].second == INSERT_AS_TRUE) insertTrue(insertResults[i].first);
                        else if(insertResults[i].second == INSERT_AS_UNDEF) insertUndef(insertResults[i].first);
                        else if(insertResults[i].second == REMOVE_FROM_UNDEF){
                            factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                            insertTrue(insertResults[i].first);
                        }
                    }
                }//close par
            }
        }
        //---------------------------------------Strongly connected component propagation-----------------------
        {
            std::unordered_set<int>* nextPropagationSet = new std::unordered_set<int>();
            std::unordered_set<int>* temp;
            bool propagated = true;
            while(propagated){
                propagated = false;
                for(int tupleId: *propagationSet){
                    Tuple* headTuple = factory.getTupleFromInternalID(tupleId);
                    int rulePred = headTuple->getPredicateName();
                    if(rulePred == _matched){
                        bool maySupport = false;
                        bool propagatedToTrue = false;
                        if(!propagatedToTrue){
                            {
                                std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                int T = (*headTuple)[0];
                                int P = (*headTuple)[1];
                                int S1 = (*headTuple)[2];
                                bool undefTuple0 = false;
                                const std::vector<int>* tuples;
                                tuples = &pmatched_0_1_.getValuesVec({T, P});
                                const std::vector<int>* tuplesU = &umatched_0_1_.getValuesVec({T, P});
                                for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                                    const Tuple * tuple0 = NULL;
                                    if(i < tuples->size()){
                                        tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                                    }
                                    else {
                                        tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                                        undefTuple0 = true;
                                    }
                                    if(tuple0 != NULL){
                                        int S = (*tuple0)[2];
                                        if(1<S){
                                            //Rule is firing 
                                            maySupport = true;
                                            std::pair<const TupleLight *, bool> insertResult;
                                            if(undefTuple0){
                                                // nextPropagationSet->insert(headTuple->getId());
                                            }
                                            else{
                                                insertResult = headTuple->setStatus(TruthStatus::True);
                                                propagatedToTrue = true;
                                                propagated = true;
                                                insertResults.push_back(std::make_pair(insertResult, REMOVE_FROM_UNDEF));
                                                for(int i : supportedByUndef[headTuple->getId()]){ nextPropagationSet->insert(i);}
                                                printTuple(headTuple);
                                            }
                                        }//close par
                                    }//close par
                                }//close par
                                for(unsigned i = 0; i< insertResults.size(); ++i){
                                    if(insertResults[i].second == INSERT_AS_TRUE) insertTrue(insertResults[i].first);
                                    else if(insertResults[i].second == INSERT_AS_UNDEF) insertUndef(insertResults[i].first);
                                    else if(insertResults[i].second == REMOVE_FROM_UNDEF){
                                        factory.removeFromCollisionsList(insertResults[i].first.first->getId());
                                        insertTrue(insertResults[i].first);
                                    }
                                }
                            }//close par
                        }
                        if(!maySupport){
                            //removing tuple from undef
                            propagated = true;
                            for(int i : supportedByUndef[headTuple->getId()]){ nextPropagationSet->insert(i);}
                            factory.removeFromCollisionsList(headTuple->getId());
                            factory.destroyTuple(headTuple->getId());
                        }
                    }
                }
                propagationSet->clear();
                temp = propagationSet;
                propagationSet = nextPropagationSet;
                nextPropagationSet = temp;
                nextPropagationSet->clear();
            }
            delete nextPropagationSet;
            delete propagationSet;
        }
    }
    std::cout<<"}\n";
    std::cout<<"\nUndefined: {\n";
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pmatch_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &umatch_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pmatch_.clear();
        pmatch_0_.clear();
        pmatch_1_.clear();
        umatch_.clear();
        umatch_0_.clear();
        umatch_1_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pmanAssignsScore_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &umanAssignsScore_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pmanAssignsScore_.clear();
        pmanAssignsScore_0_1_.clear();
        umanAssignsScore_.clear();
        umanAssignsScore_0_1_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pnonMatch_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &unonMatch_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pnonMatch_.clear();
        unonMatch_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pmatched_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &umatched_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pmatched_.clear();
        pmatched_0_1_.clear();
        umatched_.clear();
        umatched_0_1_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pwomanAssignsScore_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uwomanAssignsScore_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pwomanAssignsScore_.clear();
        pwomanAssignsScore_0_1_.clear();
        uwomanAssignsScore_.clear();
        uwomanAssignsScore_0_1_.clear();
    }
    std::cout<<"\n}\n";
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
