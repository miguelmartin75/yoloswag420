#ifndef __ERRORCODES_HPP__
#define __ERRORCODES_HPP__

struct ErrorCodes
{
	enum
	{
		SUCCESS,
		USAGE_ERROR,
		FAILED_TO_OPEN_FILE,
		SYNTAX_ERROR,
		RUN_TIME_ERROR
	};
};

#endif