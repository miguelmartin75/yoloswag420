#include <iostream>
#include <string>

#include "lexer.hpp"
#include "parser.hpp"

#include "Interpreter.hpp"
#include "ErrorCodes.hpp"

// prints the usage of the
void printUsage(char* programName);

int main(int argc, char* argv[])
{
	// check usage of the program
	if(argc == 1)
	{
		std::cerr << "[ERROR]: No input file.\n";
		printUsage(argv[0]);
		return ErrorCodes::USAGE_ERROR;
	}
	
	// holds temporary errors
	int errorCode = ErrorCodes::SUCCESS;
	
	// holds the statements we will parse
	auto statements = parse(argv[1], &errorCode);
	if(errorCode) // this is gross, I know
	{
		return errorCode;
	}
	
	Interpreter interpreter; // create an interpreter
	errorCode = interpreter.interpret(statements); // interpret the statements
	return errorCode;
}

void printUsage(char* programName)
{
	std::cout << programName << " <input-file>\n";
	std::cout << "\tWhere <input-file> is the source code of your yoloswag420 program.\n";
}
