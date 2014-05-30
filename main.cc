/** @file main.cc
 * The main program that creates a Shell instance
 * and then calls it's main method.
 * It also catches any exceptions thrown.
 */
#include <stdexcept>	// std::exception
#include <iostream>		// std::cin, std::cerr
#include <cstdlib>		// EXIT_SUCCESS, EXIT_FAILURE

#include "ansi.h"		// ansi color code strings (AC_RED, AA_RESET)
#include "Shell.h"
using namespace std;


int	main()
{
	try {
		Shell  shell(cin);	// A shell instance reading commands from cin
		shell.main();		// Do it
		return EXIT_SUCCESS;
	}
	catch(const exception& e) {
		cerr << AC_RED "Exception: " AA_RESET << e.what() << endl;
		return EXIT_FAILURE;
	} catch(...) {
		cerr << AC_RED "OOPS: something went wrong" AA_RESET << endl;
		return EXIT_FAILURE;
	}
}
