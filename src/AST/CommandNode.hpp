#ifndef COMMANDNODE_HPP
#define COMMANDNODE_HPP

#include "Node.hpp"

namespace ast
{
    enum class Command
    {
        PRINT,
        INPUT
    };

    struct CommandNode : BaseNode
    {
        Command command;

        // TODO: support multiple arguments?
        BaseNodePtr argument;
        
        CommandNode(Command command, BaseNodePtr argument);

        virtual Value eval(Interpreter&) override;
        virtual Type type() const { return Type::COMMAND; }
    };
}

#endif // COMMANDNODE_HPP
