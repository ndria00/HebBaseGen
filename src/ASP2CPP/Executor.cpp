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
const int _arc = 1;
const int _reach = 0;
AuxMap<0> parc_({});
AuxMap<0> uarc_({});
AuxMap<0> preach_({});
AuxMap<0> ureach_({});
AuxMap<32> preach_1_({1});
AuxMap<32> ureach_1_({1});
AuxMap<32> preach_0_({0});
AuxMap<32> ureach_0_({0});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"arc", _arc});
    factory.addPredicate();
    predicateToID.insert({"reach", _reach});
    factory.addPredicate();
    Executor::predicateIds.push_back("reach");
    Executor::predicateIds.push_back("arc");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _reach){
        preach_.insert2Vec(*insertResult.first);
        preach_0_.insert2Vec(*insertResult.first);
        preach_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _arc){
        parc_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _reach){
        ureach_.insert2Vec(*insertResult.first);
        ureach_0_.insert2Vec(*insertResult.first);
        ureach_1_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _arc){
        uarc_.insert2Vec(*insertResult.first);
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
        {
            bool undefTuple = false;
            const std::vector<int>* tuples;
            tuples = &parc_.getValuesVec({});
            const std::vector<int>* tuplesU = &uarc_.getValuesVec({});
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
                    int Y = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X,Y}, _reach);
                    if(t->isUnknown()){
                        printTuple(t);
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
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            bool recursiveTupleUndef = recursiveTuple->isUndef();
            if(literalName == _reach){
                {
                    bool undefTuple = false;
                    int Y = (*recursiveTuple)[1];
                    int X = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple = true;
                    }
                    const std::vector<int>* tuples;
                    tuples = &preach_0_.getValuesVec({Y});
                    const std::vector<int>* tuplesU = &ureach_0_.getValuesVec({Y});
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
                            int Z = (*tuple1)[1];
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X,Z}, _reach);
                            if(t->isUnknown()){
                                printTuple(t);
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
                    int Z = (*recursiveTuple)[1];
                    int Y = (*recursiveTuple)[0];
                    if(recursiveTupleUndef){
                        undefTuple = true;
                    }
                    const std::vector<int>* tuples;
                    tuples = &preach_1_.getValuesVec({Y});
                    const std::vector<int>* tuplesU = &ureach_1_.getValuesVec({Y});
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
                            int X = (*tuple1)[0];
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X,Z}, _reach);
                            if(t->isUnknown()){
                                printTuple(t);
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
            }
        }
    }
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
