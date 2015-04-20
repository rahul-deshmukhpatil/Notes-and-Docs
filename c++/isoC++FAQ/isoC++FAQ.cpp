===================================================================================
intrinsic-types
https://isocpp.org/wiki/faq/intrinsic-types


primitive = interinsic = built-in 

What is a “POD type”?
	A POD type is a C++ type that has an equivalent in C, and that uses the same rules as C uses for initialization, copying, layout, and addressing.
	. To make sure the other rules match, the C++ version must not have virtual functions, base classes, non-static members that are private or protected, or a destructor. It can, however, have static data members, static member functions, and non-static non-virtual member functions.

	

===================================================================================
input-output
https://isocpp.org/wiki/faq/input-output

Why should I use <iostream> instead of the traditional <cstdio>? 
	- No % fmt to provide, more type safe
	- Less error as no extra  %fmt are provided
	- classes/operators could be inherited/overloaded

Why does my program go into an infinite loop when someone enters an invalid input character?
	use return value of cin to check if value entered is legal

	int i = 0;
	while (i != -1) {
		std::cin >> i;        // BAD FORM — See comments below
		std::cout << "You entered " << i << '\n';
	}
	
	int i = 0;
	while (std::cin >> i) {    // GOOD FORM
		if (i == -1) break;
		std::cout << "You entered " << i << '\n';
	}

How can I get std::cin to skip invalid input characters?
	Use std::cin.clear() and std::cin.ignore().

	while ((std::cout << "How old are you? ")
			&& !(std::cin >> age)) {
		std::cout << "That's not a number; ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "You are " << age << " years old\n";

How does that funky while (std::cin >> foo) syntax work?
	It returns NULL upon failure, otherwise valid pointer.
	It is left associative operator
		(std::cin >> foo) >> bar;   

Why does my input seem to process past the end of file?
	it’s not even theoretically possible for the C++ library to predict whether or not the character that the user just typed will be the last character.
	
Should I end my output lines with std::endl or '\n'? 
	Using std::endl flushes the output buffer after sending a '\n', which means std::endl is more expensive in performance. 

What is type inference.
	this is new feature with c++11
	Use of decltype and auto to use the types that could be derived compiler easily.
	template<class T>
	auto print(T data) -> decltype(+data)
	{
		return +data;
	}

	for (std::vector<int>::const_iterator itr = myvec.cbegin(); itr != myvec.cend(); ++itr)
	== for (auto itr = myvec.cbegin(); itr != myvec.cend(); ++itr)
	== for (auto& itr : myvec)

===================================================================================
const-correctness
https://isocpp.org/wiki/faq/const-correctness

What is a “const member function”?
	A member function that inspects (rather than mutates) its object.

What is the relationship between a return-by-reference and a const member function? 
	If member function is const and it is returning a reference to *this, reference return type must be const

What’s the deal with “const-overloading”?
	The two distinct methods differ only in that the inspector is const and the mutator is non-const.
	The most common use of const overloading is with the subscript operator. 

What do I do if I want a const member function to make an “invisible” change to a data member?
	Use mutable (or, as a last resort, use const_cast).
	A small percentage of inspectors need to make changes to an object’s physical state that cannot be observed by external users — changes to the physical but not logical state.

Why am I getting an error converting a Foo** → const Foo**? 
	here is the most common solution: simply change const Foo** to const Foo* const*

===================================================================================
References
https://isocpp.org/wiki/faq/references

What is a reference?
	An alias (an alternate name) for an object.
	References are frequently used for pass-by-reference:

What happens if you return a reference?
	The function call can appear on the left hand side of an assignment operator.

Why does C++ have both pointers and references?
	C++ inherited pointers from C, so they couldn’t be removed without causing serious compatibility problems. References are useful for several things, but the direct reason they were introduced in C++ was to support operator overloading.

When should I use references, and when should I use pointers?
	Use references when you can, and pointers when you have to.
	References are usually preferred over pointers whenever you don’t need “reseating”. This usually means that references are most useful in a class’s public interface. References typically appear on the skin of an object, and pointers on the inside.

What does it mean that a reference must refer to an object, not a dereferenced null pointer?
	It means this is illegal:
	T* p = NULL;
	T& r = *p;  // illegal

Should I use call-by-value or call-by-reference?
	If you want to change the object passed, call by reference or use a pointer; e.g., void f(X&); or void f(X*);.
	If you don’t want to change the object passed and it is big, call by const reference; e.g., void f(const X&);.
	Otherwise, call by value; e.g. void f(X);.

What if you do want to change the argument, should you use a pointer or use a reference? 
	If passing “not an object” (e.g., a null pointer) is acceptable, using a pointer makes sense. 
	Note also that a call of a member function is essentially a call-by-reference on the object, so we often use member functions when we want to modify the value/state of an object.

Why is this not a reference? 
	Because this was introduced into C++ (really into C with Classes) before references were added. Also, Stroustrup chose this to follow Simula usage, rather than the (later) Smalltalk use of self.
===================================================================================
Memory managment
https://isocpp.org/wiki/faq/freestore-mgmt

How do I deal with memory leaks?
	If you cannot handle allocation/deallocation implicitly as part of an object you need in your application anyway, you can use a resource handle to minimize the chance of a leak. After all, we cannot tell just looking at pointer whether it needs to be deallocated and if so who is responsible for that. Using a resource handle, here the standard library unique_ptr, makes it clear where the responsibility lies
	You don’t need to use new to create an object if you also delete that object in the same scope; such an object should be a local variable.

should I use NULL or 0 or nullptr?
	You should use nullptr as the null pointer value. The others still work for backward compatibility with older code.
	A problem with both NULL and 0 as a null pointer value is that 0 is a special “maybe an integer value and maybe a pointer” value. Use 0 only for integers, and that confusion disappears.

Is it safe to delete the same pointer twice?
	That second delete p line might do some really bad things to you. It might, depending on the phase of the moon, corrupt your heap, crash your program, make arbitrary and bizarre changes to objects that are already out there on the heap, etc. Unfortunately these symptoms can appear and disappear randomly. According to Murphy’s law, you’ll be hit the hardest at the worst possible moment (when the customer is looking, when a high-value transaction is trying to post, etc.).
	back to Murphy: since it can go wrong, it will, and it will go wrong at the worst possible moment.

Can I free() pointers allocated with new? Can I delete pointers allocated with malloc()?
	No! In brief, conceptually malloc and new allocate from different heaps, so can’t free or delete each other’s memory. They also operate at different levels – raw memory vs. constructed objects.
	You can use malloc() and new in the same program. But you cannot allocate an object with malloc() and free it using delete. Nor can you allocate with new and delete with free() or use realloc() on an array allocated by new.
	The C++ operators new and delete guarantee proper construction and destruction; where constructors or destructors need to be invoked, they are. The C-style functions malloc(), calloc(), free(), and realloc() don’t ensure that. Furthermore, there is no guarantee that the mechanism used by new and delete to acquire and release raw memory is compatible with malloc() and free(). If mixing styles works on your system, you were simply “lucky” – for now.
	If you feel the need for realloc() – and many do – then consider using a standard library vector. 

What is the difference between new and malloc()?
	malloc() is a function that takes a number (of bytes) as its argument; it returns a void* pointing to unitialized storage. new is an operator that takes a type and (optionally) a set of initializers for that type as its arguments; it returns a pointer to an (optionally) initialized object of its type. The difference is most obvious when you want to allocate an object of a user-defined type with non-trivial initialization semantics. 
	Note that when you specify a initializer using the “(value)” notation, you get initialization with that value. Unfortunately, you cannot specify that for an array. Often, a vector is a better alternative to a free-store-allocated array (e.g., consider exception safety).
	Whenever you use malloc() you must consider initialization and conversion of the return pointer to a proper type. You will also have to consider if you got the number of bytes right for your use. There is no performance difference between malloc() and new when you take initialization into account.
	malloc() reports memory exhaustion by returning 0. new reports allocation and initialization errors by throwing exceptions (bad_alloc).
	Objects created by new are destroyed by delete. Areas of memory allocated by malloc() are deallocated by free().
	 Unlike malloc(), new never returns null!

How can I convince my (older) compiler to automatically check new to see if it returns null?
	Override the new_handler and abort if it is raised due to no memory is available.

Do I need to check for null before delete p?
	no. Deleteing null pointer is valid
	The C++ language guarantees that delete p will do nothing if p is null.

What are the two steps that happen when I say delete p?
	it calls the destructor, 
	then releases the memory
	The statement p->~Fred() calls the destructor for the Fred object pointed to by p.
	The statement operator delete(p) calls the memory deallocation primitive

Why doesn’t delete null out its operand?
	First, you should normally be using smart pointers, so you won’t care – you won’t be writing delete anyway.
	One reason is that the operand of delete need not be an lvalue. Consider:
		delete p+1;
		delete f(x);
	Here, the implementation of delete does not have a pointer to which it can null out. 

In p = new Fred(), does the Fred memory “leak” if the Fred constructor throws an exception?
	No.
If an exception occurs during the Fred constructor of p = new Fred(), the C++ language guarantees that the memory sizeof(Fred) bytes that were allocated will automagically be released back to the heap.
	Here are the details: new Fred() is a two-step process:

	sizeof(Fred) bytes of memory are allocated using the primitive void* operator new(size_t nbytes). This primitive is similar in spirit to malloc(size_t nbytes). (Note, however, that these two are not interchangeable; e.g., there is no guarantee that the two memory allocation primitives even use the same heap!).
	It constructs an object in that memory by calling the Fred constructor. The pointer returned from the first step is passed as the this parameter to the constructor. This step is wrapped in a try … catch block to handle the case when an exception is thrown during this step.
	Thus the actual generated code is functionally similar to:

		// Original code: Fred* p = new Fred();
		Fred* p;
		void* tmp = operator new(sizeof(Fred));
		try {
		  new(tmp) Fred();  // Placement new
		  p = (Fred*)tmp;   // The pointer is assigned only if the ctor succeeds
		}
		catch (...) {
		  operator delete(tmp);  // Deallocate the memory
		  throw;                 // Re-throw the exception
		}
	The statement marked “Placement new” calls the Fred constructor. The pointer p becomes the this pointer inside the constructor, Fred::Fred().

After p = new Fred[n], how does the compiler know there are n objects to be destructed during delete[] p?
		Short answer: Magic.

		Long answer: The run-time system stores the number of objects, n, somewhere where it can be retrieved if you only know the pointer, p. There are two popular techniques that do this. Both these techniques are in use by commercial-grade compilers, both have tradeoffs, and neither is perfect. These techniques are:

		Over-allocate the array and put n just to the left of the first Fred object.
		Use an associative array with p as the key and n as the value.


===================================================================================
Classes and objects
https://isocpp.org/wiki/faq/classes-and-objects



How do I define an in-class constant? 
	 if your compiler supports that C++11 feature
		class X {
			constexpr int c1 = 42; // preferred
			static const int c2 = 7;
			enum { c3 = 19 };
			array<char,c1> v1;
			array<char,c2> v2;
			array<char,c3> v3;
			// ...
		};
	
	You have more flexibility if the constant isn’t needed for use in a compile time constant expression:
		class Z {
			static char* p;     // initialize in definition
			const int i;        // initialize in constructor
		public:
			Z(int ii) :i(ii) { }
		};
		char* Z::p = "hello, there";

	You can take the address of a static member if (and only if) it has an out-of-class definition

How are C++ objects laid out in memory? 
	Like C, C++ doesn’t define layouts, just semantic constraints that must be met.
===================================================================================
Constructors
https://isocpp.org/wiki/faq/ctors

Is there any difference between List x; and List x();
	List x; //declare x object of class List
	List x(); //declare function x returning List

Can one constructor of a class call another constructor of the same class to initialize the this object?
	BTW do NOT try to achieve this via placement new. Though it might work on particular compiler, Its bad.

Which constructor gets called when I create an array of Fred objects?
	Default Constructor. This is why default constructor with no arguments is needed, if you override it.
	Even default constructors with no arguments are called by derived classes for base class.

Is it moral for one member object to be initialized using another member object in the initializer expression?
	Yes, but use care and do that only when it adds value.
	In a constructor’s initialization list, it is easiest and safest to avoid using one member object from this object in the initialization expression of a subsequent initializer for this object.
	Comment the declaration of the effected data members with //ORDER DEPENDENCY.

Should you use the this pointer in the constructor?
	it works, n the {body} and even in the initialization list.
	

What is the “Named Constructor Idiom”?  
	A technique that provides more intuitive and/or safer construction operations for users of your class.
	you declare all the class’s constructors in the private or protected sections, and you provide public static methods that return an object. These static methods are the so-called “Named Constructors.”

Does return-by-value mean extra copies and extra overhead?
	Not necessarily. It is not at all in case of built in type, which could be adjusted in registers.
	It could be in case of user defined types.
	All(?) commercial-grade compilers optimize away the extra copy,	RVO , return value optimization.
	your compiler might optimize away the local variable completely - zero space-cost and zero time-cost - the local variable never actually exists as a distinct object from the caller’s target variable
	 circumstances where the compiler is unable to perform the optimization. One common case is when a function may return different named objects depending on the path of execution

Why can’t I initialize my static member data in my constructor’s initialization list? 
	you have to define static member it outside of class in .cpp file
	otherwise it will give linker error
	
Can I add = initializer; to the declaration of a class-scope static const data member
	Yes. only for built in type. That too in initializer expression is compile time computable

What’s the “static initialization order fiasco”?
	In short, suppose you have two static objects x and y which exist in separate source files, say x.cpp and y.cpp. Suppose further that the initialization for the y object (typically the y object’s constructor) calls some method on the x object.

How do I prevent the “static initialization order fiasco” for my static data members? 
	Use the Construct Members On First Use Idiom, which is basically the same as the regular Construct On First Use Idiom, or perhaps one of its variants, but it uses a static member function instead of a namespace-scope / global function.
		void X::someMethod()
		{
		  static Fred& x = X::x();
		  x.goBowling();
		}

What is the purpose of the explicit keyword?
	The explicit keyword is an optional decoration for constructors and conversion operators to tell the compiler that a certain constructor or conversion operator may not be used to implicitly cast an expression to its class type.
===================================================================================
What’s the deal with destructors?  
	A destructor gives an object its last rites.

What’s the order that local objects are destructed?  
	In reverse order of construction: First constructed, last destructed.

What’s the order that objects in an array are destructed?  
	In reverse order of construction: First constructed, last destructed.

Can I overload the destructor for my class?  
	No.

Should I explicitly call a destructor on a local variable?  
	No!

But can I explicitly call a destructor if I’ve allocated my object with new?  
	Probably not.
	Unless you used placement new, you should simply delete the object rather than explicitly calling the destructor. 

What is “placement new” and why would I use it?  
	There are many uses of placement new. The simplest use is to place an object at a particular location in memory. This is done by supplying the place as a pointer parameter to the new part of a new expression

When I write a destructor, do I need to explicitly call the destructors for my member objects?
	No. You never need to explicitly call a destructor. 

When I write a derived class’s destructor, do I need to explicitly call the destructor for my base class?  
	No. You never need to explicitly call a destructor

Why can’t my derived class access private things from my base class?  
	To protect you from future changes to the base class.

===================================================================================

Friend Functions
https://isocpp.org/wiki/faq/friends

What is a friend? 
	Something to allow your class to grant access to another class or function.
	Friends can be either functions or other classes. 

Do friends violate encapsulation?
	No! If they’re used properly, they enhance encapsulation.
	If you want to access private members outside of class, friend help in that.
	you do not need to provide get/set or to make members public, in case you want to access them outside of class.

What are some advantages/disadvantages of using friend functions?
	They provide a degree of freedom in the interface design options.
	
	class X
	{
		friend void f(X x);
	}
	x.f() and f(x), both are valid friend function calls.	
	
	The major disadvantage of friend functions is that they require an extra line of code when you want dynamic binding. 
	virtual friend function idom.

What does it mean that “friendship isn’t inherited, transitive, or reciprocal”?
	inherited: I don’t necessarily trust the kids of my friends
	transitive:  don’t necessarily trust the friends of my friends.
	reciprocal: You don’t necessarily trust me simply because I declare you my friend. 	

Should my class declare a member function or a friend function?
	Use a member when you can, and a friend when you have to.
	Sometimes friends are syntactically better,  good use of friend functions are the binary infix arithmetic operators. E.g., aComplex + aComplex should be defined as a friend rather than a member if you want to allow aFloat + aComplex as well (member functions don’t allow promotion of the left hand argument, since that would change the class of the object that is the recipient of the member function invocation).

===================================================================================
Inheritance
https://isocpp.org/wiki/faq/basics-of-inheritance

I’ve been told to never use protected data, and instead to always use private data with protected access functions. Is that a good rule?
	Here’s the way I say it: if I expect derived classes, I should ask this question: who will create them? If the people who will create them will be outside your team, or if there are a huge number of derived classes, then and only then is it worth creating a protected interface and using private data. If I expect the derived classes to be created by my own team and to be reasonable in number, it’s just not worth the trouble: use protected data. And hold your head up, don’t be ashamed: it’s the right thing to do!


===================================================================================
virtual functions
https://isocpp.org/wiki/faq/virtual-functions


What is a “virtual member function”?
	Virtual member functions are key to the object-oriented paradigm, such as making it easy for old code to call new code.

Why are member functions not virtual by default?
	Because many classes are not designed to be used as base classes.
	Virtual function introduces vptr in every object
	Every virtual fun has to pay runtime cost for calling the function.

How can C++ achieve dynamic binding yet also static typing?
	Static typing means that the legality of a member function invocation is checked at the earliest possible moment: by the compiler at compile time.
	Dynamic binding means that the address of the code in a member function invocation is determined at the last possible moment: based on the dynamic type of the object at run time.

What is a pure virtual function?
	A pure virtual function is a function that must be overridden in a derived class and need not be defined.
	But could have definition.

===================================================================================
Terminology
	Named constructor
	Zero base class optimization
	Construct On First Use Idiom
	Construct Members On First Use Idiom,
	virtual friend function
	
