#ifndef VARIABLEDECLNODE_HPP
#define VARIABLEDECLNODE_HPP

#include "Node.hpp"
#include "IdentifierNode.hpp"
#include "VariableType.hpp"

namespace ast
{
    struct VariableDeclNode : public BaseNode
    {
        VariableType varType; 
        IdentifierNode::Id id;
        BaseNodePtr assignment;

        VariableDeclNode(VariableType varType, IdentifierNode::Id id) : varType(varType), id(std::move(id)) { }

        VariableDeclNode(VariableType varType, IdentifierNode::Id id, BaseNodePtr assignment) : varType(varType), id(std::move(id)), assignment(std::move(assignment)) { }

        virtual Value eval(Interpreter& inter) override;
    };
}

#endif // VARIABLEDECLNODE_HPP
