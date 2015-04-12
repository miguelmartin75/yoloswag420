#ifndef VALUE_HPP
#define VALUE_HPP

#include <boost/variant.hpp>

#include "Types.hpp"

namespace ast
{
    using Value = boost::variant<Void, Number, String>;
}

#endif // VALUE_HPP
