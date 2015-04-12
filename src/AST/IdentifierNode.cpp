#include "IdentifierNode.hpp"

#include "../Interpreter.hpp"

namespace ast
{
    Value IdentifierNode::eval(Interpreter& interpreter)
    {
        // just return the value at this id
        return Void{};
    }
}
