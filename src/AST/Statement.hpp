#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include "Value.hpp"
#include "Node.hpp"

class Interpreter;
namespace ast
{
    // A statement 
    class Statement
    {
    public:

        Statement();
        Statement(BaseNodePtr root) : m_root(std::move(root)) { }

        bool add(BaseNodePtr node);
        Value eval(Interpreter& ) const;

    private:

        BaseNodePtr m_root;
    };
}

#endif // STATEMENT_HPP
