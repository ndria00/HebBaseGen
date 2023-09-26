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
const int _uncut = 5;
const int _cut = 3;
const int _in = 2;
const int _edge = 4;
const int _node = 1;
const int _out = 0;
AuxMap<0> puncut_({});
AuxMap<0> uuncut_({});
AuxMap<0> pcut_({});
AuxMap<0> ucut_({});
AuxMap<0> pin_({});
AuxMap<0> uin_({});
AuxMap<0> pedge_({});
AuxMap<0> uedge_({});
AuxMap<0> pnode_({});
AuxMap<0> unode_({});
AuxMap<0> pout_({});
AuxMap<0> uout_({});
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
    predicateToID.insert({"uncut", _uncut});
    factory.addPredicate();
    predicateToID.insert({"cut", _cut});
    factory.addPredicate();
    predicateToID.insert({"in", _in});
    factory.addPredicate();
    predicateToID.insert({"edge", _edge});
    factory.addPredicate();
    predicateToID.insert({"node", _node});
    factory.addPredicate();
    predicateToID.insert({"out", _out});
    factory.addPredicate();
    Executor::predicateIds.push_back("out");
    Executor::predicateIds.push_back("node");
    Executor::predicateIds.push_back("in");
    Executor::predicateIds.push_back("cut");
    Executor::predicateIds.push_back("edge");
    Executor::predicateIds.push_back("uncut");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _out){
        pout_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _node){
        pnode_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _edge){
        pedge_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _in){
        pin_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _cut){
        pcut_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _uncut){
        puncut_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _out){
        uout_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _node){
        unode_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _edge){
        uedge_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _in){
        uin_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _cut){
        ucut_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _uncut){
        uuncut_.insert2Vec(*insertResult.first);
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
        std::vector<int> generatedStack;
        std::unordered_map<unsigned, std::unordered_set<int>> sourcePointers;
        std::unordered_map<unsigned, std::unordered_set<int>> supportedByUndef;
        std::unordered_set<int>* propagationSet = new std::unordered_set<int>();
        {
            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
            bool undefTuple0 = false;
            const std::vector<int>* tuples;
            tuples = &pnode_.getValuesVec({});
            const std::vector<int>* tuplesU = &unode_.getValuesVec({});
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
                    int X = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X}, _in);
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
                        t = factory.addNewInternalTuple({X}, _out);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                bool toCheck = true;
                                if(sourcePointers.find(t->getId()) == sourcePointers.end()){
                                    sourcePointers.insert({t->getId(), std::unordered_set<int>()});
                                    sourcePointers.at(t->getId()).insert(tuple0->getId());
                                    if(sourcePointers.find(tuple0->getId()) != sourcePointers.end()) toCheck = false;
                                    if(supportedByUndef.find(tuple0->getId()) == supportedByUndef.end()) supportedByUndef.insert({tuple0->getId(), std::unordered_set<int>()});
                                    else supportedByUndef.at(tuple0->getId()).insert(t->getId());
                                    if(!tuple1->isDummy()){
                                        sourcePointers.at(t->getId()).insert(tuple1->getId());
                                        if(sourcePointers.find(tuple1->getId()) != sourcePointers.end()) toCheck = false;
                                        if(supportedByUndef.find(tuple1->getId()) == supportedByUndef.end()) supportedByUndef.insert({tuple1->getId(), std::unordered_set<int>()});
                                        else supportedByUndef.at(tuple1->getId()).insert(t->getId());
                                    }
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
            tuples = &pnode_.getValuesVec({});
            const std::vector<int>* tuplesU = &unode_.getValuesVec({});
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
                    int X = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X}, _out);
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
                        t = factory.addNewInternalTuple({X}, _in);
                        if(t->isUnknown()){
                            generatedStack.push_back(t->getId());
                            if(undefTuple1){
                                insertResult = t->setStatus(TruthStatus::Undef);
                                insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                bool toCheck = true;
                                if(sourcePointers.find(t->getId()) == sourcePointers.end()){
                                    sourcePointers.insert({t->getId(), std::unordered_set<int>()});
                                    sourcePointers.at(t->getId()).insert(tuple0->getId());
                                    if(sourcePointers.find(tuple0->getId()) != sourcePointers.end()) toCheck = false;
                                    if(supportedByUndef.find(tuple0->getId()) == supportedByUndef.end()) supportedByUndef.insert({tuple0->getId(), std::unordered_set<int>()});
                                    else supportedByUndef.at(tuple0->getId()).insert(t->getId());
                                    if(!tuple1->isDummy()){
                                        sourcePointers.at(t->getId()).insert(tuple1->getId());
                                        if(sourcePointers.find(tuple1->getId()) != sourcePointers.end()) toCheck = false;
                                        if(supportedByUndef.find(tuple1->getId()) == supportedByUndef.end()) supportedByUndef.insert({tuple1->getId(), std::unordered_set<int>()});
                                        else supportedByUndef.at(tuple1->getId()).insert(t->getId());
                                    }
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
            if(literalName == _in){
                {
                    std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                    bool undefTuple0 = false;
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({X}, _node);
                        if(tuple1 != NULL && tuple1->isUndef()){
                            undefTuple1 = true;
                        }
                        if(tuple1 != NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X}, _out);
                            if(t->isUnknown()){
                                generatedStack.push_back(t->getId());
                                if(undefTuple1){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                    bool toCheck = true;
                                    if(sourcePointers.find(t->getId()) == sourcePointers.end()){
                                        sourcePointers.insert({t->getId(), std::unordered_set<int>()});
                                        if(!tuple0->isDummy()){
                                            sourcePointers.at(t->getId()).insert(tuple0->getId());
                                            if(sourcePointers.find(tuple0->getId()) != sourcePointers.end()) toCheck = false;
                                            if(supportedByUndef.find(tuple0->getId()) == supportedByUndef.end()) supportedByUndef.insert({tuple0->getId(), std::unordered_set<int>()});
                                            else supportedByUndef.at(tuple0->getId()).insert(t->getId());
                                        }
                                        sourcePointers.at(t->getId()).insert(tuple1->getId());
                                        if(sourcePointers.find(tuple1->getId()) != sourcePointers.end()) toCheck = false;
                                        if(supportedByUndef.find(tuple1->getId()) == supportedByUndef.end()) supportedByUndef.insert({tuple1->getId(), std::unordered_set<int>()});
                                        else supportedByUndef.at(tuple1->getId()).insert(t->getId());
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
            if(literalName == _out){
                {
                    std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                    bool undefTuple0 = false;
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({X}, _node);
                        if(tuple1 != NULL && tuple1->isUndef()){
                            undefTuple1 = true;
                        }
                        if(tuple1 != NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X}, _in);
                            if(t->isUnknown()){
                                generatedStack.push_back(t->getId());
                                if(undefTuple1){
                                    insertResult = t->setStatus(TruthStatus::Undef);
                                    insertResults.push_back(std::make_pair(insertResult, INSERT_AS_UNDEF));
                                    bool toCheck = true;
                                    if(sourcePointers.find(t->getId()) == sourcePointers.end()){
                                        sourcePointers.insert({t->getId(), std::unordered_set<int>()});
                                        if(!tuple0->isDummy()){
                                            sourcePointers.at(t->getId()).insert(tuple0->getId());
                                            if(sourcePointers.find(tuple0->getId()) != sourcePointers.end()) toCheck = false;
                                            if(supportedByUndef.find(tuple0->getId()) == supportedByUndef.end()) supportedByUndef.insert({tuple0->getId(), std::unordered_set<int>()});
                                            else supportedByUndef.at(tuple0->getId()).insert(t->getId());
                                        }
                                        sourcePointers.at(t->getId()).insert(tuple1->getId());
                                        if(sourcePointers.find(tuple1->getId()) != sourcePointers.end()) toCheck = false;
                                        if(supportedByUndef.find(tuple1->getId()) == supportedByUndef.end()) supportedByUndef.insert({tuple1->getId(), std::unordered_set<int>()});
                                        else supportedByUndef.at(tuple1->getId()).insert(t->getId());
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
                    if(rulePred == _in){
                        bool maySupport = false;
                        bool propagatedToTrue = false;
                        if(!propagatedToTrue){
                            {
                                std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                int X = (*headTuple)[0];
                                bool undefTuple0 = false;
                                const Tuple* tuple0 = factory.find({X}, _out);
                                if(tuple0 == NULL){
                                    tuple0 = &dummyTuple;
                                }
                                else{
                                    if(tuple0->isTrue()){
                                        tuple0= NULL;
                                    }
                                    else undefTuple0 = true;
                                }
                                if(tuple0 != NULL){
                                    bool undefTuple1 = undefTuple0;
                                    const Tuple* tuple1 = factory.find({X}, _node);
                                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                                    if(tuple1 != NULL){
                                        //Rule is firing 
                                        maySupport = true;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        if(undefTuple1){
                                            std::cout <<"yo\n";                                            // nextPropagationSet->insert(headTuple->getId());
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
                    if(rulePred == _out){
                        bool maySupport = false;
                        bool propagatedToTrue = false;
                        if(!propagatedToTrue){
                            {
                                std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                                int X = (*headTuple)[0];
                                bool undefTuple0 = false;
                                const Tuple* tuple0 = factory.find({X}, _in);
                                if(tuple0 == NULL){
                                    tuple0 = &dummyTuple;
                                }
                                else{
                                    if(tuple0->isTrue()){
                                        tuple0= NULL;
                                    }
                                    else undefTuple0 = true;
                                }
                                if(tuple0 != NULL){
                                    bool undefTuple1 = undefTuple0;
                                    const Tuple* tuple1 = factory.find({X}, _node);
                                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                                    if(tuple1 != NULL){
                                        //Rule is firing 
                                        maySupport = true;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        if(undefTuple1){
                                            std::cout <<"yo\n";                                            // nextPropagationSet->insert(headTuple->getId());
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
                std::cout <<"Here prop stack: "<< propagationSet->size()<<"\n";
            }
            delete nextPropagationSet;
            delete propagationSet;
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
            bool undefTuple0 = false;
            const std::vector<int>* tuples;
            tuples = &pin_.getValuesVec({});
            const std::vector<int>* tuplesU = &uin_.getValuesVec({});
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
                    int X = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pout_.getValuesVec({});
                    const std::vector<int>* tuplesU = &uout_.getValuesVec({});
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
                            int Y = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({X, Y}, _edge);
                            if(tuple2 != NULL && tuple2->isUndef()){
                                undefTuple2 = true;
                            }
                            if(tuple2 != NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y}, _cut);
                                if(t->isUnknown()){
                                    if(undefTuple2){
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
                                    if(!undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertResults.push_back(std::make_pair(insertResult, REMOVE_FROM_UNDEF));
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
            tuples = &pin_.getValuesVec({});
            const std::vector<int>* tuplesU = &uin_.getValuesVec({});
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
                    int X = (*tuple0)[0];
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pout_.getValuesVec({});
                    const std::vector<int>* tuplesU = &uout_.getValuesVec({});
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
                            int Y = (*tuple1)[0];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({X, Y}, _edge);
                            if(tuple2 != NULL && tuple2->isUndef()){
                                undefTuple2 = true;
                            }
                            if(tuple2 != NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({Y,X}, _cut);
                                if(t->isUnknown()){
                                    if(undefTuple2){
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
                                    if(!undefTuple2){
                                        insertResult = t->setStatus(TruthStatus::True);
                                        insertResults.push_back(std::make_pair(insertResult, REMOVE_FROM_UNDEF));
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
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
            bool undefTuple0 = false;
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
                if(tuple0 != NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X, Y}, _cut);
                    if(tuple1 == NULL){
                        tuple1 = &dummyTuple;
                    }
                    else{
                        if(tuple1->isTrue())    tuple1= NULL;
                        else undefTuple1 = true;
                    }
                    if(tuple1 != NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X,Y}, _uncut);
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
    std::cout<<"}\n";
    std::cout<<"\nUndefined: {\n";
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pout_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uout_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pout_.clear();
        uout_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pnode_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &unode_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pnode_.clear();
        unode_.clear();
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
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pedge_.clear();
        uedge_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pin_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uin_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pin_.clear();
        uin_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pcut_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ucut_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pcut_.clear();
        ucut_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &puncut_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uuncut_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        puncut_.clear();
        uuncut_.clear();
    }
    std::cout<<"\n}\n";
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
