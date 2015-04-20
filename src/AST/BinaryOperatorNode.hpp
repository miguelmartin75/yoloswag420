#ifndef BINARYOPERATORNODE_HPP
#define BINARYOPERATORNODE_HPP

#include "Node.hpp"

namespace ast
{
    struct BinaryOperatorNode : public BaseNode
    {
        enum class Operator
        {
            ASSIGNMENT,

            // arithmetic
            PLUS,
            MINUS,
            MULT,
            DIV,

            // comparisons/logical operators
            /*
             TODO: need boolean variables
            EQUALITY,
            NON_EQUALITY,
            LESS_THAN,
            GREATER_THAN,
            LESS_THAN_OR_EQUALS,
            GREATER_THAN_OR_EQUALS,
            LOGICAL_OR,
            LOGIAL_AND,
            */

            UNDEF
        } 
        // the operator to use
        op;

        BaseNodePtr left;
        BaseNodePtr right;

        BinaryOperatorNode(Operator op, BaseNodePtr left, BaseNodePtr right);
        virtual Value eval(Interpreter&) override;
        virtual Type type() const override { return Type::BINARY_OP; }
    };
}

#endif // BINARYOPERATORNODE_HPP
