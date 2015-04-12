#include "VariableDeclNode.hpp"

#include "../Interpreter.hpp"

namespace ast
{
    Value VariableDeclNode::eval(Interpreter& inter)
    {
        auto actualId = id.id;
        if(inter.variables().count(actualId) > 0)
        {
            std::cerr << "variable already declared!\n";
            return Void{};
        }

        if(assignment)
        {
            inter.variables().emplace(actualId, assignment->eval(inter));
        }
        else
        {
            inter.variables().emplace(actualId, varType == VariableType::STRING ? "" : 0);
        }

        return id.eval(inter);
    }
}
