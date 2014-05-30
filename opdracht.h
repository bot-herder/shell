/** @file opdracht.h
 * This file contains the doxygen code for this assignment
 */
/** \mainpage

<p>The assignment:
	Finish a unix style command line interpreter, aka \"<a
	target='info' href='http://en.wikipedia.org/wiki/Shell_(computing)'>shell</a>".
	Consult your "blokboek" for the precise requirements.</p>

<p>A large part of the code is already given:
<dl>
<dt>class Shell
<dd>The main command interpreter.
	It first builds a data structure from the input
	then that sequence of commands will be executed.
<dt>class Sequence
<dd>A sequence of pipelines to be executed one after the other.
<dt>class Pipeline
<dd>A group of commands to be executed in parallel.
<dt>class Command
<dd>A command to be executed.
<dt>class Token
<dd>Contains the scanner that returns the next token from the input.
</dl>

<p>What you have to do is add the code (unix <a target='info'
href='http://en.wikipedia.org/wiki/System_call'>systemcalls</a>) that:
	creates the sub-processes,
	connects them with pipes,
	handles io-redirection
	and executes the desired program.
	Also, you'll have to wait for child-processes
	and examine their exit-status.</p>

@note
The given code only covers the "BASIC" version of the shell.
If you want more sofisticated levels you may have to extend the parser code.

<p>There are various unix systemcalls you'll have to use in this assignment,
	for instance:
\htmlonly
<dl>
<dt><a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+fork+2'>fork(2)</a>
	<dd>To create a new process.
<dt><a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+pipe+2'>pipe(2)</a>
	<dd>To create a communication pipe between processes.
<dt><a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+open+2'>open(2)</a>
	<dd>To connect a process to an input and/or output file.
<dt><a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+dup2+2'>dup2(2)</a>
or <a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+dup+2'>dup(2)</a>
	<dd>To change the association between open-file descriptors.
<dt><a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+close+2'>close(2)</a>
	<dd>To close unneeded file descriptors
<dt><a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+nice+2'>nice(2)</a>
	<dd>To alter the process priority.
<dt><a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+execv+3'>execv(3)</a>
	<dd>A function to let the current proces execute a program
		when you know it's exact location on the system.
<dt><a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+getenv+3'>getenv(3)</a>
	<dd>To retrieve an
		"<a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+environ+7'>environment(7)</a>"
		variable e.g. the PATH variable which tells in which directories programs are to be found.
		(also see: <a target='info' href='http://en.wikipedia.org/wiki/Environment_variable'>environment</a>).
<dt><a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+access+2'>access(2)</a>
	<dd>To check whether you have access permission to a file/program
		or simply whether it exists in the first place.
		Also see:
		"<a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+path_resolution+7'>path resolution(7)</a>"

<dt><a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+wait+2'>wait(2)</a>
	or <a target='info' href='http://casper.cii.saxion.nl/cgi-bin/man2html?+waitpid+2'>waitpid(2)</a>
	<dd>To wait for the termination of a child process
		and retrieve it's exit status.
</dl>
\endhtmlonly
\note
The notation xxx(N) means: the unix manual about xxx in manual section N.
N=2: system calls, N=3: common library functions, N=7: conventions.
\note
The unix manuals tell which \#include files you need for programs writen in C.
When programming in C++ there are often C++ alternatives available,
e.g. "cstdlib" rather then "stdlib.h".
In this assignment you may use either variant.
<p>&nbsp;</p>

\example shell.txt
\example signal.cc


 */
