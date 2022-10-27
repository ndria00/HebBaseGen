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
const int _c = 4;
const int _e = 3;
const int _b = 1;
const int _d = 2;
const int _a = 0;
AuxMap<0> pc_({});
AuxMap<0> uc_({});
AuxMap<0> pe_({});
AuxMap<0> ue_({});
AuxMap<0> pb_({});
AuxMap<0> ub_({});
AuxMap<0> pd_({});
AuxMap<0> ud_({});
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
void Executor::init(){
    predicateToID.insert({"c", _c});
    factory.addPredicate();
    predicateToID.insert({"e", _e});
    factory.addPredicate();
    predicateToID.insert({"b", _b});
    factory.addPredicate();
    predicateToID.insert({"d", _d});
    factory.addPredicate();
    predicateToID.insert({"a", _a});
    factory.addPredicate();
    Executor::predicateIds.push_back("a");
    Executor::predicateIds.push_back("b");
    Executor::predicateIds.push_back("d");
    Executor::predicateIds.push_back("e");
    Executor::predicateIds.push_back("c");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _a){
        pa_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d){
        pd_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b){
        pb_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _e){
        pe_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c){
        pc_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _a){
        ua_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _d){
        ud_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _b){
        ub_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _e){
        ue_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _c){
        uc_.insert2Vec(*insertResult.first);
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
    //TODO
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        {//adding already existing tuple for predicates involved in recursion
            const std::vector<int>* actualTuples;
            actualTuples = &pb_.getValuesVec({});
            for(int i = 0; i < actualTuples->size(); ++i) generatedStack.push_back((factory.getTupleFromInternalID(actualTuples->at(i)))->getId());
            actualTuples = &ub_.getValuesVec({});
            for(int i = 0; i < actualTuples->size(); ++i) generatedStack.push_back((factory.getTupleFromInternalID(actualTuples->at(i)))->getId());
            actualTuples = &pa_.getValuesVec({});
            for(int i = 0; i < actualTuples->size(); ++i) generatedStack.push_back((factory.getTupleFromInternalID(actualTuples->at(i)))->getId());
            actualTuples = &ua_.getValuesVec({});
            for(int i = 0; i < actualTuples->size(); ++i) generatedStack.push_back((factory.getTupleFromInternalID(actualTuples->at(i)))->getId());
        }
        {
            bool undefTuple0= false;
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
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    bool undefTuple1= undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pd_.getValuesVec({});
                    const std::vector<int>* tuplesU = &ud_.getValuesVec({});
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
                            bool undefTuple2= undefTuple1;
                            const Tuple negativeTuple = Tuple({X, Y}, _c, true);
                            const Tuple* tuple2 = factory.find({X, Y}, _c);
                            if(tuple2 == NULL){
                                tuple2 = &negativeTuple;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple2 = true;
                            }
                            if(tuple2!= NULL){
                                bool undefTuple3= undefTuple2;
                                const std::vector<int>* tuples;
                                tuples = &pe_.getValuesVec({});
                                const std::vector<int>* tuplesU = &ue_.getValuesVec({});
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
                                        int Z = (*tuple3)[0];
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({X}, _a);
                                        if(t->isUnknown()){
                                            printTuple(t);
                                            generatedStack.push_back(t->getId());
                                            if(!undefTuple3){
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pa_.getValuesVec({});
            const std::vector<int>* tuplesU = &ua_.getValuesVec({});
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
                    bool undefTuple1= undefTuple0;
                    const Tuple* tuple1 = factory.find({X}, _d);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X}, _b);
                        if(t->isUnknown()){
                            printTuple(t);
                            generatedStack.push_back(t->getId());
                            if(!undefTuple1){
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
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            bool recursiveTupleUndef = recursiveTuple->isUndef();
            if(literalName == _b){
                {
                    bool undefTuple0= false;
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1= undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pd_.getValuesVec({});
                    const std::vector<int>* tuplesU = &ud_.getValuesVec({});
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
                            bool undefTuple2= undefTuple1;
                            const std::vector<int>* tuples;
                            tuples = &pe_.getValuesVec({});
                            const std::vector<int>* tuplesU = &ue_.getValuesVec({});
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
                                    int Z = (*tuple2)[0];
                                    bool undefTuple3= undefTuple2;
                                    const Tuple negativeTuple = Tuple({X, Y}, _c, true);
                                    const Tuple* tuple3 = factory.find({X, Y}, _c);
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
                                        t = factory.addNewInternalTuple({X}, _a);
                                        if(t->isUnknown()){
                                            printTuple(t);
                                            generatedStack.push_back(t->getId());
                                            if(!undefTuple3){
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
            }
            if(literalName == _a){
                {
                    bool undefTuple0= false;
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1= undefTuple0;
                    const Tuple* tuple1 = factory.find({X}, _d);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        //Rule is firing 
                        Tuple* t;
                        std::pair<const TupleLight *, bool> insertResult;
                        t = factory.addNewInternalTuple({X}, _b);
                        if(t->isUnknown()){
                            printTuple(t);
                            generatedStack.push_back(t->getId());
                            if(!undefTuple1){
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
            }
        }
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
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pc_.clear();
        uc_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pe_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ue_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pe_.clear();
        ue_.clear();
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
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pb_.clear();
        ub_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pd_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ud_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pd_.clear();
        ud_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pa_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ua_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pa_.clear();
        ua_.clear();
    }
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
