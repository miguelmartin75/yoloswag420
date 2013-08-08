///
/// intrptr
/// Copyright (C) 2013 Miguel Martin. All rights reserved.
///
///
/// This software is provided 'as-is', without any express or implied warranty.
/// In no event will the authors be held liable for any damages arising from the
/// use of this software.
///
/// Permission is hereby granted, free of charge, to any person
/// obtaining a copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// 1. The origin of this software must not be misrepresented;
///    you must not claim that you wrote the original software.
///    If you use this software in a product, an acknowledgment
///    in the product documentation would be appreciated but is not required.
///
/// 2. Altered source versions must be plainly marked as such,
///	   and must not be misrepresented as being the original software.
///
/// 3. The above copyright notice and this permission notice shall be included in
///    all copies or substantial portions of the Software.
///

#ifndef __INTERPRETER_HPP__
#define __INTERPRETER_HPP__

#include <unordered_map>
#include <string>

#include "Statement.hpp"

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