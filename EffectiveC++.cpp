
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
		e. step deugging is not possible in case of macro code snippet

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
			I> parent base classes, in order of their declaration of inheriatance
			II> data members in order of declaration.
			irrespective of their order in initialization list, so we should try to
			maintain same order as of compiler. Because this might introduce bugs
			if programmers thinks order of initialization is same as in initialization 
			list. They are initialized in same order in case of inbuilt copy constructor
			or copy assigment operator.
	 
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
			copy constructor or operator=, then make it private. 
			But this will allow 
				I. member functions or friend functions to call them. 
				II. And generate the link time error. 
			So make it private in the base class Uncopyable, which will generate the
			compile time error.
				class Uncopyable {
					private:
						Uncopyable(const Uncopyable &);
						Uncopyable& operator=(const Uncopyable &);
				};

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
			destructors. If destructor called during unwinding stack raises any excpetion further, this 
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
			they accept as a parameter should return the *this. So that coudld be used 
			in cascaded = expressions. 

11.	Handle operator= correctly.
		a.	May check if self assignment is being done and you do not delete any part
			if destination object without successfully initializing to part in source.
		
			TextBlock& operator=(TextBlock &rhs)
			{
				// Below check condition depends upon how frequently you call
				// the operator= and how heavy the new assignment is 
				if(this == &rhs) return *this;
			
				char *oldPb = pb; 	// made a copy of pb
				pb = new char[10];	// allocated new pb, this may throw exception
									// but pb in that case will return old value
				delete oldPb;
				return *this;
			}

12. Copy all parts of an object
		a.	When we override the assignment and copy constructors, upon adding new data member 
			to the class we often forget to initialize it in the constructor. Do not let that	
			happen.
		
		b.	See if class is inherited, base class copy constructor is being called correctly
			from inherited class copy constructors initialization list. try to copy the data
			members as well in the initialization list as said for all other constructors 
			initialization.
	
		c.	In case of assigment operator, see if all base class = operators are being called
			correctly.

		d.	If some code is common among the assignment operator and copy constructor, put it
			in a third function, called init, rather than calling copy constructor or assigment
			operator from each other.

		e.	Assigment operator and copy constructors looks almost same in case of using, syntax, but
			they are quiet different in functionality intended from them.

 
=================================================================================================
| 	RESOURCE MANAGEMENT 																		|
=================================================================================================
			
13.	Use objects to manage resources.
		a.	if you handle manual allocation and deletion then you are inviting memory leaks.
			You do not just leak memory but could leak resources as well, ie locks, file handles.
			this might result in endingup with free resources.

		b.	Resouce Mangaging classes have two principles	
			I.	Aquire/create resource object and tranfer to managing object.
			II.	Use destructor of the resource managing object to release/delete resource
	
		c.	STL containers expects normal copying behaviour in copying operation. std::auto_ptr
			makes the source object raw resource pointer NULL while copying to destination. Hence
			STL containers of the std::auto_ptr are not allowed.
	
		d.	RCSP(reference counting smart pointers), can not break cycle of references unlike
			garbage collectors in the java.
	
		e.	std::shared_ptr and std::auto_ptr use delete (and not delete []) in the destructors
			so it is not possible to use arrays of the shared_ptr and auto_ptr.
		
		f.	In C++, vector and string, always could replace [] in C. so try to use these c++ stls. 
			

14.	Think carefully about copying behaviour in resouce managing object.
		a.	Prohabit copying of the resource managing objects:
			Locks used for synchronization, there is hardly any logical scenario where you want to
			copy the objects. So make it uncopyable.
		
		b.	Manage count of pointers to resource.
			Free resource only when last pointer goes out of scope. You may use std::shared_ptr()
			in your custom implementation. But std::auto_ptr always calls the delete on the resource
			object at the time of being destructed. Fortuantley tr1::shared_ptr we could have second
			paratmeter deleter whihc could point to the unlock function in case of the lock.
			eg.
				class Lock {
						std::tr1::shared_ptr<Mutex> mPtr;
					public:
						explicit Lock(Mutex *ptr)
						:mPtr(ptr, unlock)
						{
							lock(mptr.get());
						}
				};

		c.	Copy the underlying resource.
			While copying the resource managing object, ensure that you are doing deep copy and resource
			as well is getting copied so that when you delete the resource managing object all copies
			are deleted in a safe manner.
			Transfer the ownership, while copying, like in std::auto_ptr if that is the requirement.
		
15. Provide the access to the raw resources in resource managing objects.
		a.	Both std::auto_ptr and std::shared_ptr provide the function get(), to access the raw pointer
			of the resource they are holding. They as well provide the implicit conversion via operator*
			and operator-> as expected from smart pointers. Giving access to raw poiter of resource might
			be sometimes need but it might create copy of the raw pointers, which could remain for the
			dangling access.
		b.	So your interfaces must be easy to use, but hard to exploit to break(use incorrectly).
			
			 
16.	Use the same form of delete as in new.

		a.	If you are using just new then use delete
			if you are using new [], then you must use delete[].
			if delete [] is used in first case then it might result into undefined behaviour.
			if delete is used in later case, you might endup with memory leakage, depending
			upon how meta data for the memory manamgent is saved.
		
		b.	you must used same for of new to initialize the member objects in a class, because
			there is only one destructor and only one statement having delete is going to delete
			the member.

		c.	Do not use typedefs having arrays in them. Whatever arrays could do, could be done
			with the vectors and string.

17.	Store Smartpointers in stanalone statements.
		a.	We may initialize the smart pointer in a complex statements.
			eg. function call having smart pointer as argument and other arguments are calculated
				by other functions. 
			Compiler might reorder the complex statements function calls, so raw pointer in smart
			pointer will be allocated via new, but will not passed to smart pointer constructor if
			any other function throws exception.
			function(std::shard_ptr<int>(new int), calculate())
			compiler might reorder the statement parts
			a> new int
			b> calculate()			//this throws exception
			c> std::smart_ptr<int>	//this constructor will  not be called so not freeing int allocated
									//above
			
			so intialize the smart pointer first and then pass it to function call. This will not make
			compiler to reorder.

18.	Make interfaces easy to use and hard to exploite/abuse.
		a.	Make it hard to pass the wrong value, by using the static functions returning correct values.
		b.	shared_ptr is as twice the size of the normal pointer. Handles the metadata dynamically.
			It also supports the synchronization for count increment in case of the multithreaded app.	
			this multithread support of shared_ptr can be turned off with the preprocessor.
		c.	Ways to prevent errors include
			I. 	define new type
			II. Constrain the values of new type.
			III.restrict operations on new type
			IV.	eliminate client from resouce managment. Return shared_ptrs.
		d.	Shared pointer supports the deleter facility , which can be used to prevent the cross-DLL
			problem.

19.	Treat class design as type design.
		Read book. did not get the point

20.	Prefer pass by const reference over pass by value.
		a.	Pass by value calls the constructor, which may inturn call several constructors and memory
			allocations in case of deepy copy.

		b.	In derived class pass by value to base class type accepting function, objects are sliced 
			off(no more virtual functions call work as you expect)

		c.	For builtin data types use the pass by value, as reference takes as much space as pointer.
			It is pass by value efficient here.
		
		d.	You may tempt to use the passs by value for other user defined functions having less size
			but implementions of such classes(user defined or stls) is subject to change and it might
			take different size in future.

		e.	Use pass by value for user defined type, stl iterators, function objects ie functors.

21.	Do not return reference when you must return the object.
		a.	In case of the operator overloading of '+', '-', '*', ... you must return the actual newly
			constructed objects.
			you can not return the below:
			I	reference to locally built object in operator implementation:
					As the local objects get destroyed after function finish the implementation.
			II	pointer to locally build object: this return type is incompatible with expected declaration.
			III Deference pointer to locally newed object:	
					- clients of the function will have to take care of freeing the resultant object.
					- in case of x = y = z; // memory leakage will happen in newed memory while y = z
			IV	reference to local static objects: 
					- synchronization in multithreaded env.
					- if (operator==(operator*(x,y),operator(z,w)); // compares same static object in operator ==.
		
22.	Declare data members to be private.
		a.	You can have read/write access control and log over the members.
		b.	You can change the implementation of members to functions.
		c.	clients do not have to remember if to put () to access the member, its always that they will have to put.
		d.	Hiding data members give the implementations flexibility.
			-	in changing member name
			-	replacing data member with function computation
			-	synchronization around data member, specially static
			-	read/write access preverntion implementation
			-	having pre/post conditions on the member data set/get
			-	ability to freely change your code.
		e.	Encapusulation is inversly proportional to the amount of broeken code.
		f.	Once you declare the data public/protected and clients start using it, its hard to change the code
			as clients have preasumed the free access to public members and to protected in case of derived class.

23.	Prefer non-member, non-friend functions 
		a.	More the data could be accessed via functions less is encapsulation.
			This is true for member functions as well.
		b.	Functions are not part of the class, changing them would not require to recompile the code of class.
		c.	All such utility functions using the class functions could be put in saperate files.
		

30.	Know the ins and outs of inlining
		a.	Inline is smarter only if function code of calling and retruning is more than the function body.
		b.	Function inlining is request.
		c.	All functions declared inside class definition are inlined. This include friend functions.
		d.	Even empty derived class constuctor has inlined base class constructor code. 	
		e.	Inlining could result in more object code and instruction cache miss.
		e.	Virtual functions defy inlining.
		f.	in c++, inlining is compile time acitvity.
		g.	if address of inline function is taken, that function is globally instantiated.
		h.	pointer to function, work on globally instantiated inline functions.
		i.	Do not inline the template functions, until you really mean.
		j.	if definition of inline function changes in a library, then client code using this
			libarary and the inline function must be recompiled in client library. To recompile in client
			libarary inline function must be in the header files which are provided with the release.

31.	Minimize compilation dependencies in between files.
		a.	you can have seperate header files for declaration and definition.
		b.	function definitions returning/passing argument by value do not need definition.
		c.	make header files self sufficient, if not possible, depend upon the class declartions
			and not definitions.
		d.	c++ has keyword 'export' which saperated template declaration from definition.
		e.	pImpl idom: class had single member pointer to the real implementation.
		f.	abstract interface: Abstract parent class created with pure virtual function, which
			is overrided by real implementation. Abstract class provides factory function 'create'
			which returns the shared_ptr to derived class dynamically created object.
		g.	Interface/handle methods:
				-	costs speed as involvs virtual functions in case of interface.
				-	extra function call in case of handle method.
				-	costs extra pointer size to dynamically allocated derived object.
				-	dynamic allocation time overhead.
		h.	Use interface and handle classes at the time of development, till the classes get
			matured and strong coupling is found.
		
32.	Make sure that public inheritance is "is-a" relationship
		a.	public inheritance is defined by is-a relationship.
			But be careful, penguin is a bird, but bird can not fly.
			it is no more square.
		b.	Best design depends upon both, what is does now and what it can do in future.
		c.	Public inheritance asserts that everything that applies to base class applies
			to derived.	
			Square(derived) is a rectangle(base), but once you change width of rectangle(which is square),

33.	Avoid hiding the inherted names
		a.	If base class has overloaded methods and in derived class if you override only some of them
			other methods are hidden. Use 'using' to avoid this hiding of overloaded methods in derived class.

34.	Differentiate between inheritance of interface and inheritance of implementation.
		a.	Pure Virtual functions: only interface is inherited. No implementation.
			Though pure virtual functions can have definitions, which could be called via a explicit
			ptrDerived->base::PureVirtfunction() syntax.
		b.	Simple/Impure Virtual function: used to inherite the interface and implementation.
			Use the default implementation or specialize if needed.
		c.	Non virtual function: Derived class inherit the interface as well as implementation.

36.	Never redefine the non-virtual inherited function:
		a.	if non virtual function mf() is inherited in class D.
			then calls to b->mf() and d->mf() will result in calling different functions.
			Since D is-a B, but behaviour on calling mf() is different.

37.	Never redefine default parameters of the virtual functions.
		a.	Virtual functions are dynamically bound, but the default parameters they
			accept are statically bound.
		b.	This is done for efficiency that default values are statically bound. If done
			dynamically it would have been complex.
		c.	Code duplication is worse, code duplication with dependencies is even worst.
			Use Non-Virtual public interface calling private non accesible private virtual
			functions as a remedy.
		
38.	Model "has-a" or "is-implemented-in-terms" of through composition.
		a.	Composition has lots of names: layering, containment, aggregation and embedding.
		b.	has-a : application domain. Vechicle has engine.
		c.	is-implemented-in-terms: implementation domain. Set is implemented in terms of list.
		
39.	Use private inheritance judiciously.
		a.	Compilers do not convert privatly derived objects to the type of base class implicitly.
		b.	Private inheritance is-implemented-in-terms of. Composition and private interface are
			alternative to each other.
		c.	Private inheritance is implementation technique, it means implementation should be only
			inherited and interface should be ignored.
		d.	Private inheritance means nothing during design, only during inheritance.
		e.	Use composition whenever you can and use private inheritance whenever you must.
		f.	Empty Base Optimization: Inherited part of empty base class has size 0 as total object size
				grows more than 0. 
		g.	Empty base classes are used for typedefs, static-data, enums, non-virtual functions.
		f.	Private inheritance must be used when classes do not have is-a relationship and derived 
			class wants to use the protected members of base class or want to redefine the virtual functions.

40.	Use multiple inheritance judiciously.
		a.	C++ first tries to identify the best function match. Later it tries to check the accessibilty.
		b.	Virtually derived class objects are larger in size, slower in member access.
		c.	Rules for virtual base class initialization are complex. Most derived class is responsible	
			for direct and indirect virtual base class.
		d.	Try to avoid the virtual base classes.
		e.	If neccessory to have virtual base class, just have functions, typedefs , enums in them.
		f.	In case of multiple inheritance, Use public inheritance for interface and private inheritance
			for the implementation.
