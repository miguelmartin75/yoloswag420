#include "BinaryOperatorNode.hpp"

#include "../Interpreter.hpp"

namespace ast
{
    BinaryOperatorNode::BinaryOperatorNode(Operator op, BaseNodePtr left, BaseNodePtr right) :
        op{op}, left{std::move(left)}, right{std::move(right)}
    {
    }

    Value BinaryOperatorNode::eval(Interpreter& interpreter)
    {
        auto l = left->eval(interpreter);
        auto r = right->eval(interpreter);
        /*
        switch(op)
        {
            case PLUS:
                // you can add a string and a number fine...
                return l + r;
            case MINUS:
                // subtracting a string with
                // anything doesn't make sense..
                if(l.getType() == Interpreter::Variable::Type::String ||
                   r.getType() == Interpreter::Variable::Type::String)
                {
                    interpreter.logError("Using the '-' operand with a string is not defined");
                    return l;
                }
                return l - r;
            case MULT:
                // multiplying a string does make sense, 
                // but I ceebs implementing it
                if(l.getType() == Interpreter::Variable::Type::String ||
                   r.getType() == Interpreter::Variable::Type::String)
                {
                    interpreter.logError("Using the '*' operand with a string is not defined");
                    return l;
                }
                return l * r;
            case DIV:
                if(l.getType() == Interpreter::Variable::Type::String ||
                   r.getType() == Interpreter::Variable::Type::String)
                {
                    interpreter.logError("Using the '/' operand with a string is not defined");
                    return l;
                }
                return l / r;

            // ignore things I ceebs implementing atm
            default:
                break;
        }
        */
        return Void{};
    }
}
