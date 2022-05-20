#ifndef BUILDER_H_
#define BUILDE_H_

#include "parser/ASPCore2Parser.h"
#include "Atom.h"
#include "Head.h"
#include "Rule.h"
#include "Program.h"

class Builder{
    public:
        Builder();
        void buildAtom(ASPCore2Parser::Classic_literalContext*, Atom& );
        void buildHead(ASPCore2Parser::HeadContext*, Head&);
        void buildSimpleRule(ASPCore2Parser::Simple_ruleContext*, Rule&);
        void buildRule(ASPCore2Parser::RuleContext*, Program&);
        void buildProgram(ASPCore2Parser::ProgramContext*, Program&);        
};

#endif