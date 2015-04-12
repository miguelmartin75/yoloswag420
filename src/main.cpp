#include <iostream>
#include <string>

#include "lexer.hpp"
#include "parser.hpp"

#include "Interpreter.hpp"
#include "ErrorCodes.hpp"

ast::StatementList parse(const std::string& filepath, int* errorCode);

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
	auto statements = parse(std::string{argv[1]}, &errorCode);
	if(errorCode) // this is gross, I know
	{
		return errorCode;
	}
	
    std::cout << "interpreting... " << statements.size() << " statements\n";
	Interpreter interpreter; // create an interpreter
	errorCode = interpreter.interpret(statements); // interpret the statements
	return errorCode;
}

void printUsage(char* programName)
{
	std::cout << programName << " <input-file>\n";
	std::cout << "\tWhere <input-file> is the source code of your yoloswag420 program.\n";
}

ast::StatementList parse(const std::string& filepath, int* errorCode = nullptr)
{
    ast::StatementList statements;
	// Open the file we wish to interpret
	FILE* file = fopen(filepath.c_str(), "r"); // have to use FILE for bison/flex
	
    // if we failed to open the file
    if(!file)
	{
		std::cerr << "[ERROR]: Failed to open file: \"" << filepath << "\"\n";
		std::cerr << "Perhaps there you do not have permission to read the file, or the file does not exist?\n";

		if(errorCode)
        {
            // TODO: don't use magic number
            *errorCode = -1;
        }
        return statements;
	}

	
	// set flex to read from the file instead of stdin
	yyin = file;


	// parse through the file
	while(!feof(yyin))
	{
        std::cout << "parsing...\n";
		// get yacc (bison in this case) to parse the file
		yyparse(statements);
	}

    return statements;
}
