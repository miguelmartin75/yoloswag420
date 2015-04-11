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


/********************
 * Token Evaluation *
 ********************/
%%

{WHITESPACE} { /* ignore whitespace */ }
{STRING_LITERAL} { yylval.stringValue = yytext; return TOKEN_STRING_LITERAL; }
{DIGIT}\.{DIGIT} { util::from_string<std::string>(yytext, yylval.numberValue); return TOKEN_NUMBER_CONSTANT; }
{ALPHA}*{DIGIT} { return TOKEN_IDENTIFIER; }

"#yoloswag" { return TOKEN_BEGIN_PROGRAM; }
"#420" { return TOKEN_END_PROGRAM; }
"plz" { return TOKEN_END_OF_STATEMENT; }

"prnt" { return TOKEN_PRINT; }
"inpt" { return TOKEN_INPUT; }
"str" { return TOKEN_STRING_TYPE; }
"#" { return TOKEN_NUMBER_TYPE; }

"(" { return TOKEN_LEFT_PARAN; }
")" { return TOKEN_RIGHT_PARAN; }
"+" { return TOKEN_PLUS; }
"-" { return TOKEN_MINUS; }
"*" { return TOKEN_MULTIPLY; }
"/" { return TOKEN_DIVIDE; }
"=" { return TOKEN_ASSIGNMENT; }

. { print_error("Unknown token: \'", yytext, "\'"); }

%%

// TODO: use logger
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
