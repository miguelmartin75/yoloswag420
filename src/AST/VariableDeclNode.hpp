#ifndef VARIABLEDECLNODE_HPP
#define VARIABLEDECLNODE_HPP

#include "Node.hpp"
#include "IdentifierNode.hpp"

namespace ast
{
    enum class VariableType
    {
        NUMBER,
        STRING
    };

    struct VariableDeclNode : public BaseNode
    {
        VariableType varType; 
        IdentifierNode id;
        BaseNodePtr assignment;

        VariableDeclNode(VariableType varType, String id) : varType(varType), id(id) { }

        VariableDeclNode(VariableType varType, String id, BaseNodePtr assignment) : varType(varType), id(id), assignment(std::move(assignment)) { }

        virtual Value eval(Interpreter& inter) override;
    };
}

#endif // VARIABLEDECLNODE_HPP
