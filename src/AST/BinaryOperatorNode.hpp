#ifndef BINARYOPERATORNODE_HPP
#define BINARYOPERATORNODE_HPP

#include "Node.hpp"

namespace ast
{
    struct BinaryOperator : Node
    {
        enum Operator
        {
            /*
            // comparisions
            EQUALITY,
            NON_EQUALITY,
            LESS_THAN,
            GREATER_THAN,
            LESS_THAN_OR_EQUALS,
            GREATER_THAN_OR_EQUALS,
            */

            // arithmetic
            PLUS,
            MINUS,
            MULT,
            DIV,

            /*
            // logical
            LOGICAL_OR,
            LOGIAL_AND,

            // bitwise
            BITWISE_OR,
            BITWISE_AND,
            BITWISE_XOR
            */
        } 
        // the operator to use
        op;

        Node& left;
        Node& right;

        BinaryOperator(Node& Left, Node& Right, Operator Op)
            : left(Left), right(Right), op(Op)
        {
        }

        virtual Value eval(Interpreter&) override;
    };
}

#endif // BINARYOPERATORNODE_HPP
