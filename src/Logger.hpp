#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <utility>

enum class LogLevel
{
    NORMAL,
    WARN,
    ERROR
};

class Logger
{
public:
    
    Logger(std::ostream& os) : m_os{os} { }
    
    template <class T, class... Args>
    void log(LogLevel level, const T& obj, Args&&... args)
    {
        static constexpr const char* LOG_LEVELS[] = { "LOG", "WARN", "ERROR" };
        m_os << "[" << LOG_LEVELS[static_cast<int>(level)] << "]: ";
        log(obj);
        log(std::forward<Args>(args)...);
    }

    template <class T, class... Args>
    void log(const T& obj, Args&&... args)
    {
        log(obj);
        log(std::forward<Args>(args)...);
    }

    template <class T>
    void log(const T& obj)
    {
        m_os << obj;
    }

private:

    std::ostream& m_os;
};

#endif // LOGGER_HPP
