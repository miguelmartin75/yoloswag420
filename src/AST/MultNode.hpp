#ifndef MULTNODE_HPP
#define MULTNODE_HPP

#include "Node.hpp"

namespace ast
{
    struct MultNode : Node
    {
        Node *lhs, *rhs;
        virtual Value eval() override
        {
            return Value();
        }
    };
}

#endif // MULTNODE_HPP
