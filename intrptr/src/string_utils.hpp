#ifndef __STRING_UTILS_HPP__
#define __STRING_UTILS_HPP__

#include <sstream>

template <typename T>
std::string to_string(const T& var)
{
	std::ostringstream temp;
	temp << var;
	return temp.str();
}

#endif // __STRING_UTILS_HPP__