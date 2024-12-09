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
Name lookup
    qualified – unqualified (ADL)
	As-if rule
	Undefined behavior (UB)
	Memory – Multithread (C++11)
	Character sets and encodings
	Phases of translation
	The main function
	Modules (C++20)
