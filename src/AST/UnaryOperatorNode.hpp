#ifndef UNARYOPERATORNODE_HPP
#define UNARYOPERATORNODE_HPP

#include "Node.hpp"

namespace ast
{
    struct UnaryNode : Node
    {
        enum class Operator
        {
            // TODO: 
            // Post-increment?
            // Pre-increment?
            PLUS,
            NEGATIVE
        } op;

        NodePtr node;

        UnaryNode(Operator op, NodePtr node) : 
            op(op), 
            node(std::move(node))
        { 
        }

        virtual Value eval(Interpreter& interpreter) override;
        virtual Type type() const override { return Node::Type::UNARY_OP; }
    }
}



#endif // ASSIGNMENTNODE_HPP
