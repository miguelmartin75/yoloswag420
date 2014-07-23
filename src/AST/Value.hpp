#ifndef VALUE_HPP
#define VALUE_HPP

#include <string>

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
