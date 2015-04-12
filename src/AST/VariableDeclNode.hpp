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

        VariableDeclNode(VariableType varType, IdentifierNode id) : varType(varType), id(id) { };

        virtual Value eval(Interpreter& inter) override { return id.eval(inter); }
    };
}

#endif // VARIABLEDECLNODE_HPP
