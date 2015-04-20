#include "BinaryOperatorNode.hpp"

#include "../Interpreter.hpp"

#include <boost/optional.hpp>
#include <boost/lexical_cast/try_lexical_convert.hpp>

namespace ast
{
    namespace detail
    {
        struct BinaryOpVisitor : public boost::static_visitor<boost::optional<Value>>
        {
            BinaryOperatorNode::Operator op;
            BinaryOpVisitor(BinaryOperatorNode::Operator op) : op(op) { }

            boost::optional<Value> operator()(Number n1, Number n2) const
            {
                switch(op)
                {
                    case BinaryOperatorNode::Operator::PLUS:
                        return Value{n1 + n2};
                    case BinaryOperatorNode::Operator::MINUS:
                        return Value{n1 - n2};
                    case BinaryOperatorNode::Operator::DIV:
                        return Value{n1 / n2};
                    case BinaryOperatorNode::Operator::MULT:
                        return Value{n1 * n2};
                    default:
                        break;
                }
                return boost::none;
            }

            boost::optional<Value> operator()(Number num, const String& str) const
            {
                switch(op)
                {
                    case BinaryOperatorNode::Operator::PLUS:
                        {
                            String temp;
                            if(!boost::conversion::try_lexical_convert(num, temp))
                                return boost::none;
                            return Value{temp + str};
                        }
                        break;
                    default:
                        break;
                }
                return boost::none;
            }

            boost::optional<Value> operator()(const String& str, Number num) const
            {
                switch(op)
                {
                    case BinaryOperatorNode::Operator::PLUS:
                        {
                            String temp;
                            if(!boost::conversion::try_lexical_convert(num, temp))
                                return boost::none;
                            return Value{str + temp};
                        }
                        break;
                    default:
                        break;
                }
                return boost::none;
            }

            boost::optional<Value> operator()(const String& str1, const String& str2) const
            {
                switch(op)
                {
                    case BinaryOperatorNode::Operator::PLUS:
                        return Value{str1 + str2};
                        break;
                    default:
                        break;
                }

                return boost::none;
            }

            template <class T1, class T2>
            boost::optional<Value> operator()(const T1&, const T2&) const
            {
                return boost::none;
            }
        };
    }

    BinaryOperatorNode::BinaryOperatorNode(Operator op, BaseNodePtr left, BaseNodePtr right) :
        op{op}, left{std::move(left)}, right{std::move(right)}
    {
    }

    Value BinaryOperatorNode::eval(Interpreter& interpreter)
    {
        if(op == Operator::ASSIGNMENT)
        {
            if(left->type() == Type::IDENTIFIER)
            {
                auto& id = static_cast<IdentifierNode*>(left.get())->id;
                //interpreter.variables()[id] = 
            }
            else
            {
                // TODO: workout how to go
                // a = b = c
                std::cerr << "cannot assign to a non-identifier\n";
                return Void{};
            }
        }

        auto l = left->eval(interpreter);
        auto r = right->eval(interpreter);

        auto result = boost::apply_visitor(detail::BinaryOpVisitor{op}, l, r);
        return result ? *result : Void{};
    }
}
