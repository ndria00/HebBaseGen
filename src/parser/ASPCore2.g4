grammar ASPCore2;

program: 					rule+;
     	

	
rule: 						simple_rule
						| query;
     		
simple_rule:					head DOT
     						| head CONS DOT
     						| head CONS body DOT
     						| CONS body DOT
     						| WCONS body DOT weight_at_levels;
		
head:						disjunction;
	
body:						conjunction;

weight_at_levels:				SQUARE_OPEN term SQUARE_CLOSED
						| SQUARE_OPEN term levels_and_terms SQUARE_CLOSED;

levels_and_terms:				AT term
						| AT term COMMA terms
						| COMMA terms;

disjunction: 					classic_literal
						| classic_literal HEAD_SEPARATOR disjunction
						| existential_atom
						| existential_atom HEAD_SEPARATOR disjunction;
	
conjunction:					naf_literal_aggregate
						| naf_literal_aggregate COMMA conjunction;

classic_literal:				atom
						| DASH atom;

naf_literals:					naf_literal
						| naf_literal COMMA naf_literals;

naf_literal:					classic_literal
						| NAF classic_literal
						| builtin_atom
						| extAtom
						| NAF extAtom;

naf_literal_aggregate:				naf_literal
						| aggregate_atom
						| NAF aggregate_atom;

existential_atom:				EXISTS vars atom;

atom:						identifier
						| identifier PARAM_OPEN terms PARAM_CLOSE
						| identifier PARAM_OPEN PARAM_CLOSE;
						
extAtom:					AMPERSAND identifier PARAM_OPEN terms extSemicol terms PARAM_CLOSE
						| AMPERSAND identifier PARAM_OPEN extSemicol terms PARAM_CLOSE
						| AMPERSAND identifier PARAM_OPEN terms extSemicol PARAM_CLOSE
						| AMPERSAND identifier PARAM_OPEN PARAM_CLOSE;

extSemicol:					SEMICOLON;

identifier:					SYMBOLIC_CONSTANT
						| STRING
						| VARIABLE;
							

query: 					atom QUERY_MARK;

lower_guard_compare_aggregate:		term compareop;

upper_guard_compare_aggregate:		compareop term;

compare_aggregate:				lower_guard_compare_aggregate aggregate
						|aggregate upper_guard_compare_aggregate;

lower_guard_leftward_left_aggregate:		term leftwardop;

leftward_left_aggregate:			lower_guard_leftward_left_aggregate aggregate;
	
left_aggregate:				leftward_left_aggregate
						| rightward_left_aggregate;

lower_guard_rightward_left_aggregate:		term rightwardop;

rightward_left_aggregate:			lower_guard_rightward_left_aggregate aggregate;

upper_guard_leftward_right_aggregate:		leftwardop term;
	
upper_guard_rightward_right_aggregate:	rightwardop term;

right_aggregate:				aggregate upper_guard_leftward_right_aggregate
						| aggregate upper_guard_rightward_right_aggregate;

aggregate_atom:				left_aggregate
						| right_aggregate
						| compare_aggregate
						| leftward_left_aggregate upper_guard_leftward_right_aggregate
						| rightward_left_aggregate upper_guard_rightward_right_aggregate;

leftwardop:					LESS
						| LESS_OR_EQ;
					
rightwardop:					GREATER
						| GREATER_OR_EQ;

aggregate:					aggregate_function CURLY_OPEN aggregate_elements CURLY_CLOSED
						|aggregate_function CURLY_OPEN CURLY_CLOSED;
					
aggregate_elements:				aggregate_element SEMICOLON aggregate_elements
						| aggregate_element;

aggregate_element:				basic_terms COLON naf_literals;

aggregate_function:				AGGR_COUNT
						| AGGR_MAX
						| AGGR_MIN
						| AGGR_SUM;
											
terms:						term
						| term COMMA terms;
			
basic_terms:					basic_term
						| basic_term COMMA basic_terms;

builtin_atom:					term binop term;
						
compareop:					EQUAL
						| UNEQUAL;
						
binop:						compareop
						| compareop
						| leftwardop
						| rightwardop;

factor:					term__
						| term__ arithop2 factor;

basic_term:					ground_term
						| variable_term
						| functional_term;
	
ground_term:					SYMBOLIC_CONSTANT
						| STRING
						| NUMBER
						| DASH NUMBER;
	
variable_term:					VARIABLE
						| ANON_VAR;
			
functional_term:				identifier PARAM_OPEN terms PARAM_CLOSE;
			
expr:						factor
						| factor arithop1 expr;

arithop2:					TIMES
						| SLASH
						| BACK_SLASH;
						
arithop1: 					PLUS
						| DASH;

term_:						ANON_VAR
						| identifier PARAM_OPEN terms PARAM_CLOSE
						| NUMBER DDOT NUMBER
						| DASH term;

term__:					identifier
						| NUMBER
						| PARAM_OPEN term PARAM_CLOSE;
			
term:						term_
						| expr;

vars:						VARIABLE
						| VARIABLE COMMA vars;
				
				
NAF:						'not' ;
COMMENT_EMPTY:					'%\n' -> skip ;
COMMENT: 					'%'(.)*?'\n' -> skip ;

SYMBOLIC_CONSTANT:   				[a-z][A-Za-z_0-9]* ;
VARIABLE:           				[A-Z][A-Za-z_0-9]* ;
STRING:					'"' ('\\"' | . )*? '"' ;
NUMBER:					[0-9]+ ;

WS:			 			[ \t\n]+ -> skip ;


DOT: 						'.' ;
DDOT: 						'..' ;
COMMA:						',' ;
HEAD_SEPARATOR:				'|' ;
SEMICOLON:					';' ;
COLON: 					':' ;
AT: 						'@' ;
CONS:						':-' ;
WCONS: 					':~' ;
PLUS:						'+' ;
DASH:						'-' ;
TIMES: 					'*' ;
SLASH: 					'/' ;
BACK_SLASH:					'\\' ;
PARAM_OPEN:					'(' ;
PARAM_CLOSE:					')' ;
SQUARE_OPEN: 					'[' ;
SQUARE_CLOSED:					']' ;
CURLY_OPEN: 					'{' ;
CURLY_CLOSED:					'}' ;
QUERY_MARK:					'?' ;	
ANON_VAR:					'_' ;
EQUAL:						'=' | '==' ;
UNEQUAL: 					'<>' | '!=' ;
LESS: 						'<' ;
GREATER: 					'>' ;
LESS_OR_EQ:					'<=' ;
GREATER_OR_EQ:			 		'>=' ;
AMPERSAND: 					'&' ;	
EXISTS:					'\\E';


AGGR_COUNT:          				'#count';
AGGR_MAX:            				'#max';
AGGR_MIN:            				'#min';
AGGR_SUM:            				'#sum';
















