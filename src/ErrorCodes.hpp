#ifndef ERRORCODES_HPP
#define ERRORCODES_HPP

struct ErrorCodes
{
    enum Code
    {
        SUCCESS,
        USAGE_ERROR,
        FAILED_TO_OPEN_FILE,
        SYNTAX_ERROR,
        RUN_TIME_ERROR
    };
};

#endif // ERRORCODES_HPP
