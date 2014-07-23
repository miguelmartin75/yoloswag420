#ifndef ASSIGNMENTNODE_HPP
#define ASSIGNMENTNODE_HPP

#include "Node.hpp"

namespace ast
{
    struct AssignmentNode : Node
    {
        Node& lhs;
        Node& rhs;

        virtual Value eval() override
        {
            // todo
        }
    }
}

#endif // ASSIGNMENTNODE_HPP
