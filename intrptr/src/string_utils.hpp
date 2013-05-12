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

template <typename T>
T& from_string(const std::string& str, T& obj)
{
	std::istringstream temp(str);
	temp >> obj;
}

template <typename T>
T from_string(const std::string& str)
{
	T temp;
	return from_string(str, temp);
}

#endif // __STRING_UTILS_HPP__