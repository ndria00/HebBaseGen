#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "parser/ASPCore2Lexer.h"
#include "parser/ASPCore2Parser.h"
#include "listeners/ASPCore2ProgramListener.h"
#include "Program.h"

void print(){
	std::cout << "Hello world !" << std::endl;
}
static std::once_flag printFlag;

int main(int argc, char *argv[]){
	
	std::ifstream myFile;
	std::string myInput = "";
	myFile.open("../src/resources/input.txt");
	if(myFile.is_open()){
		std::string line;
		while(getline(myFile, line)){
			myInput += line;
		}
	}
	


	antlr4::ANTLRInputStream input;
	input.load(myInput);
	std::cout<<"Parsing "<<myInput<<std::endl;
	ASPCore2Lexer lexer (&input);
	antlr4::CommonTokenStream tokens(&lexer);
	ASPCore2Parser parser (&tokens);
	antlr4::tree::ParseTree *tree = parser.program();

	Program* program =  new Program();
	Builder* builder =  new Builder(program);
	ASPCore2ProgramListener listener(builder);
	std::cout<<"Calling builder\n";
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
	
	std::cout<<"Builder finished\n";
	listener.getBuilder()->printProgram();
	
	listener.getBuilder()->clearMemory();
	delete program;
	delete builder;

}