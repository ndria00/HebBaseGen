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
const int _jailed = 4;
const int _nonMatch = 3;
const int _womanAssignsScore = 2;
const int _manAssignsScore = 1;
const int _match = 0;
AuxMap<0> pjailed_({});
AuxMap<0> ujailed_({});
AuxMap<0> pnonMatch_({});
AuxMap<0> unonMatch_({});
AuxMap<0> pwomanAssignsScore_({});
AuxMap<0> uwomanAssignsScore_({});
AuxMap<0> pmanAssignsScore_({});
AuxMap<0> umanAssignsScore_({});
AuxMap<0> pmatch_({});
AuxMap<0> umatch_({});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"jailed", _jailed});
    factory.addPredicate();
    predicateToID.insert({"nonMatch", _nonMatch});
    factory.addPredicate();
    predicateToID.insert({"womanAssignsScore", _womanAssignsScore});
    factory.addPredicate();
    predicateToID.insert({"manAssignsScore", _manAssignsScore});
    factory.addPredicate();
    predicateToID.insert({"match", _match});
    factory.addPredicate();
    Executor::predicateIds.push_back("match");
    Executor::predicateIds.push_back("manAssignsScore");
    Executor::predicateIds.push_back("womanAssignsScore");
    Executor::predicateIds.push_back("nonMatch");
    Executor::predicateIds.push_back("jailed");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _match){
        pmatch_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _manAssignsScore){
        pmanAssignsScore_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _womanAssignsScore){
        pwomanAssignsScore_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nonMatch){
        pnonMatch_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _jailed){
        pjailed_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _match){
        umatch_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _manAssignsScore){
        umanAssignsScore_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _womanAssignsScore){
        uwomanAssignsScore_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _nonMatch){
        unonMatch_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _jailed){
        ujailed_.insert2Vec(*insertResult.first);
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
        {//adding already existing tuple for predicates involved in recursion
            const std::vector<int>* actualTuples;
            actualTuples = &pnonMatch_.getValuesVec({});
            for(int i = 0; i < actualTuples->size(); ++i) generatedStack.push_back((factory.getTupleFromInternalID(actualTuples->at(i)))->getId());
            actualTuples = &unonMatch_.getValuesVec({});
            for(int i = 0; i < actualTuples->size(); ++i) generatedStack.push_back((factory.getTupleFromInternalID(actualTuples->at(i)))->getId());
            actualTuples = &pmatch_.getValuesVec({});
            for(int i = 0; i < actualTuples->size(); ++i) generatedStack.push_back((factory.getTupleFromInternalID(actualTuples->at(i)))->getId());
            actualTuples = &umatch_.getValuesVec({});
            for(int i = 0; i < actualTuples->size(); ++i) generatedStack.push_back((factory.getTupleFromInternalID(actualTuples->at(i)))->getId());
        }
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            if(literalName == _nonMatch){
                {
                    int W = (*recursiveTuple)[1];
                    int M = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({M}, _manAssignsScore);
                    if(tuple1!= NULL){
                        const Tuple* tuple2 = factory.find({W}, _womanAssignsScore);
                        if(tuple2!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({M,W}, _match);
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
            }
            if(literalName == _match){
                {
                    int W = (*recursiveTuple)[1];
                    int M = (*recursiveTuple)[0];
                    const Tuple* tuple1 = factory.find({M}, _manAssignsScore);
                    if(tuple1!= NULL){
                        const Tuple* tuple2 = factory.find({W}, _womanAssignsScore);
                        if(tuple2!= NULL){
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({M,W}, _nonMatch);
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
            }
        }
    }
    //---------------------------------------Strongly connected component------------------------
    {
        {
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
                }
                if(tuple0!= NULL){
                    int M = (*tuple0)[0];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({M}, _jailed);
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
    }
    printGeneratedBase();
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
void Executor::printGeneratedBase(){
    const std::vector<int>* tuples;
    tuples = &pjailed_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ujailed_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pnonMatch_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &unonMatch_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pwomanAssignsScore_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uwomanAssignsScore_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pmanAssignsScore_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &umanAssignsScore_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &pmatch_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &umatch_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
}
