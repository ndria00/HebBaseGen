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
const int _c = 2;
const int _b = 1;
const int _a = 0;
AuxMap<0> pc_({});
AuxMap<0> uc_({});
AuxMap<0> pb_({});
AuxMap<0> ub_({});
AuxMap<0> pa_({});
AuxMap<0> ua_({});
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
    predicateToID.insert({"c", _c});
    factory.addPredicate();
    predicateToID.insert({"b", _b});
    factory.addPredicate();
    predicateToID.insert({"a", _a});
    factory.addPredicate();
    Executor::predicateIds.push_back("a");
    Executor::predicateIds.push_back("b");
    Executor::predicateIds.push_back("c");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _a){
        pa_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b){
        pb_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c){
        pc_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _a){
        ua_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b){
        ub_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c){
        uc_.insert2Vec(*insertResult.first);
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
            tuples = &pb_.getValuesVec({});
            const std::vector<int>* tuplesU = &ub_.getValuesVec({});
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
                    if(X == X){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({X}, _c);
                        if(tuple1 == NULL){
                            tuple1 = &dummyTuple;
                            undefTuple1 = true;
                        }
                        else{
                            if(tuple1->isTrue())    tuple1= NULL;
                            else undefTuple1 = true;
                        }
                        if(tuple1 != NULL){
                            if(X == X){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X}, _a);
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
            tuples = &pb_.getValuesVec({});
            const std::vector<int>* tuplesU = &ub_.getValuesVec({});
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
                    if(X == X){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({X}, _a);
                        if(tuple1 == NULL){
                            tuple1 = &dummyTuple;
                            undefTuple1 = true;
                        }
                        else{
                            if(tuple1->isTrue())    tuple1= NULL;
                            else undefTuple1 = true;
                        }
                        if(tuple1 != NULL){
                            if(X == X){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X}, _c);
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
            if(literalName == _c){
                {
                    std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                    bool undefTuple0 = false;
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({X}, _b);
                        if(tuple1 != NULL && tuple1->isUndef()){
                            undefTuple1 = true;
                        }
                        if(tuple1 != NULL){
                            if(X == X){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X}, _a);
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
            if(literalName == _a){
                {
                    std::vector< std::pair<std::pair<const TupleLight *, bool>, int>> insertResults;
                    bool undefTuple0 = false;
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    if(!recursiveTuple->isTrue()){
                        bool undefTuple1 = undefTuple0;
                        const Tuple* tuple1 = factory.find({X}, _b);
                        if(tuple1 != NULL && tuple1->isUndef()){
                            undefTuple1 = true;
                        }
                        if(tuple1 != NULL){
                            if(X == X){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X}, _c);
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
                    if(rulePred == _c){
                        bool maySupport = false;
                        bool propagatedToTrue = false;
                        if(!propagatedToTrue){
                        }
                        if(!maySupport){
                            //removing tuple from undef
                            propagated = true;
                            for(int i : supportedByUndef[headTuple->getId()]){ nextPropagationSet->insert(i);}
                            factory.removeFromCollisionsList(headTuple->getId());
                            factory.destroyTuple(headTuple->getId());
                        }
                    }
                    if(rulePred == _a){
                        bool maySupport = false;
                        bool propagatedToTrue = false;
                        if(!propagatedToTrue){
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
        tuplesToRemove = &pa_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ua_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pa_.clear();
        ua_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pb_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ub_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pb_.clear();
        ub_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pc_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uc_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            printTuple(factory.getTupleFromInternalID(tuplesToRemove->at(i)));
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pc_.clear();
        uc_.clear();
    }
    std::cout<<"\n}\n";
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
