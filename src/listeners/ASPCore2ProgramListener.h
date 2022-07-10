#include "../parser/ASPCore2BaseListener.h"
#include "../Builder.h"

class ASPCore2ProgramListener : public ASPCore2BaseListener{
    public:
        ASPCore2ProgramListener(Builder&);
        
        void enterProgram(ASPCore2Parser::ProgramContext * /*ctx*/) override;
        void exitProgram(ASPCore2Parser::ProgramContext * /*ctx*/) override;
        
        void enterHead(ASPCore2Parser::HeadContext * /*ctx*/) override;
        void exitHead(ASPCore2Parser::HeadContext * /*ctx*/) override;

        void enterBody(ASPCore2Parser::BodyContext * /*ctx*/) override;
        void exitBody(ASPCore2Parser::BodyContext * /*ctx*/) override;

        void enterSimple_rule(ASPCore2Parser::Simple_ruleContext * /*ctx*/) override;
        void exitSimple_rule(ASPCore2Parser::Simple_ruleContext * /*ctx*/) override;

        void enterClassic_literal(ASPCore2Parser::Classic_literalContext * /*ctx*/) override;
        void exitClassic_literal(ASPCore2Parser::Classic_literalContext * /*ctx*/) override;
    
        void enterAtom(ASPCore2Parser::AtomContext * /*ctx*/) override;
        void exitAtom(ASPCore2Parser::AtomContext * /*ctx*/) override;
    
        void enterTerm_(ASPCore2Parser::Term_Context * /*ctx*/) override;
        void enterTerm__(ASPCore2Parser::Term__Context * /*ctx*/) override;
        void enterTerm(ASPCore2Parser::TermContext * /*ctx*/) override;
    
        void enterAggregate(ASPCore2Parser::AggregateContext * /*ctx*/) override;
        void exitAggregate(ASPCore2Parser::AggregateContext * /*ctx*/) override;

        void enterAggregate_atom(ASPCore2Parser::Aggregate_atomContext * /*ctx*/) override;
        void exitAggregate_atom(ASPCore2Parser::Aggregate_atomContext * /*ctx*/) override;

        void enterLeftwardop(ASPCore2Parser::LeftwardopContext * /*ctx*/) override;
        void enterRightwardop(ASPCore2Parser::RightwardopContext * /*ctx*/) override;

        void enterNaf_literal(ASPCore2Parser::Naf_literalContext * /*ctx*/) override;
        void exitNaf_literal(ASPCore2Parser::Naf_literalContext * /*ctx*/) override;

        void enterBasic_term(ASPCore2Parser::Basic_termContext * /*ctx*/) override;
        void exitBasic_term(ASPCore2Parser::Basic_termContext * /*ctx*/) override;

        Builder getBuilder();
        void setBuilder(Builder& );
    private:
        Builder builder;
};