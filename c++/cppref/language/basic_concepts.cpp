Comments
ASCII chart
	0-31 are special characters
	32-63 punctuations
	64-95 capital
	96-128 small case

Punctuation
	operators +, < 
	characters (), {}, []

Names and identifiers
	variable names
		except:	special names 
			langauge keywords
			predefined macros

	Begins with two underscores (__)
		Reserved for any use by the compiler and std lib 
	Begins with an underscore and uppercase letter (_A)	
		Reserved for any use by the implementation
	Begins with an underscore and lowercase letter (_a)	
		Reserved in the global namespace (not allowed as global identifiers)
	Contains two consecutive underscores (__)
		Reserved in C++ (but okay in C)


Types – Fundamental types
	Fundamental
		void
		integral
	Compound
		class, ref, pointer, member pointer
		array
	
Object – Scope – Lifetime
	sizeof, alignof
	storage duration: auto, static, thread-local, global
	lifetime
	type,
	value

	memcpy: overllaping dst, src undefined behavior
	memmove: copy like using temp mem 

	polymorphic object:	RTTI, typeid

	scope:
		block
		function
		namespace V { void f(); } // first scope
				void V::f{ // second scope
					void h(); // V::h def is part of namespace
				}  
		class : same as namespace
				struct Derived: Base<0>, Base<1>, Base<2>
				{
					using Base<0>::next,     // next is in scope at the comma
						  Base<next>::value; // Derived::value is 1
				};

		lambda : could be recursive
		enum:
			enum E : int // E is in scope at the colon
			{
				// int x=12; outside
				x = x + 1, // enumerator x is in scope at the comma,
						   // outer x is in scope before the comma,
						   // enumerator x is initialized to 13
				y = x + 1  // y is initialized to 14
				A = sizeof(E)
			};

		template param scope: scope begins after ',' rather than after ';' of the definition
			and scope ends at the template class definition

			// the class template declaration of “X”
			// introduces a template parameter scope “S1”
			template
			<
			// scope “S1” begins here
			template // the template template parameter “T”
					 // introduces another template parameter scope “S2”
				<
				typename T1
				typename T2
				> requires std::convertible_from<T1, T2> // scope “S2” ends here
				class T,
				typename U
			>
			class X; // scope “S1” ends before the semicolon

			typedef unsigned char T;
			 template<
			 class T = T, // template parameter T is in scope at the comma,
						  // typedef name of unsigned char is in scope before the comma
			 T // template parameter T is in scope
			 N = 0
			 >
			 struct A{};
		

Definitions and ODR
	decl is def except
		func without body
		extern
		non inline static member
		constexpr inline static member in cpp file
		class Y func(class T t); // Y and T might be incomplete decls of class
		enum Color : int;
		typedef and aliasing ; // of might be incomplete types

	Inheriting constructors
		all overloads of Base::Base inherited
		members default init values could be func
			class A{ int a=func();};
		D: B1, B2 { using B1:B1;}; // first intialize args of B1::B1 and then 
								// B2 and D are default intialized
	
	ODR:
		two levels
		1. translation unit level
			fn, var, template, class, enum can have only 1 defn in 1 translation unit
		2. global level
			non-inline func and non-inline var can have only 1 defn across program

		Odr used : if you must know address or address matters during runtime
		var: read(except compile time constants), written, address taken
		ref: referent is not known at compile time
		func: called or address taken

Name lookup
	std::cout << std::endl; // endl is passed as callable fn arg.
		multiple decls in std::namespace for operator <<
		search in std::ostream::operator <<
	
	for fn and fn templates:
		- ADL
		- template arg deduction
	Then do overload resolution for all the definitions found
	And then apply member access checks, so if private fn is used after overload resolution 
	compilation error will be thrown

    qualified – unqualified (ADL)

As-if rule : 
	Allows any and all code transformations that do not change the observable behavior of the program.

	This is about compiler reording the instructions to optimize 
	such that behavior of program is not resonably altered
	1. volatile : for volatile variables
		a. all writes are complete before seq point
		b. no read is started before seq point
		c. multiple volatile varibles ops are not inter mingled
	2. file and output text
		a. before termination all files are written
		b. text is displayed before blocking wait to receive input

	Compiler 
	1. external libs: cant optimize these calls as it cant analyze code
	2. std lib: it can replace, remove, add calls
	3. static libs: does LTO

	Exceptions: copy ellision and user defined new(replaceble allocation function)
		might remove calls even if those have visible side effects


	Undefined behavior (UB)
		program can be
		1. ill-formatted : syntax error, compiler throws warning
		2. ill-formatted : ODR rule violated, link time error
		3. implementation defined : type of size_t
		4. unspecified behavior: compiler dependant, but compiler not required to disclose/document it
		5. undefined behavior:
				data race
				mem access out of array bounds
				signed int overflow
				more than 1 modification of same scalar
				Compilers are not required to
					dignose
					do anything meaningful for the UB

			UB and optimization:
				If you compile program with UB, compiler usually optimize programs

				int foo(int x)
				{
					// compiler optimizes to return 1 always, even though for MAX_INT, it should be false
				    return x + 1 > x; // either true or UB due to signed overflow
				}


				std::size_t f(int x)
				{
				    std::size_t a;
					if (x) // either x nonzero or UB
						a = 42;
					// compiled optimizes to always returns 42
					return a;
				}

			Clang compiles and does not cause any runtime error for below
			but GCC causes SIGSEGV
				int foo(int* p)
				{
					int x = *p;
					if (!p)
						return x; // Either UB above or this branch is never taken
					else
						return 0;
				}

				int bar()
				{
					int* p = nullptr;
					return *p; // Unconditional UB
				}

			clang optimizes the nullptr access and returns default value
			foo(int*):
					// always return 0
			        xor     eax, eax
					        ret
			bar():
					//return random value in output reg
					ret


			
	Multithread (C++11)
		std::thread, std::async,
		std::jthread (could be cancelled or stopped any time)

		Container Data race:
			parallel modify of content of elements except std::vector<bool>
			is data race free

		Memory order
			relaxed, consume, aquire etc

		Trivial infinite loops

		for/while(empty or const-expr-true) { /*empty*/ }

		implementation could add std::thread_yeild() call in loop.
		which will give its timeslice to other thread or



	Character sets and encodings
	Phases of translation
	The main function
	Modules (C++20)
