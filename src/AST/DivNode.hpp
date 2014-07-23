#ifndef DIVNODE_HPP
#define DIVNODE_HPP

#include "Node.hpp"

namespace ast
{
    struct DivNode : Node
    {
        Node *lhs, *rhs;

        virtual Value eval() override
        {
            Value result;
            // todo
            return result;
        }
    };
}

#endif // DIVNODE_HPP
