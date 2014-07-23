%{

#include <iostream>
#include <util/string_utils.hpp> // mainly for to_string
#include "parser.hpp" // The parser; generated from yacc (bison)

int yyerror(const char* message);

%}

%option outfile="lexer.cpp"
%option header-file="lexer.hpp"

/* Character Specifics */
DIGIT [0-9]+
UPPERCASE_ALPHA [A-Z]+
LOWERCASE_ALPHA [a-z]+
ALPHA [A-Za-z]+
STRING_LITERAL "\".*\""
WHITESPACE [ \t\r\n]*
END_OF_STATEMENT "plz"
BEGIN_PROGRAM "#yoloswag"
END_PROGRAM "#420"

/* Operators */
LEFT_PARAN "("
RIGHT_PARAN ")"
PLUS "+"
MINUS "-"
MULTIPLY "*"
DIVIDE "/"
ASSIGNMENT "="

/* Built-in Types/Commands */
PRINT "prnt"
INPUT "inpt"
STRING_VAR "txt"
NUMBER_VAR "#"


/********************
 * Token Evaluation *
 ********************/
%%

{END_OF_STATEMENT} { return TOKEN_END_OF_STATEMENT; }
{WHITESPACE} { /* ignore whitespace */ }
{BEGIN_PROGRAM} { return TOKEN_BEGIN_PROGRAM; }
{END_PROGRAM} { return TOKEN_END_PROGRAM; }
{STRING_LITERAL} { yylval.stringValue = yytext; return TOKEN_STRING_LITERAL; }
{DIGIT}\.{DIGIT} { util::from_string<std::string>(yytext, yylval.numberValue); return TOKEN_NUMBER_CONSTANT; }
{ALPHA}*{DIGIT} { return TOKEN_IDENTIFIER; }

{LEFT_PARAN} { return TOKEN_LEFT_PARAN; }
{RIGHT_PARAN} { return TOKEN_RIGHT_PARAN; }
{PLUS} { return TOKEN_PLUS; }
{MINUS} { return TOKEN_MINUS; }
{MULTIPLY} { return TOKEN_MULTIPLY; }
{DIVIDE} { return TOKEN_DIVIDE; }
{ASSIGNMENT} { return TOKEN_ASSIGNMENT; }

{PRINT} { return TOKEN_PRINT; }
{INPUT} { return TOKEN_INPUT; }
{STRING_VAR} { return TOKEN_STRING_VAR; }
{NUMBER_VAR} { return TOKEN_NUMBER_VAR; }

. { print_error("Unknown token: \'", yytext, "\'"); }

%%

template <typename T, typename... Args>
void impl_continue_to_print_error(const T& obj, Args&&... args)
{
    std::cerr << obj;
    impl_continue_to_print_error(args...);
}

template <typename T>
void impl_continue_to_print_error(const T& obj)
{
    std::cerr << obj << '\n';
}

template <typename T, typename... Args>
void print_error(const T& obj, Args&&... args)
{
    std::cerr << "[ERROR]: " << obj;
    impl_continue_to_print_error(Args...);
}

int yyerror(const char* message)
{
    print_error(message);
}
