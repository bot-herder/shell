/** @file unix_error.cc
 * The implementation of the unix_error exception class.
 */
// linux hooks
#include <cstring>		// extern char *strerror(int errnum);
#include <cerrno>		// extern int errno;

// our own stuff
#include "ansi.h"		// ansi colorcode strings
#include "unix_error.h"	// class unix_error


static // (i.e. only visible in this source file)
// A function to combine the given argument
// with the unix error message that belongs with the given errornumber
// into a nice c++ string.
std::string	makeErrorString(const std::string& what_arg, int errornumber)
{
	std::string  s;
	s += AC_RED;
	if (!what_arg.empty()) {
		s += what_arg;
		s += ": ";
	}
	s += strerror(errornumber);
	s += AA_RESET;
	return  s;
}


// Construct a unix system error
unix_error::unix_error(const std::string& what_arg)
	: std::runtime_error( makeErrorString(what_arg, errno) )
{
}


// Construct a unix system error
unix_error::unix_error(const char *what_arg)
	: std::runtime_error( makeErrorString( std::string(what_arg), errno) )
{
}

// vim:sw=4:ai:aw:ts=4:
