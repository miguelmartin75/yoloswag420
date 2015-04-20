#ifndef ASSIGNMENTVISITOR_HPP
#define ASSIGNMENTVISITOR_HPP

#include "../Types.hpp"

#include <boost/variant/static_visitor.hpp>

#include <boost/optional.hpp>
#include <boost/lexical_cast/try_lexical_convert.hpp>

namespace ast
{
    namespace detail
    {
        struct AssignmentEvaluator : public boost::static_visitor<bool>
        {
            bool operator()(String& str1, const String& str2) const
            {
                str1 = str2;
                return true;
            }

            bool operator()(Number& n1, const Number& n2) const
            {
                n1 = n2;
                return true;
            }

            bool operator()(Number& number, const String& str) const
            {
                if(!boost::conversion::try_lexical_convert(str, number))
                {
                    return false;
                }
                return true;
            }

            bool operator()(String& str, const Number& number) const
            {
                if(!boost::conversion::try_lexical_convert(number, str))
                {
                    return false;
                }
                return true;
            }

            // void types
            bool operator()(Void&, const Number&) const { return false; }
            bool operator()(Void&, const String&) const { return false; }
            bool operator()(String&, const Void&) const { return false; }
            bool operator()(Number&, const Void&) const { return false; }

            bool operator()(Void&, const Void&) const { return false; }
        };
    }
}


#endif // ASSIGNMENTVISITOR_HPP
