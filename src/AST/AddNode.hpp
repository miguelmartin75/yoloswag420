#ifndef ADDNODE_HPP
#define ADDNODE_HPP

#include "Node.hpp"

namespace ast
{
    struct AddNode : Node
    {
        Node* lhs, Node* rhs;

        virtual Value eval() override
        {
        }
    };
}

#endif // ADDNODE_HPP
