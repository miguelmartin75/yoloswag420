#ifndef COMMANDNODE_HPP
#define COMMANDNODE_HPP

#include "Node.hpp"

namespace ast
{
    struct CommandNode : Node
    {
        enum class Command
        {
            PRINT,
            INPUT
        } 
        command;

        // TODO: support multiple arguments?
        NodePtr argument;
        
        CommandNode(Command command, NodePtr argument) :
            command(command), argument(argument)
        {
        }

        virtual Value eval(Interpreter&) override;
        virtual Type type() const { return Node::Type::COMMAND; }
    };
}

#endif // COMMANDNODE_HPP
