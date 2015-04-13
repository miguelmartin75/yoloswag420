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
    
    template <class... Args>
    void log(LogLevel level, Args&&... args)
    {
        static constexpr const char* LOG_LEVELS[] = { "LOG", "WARN", "ERROR" };
        m_os << "[" << LOG_LEVELS[static_cast<int>(level)] << "]: ";
        log_impl(std::forward<Args>(args)...);
    }

    template <class T, class... Args>
    void log(const T& obj, Args&&... args) 
    {
        std::cout << "[LOG]: ";
        log_impl(obj);
        log_impl(args...);
    }

private:

    template <class T, class... Args>
    void log_impl(const T& obj, Args&&... args)
    {
        log_impl(obj);
        log(std::forward<Args>(args)...);
    }

    template <class T>
    void log_impl(const T& obj)
    {
        m_os << obj << '\n';
    }

private:

    std::ostream& m_os;
};

#endif // LOGGER_HPP
