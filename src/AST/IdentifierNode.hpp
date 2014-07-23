#ifndef IDENTIFIERNODE_HPP
#define IDENTIFIERNODE_HPP

#include <string>

#include "Node.hpp"

namespace ast
{
    /// \note Due to this design, this makes it possible for 
    ///       any type of variable to have any possible value.
    struct IdentifierNode : Node
    {
        IdentifierNode(const std::string& name) : id(name) { }

        std::string id;

        virtual Value eval(Interpreter& interpreter) override;
    };
}

#endif // IDENTIFIERNODE_HPP
