#include "Statement.hpp"

#include "BinaryOperatorNode.hpp"

namespace ast
{
    namespace detail
    {
        bool append(ast::BaseNodePtr& root, ast::BaseNodePtr&& nodeToInsert);
    }


    Statement::Statement()
    {
    }

    bool Statement::add(BaseNodePtr node)
    {
        return detail::append(m_root, std::move(node));
    }

    Value Statement::eval(Interpreter& inter) const
    {
        return m_root == nullptr ? Void{} : m_root->eval(inter);
    }

    namespace detail
    {
        bool append(ast::BaseNodePtr& root, ast::BaseNodePtr&& nodeToInsert)
        {
            if(root == nullptr)
            {
                root = std::move(nodeToInsert);
                return true;
            }
            else if(root->type() == ast::BaseNode::Type::BINARY_OP)
            {
                auto& opNode = *static_cast<ast::BinaryOperatorNode*>(root.get());
                auto& left = opNode.left;
                auto& right = opNode.right;

                if(left == nullptr)
                {
                    left = std::move(nodeToInsert);
                    return true;
                }
                else if(right == nullptr)
                {
                    right = std::move(nodeToInsert);
                    return true;
                }
                else
                {
                    return append(left, std::move(nodeToInsert)) || append(right, std::move(nodeToInsert));
                }
            }

            return false;
        }
    }
}

