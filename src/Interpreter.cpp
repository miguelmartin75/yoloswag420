#include "interpreter.hpp"

Interpreter::Interpreter(std::ostream& logStream)
    : m_logger{logStream}
{
}

int Interpreter::interpret(const StatementList& statements)
{
    for(auto& statement : statements)
    {
        statement.eval(*this);
    }

	return 0;
}
