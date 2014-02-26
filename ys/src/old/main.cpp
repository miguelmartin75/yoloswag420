///
/// intrptr
/// Copyright (C) 2013 Miguel Martin. All rights reserved.
///
///
/// This software is provided 'as-is', without any express or implied warranty.
/// In no event will the authors be held liable for any damages arising from the
/// use of this software.
///
/// Permission is hereby granted, free of charge, to any person
/// obtaining a copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// 1. The origin of this software must not be misrepresented;
///    you must not claim that you wrote the original software.
///    If you use this software in a product, an acknowledgment
///    in the product documentation would be appreciated but is not required.
///
/// 2. Altered source versions must be plainly marked as such,
///	   and must not be misrepresented as being the original software.
///
/// 3. The above copyright notice and this permission notice shall be included in
///    all copies or substantial portions of the Software.
///

#include <iostream>
#include <string>

#include "lexer.hpp"
#include "parser.hpp"
#include "Interpreter.hpp"
#include "ErrorCodes.hpp"

// Functions
void printUsage();

int main(int argc, char* argv[])
{
	// check usage of the program
	if(argc == 1)
	{
		std::cerr << "[ERROR]: No input file\n";
		printUsage();
		return ErrorCodes::USAGE_ERROR;
	}
	
	// holds temporary errors
	int errorCode = ErrorCodes::SUCCESS;
	
	
	// holds the statements we will parse
	StatementList statements = parse(argv[1], &errorCode);
	if(errorCode) // this is gross, I know
	{
		return errorCode;
	}
	
	Interpreter interpreter; // create an interpreter
	errorCode = interpreter.interpret(statements); // interpret the statements
	
	return errorCode;
}

void printUsage()
{
	std::cout << "intrptr <input-file>\n";
	std::cout << "\tWhere <input-file> is the source code of your yoloswag420 application\n";
}