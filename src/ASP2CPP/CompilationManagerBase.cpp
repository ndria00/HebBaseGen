#include "CompilationManagerBase.h"
#include "PreCompilerASP.h"
#include "../DataStructures/TupleFactory.h"
#include <unordered_map>

CompilationManagerBase::CompilationManagerBase(){
    indentation = Indentation(0);
    declaredMaps = std::set<std::string>();
}


void CompilationManagerBase::setOutStream(std::ostream* outputFile){
    this->out = outputFile;
}


void CompilationManagerBase::printLiteralTuple(const Literal* lit) {
    for (unsigned t = 0; t < lit->getArity(); t++) {
        if (t > 0) {
            *out << ", ";
        }
        if (!lit->getTerms().at(t)->isVariable() && !sharedFunc::isInteger(lit->getTermAt(t))) {
            *out << "ConstantsManager::getInstance().mapConstant(\"" << sharedFunc::escapeDoubleQuotes(lit->getTerms().at(t)->getRepresentation()) << "\")";
        } else {
            *out << lit->getTermAt(t);
        }
    }


}

void CompilationManagerBase::printLiteralTuple(const Literal* lit, const std::unordered_set<std::string>& boundVariables) {
    bool first = true;
    for (unsigned t = 0; t < lit->getArity(); t++) {
        if (!lit->getTerms().at(t)->isVariable() || boundVariables.count(lit->getTermAt(t))) {
            if (!first) {
                *out << ", ";
            }
            if (!lit->getTerms().at(t)->isVariable() && !sharedFunc::isInteger(lit->getTerms().at(t)->getRepresentation())) {
                *out << "ConstantsManager::getInstance().mapConstant(\"" << sharedFunc::escapeDoubleQuotes(lit->getTerms().at(t)->getRepresentation()) << "\")";
            } else {
                *out << lit->getTerms().at(t)->getRepresentation();
            }
            first = false;
        }
    }


}


void CompilationManagerBase::setPreCompiler(PreCompilerASP* preCompiler){
    this->preCompiler = preCompiler;
}