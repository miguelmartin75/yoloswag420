#ifndef NODE_HPP
#define NODE_HPP

#include "Value.hpp"

namespace ast
{
    /// \brief The base node class for the AST
    struct Node
    {
        /// Evaluates the node
        virtual Value eval() = 0;
    };
}

#endif // NODE_HPP
