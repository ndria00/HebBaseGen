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
const int _company = 5;
const int _non_strategic_pair = 4;
const int _controlled_by = 2;
const int _strategic_pair = 3;
const int _produced_by = 1;
const int _strategic = 0;
AuxMap<0> pcompany_({});
AuxMap<0> ucompany_({});
AuxMap<0> pnon_strategic_pair_({});
AuxMap<0> unon_strategic_pair_({});
AuxMap<0> pcontrolled_by_({});
AuxMap<0> ucontrolled_by_({});
AuxMap<0> pstrategic_pair_({});
AuxMap<0> ustrategic_pair_({});
AuxMap<0> pproduced_by_({});
AuxMap<0> uproduced_by_({});
AuxMap<0> pstrategic_({});
AuxMap<0> ustrategic_({});
AuxMap<32> pcontrolled_by_4_({4});
AuxMap<32> ucontrolled_by_4_({4});
AuxMap<32> pcontrolled_by_3_({3});
AuxMap<32> ucontrolled_by_3_({3});
AuxMap<32> pcontrolled_by_1_({1});
AuxMap<32> ucontrolled_by_1_({1});
AuxMap<32> pcontrolled_by_2_({2});
AuxMap<32> ucontrolled_by_2_({2});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"company", _company});
    factory.addPredicate();
    predicateToID.insert({"non_strategic_pair", _non_strategic_pair});
    factory.addPredicate();
    predicateToID.insert({"controlled_by", _controlled_by});
    factory.addPredicate();
    predicateToID.insert({"strategic_pair", _strategic_pair});
    factory.addPredicate();
    predicateToID.insert({"produced_by", _produced_by});
    factory.addPredicate();
    predicateToID.insert({"strategic", _strategic});
    factory.addPredicate();
    Executor::predicateIds.push_back("strategic");
    Executor::predicateIds.push_back("produced_by");
    Executor::predicateIds.push_back("controlled_by");
    Executor::predicateIds.push_back("strategic_pair");
    Executor::predicateIds.push_back("non_strategic_pair");
    Executor::predicateIds.push_back("company");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _strategic){
        pstrategic_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _produced_by){
        pproduced_by_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _strategic_pair){
        pstrategic_pair_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _controlled_by){
        pcontrolled_by_.insert2Vec(*insertResult.first);
        pcontrolled_by_1_.insert2Vec(*insertResult.first);
        pcontrolled_by_2_.insert2Vec(*insertResult.first);
        pcontrolled_by_3_.insert2Vec(*insertResult.first);
        pcontrolled_by_4_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _non_strategic_pair){
        pnon_strategic_pair_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _company){
        pcompany_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _strategic){
        ustrategic_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _produced_by){
        uproduced_by_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _strategic_pair){
        ustrategic_pair_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _controlled_by){
        ucontrolled_by_.insert2Vec(*insertResult.first);
        ucontrolled_by_1_.insert2Vec(*insertResult.first);
        ucontrolled_by_2_.insert2Vec(*insertResult.first);
        ucontrolled_by_3_.insert2Vec(*insertResult.first);
        ucontrolled_by_4_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _non_strategic_pair){
        unon_strategic_pair_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _company){
        ucompany_.insert2Vec(*insertResult.first);
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
        std::vector<int> generatedStack;
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pproduced_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &uproduced_by_.getValuesVec({});
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
                    int X1 = (*tuple0)[1];
                    int X2 = (*tuple0)[2];
                    int X3 = (*tuple0)[3];
                    int X4 = (*tuple0)[4];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X1}, _strategic);
                    if(t->isUnknown()){
                        printTuple(t);
                        insertResult = t->setStatus(TruthStatus::Undef);
                        insertUndef(insertResult);
                    }
                    else if(t->isUndef()){
                        insertResult = t->setStatus(TruthStatus::Undef);
                    }
                    t = factory.addNewInternalTuple({X2}, _strategic);
                    if(t->isUnknown()){
                        printTuple(t);
                        insertResult = t->setStatus(TruthStatus::Undef);
                        insertUndef(insertResult);
                    }
                    else if(t->isUndef()){
                        insertResult = t->setStatus(TruthStatus::Undef);
                    }
                    t = factory.addNewInternalTuple({X3}, _strategic);
                    if(t->isUnknown()){
                        printTuple(t);
                        insertResult = t->setStatus(TruthStatus::Undef);
                        insertUndef(insertResult);
                    }
                    else if(t->isUndef()){
                        insertResult = t->setStatus(TruthStatus::Undef);
                    }
                    t = factory.addNewInternalTuple({X4}, _strategic);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pcontrolled_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucontrolled_by_.getValuesVec({});
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
                    int X1 = (*tuple0)[1];
                    int X2 = (*tuple0)[2];
                    int X3 = (*tuple0)[3];
                    int X4 = (*tuple0)[4];
                    bool undefTuple1 = undefTuple0;
                    const Tuple* tuple1 = factory.find({X4}, _strategic);
                    if(tuple1 != NULL && tuple1->isUndef()) undefTuple1 = true;
                    if(tuple1!= NULL){
                        bool undefTuple2 = undefTuple1;
                        const Tuple* tuple2 = factory.find({X3}, _strategic);
                        if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                        if(tuple2!= NULL){
                            bool undefTuple3 = undefTuple2;
                            const Tuple* tuple3 = factory.find({X2}, _strategic);
                            if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                            if(tuple3!= NULL){
                                bool undefTuple4 = undefTuple3;
                                const Tuple* tuple4 = factory.find({X1}, _strategic);
                                if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                if(tuple4!= NULL){
                                    //Rule is firing 
                                    Tuple* t;
                                    std::pair<const TupleLight *, bool> insertResult;
                                    t = factory.addNewInternalTuple({W}, _strategic);
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
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            bool recursiveTupleUndef = recursiveTuple->isUndef();
            if(literalName == _strategic){
                {
                    bool undefTuple0= false;
                    int X1 = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pcontrolled_by_1_.getValuesVec({X1});
                    const std::vector<int>* tuplesU = &ucontrolled_by_1_.getValuesVec({X1});
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
                            int X2 = (*tuple1)[2];
                            int X3 = (*tuple1)[3];
                            int X4 = (*tuple1)[4];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({X4}, _strategic);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const Tuple* tuple3 = factory.find({X3}, _strategic);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple* tuple4 = factory.find({X2}, _strategic);
                                    if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({W}, _strategic);
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
                    int X2 = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pcontrolled_by_2_.getValuesVec({X2});
                    const std::vector<int>* tuplesU = &ucontrolled_by_2_.getValuesVec({X2});
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
                            int X1 = (*tuple1)[1];
                            int X3 = (*tuple1)[3];
                            int X4 = (*tuple1)[4];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({X4}, _strategic);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const Tuple* tuple3 = factory.find({X3}, _strategic);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple* tuple4 = factory.find({X1}, _strategic);
                                    if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({W}, _strategic);
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
                    int X3 = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pcontrolled_by_3_.getValuesVec({X3});
                    const std::vector<int>* tuplesU = &ucontrolled_by_3_.getValuesVec({X3});
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
                            int X1 = (*tuple1)[1];
                            int X2 = (*tuple1)[2];
                            int X4 = (*tuple1)[4];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({X4}, _strategic);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const Tuple* tuple3 = factory.find({X2}, _strategic);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple* tuple4 = factory.find({X1}, _strategic);
                                    if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({W}, _strategic);
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
                    int X4 = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple0 = true;
                    }
                    bool undefTuple1 = undefTuple0;
                    const std::vector<int>* tuples;
                    tuples = &pcontrolled_by_4_.getValuesVec({X4});
                    const std::vector<int>* tuplesU = &ucontrolled_by_4_.getValuesVec({X4});
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
                            int X1 = (*tuple1)[1];
                            int X2 = (*tuple1)[2];
                            int X3 = (*tuple1)[3];
                            bool undefTuple2 = undefTuple1;
                            const Tuple* tuple2 = factory.find({X3}, _strategic);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple2 = true;
                            if(tuple2!= NULL){
                                bool undefTuple3 = undefTuple2;
                                const Tuple* tuple3 = factory.find({X2}, _strategic);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple3 = true;
                                if(tuple3!= NULL){
                                    bool undefTuple4 = undefTuple3;
                                    const Tuple* tuple4 = factory.find({X1}, _strategic);
                                    if(tuple4 != NULL && tuple4->isUndef()) undefTuple4 = true;
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({W}, _strategic);
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
            }
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pstrategic_.getValuesVec({});
            const std::vector<int>* tuplesU = &ustrategic_.getValuesVec({});
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
                    tuples = &pstrategic_.getValuesVec({});
                    const std::vector<int>* tuplesU = &ustrategic_.getValuesVec({});
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
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X,Y}, _strategic_pair);
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
        }//close par
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pstrategic_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ustrategic_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pstrategic_.clear();
        ustrategic_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pproduced_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &uproduced_by_.getValuesVec({});
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
                    int X1 = (*tuple0)[1];
                    int X2 = (*tuple0)[2];
                    int X3 = (*tuple0)[3];
                    int X4 = (*tuple0)[4];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X1}, _company);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pproduced_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &uproduced_by_.getValuesVec({});
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
                    int X1 = (*tuple0)[1];
                    int X2 = (*tuple0)[2];
                    int X3 = (*tuple0)[3];
                    int X4 = (*tuple0)[4];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X2}, _company);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pproduced_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &uproduced_by_.getValuesVec({});
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
                    int X1 = (*tuple0)[1];
                    int X2 = (*tuple0)[2];
                    int X3 = (*tuple0)[3];
                    int X4 = (*tuple0)[4];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X3}, _company);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pproduced_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &uproduced_by_.getValuesVec({});
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
                    int X1 = (*tuple0)[1];
                    int X2 = (*tuple0)[2];
                    int X3 = (*tuple0)[3];
                    int X4 = (*tuple0)[4];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X4}, _company);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pcontrolled_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucontrolled_by_.getValuesVec({});
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
                    int X1 = (*tuple0)[1];
                    int X2 = (*tuple0)[2];
                    int X3 = (*tuple0)[3];
                    int X4 = (*tuple0)[4];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({W}, _company);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pcontrolled_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucontrolled_by_.getValuesVec({});
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
                    int X1 = (*tuple0)[1];
                    int X2 = (*tuple0)[2];
                    int X3 = (*tuple0)[3];
                    int X4 = (*tuple0)[4];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X1}, _company);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pcontrolled_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucontrolled_by_.getValuesVec({});
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
                    int X1 = (*tuple0)[1];
                    int X2 = (*tuple0)[2];
                    int X3 = (*tuple0)[3];
                    int X4 = (*tuple0)[4];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X2}, _company);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pcontrolled_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucontrolled_by_.getValuesVec({});
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
                    int X1 = (*tuple0)[1];
                    int X2 = (*tuple0)[2];
                    int X3 = (*tuple0)[3];
                    int X4 = (*tuple0)[4];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X3}, _company);
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
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pcontrolled_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucontrolled_by_.getValuesVec({});
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
                    int X1 = (*tuple0)[1];
                    int X2 = (*tuple0)[2];
                    int X3 = (*tuple0)[3];
                    int X4 = (*tuple0)[4];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X4}, _company);
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
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pcontrolled_by_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ucontrolled_by_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pcontrolled_by_.clear();
        pcontrolled_by_1_.clear();
        pcontrolled_by_2_.clear();
        pcontrolled_by_3_.clear();
        pcontrolled_by_4_.clear();
        ucontrolled_by_.clear();
        ucontrolled_by_1_.clear();
        ucontrolled_by_2_.clear();
        ucontrolled_by_3_.clear();
        ucontrolled_by_4_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pproduced_by_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &uproduced_by_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pproduced_by_.clear();
        uproduced_by_.clear();
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple0= false;
            const std::vector<int>* tuples;
            tuples = &pcompany_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucompany_.getValuesVec({});
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
                    tuples = &pcompany_.getValuesVec({});
                    const std::vector<int>* tuplesU = &ucompany_.getValuesVec({});
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
                            const Tuple negativeTuple = Tuple({X, Y}, _strategic_pair, true);
                            const Tuple* tuple2 = factory.find({X, Y}, _strategic_pair);
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
                                t = factory.addNewInternalTuple({X,Y}, _non_strategic_pair);
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
        }//close par
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pcompany_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ucompany_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pcompany_.clear();
        ucompany_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pnon_strategic_pair_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &unon_strategic_pair_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pnon_strategic_pair_.clear();
        unon_strategic_pair_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &pstrategic_pair_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        tuplesToRemove = &ustrategic_pair_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        pstrategic_pair_.clear();
        ustrategic_pair_.clear();
    }
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
