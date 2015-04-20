%{

#include <cstdio>
#include <iostream>

#include "AST/StatementList.hpp"
#include "AST/BinaryOperatorNode.hpp"

extern FILE *yyin;
extern FILE *yyout;
extern int yylex(void);
extern int yylineno;

int yyerror(ast::StatementList& ast, const char* message);
extern int yywrap(void);

ast::BinaryOperatorNode::Operator toBinaryOp(int token);

%}

/***************
 * Preferences *
 ***************/

%code requires {
    #include "AST/AST.hpp"

    #include "AST/AST.hpp"
    #include "AST/StatementList.hpp"
    #include "AST/Types.hpp"
}

%defines "parser.hpp"
%output "parser.cpp"

%parse-param {ast::StatementList& statements}

%union {
    ast::BaseNode* node; 
    ast::IdentifierNode* idNode;

    double number;
    char* string;

    // to store the actual token
    // e.g. for an operator we will store the token
    // thus when converting we will just:
    // if token == TOKEN_PLUS
    // etc. etc.
    int token;
}

/********************
* Token Definitions *
*********************/

%token TOKEN_BEGIN_PROGRAM;
%token TOKEN_END_PROGRAM;
%token TOKEN_END_OF_STATEMENT

/* Commands */
%token TOKEN_PRINT
%token TOKEN_INPUT

/* Variable Types */
%token TOKEN_STRING_TYPE
%token TOKEN_NUMBER_TYPE

/* Identifiers/constant expressions */
%token <string> TOKEN_STRING_LITERAL
%token <number> TOKEN_NUMBER_CONSTANT

/* Operators */
%token <token> TOKEN_LEFT_PARAN
%token <token> TOKEN_RIGHT_PARAN

%token <token> TOKEN_ASSIGNMENT 
%token <token> TOKEN_MULTIPLY
%token <token> TOKEN_DIVIDE
%token <token> TOKEN_PLUS
%token <token> TOKEN_MINUS

%token <string> TOKEN_IDENTIFIER

%type <node> expression 
%type <node> constant
%type <node> value
%type <node> command
%type <node> statement
%type <node> variable_declaration
%type <node> identifier

%type <token> binary_op

/* Operator precedence for mathematical operators */
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULTIPLY TOKEN_DIVIDE

/*%right TOKEN_ASSIGNMENT;*/

%start program

%%

program : TOKEN_BEGIN_PROGRAM statements TOKEN_END_PROGRAM | TOKEN_BEGIN_PROGRAM TOKEN_END_PROGRAM;

statements : statement TOKEN_END_OF_STATEMENT { statements.emplace_back(ast::node($1)); } |
             statements statement TOKEN_END_OF_STATEMENT { statements.emplace_back(ast::node($2)); } |
             TOKEN_END_OF_STATEMENT;

statement : variable_declaration | expression;

/* TODO: Throw errors */

variable_declaration : TOKEN_STRING_TYPE identifier { $$ = new ast::VariableDeclNode(ast::VariableType::STRING, static_cast<ast::IdentifierNode*>($2)->id); } |
                       TOKEN_NUMBER_TYPE identifier { $$ = new ast::VariableDeclNode(ast::VariableType::NUMBER, static_cast<ast::IdentifierNode*>($2)->id); } |
                       TOKEN_STRING_TYPE identifier TOKEN_ASSIGNMENT expression { $$ = new ast::VariableDeclNode(ast::VariableType::STRING, static_cast<ast::IdentifierNode*>($2)->id, ast::node($4)); } |
                       TOKEN_NUMBER_TYPE identifier TOKEN_ASSIGNMENT expression { $$ = new ast::VariableDeclNode(ast::VariableType::NUMBER, static_cast<ast::IdentifierNode*>($2)->id, ast::node($4)); };

identifier : TOKEN_IDENTIFIER { $$ = new ast::IdentifierNode($1); }

/* expression */
expression : identifier | 
             constant | 
             command |
             value binary_op value
             { 
               auto op = toBinaryOp($2);
               using OperatorType = decltype(op);
               if(op == OperatorType::UNDEF)
               {
                    std::cerr << "unknown operator\n";
                    exit(-1);
               }
               $$ = new ast::BinaryOperatorNode(op, ast::node($1), ast::node($3)); 
             };

value: constant | identifier;

constant: TOKEN_NUMBER_CONSTANT { $$ = new ast::ConstantValueNode{$1}; } | 
          TOKEN_STRING_LITERAL  { $$ = new ast::ConstantValueNode{$1}; } ;

binary_op : TOKEN_PLUS;

command : TOKEN_PRINT expression { $$ = new ast::CommandNode(ast::Command::PRINT, ast::node($2)); }; | 
          TOKEN_INPUT { $$ = new ast::CommandNode(ast::Command::INPUT, nullptr); };

%%

/*
expression : unary_op expression { } |
expression:
             expression binary_op expression { } |
unary_op : TOKEN_ASSIGNMENT | TOKEN_PLUS | TOKEN_MINUS;
*/

ast::BinaryOperatorNode::Operator toBinaryOp(int token)
{
    switch(token)
    {
        case TOKEN_ASSIGNMENT:
            return ast::BinaryOperatorNode::Operator::ASSIGNMENT;
        case TOKEN_MULTIPLY:
            return ast::BinaryOperatorNode::Operator::MULT;
        case TOKEN_DIVIDE:
            return ast::BinaryOperatorNode::Operator::DIV;
        case TOKEN_PLUS:
            return ast::BinaryOperatorNode::Operator::PLUS;
        case TOKEN_MINUS:
            return ast::BinaryOperatorNode::Operator::MINUS;
        default:
            return ast::BinaryOperatorNode::Operator::UNDEF;
    }
}

int yyerror(ast::StatementList& ast, const char* message)
{
    std::cerr << "[ERROR]: " << message << " (line: " << yylineno << ")\n";
    return 0;
}
