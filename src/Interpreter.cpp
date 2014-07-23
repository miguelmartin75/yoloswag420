#include "interpreter.hpp"

Interpreter::Interpreter(std::ostream& logStream)
    : m_logStream(logStream)
{
}

Interpreter::Variable& addVariable(const IdentifierNode& name)
{
    return m_variables[name.id];
}

Interpreter::Variable& removeVariable(const IdentifierNode& name)
{
    m_variables.erase(name.id);
}

Interpreter::Variable& getVariable(const IdentifierNode& name)
{
    return m_variables[name.id];
}

int Interpreter::interpret(const StatementList& statements)
{
    for(auto& statement : statements)
    {
        statement.eval(*this);

        if(errorState != NO_ERROR)
        {
            return errorState;
        }
    }

	return 0;
}

void Interpreter::logError(const std::string& str)
{
    m_logStream << "[ERROR]: " << str;
}

std::ostream& Interpreter::logStream() const
{
    return m_logStream;
}
