#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <unordered_map>

#include "ErrorCodes.hpp"
#include "Types.hpp"
#include "Logger.hpp"
#include "StatementList.hpp"

#include "AST/AST.hpp"

class Interpreter
{
public:

    using Variable = ast::Value;
    using VariableMap = std::unordered_map<String, ast::Value>;

    Interpreter(std::ostream& logStream = std::cerr);

    /// Interprets a list of statements
    /// \return 0 if success. 
    int interpret(const StatementList& statements);

    Logger& logger() { return m_logger; }
    VariableMap& variables() { return m_variables; }
    const VariableMap& variables() const { return m_variables; }

private:

    Logger m_logger;
    VariableMap m_variables;
};

#endif // INTERPRETER_HPP
