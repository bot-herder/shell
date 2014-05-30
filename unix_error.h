#pragma once
#ifndef UNIX_ERROR_H
#define UNIX_ERROR_H 1
/** @file unix_error.h
 * The declaration of the unix_error exception class.
 */

// c++ hooks
#include <stdexcept>	// std::runtime_error
#include <string>		// std::string

/** @class unix_error
 * A class to throw unix system errors with some additional text (derives from runtime_error).
 *
 * When somewhere in your program a systemcall fails,
 * e.g. you can not open a file,
 * the reason is explained as a code in the global 'errno' variable.
 *
 * This exception class takes that code,
 * converting it into some human readable string,
 * addding the given argument as a prefix.
 * <br>Also see: errno, std::strerror() and std::perror()
 *
 * An example:
@code
try {
	// With C++ STL classes
	ifstream  inputfile("some_filename");	// an ifstream
	if (!inputfile)							// failed to open?
		throw unix_error("inputfile");		// report the problem
	// With unix systemcalls
	if (chdir("/tmp") < 0)
		throw unix_error("chdir /tmp");
}
catch(const unix_error& e) {
	cerr << "Oops: " << e.what() << endl;
}
@endcode
 *
 */
class unix_error : public std::runtime_error
{
public:
	explicit	// see: http://en.cppreference.com/w/cpp/language/explicit
	/// Construct a unix system error with some additional text
	/// @param what_arg	additional text
	unix_error(const std::string& what_arg);

	explicit	// see: http://en.cppreference.com/w/cpp/language/explicit
	/// Construct a unix system error with some additional text
	/// @param what_arg	additional text
	unix_error(const char *what_arg);
};


#endif // UNIX_ERROR_H
// vim:sw=4:ts=4:ai:aw:
