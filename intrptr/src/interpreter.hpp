#ifndef __INTERPRETER_HPP__
#define __INTERPRETER_HPP__

#include <unordered_map>
#include <string>

#include "statement.hpp"

class Interpreter
{
public:
	
    typedef std::string String;
    typedef double Number;
	
	Interpreter();
	
	int interpret(const StatementList&);
	
	
    const Number& createNumber(const String& name, Number value)
	{ return _numberVariables[name] = value; }
    const String& createString(const String& name, const String& value)
	{ return _stringVariables[name] = value; }
	
	Number& getNumber(const String& name)
	{ return _numberVariables[name]; }
	String& getString(const String& name)
	{ return _stringVariables[name]; }
	const Number& getNumber(const String& name) const
	{ return _numberVariables[name]; }
	const String& getString(const String& name) const
	{ return _stringVariables[name]; }
	
private:
	
	int interpret(Statement& statement);
	
    std::unordered_map<std::string, double> _numberVariables;
    std::unordered_map<std::string, std::string> _stringVariables;
};

#endif // __INTERPRETER_HPP__