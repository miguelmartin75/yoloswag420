#ifndef ASSIGNMENTNODE_HPP
#define ASSIGNMENTNODE_HPP

#include "Node.hpp"
#include "VariableNode.hpp"

namespace ast
{
    struct AssignmentNode : Node
    {
        AssignmentNode(IdentifierNode& id, Node& node)
            : assignee(id), rhs(node) { }

        /// The assignee
        IdentifierNode& assignee;

        /// The expression to assign to
        Node& rhs;
        
        virtual Value eval(Interpreter& interpreter) override
    }
}

#endif // ASSIGNMENTNODE_HPP
