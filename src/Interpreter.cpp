#include "Interpreter.hpp"

Interpreter::Interpreter(std::ostream& logStream)
    : m_logger{logStream}
{
}

int Interpreter::interpret(const ast::StatementList& statements)
{
    for(auto& statement : statements)
    {
        // TODO: make eval return an error code along
        // with a Value?
        statement.eval(*this);
    }

	return 0;
}
