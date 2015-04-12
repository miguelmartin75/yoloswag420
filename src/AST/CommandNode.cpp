#include "CommandNode.hpp"

#include <iostream>


namespace ast
{
    namespace detail
    {
        struct Printer : public boost::static_visitor<void>
        {
            template <class T>
            void operator()(const T& obj) const
            {
                std::cout << obj;
            }
            
            void operator()(const Void& obj) const
            {
                std::cout << "null";
            }
        };
    }
    CommandNode::CommandNode(CommandNode::Command command, ast::BaseNodePtr argument) :
        command(command), argument(std::move(argument))
    {
    }

    Value CommandNode::eval(Interpreter& interpreter)
    {
        switch(command)
        {
            case Command::INPUT:
                {
                    String buffer;
                    std::getline(std::cin, buffer);
                    return buffer;
                }
                break;
            case Command::PRINT:
                {
                    auto valueOfArg = argument->eval(interpreter);
                    boost::apply_visitor(detail::Printer(), valueOfArg);
                }
                break;
        }
    }
}
