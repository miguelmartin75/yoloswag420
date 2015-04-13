#include "IdentifierNode.hpp"

#include "../Interpreter.hpp"

namespace ast
{
    Value IdentifierNode::eval(Interpreter& interpreter)
    {
        return interpreter.variables().count(id) == 0 ? (std::cerr << "no such variable: " << id << '\n', Void{}): interpreter.variables().at(id);
    }
}
