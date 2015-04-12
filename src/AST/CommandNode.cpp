#include "CommandNode.hpp"

#include <iostream>


namespace ast
{
    namespace detail
    {
        struct Printer : boost::static_visitor<void>
        {
            template <class T>
            void operator()(const T& obj)
            {
                std::cout << obj;
            }
        };
    }
    CommandNode::CommandNode(CommandNode::Command command, ast::BaseNodePtr argument) :
        command(command), argument(std::move(argument))
    {
    }

    Value CommandNode::eval(Interpreter&)
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
                    boost::apply_visitor(detail::Printer{}, argument); 
                }
                break;
        }
    }
}
