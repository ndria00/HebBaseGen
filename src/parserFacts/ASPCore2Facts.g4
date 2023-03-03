grammar ASPCore2Facts;

instance:            fact*;
     	
     		
fact:               head DOT;
     						
		
head:				disjunction;
							


disjunction:        classic_literal
					| classic_literal HEAD_SEPARATOR disjunction;

classic_literal:	atom;

atom:				identifier
					| identifier PARAM_OPEN terms PARAM_CLOSE;
						

terms:				term
					| term COMMA terms;

term_:				ANON_VAR
					| NUMBER DDOT NUMBER;
			
term:				term_
					| NUMBER
					| identifier;

identifier:			SYMBOLIC_CONSTANT
					| STRING;
						



SYMBOLIC_CONSTANT:      [a-z][A-Za-z_0-9]* ;
STRING:                 '"' ('\\"' | . )*? '"' ;
NUMBER:					[0-9]+ ;

WS:			 			[ \t\n]+ ->skip ;


DOT: 					'.' ;
DDOT: 					'..' ;
COMMA:					',' ;
HEAD_SEPARATOR:			'|' ;
COLON: 					':' ;
CONS:					':-' ;
PARAM_OPEN:				'(' ;
PARAM_CLOSE:			')' ;
ANON_VAR:				'_' ;


EMPTY_COMMENT:			'%''\n' ->skip;
COMMENT: 				'%'~('@' | '\n')(.)*?'\n' ->skip;