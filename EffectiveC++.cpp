
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

7. Declare destructor virtual in polymorphic class
		a.	Use virtual destructors only in
			I> polymorphic classes, which are inherited
			II> Or if any other fuction is virtual, which is basically sign on inheritance later.
	
		b.	STL classes mostly do not have the virtual destructors, So do not inherite them
			and try to destroy polymorphically.
		
		c.	Do not use virtual destructor in the classes which are just meant to be inherited
			and do not contain any object of other than integral type, as data member.
			eg Uncopyable/noncopyable. 

8. Prevent exception from leaving destructors
		a.	Whenever exception is raised the objects on the stack are unwinded by calling the
			destructors. If such unwinding destructors raises any excpetion further, this 
			leads to the undefined behaviour(if not crash), which is very hard to detect.
			c++ does not like exceptions that emit the destructor.
		
		b.	There could be situation where destructor must have to call fuction that raises 
			the exception. There are two ways to mitigate this
			I>	Abort in the catch clock of such exception in destructor. This will prevent
				the undefined behaviour later.
			II>	Swallow the excption raised by just logging the excpetion. This is bad idea,
				but will let you run the program.

		c.	In above case you may provide functionality to call the function explicitly as 
			which is being called from destructor. As well back up call to such function 
			will suffice in case of clients of such function do not call "the function"
			eg.
				class DBConn {
						bool closed;
					public:
						close() throw DBConnEx 
						{ 
							db.close();
							closed=true;
						}
						~DBConn 
						{
							if(!closed)
							{
								try
								{
									db.close();
								}
								catch
								{
									//swallow by logging exception raised
									//or call std::abort to terminate
								}
							}
						}		
				} 	

9.	Calling virtual functions from constructor or destructor
	you should not call virtual function from the constructor or destructor	
		a.	Because it will call only base class function irrespective of
			what is actual type of object being constructed or destructed.
			so result will be against programmers intitution.

		b.	Even run time type identification, dynamic_cast and typeid
			does not work in constructor and in destructor.

		c.	If virtual function being called from base class ctor or dtor
			is pure in base class, it will result in runtime abort.

		d.	To prevent this calling of virtual function, pass the result
			of virtual function as a parameter to the base class ctor.

10.	Assignment operators returns *this.
		a.	All assignment operators =, +=, *=, ... irrespective of the source type
			they accept as a parameter should return the *this. 
