#ifndef UNARYOPERATORNODE_HPP
#define UNARYOPERATORNODE_HPP

#include "Node.hpp"

namespace ast
{
    struct UnaryOperatorNode : public BaseNode
    {
        enum class Operator
        {
            // TODO: 
            // Post-increment?
            // Pre-increment?
            PLUS,
            NEGATIVE
        } op;

        BaseNodePtr expression;

        UnaryOperatorNode(Operator op, BaseNodePtr expression) : 
            op(op), 
            expression(std::move(expression))
        { 
        }

        virtual Value eval(Interpreter& interpreter) override;
        virtual Type type() const override { return Type::UNARY_OP; }
    };
}



#endif // ASSIGNMENTNODE_HPP
