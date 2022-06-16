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

        void enterRule(ASPCore2Parser::RuleContext * /*ctx*/) override;
        void exitRule(ASPCore2Parser::RuleContext * /*ctx*/) override;
        void enterClassic_literal(ASPCore2Parser::Classic_literalContext * /*ctx*/) override;
        void exitClassic_literal(ASPCore2Parser::Classic_literalContext * /*ctx*/) override;
    
        Builder getBuilder();
        void setBuilder(Builder& );
    private:
        Builder builder;
};