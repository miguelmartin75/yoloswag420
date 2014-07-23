#ifndef VALUE_HPP
#define VALUE_HPP

#include <string>

#include <util/string_utils.hpp>

namespace ast
{
    /// \brief Defines a value type
    struct Value
    {
        typedef double NumberType;
        typedef std::string StringType;
        
        Value()
            : type(Type::NOTHING)
        {
        }

        Value(const StringType& str)
            : type(Type::STRING),
              number(util::from_string<NumberType>(str))
              string(str)
        {
        }

        Value(NumberType num)
            : type(Type::NUMBER),
              number(num),
              string(util::to_string(num))
        {
        }

        Value(const Value& value)
            : type(value.type),
              number(value.number),
              string(value.string)
        {
        }

        enum class Type
        {
            /// Represents that the Value doesn't contain
            /// anything interesting. e.g. for print statements.
            NOTHING,

            /// Represents that the Value contains a number
            NUMBER,

            /// Represents that the Value contains a string
            STRING
        };

        /// assigns the value
        void assign(NumberType number)
        {
            m_number = number;
            m_string = util::to_string(number);
        }

        void assign(const std::string& str)
        {
            m_number = util::from_string<NumberType>(number);
            m_string = str;
        }

        NumberType asNumber() const
        {
            return m_number;
        }

        const StringType& asString() const
        {
            return m_string;
        }

        Type getType() const
        {
            return m_type;
        }

    private:

        /// The actual type of value
        Type m_type;

        NumberType m_number;

        StringType m_string;
    };
}

#endif // VALUE_HPP
