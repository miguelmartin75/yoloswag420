#include "AssignmentNode.hpp"

#include "../Interpreter.hpp"

namespace ast
{
    Value AssignmentNode::eval(Interpreter& interpreter)
    {
        Value& var = interpreter.getVariable(assignee);
        var = rhs.eval();
        return var;
    }
}
