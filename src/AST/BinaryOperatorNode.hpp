#ifndef BINARYOPERATORNODE_HPP
#define BINARYOPERATORNODE_HPP

#include "Node.hpp"

namespace ast
{
    struct BinaryOperator : Node
    {
        enum Operator
        {
            ASSIGNMENT,

            // comparisions
            EQUALITY,
            NON_EQUALITY,
            LESS_THAN,
            GREATER_THAN,
            LESS_THAN_OR_EQUALS,
            GREATER_THAN_OR_EQUALS,

            // arithmetic
            PLUS,
            MINUS,
            MULT,
            DIV,

            // logical
            LOGICAL_OR,
            LOGIAL_AND,
        } 
        // the operator to use
        op;

        NodePtr left;
        NodePtr right;

        BinaryOperator(Operator op, NodePtr left, NodePtr right);
        virtual Value eval(Interpreter&) override;
        virtual Type type() const override { return Node::Type::BINARY_OP; }
    };
}

#endif // BINARYOPERATORNODE_HPP
