#ifndef VARIABLENODE_HPP
#define VARIABLENODE_HPP

#include "Node.hpp"
#include "Value.hpp"

namespace ast
{
    struct VariableNode : Node
    {
        Value var;

        virtual Value eval() override
        {
            return var;
        }
    };
}

#endif // VARIABLENODE_HPP
