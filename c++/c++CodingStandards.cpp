0> Dont waste time on small stuff
	- tabs vs spaces
	- hungarian notations
	- single entry/ single exit/return

1> Compile cleanly
	- Do not lower warning level
	- If third party header is giving warning, wrap it with another 
		header and disable warning in that particular custom wrapper
		header
	
	#pragma warning(push)
	//disable for this header only
	#pragma warning(disable:4512)
	#pragma warning(disable:4180)
	#include <boost/lambda/lambda.hpp> #pragma
	warning(pop)
	//restore original warning level


	- Do not name unused function parameters
	- Variables defined but not used. Use variable as expression.
		void Fun()
		{
			Lock lock;
			lock;
		}
	- Missing return, when default is reached.

		Fun( Color c ) {
		switch( c) {
		case Red: return 2;
		case Green: return 0;
		case Blue:
		case Black: return 1;
		default:
		assert( {"should never get here!" );
		return -1;
		}
		}
		
2> Use automated build system at the begging of project
3> Use CVS
4> Do code reviews


Design Style
5> Give module a specific responsiblity.
	More than one resposibilty causes complex sytem when project grows with more features

6> Correctness, Simplicity and clarity comes first.
	- Write code so human beings understand.
		Correct is better than faster.
		Simple is better than complex.
		clear is better than cute.

7> Know when and how to scale code.
	- Use dynamic arrays over static fixed size arrays
	- Know algorithms complexity first
	- Prefer linear or faster algorithms
	- Use exponential algorithms when there is no option

8> Dont optimize prematurely
	- It is far, far easier to make a correct program fast
	than it is to make a fast program correct.
	- Use fast algorithm over small optimizations
	- Try to find bottlenecks
	- Do not assume that some code is slow, prove it first
	- do not make functions inline blindly. Prove code is slow.
	- Compilers mostly optimize clear/simple code to execute faster on given platform.

9> Dont pessimize prematurely
	- Good code practices should naturelly come out of your fingers
			- Pass by reference
			- prefix ++ and --
			- Using initilizer list
	- Use libaries and std containers
	- Using range based functions once over calling function for each single element.

10> Minimize global and shared data
	Global data pollutes the global namespace.
	In case of multithreading it is overhead to manage secure access.

11> Hide information
	Dont give accesss to data members.
	It localizes changes for implemenation and there is flexibility in changing implementation

12> Know when and how to code for concurrency
	- Use atomics
	- Keep thread shared data minimum
	- lock free designs
	- external and internal locking of data structures

13> Ensure resources are owned by objects. Use explicit RAII and smart pointers
	- They prevent memory leaks
	- They are bit costly, so use judiciously.

14> Prefer compile- and link-time errors to
	run-time errors
	run time errors depend upon input data and execution flow. 
	program could crash or behavior could not be defined
	Static checks are stronger and dont incure runtime overhead

15> Use const proactively
16> Avoid macros
	They are not good, Expand and cause undefined behavior sometimes

17> Avoid magic numbers
	instead of doing int a = 84 // 42* 2 define  42 and 2 as constants 
	and assign 'a' value as their multiplication

18> Declare variables as locally as possible
	declare near where they are used. Prevent unecessory initializations.

19> Always initialize variables
	Unintilized cause undefined behavior

20> Avoid long functions. Avoid deep nesting
	Functions should be short and with clear responsibilty.
	Nested for, if, while loops cause confusion

21> Avoid initialization dependancies across compilation units
	
22> Avoid cyclic dependancies
	If work can be done with just declarion get it done it with

23> Make header selfsufficient
	Dont include other headers which are not needed.
	It costs to open other headers and parse them.

24> Always write  "#include __HEADER_H__" guards for header



