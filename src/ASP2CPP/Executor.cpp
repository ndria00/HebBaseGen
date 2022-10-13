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
}
void Executor::executeProgram(){
    auto start = std::chrono::high_resolution_clock::now();
    //TODO
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        {
            bool undefTuple = false;
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
                    undefTuple = true;
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
                        generatedStack.push_back(t->getId());
                        insertResult = t->setStatus(TruthStatus::Undef);
                        insertUndef(insertResult);
                    }
                    else if(t->isUndef()){
                        insertResult = t->setStatus(TruthStatus::Undef);
                    }
                    t = factory.addNewInternalTuple({X2}, _strategic);
                    if(t->isUnknown()){
                        generatedStack.push_back(t->getId());
                        insertResult = t->setStatus(TruthStatus::Undef);
                        insertUndef(insertResult);
                    }
                    else if(t->isUndef()){
                        insertResult = t->setStatus(TruthStatus::Undef);
                    }
                    t = factory.addNewInternalTuple({X3}, _strategic);
                    if(t->isUnknown()){
                        generatedStack.push_back(t->getId());
                        insertResult = t->setStatus(TruthStatus::Undef);
                        insertUndef(insertResult);
                    }
                    else if(t->isUndef()){
                        insertResult = t->setStatus(TruthStatus::Undef);
                    }
                    t = factory.addNewInternalTuple({X4}, _strategic);
                    if(t->isUnknown()){
                        generatedStack.push_back(t->getId());
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
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            if(literalName == _strategic){
                {
                    bool undefTuple = false;
                    int X1 = (*recursiveTuple)[0];
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
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int W = (*tuple1)[0];
                            int X2 = (*tuple1)[2];
                            int X3 = (*tuple1)[3];
                            int X4 = (*tuple1)[4];
                            const Tuple* tuple2 = factory.find({X4}, _strategic);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                const Tuple* tuple3 = factory.find({X3}, _strategic);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple = true;
                                if(tuple3!= NULL){
                                    const Tuple* tuple4 = factory.find({X2}, _strategic);
                                    if(tuple4 != NULL && tuple4->isUndef()) undefTuple = true;
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({W}, _strategic);
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
                    int X2 = (*recursiveTuple)[0];
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
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int W = (*tuple1)[0];
                            int X1 = (*tuple1)[1];
                            int X3 = (*tuple1)[3];
                            int X4 = (*tuple1)[4];
                            const Tuple* tuple2 = factory.find({X4}, _strategic);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                const Tuple* tuple3 = factory.find({X3}, _strategic);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple = true;
                                if(tuple3!= NULL){
                                    const Tuple* tuple4 = factory.find({X1}, _strategic);
                                    if(tuple4 != NULL && tuple4->isUndef()) undefTuple = true;
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({W}, _strategic);
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
                    int X3 = (*recursiveTuple)[0];
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
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int W = (*tuple1)[0];
                            int X1 = (*tuple1)[1];
                            int X2 = (*tuple1)[2];
                            int X4 = (*tuple1)[4];
                            const Tuple* tuple2 = factory.find({X4}, _strategic);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                const Tuple* tuple3 = factory.find({X2}, _strategic);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple = true;
                                if(tuple3!= NULL){
                                    const Tuple* tuple4 = factory.find({X1}, _strategic);
                                    if(tuple4 != NULL && tuple4->isUndef()) undefTuple = true;
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({W}, _strategic);
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
                    int X4 = (*recursiveTuple)[0];
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
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int W = (*tuple1)[0];
                            int X1 = (*tuple1)[1];
                            int X2 = (*tuple1)[2];
                            int X3 = (*tuple1)[3];
                            const Tuple* tuple2 = factory.find({X3}, _strategic);
                            if(tuple2 != NULL && tuple2->isUndef()) undefTuple = true;
                            if(tuple2!= NULL){
                                const Tuple* tuple3 = factory.find({X2}, _strategic);
                                if(tuple3 != NULL && tuple3->isUndef()) undefTuple = true;
                                if(tuple3!= NULL){
                                    const Tuple* tuple4 = factory.find({X1}, _strategic);
                                    if(tuple4 != NULL && tuple4->isUndef()) undefTuple = true;
                                    if(tuple4!= NULL){
                                        //Rule is firing 
                                        Tuple* t;
                                        std::pair<const TupleLight *, bool> insertResult;
                                        t = factory.addNewInternalTuple({W}, _strategic);
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
            }
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
            bool undefTuple = false;
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
                    undefTuple = true;
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
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
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int Y = (*tuple1)[0];
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X,Y}, _strategic_pair);
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
            tuples = &pproduced_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &uproduced_by_.getValuesVec({});
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
            tuples = &pproduced_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &uproduced_by_.getValuesVec({});
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
            tuples = &pproduced_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &uproduced_by_.getValuesVec({});
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
            tuples = &pproduced_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &uproduced_by_.getValuesVec({});
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
            tuples = &pcontrolled_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucontrolled_by_.getValuesVec({});
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
            tuples = &pcontrolled_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucontrolled_by_.getValuesVec({});
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
            tuples = &pcontrolled_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucontrolled_by_.getValuesVec({});
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
            tuples = &pcontrolled_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucontrolled_by_.getValuesVec({});
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
            tuples = &pcontrolled_by_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucontrolled_by_.getValuesVec({});
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
            tuples = &pcompany_.getValuesVec({});
            const std::vector<int>* tuplesU = &ucompany_.getValuesVec({});
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
                    int X = (*tuple0)[0];
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
                            undefTuple = true;
                        }
                        if(tuple1!= NULL){
                            int Y = (*tuple1)[0];
                            const Tuple negativeTuple = Tuple({X, Y}, _strategic_pair, true);
                            const Tuple* tuple2 = factory.find({X, Y}, _strategic_pair);
                            if(tuple2 == NULL){
                                tuple2 = &negativeTuple;
                            }
                            else{
                                if(tuple2->isTrue())    tuple2= NULL;
                                else undefTuple = true;
                            }
                            if(tuple2!= NULL){
                                //Rule is firing 
                                Tuple* t;
                                std::pair<const TupleLight *, bool> insertResult;
                                t = factory.addNewInternalTuple({X,Y}, _non_strategic_pair);
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
    }
    printGeneratedBase();
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
void Executor::printGeneratedBase(){
    const std::vector<int>* tuples;
    tuples = &pcompany_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ucompany_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pnon_strategic_pair_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &unon_strategic_pair_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pcontrolled_by_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ucontrolled_by_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pstrategic_pair_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ustrategic_pair_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pproduced_by_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uproduced_by_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pstrategic_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ustrategic_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
}
