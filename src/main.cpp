#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "antlr4-runtime.h"
#include "parser/ASPCore2Lexer.h"
#include "parser/ASPCore2Parser.h"
#include "parserFacts/ASPCore2FactsLexer.h"
#include "parserFacts/ASPCore2FactsParser.h"
#include "listeners/ASPCore2ProgramListener.h"
//#include "listeners/ASPCore2FactListenerNoTree.h"
#include "listeners/ASPCore2FactsListenerLight.h"
#include "grounder/Program.h"
#include "DataStructures/AuxiliaryMapSmart.h"
#include "DataStructures/TupleFactory.h"
#include "DataStructures/TupleLight.h"
#include "DataStructures/ConstantsManager.h"
#include "ASP2CPP/CompilationManagerBase.h"
#include "ASP2CPP/PreCompilerASP.h"
#include "ASP2CPP/Executor.h"
#include "listeners/ASPFactParserRegex.h"
#include <filesystem>

enum ExecutionMode{COMPILER = 0, GENERATOR = 1};
enum PrintMode{SILENT = 0, VERBOSE = 1};

int main(int argc, char *argv[]){
	ExecutionMode MODE = COMPILER;
	PrintMode printMode = SILENT;
	bool usedArgs[argc] = {0};
	//never use the executable ar option
	usedArgs[0] = true;

	if(argc > 1){
		std::string option1 = "";
		for(unsigned i = 0; i < argc; ++i){
			std::string option = argv[i];
			if(option == "compile"){
				option1 = argv[i];
				usedArgs[i] = true;
				break;
			}
			if(option == "generate"){
				option1 = argv[i];
				usedArgs[i] = true;
				break;
			}
		}
		if(option1 == "compile"){
			MODE = COMPILER;
		}
		else if(option1 == "generate"){
			MODE = GENERATOR;
		}
		else{
			std::cout<<"Option not supported(specify one between compile and generate)... terminating\n";
			return 0;
		}
	}

	std::ifstream myFile;
	std::string myInput = "";
	bool datalogEncoding = true;
	if(MODE == COMPILER){
		if(argc < 2){
			std::cout << "Opening default encoding at @project_root/src/resources/input.txt\n";
			myFile.open("/src/resources/input.txt");
		}		
		else{
			//get as file path the first non-used option
			std::string fileName = "";
			for(unsigned i = 0; i < argc; ++i){
				if(usedArgs[i] == false){
					fileName = argv[i];
					break;
				}
			}
			if(fileName == ""){
				fileName = "/src/resources/input.txt";
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
				std::cout << "Opening default instance at @project_root/src/resources/facts.txt\n";
			myFile.open("/src/resources/facts.txt");
		}
		else{
			//get as file path the first non-used option
			std::string fileName = "";
			for(unsigned i = 0; i < argc; ++i){
				if(usedArgs[i] == false){
					fileName = argv[i];
					break;
				}
			}
			if(printMode == VERBOSE)
				std::cout << "Not Opening default encoding\n";
			if(!std::filesystem::exists(fileName)){
				std::cout << "Input file does not exist\n";
				return 0;
			}
			else
				myFile.open(fileName);
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
		//program->setLanguageDatalog(datalogEncoding);
		
		
		PreCompilerASP* preCompiler = new PreCompilerASP(program);
		CompilationManagerBase* compManager = preCompiler->getCompilationManager();
		// if(program->isDatalog()){
		// 	//generating compiled program
		// 	compManager = new CompilationManagerDatalog(builder);
		// }
		// else{
		// 	compManager = new CompilationManagerASP(builder);
		// }
		compManager->setPreCompiler(preCompiler);
		
		std::ofstream outfile("src/ASP2CPP/Executor.cpp");
		compManager->setOutStream(&outfile);
		compManager->generateProgram(program);
		outfile.close();
		builder->clearMemory();
		delete preCompiler;
		delete program;
		delete builder;
	}
	else if(MODE == GENERATOR){
		Executor* executor = new Executor();
		executor->init();
		ASPFactParserRegex* factParser = new ASPFactParserRegex(executor);
		if(myFile.is_open()){
			std::string line;
			//std::cout<< "facts{\n";
			std::cout <<"True: {\n";

			while(getline(myFile, line)){
				factParser->parseFact(line);
			}
			//std::cout<<"}\n";
		}	


		//std::cout<<"Builder finished\n";
		//std::cout<<"Generating base...\n";
		executor->executeProgram();
		std::cout<<std::endl;
		delete factParser;
		delete executor;
	}
}