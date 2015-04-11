#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <utility>

#include "../Interpreter.hpp"
#include "Value.hpp"

namespace ast
{
    /// \brief The base node class for the AST
    struct Node
    {
        enum class Type
        {
            IDENTIFIER,
            UNARY_OP,
            BINARY_OP,
            COMMAND
        };

        virtual ~Node() { }

        /// Evaluates the node
        virtual Value eval(Interpreter&) = 0;
        virtual Type type() const = 0;
    };

    using NodePtr = std::unique_ptr<ast::Node>

    // used to create nodes, e.g.
    // auto rootNode = node<VariableNode>("x", 32);
    template <class T, class... Args>
    NodePtr node(Args&&... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
}



#endif // NODE_HPP
