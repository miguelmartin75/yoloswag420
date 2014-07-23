#ifndef NODE_HPP
#define NODE_HPP

#include "Value.hpp"

class Interpreter;

namespace ast
{
    /// \brief The base node class for the AST
    struct Node
    {
        virtual ~Node() { }

        /// Evaluates the node
        virtual Value eval(Interpreter&) = 0;
    };
}

#endif // NODE_HPP
