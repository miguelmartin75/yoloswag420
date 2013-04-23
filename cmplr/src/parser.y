%{
#include <string>
%}

%code requires {
    /* Requirements */
}



/***************
 * Preferences *
 ***************/
%defines "Parser.hpp"
%output "Parser.cpp"

%union {
    double numberValue;
    std::string stringValue;

}

/********************
* Token Definitions *
*********************/

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

%%
