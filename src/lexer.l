%{

#include <iostream>
#include <boost/lexical_cast/try_lexical_convert.hpp>
#include "parser.hpp" // The parser; generated from yacc (bison)

#include "AST/Types.hpp"

int yyerror(ast::StatementList&, const char* message);
inline int token(int token) { yylval.token = token; return token; }
std::string stringBuffer;

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
STRING_LITERAL \"(\\.|[^\\"])*\"
WHITESPACE [ \t\r\n]*

/********************
 * Token Evaluation *
 ********************/
%x str
%%

\" { BEGIN str; stringBuffer.clear(); }
<str>[^\\\"\n]* { stringBuffer += yytext; }
<str>\\n { stringBuffer += '\n'; }
<str>\\r { stringBuffer += '\r'; }
<str>\\a { stringBuffer += '\a'; }
<str>\\b { stringBuffer += '\b'; }
<str>\\t { stringBuffer += '\t'; }
<str>\\[\\"] { stringBuffer += yytext[1]; }
<str>\" { yylval.string = &(*stringBuffer.begin()); BEGIN 0; return TOKEN_STRING_LITERAL; }
<str>\\. { std::cerr << "error in string literal. TODO give more meaning to this message.\n"; }


{WHITESPACE} { /* ignore whitespace */ }
"#yoloswag" { return token(TOKEN_BEGIN_PROGRAM); }
"#420" { return token(TOKEN_END_PROGRAM); }
"plz" { return token(TOKEN_END_OF_STATEMENT); }

"prnt" { return token(TOKEN_PRINT); }
"inpt" { return token(TOKEN_INPUT); }
"txt" { return token(TOKEN_STRING_TYPE); }
"#" { return token(TOKEN_NUMBER_TYPE); }

{DIGIT}+\.{DIGIT} { 
    boost::conversion::try_lexical_convert(yytext, yylval.number);
    return token(TOKEN_NUMBER_CONSTANT); 
}
{DIGIT}+ { 
    boost::conversion::try_lexical_convert(yytext, yylval.number);
    return token(TOKEN_NUMBER_CONSTANT); 
}

[a-zA-Z_][a-zA-Z0-9_]* { yylval.string = yytext; return TOKEN_IDENTIFIER; }

"(" { return token(TOKEN_LEFT_PARAN); }
")" { return token(TOKEN_RIGHT_PARAN); }
"+" { return token(TOKEN_PLUS); }
"-" { return token(TOKEN_MINUS); }
"*" { return token(TOKEN_MULTIPLY); }
"/" { return token(TOKEN_DIVIDE); }
"=" { return token(TOKEN_ASSIGNMENT); }

. { std::cerr << "[ERROR]: Unknown token: \'" << yytext << "\'" << '\n'; }

%%
