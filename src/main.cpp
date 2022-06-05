#include <iostream>
#include <string>
#include "antlr4-runtime.h"
#include "parser/ASPCore2Lexer.h"
#include "parser/ASPCore2Parser.h"
#include "Program.h"
#include "Builder.h"

void print(){
	std::cout << "Hello world !" << std::endl;
}
static std::once_flag printFlag;
int main(int argc, char *argv[])
{
	/*
	//std::cout << "Parsing " << argv[1]<<std::endl;
	std::string myInput;
	std::cout<<"Inserire input di cui fare il parsing: ";
	std::cin>>myInput;

	//std::string toParse("a(X):-b(X.");

	antlr4::ANTLRInputStream input;
	input.load(myInput);
	std::cout<<"Parsing "<<input.toString()<<std::endl;
	// std::call_once(printFlag,print);
	ASPCore2Lexer lexer (&input);
	antlr4::CommonTokenStream tokens(&lexer);
	ASPCore2Parser parser (&tokens);
	antlr4::tree::ParseTree *tree = parser.program();
	std::cout << tree->toStringTree() <<std::endl;
	Program program;
	//Builder builder;
	std::cout<<"Calling builder\n";
	//builder.buildProgram(parser.program(), program);
	for(Rule r: program.getRules()){
		r.print();
	}
	std::cout<<"Builder finished\n";
	*/
	std::string myString = "WE";
	Term t;
	t.setValue(myString);
	Atom a;
	a.addTerm(&t);
	Rule rule;
	rule.addAtomInHead(&a);

	//delete rule;
	//delete a;
	//delete t;
	//rule.clearRule();

}