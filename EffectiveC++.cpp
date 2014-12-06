
1. C++ as a federation of languages.
	c++ could be devided into four parts, sub languages
		a.	C from which it is inherited
		b.	C++ obj oriented concepts
		c.	Templates: template metaprogramming
		d.	STL: data structures easyness and help in fast,relieable program
	
2. Prefer const, enum , inline over	#define macro variables
		a. macros do not have scope, they are global till #undef is done
		b. no return type checking
 		c. macros are not logged in symbol tables, hard to debug if macro is in
			3rd party lib as you will see value of macro in compiler error which
			does not make sense.
		d. macros do not make sense when arguments passed is complex expression

		c++ requires definition of anything that you use. But class static
		const member of integral could be used with just declration,as long as
		you do not take the address.

3. Use const whenever possible;
		a. with local auto variables
		b. with function arguments
		c. const functions of class
		d. const with the stl iterators ie const_iterator 
		otherwise for user defined type
			while(a * b = c); where will be taken as while( (a * b) = c);
			where programmer really meant is while( (a * b) == c) 
			with const assignment of 'c' to multiplication will not happen
	
		Avoid duplication in const and non-const member function.
		simply make non-const member function to call const function using double
		type casting
			const dType& operator[] (int i) const;
			dType& operator[] (int i)
			{
				return const_cast<dType &>
						(static_cast<const dType *>(this)[i]);
			}

4. Make sure objects are initialized before they are used.
		a.	Everything must be initialized with the constructors initialization list
			in ordered manner so that client/programmer are not confused.
			compiler initialize
			I> parent class, in order of their declaration of inheriatance
			II> data members in order of declaration.
			irrespective of their order in initialization list, so we should try to
			maintain same order as of compiler. Because this might introduce bugs
			if programmers thinks order of initialization is same as in initialization 
			list.
	 
		b.	Make sure everything is initialised in all constructors.
			here code duplication will come in scenario could be avoided with the
			having common initialization function.

		c. 	const and references must be initized in initialization list.
		
		d.	static objects begin life when constructor invoked till program lasts.
			local static begin life when first time function is called.
			
		e.	Class global static objects have very unreliable initialization order. So it is
			better to make them local static members of the function and use that function
			to get/set these static variables. But any local/global non-const static varible
			is suseptible to bug, in case of multiple threads. Only solution is to manually
			invoke the reference(to static members) in single threaded startup. 

5. C++ silent function additions	
		a.	If default constructor, copy constructor, operator=, destructor are not provided
			explicitly then they are added when compiler finds need to add them. Destructor
			added by compiler is non-virtual if in base class(if present) it is not virtual.
			In default constructor compiler calls constructors of the base classes and the
			non static member data objects in the order they are declared. For integral types 
			compiler does the bitwise copying. 
				If class has a reference variable or const variables, as these variables could
			be initialized only in the initialization list, compiler refuses to provide the
			copy constructor or operator=.

6. Explicitly disallow use of compiler generated functions you do not want
		a.	Some obejcts are uniq and you do not want the copying of them by the implicit
			copy constructor or operator=, then make it private. But this will allow 
			member functions or friend functions to call them. And generate the link time
			error. So make it private in the base class Uncopyable, which will generate the
			compile time error.
		 		
