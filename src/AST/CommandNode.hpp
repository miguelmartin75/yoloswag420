#ifndef COMMANDNODE_HPP
#define COMMANDNODE_HPP

#include "Node.hpp"

namespace ast
{
    struct CommandNode : BaseNode
    {
        enum class Command
        {
            PRINT,
            INPUT
        } 
        command;

        // TODO: support multiple arguments?
        BaseNodePtr argument;
        
        CommandNode(Command command, BaseNodePtr argument);

        virtual Value eval(Interpreter&) override;
        virtual Type type() const { return Type::COMMAND; }
    };
}

#endif // COMMANDNODE_HPP
