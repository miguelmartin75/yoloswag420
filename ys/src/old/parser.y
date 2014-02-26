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

%{
#include <iostream>
#include <string>
#include "ErrorCodes.hpp"
#include "Interpreter.hpp"

// extern functions/vars (yuck, I know)
extern "C" {
	FILE *yyin;
	FILE *yyout;
	int yyparse(void);
}

StatementList parse(const std::string& filepath, int* errorCode = nullptr);
%}

%parse-param {StatementList& statements}

/***************
 * Preferences *
 ***************/
%defines "parser.hpp"
%output "parser.cpp"

%union {
    double numberValue;
    char* stringValue;
}

/********************
* Token Definitions *
*********************/

%token TOKEN_BEGIN_PROGRAM;
%token TOKEN_END_PROGRAM;

/* Variable Types */
%token TOKEN_STRING_VAR
%token TOKEN_NUMBER_VAR

/* Identifiers/constant expressions */
%token TOKEN_IDENTIFIER
%token <stringValue> TOKEN_STRING_LITERAL
%token <numberValue> TOKEN_NUMBER_CONSTANT
%token TOKEN_END_OF_STATEMENT

/* Commands */
%token TOKEN_PRINT
%token TOKEN_INPUT

/* Operators */
%token TOKEN_LEFT_PARAN
%token TOKEN_RIGHT_PARAN
%token TOKEN_ASSIGNMENT 
%token TOKEN_MULTIPLY
%token TOKEN_DIVIDE
%token TOKEN_PLUS
%token TOKEN_MINUS

/* Operator precedence for mathematical operators */
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULTIPLY TOKEN_DIVIDE

%start program

%%
program : TOKEN_BEGIN_PROGRAM statements TOKEN_END_PROGRAM;

statements : statement TOKEN_END_OF_STATEMENT | TOKEN_END_OF_STATEMENT;

statement : variable_declaration | command | expression;

variable_declaration : TOKEN_STRING_VAR TOKEN_IDENTIFIER { } |
                       TOKEN_NUMBER_VAR TOKEN_IDENTIFIER { };

expression : var;

command : TOKEN_PRINT expression { } | 
          TOKEN_INPUT var { };

var : TOKEN_IDENTIFIER { std::cout << "reference to a variable made\n"; };
%%

StatementList parse(const std::string& filepath, int* errorCode)
{
	// Open the file we wish to interpet
	FILE* file = fopen(filepath.c_str(), "r"); // have to use FILE for bison/flex
	
	// if we failed to open the file
	if(!file)
	{
		std::cerr << "[ERROR]: Failed to open file: \"" << filepath << "\"\n";
		std::cerr << "Perhaps there is no persmission or file does not exist?\n";

		if(errorCode)
            *errorCode = ErrorCodes::FAILED_TO_OPEN_FILE;

        return;
	}
	
	// set flex to read from the file instead of stdin
	yyin = file;

    // temporary variable to all the statements in the program
    StatementList statements;

	// parse through the file
	while(!feof(yyin))
	{
		// get yacc (bison in this case) to parse the file
		yyparse(statements);
	}

    // return all the statements - to be ready to interpretered/compiled
	return statements;
}
