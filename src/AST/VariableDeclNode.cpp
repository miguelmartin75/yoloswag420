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
            auto value = assignment->eval(inter);
            inter.variables().emplace(actualId, value);
        }
        else
        {
            switch(varType)
            {
                case VariableType::STRING:
                    inter.variables().emplace(actualId, String{});
                    break;
                case VariableType::NUMBER:
                    inter.variables().emplace(actualId, Number{});
                    break;
                default:
                    break;
            }
        }

        return id.eval(inter);
    }
}
