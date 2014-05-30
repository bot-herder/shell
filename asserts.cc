static const char sccsid[] = "@(#)asserts.cc	2.2	AKK	2012/07/23";
/** @file asserts.cc
 * The implementation of the 'asserts' function
 * that checks various kinds of assertions.
 *
 * @author R.A.Akkersdijk@saxion.nl
 * @version 2.2	2012/07/23
 */

#include "asserts.h"
#include "ansi.h"   // for: ansi color strings
#include <cstdio>	// for: snprintf


void	asserts(const char *file, const int line, const char *func,
                const int outcome, const char *type, const char *expr)
{
	if (outcome) {	// true as it should be ? oke
		return;
	}
	// The assertion was not met, inform the user something is wrong.
	char  message[1024];
	if (func) {
		snprintf(message, 1024,
		         AC_RED"%s[%d]\nin %s\n\t%s("AA_RESET "%s" AC_RED") failed:"AA_RESET"\n",
		         file, line, func, type, expr);
	} else {
		snprintf(message, 1024,
		         AC_RED"%s[%d]\nin %s ("AA_RESET "%s" AC_RED") failed:"AA_RESET"\n",
		         file, line, type, expr);
	}
	throw assert_error(message);
}

// vim:sw=4:ai:aw:ts=4:
