#include "VariableDeclNode.hpp"

#include "../Interpreter.hpp"

#include "detail/AssignmentVisitor.hpp"

namespace ast
{
    Value VariableDeclNode::eval(Interpreter& inter)
    {
        if(inter.variables().find(id) != inter.variables().end())
        {
            std::cerr << "variable already declared!\n";
            return Void{};
        }

        Value* value;
        switch(varType)
        {
            case VariableType::STRING:
                value = &(inter.variables()[id] = String{});
                break;
            case VariableType::NUMBER:
                value = &(inter.variables()[id] = Number{});
                break;
            default:
                break;
        }

        if(assignment)
        {
            auto valueToAttemptToAssign = assignment->eval(inter);

            if(!boost::apply_visitor(detail::AssignmentEvaluator{}, *value, valueToAttemptToAssign))
            {
                std::cerr << "could not assign initializer to " << id << (varType == VariableType::STRING ? "string" : "number") << '\n';
                return Void{};
            }
        }

        return *value;
    }
}
