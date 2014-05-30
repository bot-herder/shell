#pragma once
#ifndef	__asserts_h__
#define	__asserts_h__ 1
//#ident	"@(#)asserts.h	2.4	AKK	2012/07/16"

/** @file asserts.h
 * This file defines various macro's that can be used as checks in your program.
 * <br>If NDEBUG has been defined the assertions will be totally disabled for that
 * translation unit.
 * @note It relies on the __FILE__, __LINE__ and __PRETTY_FUNCTION__
 * compiler magics to actually identify lines of source code.
 * <br>If your compiler does not provide the __PRETTY_FUNCTION__ magic,
 * simply \#define it as 0 and the 'asserts' function will ignore that parameter.
 *
 * @author R.A.Akkersdijk@saxion.nl
 * @version 2.4	2012/07/16
 */


// Haal eerst deze macro's weg
#undef	require
#undef	check
#undef	ensure
#undef	notreached


#ifdef	NDEBUG	/* disable asserts? */

// Make sure that another #include "asserts.h" can be used
// to enable assertions again later.
# undef __asserts_h__

// Define some dummy macro's that have no side-effects
# define require(expr)	((void)(0))
# define check(expr)	((void)(0))
# define ensure(expr)	((void)(0))
# define notreached()	((void)(0))


#else /* asserts enabled */


# include <stdexcept>	// std::exception, std::logic_error

/** @class assert_error
 * If an assertion fails an instance of assert_error is thrown.
 */
class assert_error : public std::logic_error
{
public:
	explicit assert_error(const std::string &what_arg)
		: logic_error(what_arg) {}
	explicit assert_error(const char *what_arg)
		: logic_error(what_arg) {}
};

/** @internal
 * This "secret" function verifies that some boolean 'outcome' is true,
 * otherwise it will throw an assert_error,
 * reporting the violation, mentioning the source file, linenumber and function,
 * the violation type and the actual expression.
 */
extern void	asserts(const char *file, const int line, const char *func,
                    const int outcome,
                    const char *type, const char *expr);

/**
 * Verify whether a precondition is met, for instance: require(x>0);
 */
# define	require(condition) \
	asserts(__FILE__,__LINE__,__PRETTY_FUNCTION__,condition,"require",#condition)

/**
 * Verify an internal consistenty check, for instance: check(x>0);
 */
# define	check(condition) \
	asserts(__FILE__,__LINE__,__PRETTY_FUNCTION__,condition,"check",#condition)

/**
 * Verify whether a postcondition is met, for instance: ensure(x>0);
 */
# define	ensure(condition) \
	asserts(__FILE__,__LINE__,__PRETTY_FUNCTION__,condition,"ensure",#condition)

/**
 * Verify that this line of code is not reached, for instance
 * when the 'default' case of a 'switch' should never be reached
 * you can say
 * 		default: notreached();
 */
# define	notreached() \
	asserts(__FILE__,__LINE__,__PRETTY_FUNCTION__,0,"notreached","")

#endif	/* not NDEBUG */

#endif	/*asserts_h*/
// vim:sw=4:ai:aw:ts=4:
