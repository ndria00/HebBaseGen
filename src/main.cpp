#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "antlr4-runtime.h"
#include "parser/ASPCore2Lexer.h"
#include "parser/ASPCore2Parser.h"
#include "listeners/ASPCore2ProgramListener.h"
#include "grounder/Program.h"
#include "DataStructures/AuxiliaryMapSmart.h"
#include "DataStructures/TupleFactory.h"
#include "DataStructures/TupleLight.h"
#include "DataStructures/ConstantsManager.h"
#include "ASP2CPP/CompilationManager.h"
#include "ASP2CPP/Executor.h"

void print(){
	std::cout << "Hello world !" << std::endl;
}
static std::once_flag printFlag;

enum ExecutionMode{COMPILER = 0, GENERATOR = 1};

int main(int argc, char *argv[]){
	ExecutionMode MODE = COMPILER;
	
	if(argc > 1){
		std::string option1 = argv[1];
		if(option1 == "compile"){
			std::cout<<"Compiling program..."<<std::endl;
			MODE = COMPILER;
		}
		else if(option1 == "generate"){
			std::cout<<"reading facts and generating base..."<<std::endl;
			MODE = GENERATOR;
		}
		else{
			std::cout<<"Option not supported\n";
			return 0;
		}
	}

	std::ifstream myFile;
	std::string myInput = "";
	if(MODE == COMPILER){
		myFile.open("../src/resources/input.txt");
	}
	else if(MODE == GENERATOR){
		myFile.open("../src/resources/facts.txt");
	}

	
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
	if(MODE == COMPILER){
		std::cout<<"Building program\n";
	}
	else if (MODE == GENERATOR){
		std::cout<<"Building facts\n";
	}

	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
	std::cout<<"Builder finished\n";
	if(MODE == COMPILER){
		listener.getBuilder()->printProgram();
		
		if(program->checkSafety()){
			std::cout<<"No safety errors found"<<std::endl;
		}
		else{
			std::cout<<"Safety errors detected!"<<std::endl;
			return 0;
		}
		
		//generating compiled program
		CompilationManager compManager = CompilationManager(builder);
		
		std::ofstream outfile("../src/ASP2CPP/Executor.cpp");
		compManager.setOutStream(&outfile);
		compManager.generateProgram(program);
		outfile.close();
	}
	else if(MODE == GENERATOR){
		std::cout<<"Generating base...\n";
		ExecutorBase* executor = new Executor();
		executor->init();
		std::vector<std::pair<Literal*, bool>> facts = builder->getAllFacts();
		for(unsigned i = 0; i < facts.size(); ++i){
			executor->insertFactIntoFactory(*facts[i].first, facts[i].second);
			facts[i].first->print();
			std::cout<<". ";
		}
		executor->executeProgram();
		std::cout<<std::endl;
		delete executor;
	}
	
	builder->clearMemory();
	delete program;
	delete builder;

}