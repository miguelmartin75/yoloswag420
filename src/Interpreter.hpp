#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <iostream>
#include <unordered_map>
#include <string>

#include "ErrorCodes.hpp"
#include "AST/AST.hpp"

class Interpreter
{
public:

    typedef Value Variable;

    Interpreter(std::ostream& logStream = std::cerr);

    Variable& addVariable(const IdentifierNode& name);
    Variable& removeVariable(const IdentifierNode& name);
    Variable& getVariable(const IdentifierNode& name);

    /// Interprets a list of statements
    int interpret(const StatementList& statements);

    void logError(const std::string& str);
    std::ostream& logStream() const;

private:

    std::ostream& m_logStream;

    std::unordered_map<std::string, Value> m_variables;
};

#endif // INTERPRETER_HPP
