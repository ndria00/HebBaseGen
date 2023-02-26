#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "antlr4-runtime.h"
#include "parser/ASPCore2Lexer.h"
#include "parser/ASPCore2Parser.h"
#include "listeners/ASPCore2ProgramListener.h"
#include "listeners/ASPCore2FactListenerNoTree.h"
#include "grounder/Program.h"
#include "DataStructures/AuxiliaryMapSmart.h"
#include "DataStructures/TupleFactory.h"
#include "DataStructures/TupleLight.h"
#include "DataStructures/ConstantsManager.h"
#include "ASP2CPP/CompilationManager.h"
#include "ASP2CPP/Executor.h"
#include <filesystem>

enum ExecutionMode{COMPILER = 0, GENERATOR = 1};
enum PrintMode{SILENT = 0, VERBOSE = 1};

int main(int argc, char *argv[]){
	ExecutionMode MODE = COMPILER;
	PrintMode printMode= SILENT;
	if(argc > 1){
		std::string option1 = argv[1];
		if(option1 == "compile"){
			MODE = COMPILER;
		}
		else if(option1 == "generate"){
			MODE = GENERATOR;
		}
		else{
			std::cout<<"Option not supported... terminating\n";
			return 0;
		}
	}

	std::ifstream myFile;
	std::string myInput = "";
	bool datalogEncoding = true;
	if(MODE == COMPILER){
		if(argc < 2){
			myFile.open("../src/resources/input.txt");
		}		
		else{
			std::string option2 = argv[2];
			std::string option3 = "";
			if(argc > 3){
				option3 = argv[3];
			}
			if(option2 == "asp"){
				datalogEncoding = false;
			}
			std::string fileName = "";
			if(option3 != ""){
				fileName = option3;
			}
			else{
				fileName = "../src/resources/input.txt";
			}
			if(!std::filesystem::exists(fileName)){
				std::cout << "Input file does not exist\n";
				return 0;
			}
			else
				myFile.open(fileName);
		}
	}
	else if(MODE == GENERATOR){
		if(printMode == VERBOSE)
			std::cout<<"reading facts and generating base..."<<std::endl;
		if(argc <= 2){
			if(printMode == VERBOSE)
				std::cout << "Opening default encoding\n";
			myFile.open("../src/resources/facts.txt");
		}
		else{
				if(printMode == VERBOSE)
					std::cout << "Not Opening default encoding\n";
				if(!std::filesystem::exists(argv[2])){
					std::cout << "Input file does not exist\n";
					return 0;
				}
				else
					myFile.open(argv[2]);
		}
	}


	if(MODE == COMPILER){
		std::cout<<"Building program\n";
	}
	else if (MODE == GENERATOR){
		if(printMode == VERBOSE)
			std::cout<<"Building and generating\n";
	}

	if(MODE == COMPILER){
		antlr4::ANTLRInputStream input(myFile);
		ASPCore2Lexer lexer (&input);
		antlr4::CommonTokenStream tokens(&lexer);
		ASPCore2Parser parser (&tokens);
		antlr4::tree::ParseTree *tree = parser.program();
		Program* program =  new Program();
		Builder* builder =  new Builder(program);
		ASPCore2ProgramListener listener(builder);
		antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
		std::cout<<"Builder finished\n";
		listener.getBuilder()->printProgram();
		
		if(program->containsAggregates()){
			std::cout<<"Aggregates are not yet supported... Terminating"<<std::endl;
			return 0;
		}
		//TODO
		// if(program->containsUnsupportedBuiltIn()){
			
		// }
		for(ChoiceRule* r : program->getChoiceRules()){
			if(r->cointainsRecursiveInChoices()){
				std::cout << "recursion inside choice elements is not supported" << std::endl;
				return 0;
			}
		}
		if(program->checkSafety()){
			std::cout<<"No safety errors found"<<std::endl;
		}
		else{
			std::cout<<"Safety errors detected!"<<std::endl;
			return 0;
		}
		std::cout<<"Compiling program..."<<std::endl;
		program->setLanguageDatalog(datalogEncoding);
		//generating compiled program
		CompilationManager compManager = CompilationManager(builder);
		
		std::ofstream outfile("src/ASP2CPP/Executor.cpp");
		compManager.setOutStream(&outfile);
		compManager.generateProgram(program);
		outfile.close();
		builder->clearMemory();
		delete program;
		delete builder;
	}
	else if(MODE == GENERATOR){
		Executor* executor = new Executor();
		executor->init();
		ASPCore2FactListenerNoTree* listener = new ASPCore2FactListenerNoTree(executor);
		if(myFile.is_open()){
			std::string line;
			while(getline(myFile, line)){
				//TODO check if there is a way to avoid the creation of new objects
				//note: stackoverflow says that recreating has essentially no impact
				//on performances because most data is held in static fields
				antlr4::ANTLRInputStream input(line);
				ASPCore2Lexer lexer(&input);
				antlr4::CommonTokenStream tokens(&lexer);
				ASPCore2Parser parser(&tokens);
				//parser.setBuildParseTree(false);
				//parser.addParseListener(listener);
				listener->setTokenStream(&tokens);

				//lexer.setInputStream(&input1);
				//tokens.setTokenSource(&lexer);
				//parser.setTokenStream(&tokens);
				//factParser->parseFact(line);
				antlr4::tree::ParseTree *tree = parser.program();
				antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, tree);
				tree->children.clear(); 
			}
		}	


		//std::cout<<"Builder finished\n";
		//std::cout<<"Generating base...\n";
		executor->executeProgram();
		std::cout<<std::endl;
		delete listener;
		delete executor;
	}
}