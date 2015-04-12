#ifndef CONSTANTVALUENODE_HPP
#define CONSTANTVALUENODE_HPP

#include "Node.hpp"
#include "Value.hpp"

namespace ast
{
    struct ConstantValueNode : public BaseNode
    {
        ConstantValueNode(Value value) : value(value) { }

        Value value;

        virtual Value eval(Interpreter&) override { return value; }
        virtual Type type() const { return Type::CONSTANT; }
    };
}

#endif // CONSTANTVALUENODE_HPP
