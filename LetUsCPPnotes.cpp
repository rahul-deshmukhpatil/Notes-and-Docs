+===============================================================================================+
|Chapter3: Graduating to CPP																	|
+===============================================================================================+
	<< insertion or put to operator(cout) 
	>> extraction or get from operator(cin)
	namespace is nothing but collection of identifiers(variables and some other types of names)
	Ways to refer identifier belonging to some specefic namespace
	A> namespace::identifier	
	B> using namespace <name_of_namespace>;	

	endl is a output manipulator function
		std::endl = "\n" + flush data 
		so slower than raw \n

	iostream.h contains declarations needed by the cin and cout

FUNCTION PROTOTYPE
c++ is strong type checked lang i.e prototype of function must be known before calling

FLEXIBLE DECLARATIONS
declare variables at the time of using them, not neccessory to declare them at starting of code block.
eases the code reading as variables are declared where they are used.
As well you do not need to initialize variables if control does not reach there use point.

STRUCTURE ENUM and UNION SYNTAX
could create obj of struct, enum and union with just corrosponding name.

ANONYMOUS UNION and ENUM
union { int a; char b;} enum{z=48, x, y}
to qualify as a anonymous union you should not declare its object.As well as it should not have 
name/tag so that possibility of creating object of it doesnt exists.
Then you can use a and b in the main program, but both of them are at same memory, affecting each other
if one of them is changed.

TYPECASTING
C++ doesnt do typecasting automaticaly like C. There are to methods of typecasting
	A> intA = 8 * (int ) charB
	B> intA = 8 * int (charB)

VOID POINTER
unlike C, u cannot assign void pointer to other type of pointer, u need to add explicit typecasting
to convert void pointer to destination type.

THE :: Operator
:: is a scope resolution operator if applied to any variable gives its global variable of same name instead
of local variable.
	int a = 3;
	main()
	{
		int a = 4;
		a = ::a;
	}

REFERENCE
reference is alias of a variable. There is stuble differance between pointer and reference
Rules
	A> reference must be always intialised
	B> once initialised cannot refer to other variable i.e. they act very closly constant pointers
	C> can create reference to pointer
	  char *& rToCharPtr;
		C.1> like pointer to pointer **, you can not create reference to the refernce, rvalue reference "&&" is diff concept in c++
	D> variable can have multiple references.
	E> array of references is not possible unlike array of pointers
		E.1> you can impl your own custom `CustomRef { const T *ptr; auto operator->() {return ptr;}`, but you can not override `dot` operator for exact behavior;
	F> you can not dis-associate reference from varible it is referring to
References help to write readable code while achieving object of passing object by address.

RETURING BY REFERENCE
Do not return local variable by reference, as local variables are decalred on stack which may
get overwritten after returning and reference may refer to variable in overwritten memory.
in general return by reference, is bad idea (specificlly non-class functions which does not return any large cached golden copy object)

In general do not take address of the reference(i.e. variable) unless object is created dynamically using new,
the reference might get invalidated but pointer has unlimited lifetime.

CONST QUALIFIER
Const qualifier helps to replace #define macros as well as to control the scope of variable.

CONST REFERENCES
Used to convert pass variables to fuction, but doesnt allow function to modify the variable value.
you cannot initialise non const reference by const variable.
	int i;
	const int &r = i;
This is legale but,
	const int i;
	int &r = i
will give compilation error of type mismatch

BOOL DATA TYPE
This is new addition to C++
=================================================================================================
=================================================================================================

+===============================================================================================+
|Chapter4: FUNCTIONS																			|
+===============================================================================================+
1> FUNCTION PROTOTYPE
	Must declare function before using as c++ is a strong type check languagae.
	Declaration as well has scope.

	in C defualt prototype of funtion if not provided is `int func(...);`

2> FUNCTION OVERLOADING
	Function with same name must differ atleast in type, number or order of the parameters they
	accept. Even const and non-const functions versions are overloaded

3> DEFAULT ARGUMENTS TO FUNCTION
	Default argumnets must be the trailing one.
	Useful in 2 cases:
	A> Function almost always have same values.
	B> Suppose we add a new parameter to the function and extend functions capability and dont want
	to change older calls to the function, then older calls may use default values.
	C> Default values are needed only in declaraion, Do not need to be specefied in definition
		you can have multiple declarations with default values
		each time you can specify more default values from right to left
		f(a,b,c=1)
		f(a,b=2,c)
		f(a=3,b=2,c)

	D> Since you can have multiple declarations in different scopes, but with same signature. Each declaration
	could have different default value.

	Function arguments default value could be const, global variable or a function call.
	f(v=10);
	f(v=global_v);
	f(v=get_v());

4> Operator overloading
	Teaches normal c++ operators how to act on userdefined data types.
	A> ., ::, : cant be overloaded
	Operators which cannot be overloaded
	?: (conditional)
	. (member selection)
	.* (member selection with pointer-to-member)
	:: (scope resolution)
	: (access or inheritance specifier, range, goto, ternary, bitfield specifier)
	sizeof (object size information)
	typeid (object type information)
	static_cast (casting operator)
	const_cast (casting operator)
	reinterpret_cast (casting operator)
	dynamic_cast (casting operator)
		
	B> can not modify behaviour of operators with basic instrinsic datatypes(will make program unreadable)
	C> precedance is same as for instrinsic datatypes.

5> Inline functions
	Each time function call is made time is spent of passing values, passing control, passing return value
	and getting back the control from where function had called. To bypass this we use inline function, function
    call is replaced by the function code. 
	 It depends upon compiler to make inline function really inline as when we say function is inline it just 
	request. If function is too large compiler will treat that function as a normal rather than inline function.
	No criteria has been defined by c++ standards to make function inline and gives freedom to compiler writers
	to decide the criteria.
		There is no connection between function being inline and static. Or function templates should be inline.
	Though recursive inline calls could be really replaced by actual recurisive function code till certain depth.

	inlining like macro is source code copying, without typical drawbacks of copy-paste errors
	or flaws of modification at one place.

	Inlining might not always recommended,
		might increase cache miss
		might increase binary size
	
	Functions defined in headers are implicitely inline
	Inline functions are usually in the header files
	but they could be in source .cpp files if gcc -flto Link Time optimization is enabled
=================================================================================================
=================================================================================================

+===============================================================================================+
|Chapter5: CLASSES																				|
+===============================================================================================+
Intro:
	C++ extends structures by allowing function in structures.
	Object is an instance of an class and process of creation of object is called instantiation.

	Data hiding: Data is conceled within class and cannot be accesed by the function outside of the
	class. This prevents leagal user from commiting programming mistakes.
	
	. is a class member acess operator.

1> CLASSES and CONSTRUCTORS
	Construcotor is a function executed everytime when object is created.
	Construcor has same name as of class signfies that it is construtor to the compiler.
	There is no return type for construtor as it is only called AUTOMATICALLY when object is created, and returning 
	value doesnt make sense.
	Compiler provids default zero argument construtor even when we dont define any argument constructor.
	If we define a one or more argument constructor then default construcotr is not generated and we must to define a 0 argument constructor.
		
	Default constructor is not generated if T has
	1> Member is reference without default initializer list 
			i.e  MemberT& memRef; // without default init value = {}; ?
	2> Member is const without default initializer list or default constructor
	3> Class member variable does not have default constructor ( T()= delete; deleted def constr) 
	4> ambiguous constructor (another construtor with all params having default value)
	5> Direct or virtual base does not have Constructor or destructor accessible or deleted.
	

	mem-copyable = No-virtual/No user defined funcs
	Trivial (Trivially copied to read from C++, no user defined default logic)
							: No virtual func/base class
							: all members and base are trivial
					===>	: no user defined special member functions
							: T occupies a contiguous memory area. 
							: It can have members with different access specifiers. In C++, the compiler is free to choose how to order members in this situation. Therefore, you can memcopy such objects but you cannot reliably consume them from a C program or C++ programs compiled with another compiler. 


	c/c++ accessible: all members in one class
	standard layout (Layout does not depend on the compiler ordering of public/private/protected and Base/Dervied/Virtual orderingin memory)
							: No virtual func/base class
							: all members and base are standard layout 
					===>	: all non-static data members have same access control
							: the layout is sufficiently defined that it can be consumed by C or C++ programs compiled with diff compiler. 
							: Standard-layout types can have user-defined special member function
					===>	: Either most derived class has a non-static members or only one of the base can have non-static data memebers

	POD						: When it is both standard layout and trivial it is POD. 
							: therefore contiguous and each member has a higher address than the member that was declared before it, so that byte for byte copies and binary I/O can be performed on these types.


	https://abseil.io/tips/146
	value initialization is
		// first zero initialization
		// then default initialization
		
	There are 3 categories of constructors
		1. class Foo {}; // implicit default, i.e no contr defined
				// T t; // default init, nothing intialized
				// T t{} // value init
		2. Foo() = default; // "Used-declared", NOT "user-provided".
				// T t; // default init
				// T t{} // value init
		3. Foo() {} //  "user-provided".
			// all members are always default initalized
		4. class Foo {
			Foo()
			: v()
			{} //  "user-provided".

			int v;
		  }
			// T t{} // default init, but v is in with zero init

	Default initization : 	T a; 
							auto a = new T;
						: if static/thread local object : zero initialize
						: Calls default constructor if has any. Otherwise object is not initialized

	In simple terms
			T t; => is default initialized, some members without default initializers will be uninitialized
			// note T t(); is a function declaration;
			T t{}; or auto t = T{} or auto t = T();
					=> value initialized,
					that is first zero initialize
					then default initialize

	Value initialization : T a(); T a{}; new T(); new T{}, 
							Class::Class
								: T()
							{
							},
							Class::Class
								:T{} 
							{
							} 
						: if 
							no constructor(no implicitly declared default (in case of const or const reference data member), 
							deleted default
							no user provided)
								default initialize
						: if implicitly declared construtor: 
							first zero intialize then default initialize
						: if user declared call it  
							first zero intialize then default initialize
						: if array: initialize each element by value initialization 

	zero initialization : static or thread-local storage duration that is not subject to constant initialization, before any other initialization.
						: As part of value-initialization sequence for non-class types and for members of value-initialized class types that have no constructors, including value initialization of elements of aggregates for which no initializers are provided.
						: When an array of any character type is initialized with a string literal that is too short, the remainder of the array is zero-initialized.
	
	Aggregate initialization
						: Initializes an aggregate from braced-init-list
						: for array type or class type without user provided or inherited constructor
						: no virtual member functions or virtual, private, protected base class
						 


								

2> DESTRUCTOR
	Destructor is a special function called when object is destroyed.
	Destructors do not have return type also they dont take any argument as philosophy says there is only one way to
	destroy any object.
		
		Trivial default constructor : does nothing 
		The default constructor for class T is trivial (i.e. performs no action) if all of the following is true:
			The constructor is not user-provided (i.e., is implicitly-defined or defaulted on its first declaration)
			T has no virtual member functions
			T has no virtual base classes
			T has no non-static members with default initializers.
			(since C++11)
			Every direct base of T has a trivial default constructor
			Every non-static member of class type has a trivial default constructor

3> OVERLOADED OPERATORS
	They enable use to use +, - , && like operators, which could be used with inbuilt data types, 
	with the user defined datatypes like struct and classes. 

4> this POINTER
	this pointer comes into scenario when we call any class member function.
	"this" is a pointer(contains address) to the object of which function is member.
	Used when
	A> Member function has a formal parameter having same name as a data member.
	B> To return self reference/value of the object for which member function is called.

5> UNARY OPERATOR OVERLOADING
	Return the object by referance so the expressions like following wont give any compilaton problem
	declaration : One& operator ++();
	Use			: newObj = ++oldObj;
	Postfix
	declaration : One& operator ++(int);
	Use			: newObj = oldObj++;

6> new AND delete OPERATORS
	new and delete are the operators used to allocate(from freestore) and deallocate the memory assigned to the pointers.
	Use:
		int *pInt = new int a;
		int *pIntArry = new int [10];

		// you cannot directly assign double dimentional memory using new.
		int **ppIntArray = new int [10][10]; // illeagal, compiler error
		int (*ppIntArray)[10] = new int [10][10]; // illeagal, compiler error

		delete pInt;
		delete	[] pIntArry;
	(If u delere pIntArry by just 
	 delete	pIntArry;
	 then it will either delete only 1st mememer of array or corrupt the memory(heap))

7> OBJECT SIZE
	sizeof  will return size of the object of class.
	struct and class are same, only differance is 
	1> default members	are private in class while they are public in struct.
	2> While inheriting if access specifier is not provided to base class,
		then if derived class is declared struct then base class is inherited publically.
		While if derived class is declared class then base class inherited privatly.
	
8> ODR-use
	
	Informally, an object is odr-used if 
		its value is read (unless it is a compile time constant) 
		or written
		or its address is taken,
		or a reference is bound to it;

	a reference is odr-used if 
		it is used and its referent is not known at	compile time; 

	a function is odr-used if
		a function call to it is made 
		or its address is taken. 

	If an object, a reference or a function is odr-used, its definition must exist somewhere in the program; a violation of that
	is usually a link-time error.
		
=================================================================================================
=================================================================================================

+===============================================================================================+
|Chapter6: C++ Free Store																								|
+===============================================================================================+

1> new:
	. Allocates memory from the free store(heap)
	. Calls the constructor of an object
	. Returns pointer of type class * and not void * 
	. Could be override in the class 
	
	delete:
	. frees memory pointed by the pointer.
	. calls the destructor of an object to which pointer is pointing
	. could be override in the class. but 
	. never delete pointer twice.

2> Free store exaustion:
	. when maximum memory is already allocated, new returns NULL.
	. To handle this scenario, c++ internally maintains a function pointer _new_handler.
	. new_handler could be set using set_new_handler(void (*fp)());
	  where fp could be pointing to any memWarning/mem freeing function function.
	. ideally memWarning should free some memory so new could return some memory and program continue. 
		As well if can not free memory, should call set_new_handler to point to another mem freeing function
		otherwise current newhandler is called infinitely.

3> Custom new and delete 
	. It is possible to overide new and delete globally.
	
	void* operator new(size_t size)
	{
		
		while(true)
		{   
			void *mem = malloc(size);

			if(mem != NULL)
			{
		   
				cout << "allocating " << mem << " " << size << endl;
				return mem;
			}

			std::new_handler nh = get_new_handler();
			if(nh)
			{
				(*nh)(); 
				// Either free some memory
				// Or set new handler to another freeing function
				// Or set new handler to NULL, so that bad_alloc or its derived could be thrown
			}
			else
			{
				throw std::bad_alloc();
			}
		}   
	}

	void delete(void *mem)
	{
		free(mem);
	}

4> new and delete in class 
	. overided new and delete are always static.

	#include <iostream>
	// class-specific allocation functions
	struct X {
		static void* operator new(std::size_t sz)
		{
			std::cout << "custom new for size " << sz << '\n';
			return ::operator new(sz);
		}
		static void* operator new[](std::size_t sz)
		{
			std::cout << "custom new[] for size " << sz << '\n';
			return ::operator new(sz);
		}

		static void operator delete(void *ptr)
		{
			std::cout << "delete for single object" << '\n';
			return ::operator delete(ptr);
		}

		static void operator delete[](void *ptr)
		{
			std::cout << "delete for array" << '\n';
			return ::operator delete[](ptr);
		}

		int a;
		int b;
	};

	int main() {
		X* p1 = new X;
		delete p1;
		X* p2 = new X[10];
		delete[] p2;
	}

	. this pointer is not valid in new. Obj is still to be created.
	. delete could not be overloaded, there is only one way to destroy object
	. never mix free-delete, new-malloc,  becauase they have different wrapper funtions
		which manipulate data about allocated mem.

	Sequence:
		a> new
		b> constructor
		c> destructor
		d> delete

5> Placement  constructor: Objects at predetermined location:
	. new(ptr) class_name(); will create object of class_name at ptr location.
	. There is no concept of placement delete, that you will have to override :  
	. you will have to use placement destructor to delete same object 
		ptr->~class_name.
	. object created at predetemined location must be delete by placement destructor and vice-versa.
	. Use of placement new, could help in scenario when hardware talks with software via mem-location.
	. As well it is faster than conventional new and delete 
		so you could use pre-allocated memory
		or implement object store


Rule Of 3:  for pre C++11, its just suggestion, not requirement
	if you need 1 of 3 custom impls, you need all among (destr, copy constr, copy assignment operator)

Rule of 5:  after c++11 rule of 3 becomes rule of 5
		if you 
			1. provide any of rule of 3 functions 
			2. or default or delete them,
		then, implcite move copy/assign are not generated  

		move operations are stricter operations than copy
		so, 
		if you define one of move operations
			1. copy operations are generated
			2. but disabled with = delete;

Rule of 0: 
	if your class manages resource like pointer, then prefer RAII by using smart pointers
	this way, default functions provided by compiler automatically take care of the resource
	management by automatically freeing memory in while destroying

	so provide none or all of 5 functions for the resource

=================================================================================================
=================================================================================================

+===============================================================================================+
|Chapter7: Miscelleneous																		|
+===============================================================================================+
1> STATIC DATA MEMBERS
	Used to share common information among objects of same class.
	Defined outside of the class as class is just blueprint of object and doesnt set aside any memory.
	memory for static members is allocated only once.

2> STATIC MEMBER FUNCTION 
	You can call private constr, destr and other functions from static member functions
	Used to manipulate static data only.

	Could be called like <class_name>::<static_function>, which is the correct way, as we call these
	functions to get common info about all the objects of the class.
	
3> CONST MEMBER FUNCTION
	These will never modify any data member of the class.
	constant objects could only call const member functions.

4> CONST MEMBER FUNCTION ARGUMENTS
	Genrerally functions which pass variable by reference should pass it as const so that original
	value does not get modified by programming mistake.

5> CONST OBJECTS
	Only const member functions could be called with the const objects, as they guarntee that they
	will not modify any of data member.
	Only constructor and destructor are automitcally called non-const functions for a const declared object
		- constr and destr both are non-const functions
		- ie. the object is const: its constr and destr can call non-const methods
		- ie. if the data member is const: they cant modify it

6> OVERLOADED ASSIGMENT OPERATOR and COPY CONSTRUCTOR
	c1 = c2;	// default provided assignment operator
	<class name> c3 = c2;	// default copy construtor
	if you want to perform more complex actions while using assignment operator or copy construtor just override them.
	Overloaded = operator
	1> takes const reference as argument so time is not wasted in copying object
	2> returns reference of the calling object using this pointer so that time is not wasted in returing value also
		= operator chained like c4 = c3 = c2 = c1 etc.
		syntax:         one& one::operator =(const one&) 
			// Do not return by const one&. 
					the obj calling = op is not const 
					returning by const ref is bad idea as its allowed to bind temp

			// and its life is only exteneded till ref lives, i.e the catching const ref variable life.
			// and you might accidently return temporary for which compiler might not warn
			// but if your return non-const ref to temprary/local var, compiler will make it hard 
			// in general returning by ref is fragile specially if 
			// 			returning local var // absolutly avoid
			//			returning temp // return/catch by const ref, but its recursive refernces copy might hold to dangling reference
			

	Copy  constructor
	1> takes reference of the object as argument so time is not wasted in copying object, also if u pass it by
	value it will create infinite chain of the copy constructors. Generally compiler gives error if you dont pass value 
	by reference.

	2> Doesnt return anything as it is constructor
		syntax:         one::one(const one&)

7> DATA CONVERSION:
	BASIC to USER_DEFINED
	if u say
		one obj = 1;// will search for one::one(int)
	if u say 
		one obj;
		obj = 1; // will search for one::operator =(int)
	Also in 2nd expmple it is possible, if u dont provide any overidden = operator, compiler will
	search for construtor taking int as argument and will create temporary object and then it uses
		one& operator =(one &) (and not one& operator =(one)) to copy temporary object.
	here if both are provided operator =(int) is preffered.


	USER_DEFINED to BASIC
	To convert 
		int a; one obj;
	   	a = obj; 
	compiler will search for overloaded = operator, when it finds that int class doesnt contain
	int& operator =(one &); it will search for "int" cast operator in userdefined class. So we define 
	int cast operator in user defined class.

	IN SOURCE CLASS
	define a cast operator
	// return type is implicite
	// const func
	operator Target() const { 
		return Target{this->i}; // just templ
	}

	IN DEST CLASS
	define a one argument constructor, copy assignment operator
=================================================================================================
=================================================================================================

+===============================================================================================+
|Chapter9: Inheritance																			|
+===============================================================================================+
	The derived class can inherite all the capabilities of base class as well as can add new capabilities.
	This increases code reusability.
	Protected members behave like private members till child class is derived.
	Private members of base class are not accessible in derived class
	Compiler executes constructor function of base class and then of derived class.
	Derived class could add its own function which override base class functions.
	
	PUBLIC INHERITANCE:
		public and protected members of base become public and protected members of the derived class.
		private members of base class are not accessible in derived class.


	PRIVATE INHERITANCE:
		public and protected members of base become private members of the derived class.
		private members of base class are not accessible in derived class.

	PROTECTED INHERITANCE:
		public and protected members of base become protected members of the derived class.
		private members of base class are not accessible in derived class.

		default access specifier while inheriting class is private.

	MULTIPLE LEVEL INHERITANCE
		When there is vertical level of inheritance i.e base class used to derive is already derived from
		other class, is called multiple level inheritance.

	MULTIPLE INHERITANCE.
		When derived class is derived from more than two base classes.
		syntax:  class derived: public base1, private base2, base3
		third class base3 is inherited privatly as it is default one.

		If base classes contain function with same name, compiler tried to inherite both of these functions 
		which creates ambiguity. Then to resolve the ambiguity just declare which function among two to use
		by saying			
				base_class_name :: function_name; in the class definition.

		Constructors: In case of multiple inheritance. constructors of the base called are called first in
					the order used in the class declaration. There calls are not depend upon order in constructor
					definition.
						Constructor definition
						derived(a,b,c,d,e,f):base1(a,b), base2(c,d), base3(e,f);

					
		Destructors in the class are called exactly in the reverse order of constructors.
		Why constructors are called in order of class declaration because, if we define two constructor who call 
		base class construtor in two differant orders(depending upon order in constructor declaration) but we
		can call destructor only in one way. As it is neccessory to call destructor in only one way, the order
		will not be exactly reverse of constructor if constructors are called in two ways.

	FUNCTIONS THAT DO NOT GET INHERITED
		Zero argument constructor, a destructor, an assignment operator and a copy constructor do not get
		inherited. However if we dont define these, compiler adds them by default in the derived class.


=================================================================================================
=================================================================================================

+===============================================================================================+
|Chapter10 Virtual functions																	|
+===============================================================================================+
Virtual fuctions are called with the pointer to the function.
Virtual functions are called with the pointer to


	
=================================================================================================
=================================================================================================


+===============================================================================================+
|Chapter12: Advance Features																	|
+===============================================================================================+
COMPOSTION OF CLASSES
	It is useful when classes act like datatype.

FREIND FUNCTIONS
	Friend functions are the function which are allowed to access and manipulate private data members 
	of the class outside of the class. Its used when you need to define a function which manipulates/access
	private data members of the two distinct classes.
	class two;	//declaration which is must before prototyping frnd funciton in class one
	class one{
		public:
			friend void accessBoth(one, two);
	}

	class two{
		public:
			friend void accessBoth(one, two);
	}

OVERLOADED << and >> 
	class one{
			int i;
		public:
			friend ostream& operator << (ostream& , one&)
	}
	ostream& operator << (ostream& o, const one& x)
	{
		o << x.i;
	}
	
here statement 
	one obj
	cout << obj; // this is not converted into cout.operator <<(obj) since operator is not member of the ostream class

FRIEND FUNCTION USAGE
	a> To access private data members from non-member functions
	b> To increase versality of overloaded operators.
		Class one{
			public:
				one(int i);
				one operator *(one);
		}
		one obj; 
		obj = obj * 2;// this will call one arg constructor and the overloaded * operator 
		obj = 2 * obj;// as we cant overload int class we use friend function in the class one
					  // friend one operator *(int i, one o); this will do the job

FRIEND CLASS
	All functions of the class become friends.

	Altough friend function violate the law that functions outside class cant access private data members.
	This is why cpp is not pure OO language. Since we cant make function friend till we have source code of class
	it doesnt violate class intergrity.

CONTAINERS and SMART POINTERS


POINTERS to MEMBERS.
	eg
		typedef int (one::*oneFUNC)();
		oneFUNC fn = &one::onefn;
		one o;
		(o.*fn)();

explicit:
	To prevent implicit conversion simple solution is dont define conversion operator, but since there may
	be a constructor defined which could carry out this implicitly. To prevent such conversion we declare
	constructor as a explicit. so until and unless explicitly conversion is specified, conversion is not
	carried out.

mutable:
	Despite of object being constat you may want some of the data members to be changed. Declare such members as
	a mutable. mutable are allowed to manipulate in the const members functions, the only functions could be called
	by const objects after constructor and destructors.

	This does not allow to edit const member of non-const object
	
namespace:
	1> definition is same as of class, except last semicolon
	2> continue over multiple files
	3> can have alternate name
		namespace Mera {}
		namespace Tera = Mera; 
	4> Namespace definitions could be nested, but parent namespace must be at global scope

typeid:
	1> typeid of derived class is different from base
	2> include typeinfo for using typeid
	3> typeid(obj).name prints the type of obj

dynamic_cast:
	1> source must not be void*
	2> source must be polymorphic
	3> source and destination could be out of hierarchy i.e Y shape hierarchy and source and destination could be on the opposite branch side
	4> have to put the if(ptrConvertedIntoDestination) before using the pointer
	5> Normally used to convert base class * to derived class

static_cast: 
	1> performed at compile time
	2> does well defined conversions i.e. between integral types of int,char, float
	3> upcasting
	4> void *ptr conversion, which can not be possible with dynamic_cast
	5> Out of hierarchy conversions are not possible and gives compile time error
	5> Normally used to covert derived class * to base class. which is uneccessory.
		But otherway conversion is as well possible without any compile time error, however, 
		it is undefined behavior to static_cast down a hierarchy to a type that isn't actually the type of the object.
		CRTP uses Base to Derived conversion using static cast

const_cast:
	1> convert const object into non-const type
	
reinterpret_cast
	1> any abnormal, out of hierarchy conversion


=================================================================================================
=================================================================================================

+===============================================================================================+
|Chapter13: Template																			|
+===============================================================================================+
	Template is the mechanism which make possible to use one function or class to handle many 
	different data types. When used with functions its called function template and when used with
	the class its called class template.

	
Function Template
	When we write a different functions such as sort, swap, advance, min, max for different data types
	A> we have to rewrite code
	B> More disk space for program
	C> if any bug, error found in one we have to replicate it in all functions

	to bypass this we write only one template function, which handles all the data types
	ex MinOfTwo:

	template <class T>
	T MinOfTwo(T a, T b)
	{
		T c ;
		c = (a < b )? a : b;
		return c;
	}

	We can use this function even for user-defined data types, just dont forget to override the < operator
	in the class.
	Inheritance and composition provides way to reuse the objects code while template provide way to
	reuse the source code. Standard type conversion are not allowed in the template functions. Compiler first
	looks for the existing instances and if that instance is not found exact new instance is created.
	Whenever compiler comes accross template function is called for a new data type, it creates new copy
	function for that datatype.

	If u want template function behave in other way for some data type then manually override that function.
	
	multiple argument template:
	template <class a, class b class c>
	void fun(T a, T b, T c)

	Macro Vs Template: Its same as inline functions Vs Macro
	A> no type checking of arguments 
	B> if post incremented variable is passed then its replicated in whole macro
	C> no return type specification

Template Class: 
	Single class whos specification would work for all data types, including userdefined data types.
	Ex LL, stack.

	1> template arguments can take default argumensts
	template <class T, int max = 10>
	class stack{
			T a[max];
		public:
	};

	2> function outside of class with return type
	stack<T> stack<T>::fun(stack a)

	3> Can inherite new template from an existing one.
	template <class T>
	class newsample:public sample <T>

	4> If some of the functionality of a template does not depend upon type, it can be put in common base.

	5> Template shoud be used while creating typesafe class which could operate on data of any type.

	1. How template function argument converion happens for const/non-const params
	2. how matching partial specialization is choosen

=================================================================================================
=================================================================================================

+===============================================================================================+
|Chapter3: Graduating to CPP									|
+===============================================================================================+


	
=================================================================================================
=================================================================================================


