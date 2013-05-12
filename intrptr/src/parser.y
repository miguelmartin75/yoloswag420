%{
#include <iostream>
#include <string>
%}

%code requires {
    /* Requirements */
}



/***************
 * Preferences *
 ***************/
%defines "parser.hpp"
%output "parser.cpp"

%union {
    double numberValue;
    std::string stringValue;
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

/********
* RULES *
*********/
%%
program : TOKEN_BEGIN_PROGRAM statements TOKEN_END_PROGRAM;

statements : statement TOKEN_END_OF_STATEMENT | TOKEN_END_OF_STATEMENT;

statement : variable_declaration | expression | command;

variable_declaration : TOKEN_STRING_VAR TOKEN_IDENTIFIER { std::cout << "Variable declared!\n"; } |
                        TOKEN_NUMBER_VAR TOKEN_IDENTIFIER { std::cout << "# made\n"; };

expression : var;

command : TOKEN_PRINT expression | TOKEN_INPUT var;

var : TOKEN_IDENTIFIER { std::cout << "reference to a variable made\n"; };
%%
