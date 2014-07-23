#ifndef AST_HPP
#define AST_HPP

#include <memory>
#include <vector>

#include "Value.hpp"
#include "Node.hpp"
#include "ConstantNode.hpp"
#include "AddNode.hpp"
#include "MultNode.hpp"
#include "DivNode.hpp"

namespace ast
{
    // Defines a list of statements
    typedef std::vector<std::unique_ptr<Node>> StatementList;
}

#endif // AST_HPP
