%{

#include <iostream>
#include <util/string_utils.hpp> // mainly for to_string
#include "parser.hpp" // The parser; generated from yacc (bison)

#include "AST/Types.hpp"

int yyerror(ast::StatementList&, const char* message);
inline int token(int token) { yylval.token = token; return token; }

%}

%option outfile="lexer.cpp"
%option header-file="lexer.hpp"
%option yylineno
%option noyywrap

/* Character Specifics */
DIGIT [0-9]+
UPPERCASE_ALPHA [A-Z]+
LOWERCASE_ALPHA [a-z]+
ALPHA [A-Za-z]+
STRING_LITERAL \"(\\.|[^"])*\"
WHITESPACE [ \t\r\n]*


/********************
 * Token Evaluation *
 ********************/
%%

{WHITESPACE} { /* ignore whitespace */ }
{STRING_LITERAL} { std::cout << "hit string literal\n"; yylval.string = yytext; return TOKEN_STRING_LITERAL; }
{DIGIT}+\.{DIGIT} { yylval.number = util::from_string<Number>(String{yytext}); return TOKEN_NUMBER_CONSTANT; }
{DIGIT}+ { yylval.number = util::from_string<Number>(String{yytext}); return TOKEN_NUMBER_CONSTANT; }
{ALPHA}*{DIGIT} { return token(TOKEN_IDENTIFIER); }

"#yoloswag" { return token(TOKEN_BEGIN_PROGRAM); }
"#420" { return token(TOKEN_END_PROGRAM); }
"plz" { return token(TOKEN_END_OF_STATEMENT); }

"prnt" { return token(TOKEN_PRINT); }
"inpt" { return token(TOKEN_INPUT); }
"str" { return token(TOKEN_STRING_TYPE); }
"#" { return token(TOKEN_NUMBER_TYPE); }

"(" { return token(TOKEN_LEFT_PARAN); }
")" { return token(TOKEN_RIGHT_PARAN); }
"+" { return token(TOKEN_PLUS); }
"-" { return token(TOKEN_MINUS); }
"*" { return token(TOKEN_MULTIPLY); }
"/" { return token(TOKEN_DIVIDE); }
"=" { return token(TOKEN_ASSIGNMENT); }

"\<3.*" { std::cout << "hit comment\n"; /* ignore comment */ }

. { std::cerr << "[ERROR]: Unknown token: \'" << yytext << "\'" << '\n'; }

%%
