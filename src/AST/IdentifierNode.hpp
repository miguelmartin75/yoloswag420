#ifndef IDENTIFIERNODE_HPP
#define IDENTIFIERNODE_HPP

#include <string>

#include "Node.hpp"
#include "Types.hpp"

namespace ast
{
    /// \note Due to this design, this makes it possible for 
    ///       any type of variable to have any possible value.
    struct IdentifierNode : public BaseNode
    {
        IdentifierNode(const std::string& name) : id(name) { }

        String id;

        virtual Value eval(Interpreter& interpreter) override;
        virtual Type type() const override { return Type::IDENTIFIER; }
    };
}

#endif // IDENTIFIERNODE_HPP
