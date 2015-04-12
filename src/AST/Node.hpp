#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <utility>
#include <type_traits>

#include "Value.hpp"

class Interpreter;
namespace ast
{
    /// \brief The base node class for the AST
    struct BaseNode
    {
        enum class Type
        {
            UNDEF,
            CONSTANT,
            IDENTIFIER,
            UNARY_OP,
            BINARY_OP,
            COMMAND
        };

        virtual ~BaseNode() { }

        /// Evaluates the node
        virtual Value eval(Interpreter&) = 0;
        virtual Type type() const { return Type::UNDEF; }
    };

    namespace detail
    {
        template <class T>
        struct NodeType
        {
            static_assert(std::is_base_of<BaseNode, T>::value, "T is not a node, as it does not derive from BaseNode");
            using type = T;
        };
    }

    using BaseNodePtr = std::unique_ptr<BaseNode>;

    template <class T>
    using NodePtr = std::unique_ptr<typename detail::NodeType<T>::type>;

    // used to create nodes, e.g.
    // auto rootNode = node<VariableNode>("x", 32);
    template <class T, class... Args>
    NodePtr<T> node(Args&&... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    static inline BaseNodePtr node(BaseNode* node)
    {
        return BaseNodePtr{node};
    }
}



#endif // NODE_HPP
