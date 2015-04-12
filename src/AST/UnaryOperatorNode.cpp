#include "UnaryOperatorNode.hpp"

#include "../Interpreter.hpp"

namespace ast
{
    Value UnaryOperatorNode::eval(Interpreter& interpreter)
    {
        /*
        Value& var = interpreter.getVariable(assignee);
        var = rhs.eval();
        */
        // TODO
        return expression->eval(interpreter);
    }
}
