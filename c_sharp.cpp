https://docs.microsoft.com/en-us/archive/msdn-magazine/2001/july/c-csharp-what-you-need-to-know-to-move-from-c-to-csharp
https://docs.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-2008/yyaad03b(v=vs.90)?redirectedfrom=MSDN
https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/
https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/types/boxing-and-unboxing

Classes vs Struct
class can inherit from only 1. Can support multiple interfaces
struct cant inherit and no explicit default constructor

Arrays
array is a class with methods
char[10] array;

Boolian are separate type and not implicitely converted to int

long is 64 bit

Classes passed by reference and structs unless mentioned passed by value

switch case does not fall through next case

deleages are typesafe and secure function pointers in C++

base keyword is used to call base class method
virtual or abstract methods need to be declared with the override keyword

new modifier is required explicitely to hide the base class inherited members

Preprocessor directives are used for the conditional compilation, no headers are used

finally : keyword to executed code regardless of exception is thrown

typeof operator 


https://docs.microsoft.com/en-us/archive/msdn-magazine/2001/july/c-csharp-what-you-need-to-know-to-move-from-c-to-csharp

Moving to a Managed Environment
	Dont control where objects are created on heap. Cant take address
	Simple types on stack
	Class on heap
	garbage collector will take back storage once no longer referenced but finalization is nondeterministic
	No multiple inheritance as its difficult to implement in managed env and generics are not part of framework
	c# types are mapping to underlying CLR types
	The types in C# are determined not by the language, but by the common type system. you can derive c# object from Visual basic
	but then you will have to restrict to use the common language subset ... of features shared by all .NET languages
	No need of type discovery or late binding as they are inbuilt in langauage
	Enum and properties are first class members of the language
	fully supported by the underlying engine, as are events and delegates (type-safe function pointers)

Traps:
	no semicolon after class
	main == Main

Reference vs value Types
	values types : simple types + struct
	reference type: variable on stack but refer to object in the heap
	value types and ref types are passed to function as respective.

structs
	are value type and contain light weight objects
	no inhertence, and default members are public
	structs are value types and passed by value
	are sealed : can not derive from or have any other base class than System.ValueType which is derived from Object

Everything Derives from Object
	The Object class offers useful methods, such as ToString
	System.WriteLine : The method is overloaded to take a string and an array of objects
	WriteLine will call the virtual method Object.ToString on each of the objects
	Default implementation of ToString returns name of the class
	What happens if you pass integer values to WriteLine? You can't call ToString on an integer, but the compiler will implicitly box the int in an instance of Object whose value will be set to the value of the integer. When WriteLine calls ToString, the object will return the string representation of the integer's value

Reference Parameters and Out Parameters
	value types are passed by the value. So change by the function is not visible in callee.
	so use ref when you want and callee also must use keyword ref to call

	declaration : public void func(ref int a, ref int b)
	call : func(ref c, ref d)

	Only single return value is possible, so you need reference for out parameters
	above c and d must be initialized as c# does not allow un-initialized value types
	ie definite assignement. used before assignment

	So use the out ref
	declaration : public void func(out int a, out int b)
	call : func(out a, out b)

Calling New
	new will still allocate the value types on the stack
	you	can avoid new for structs but new will call the constructor
	and since definited assigment is the rule, you must initialize all memebers of the struct before passing struct to any function
	otherwise program will not compile


#Concepts
Constructors
	Have same name as of class
	no return type
	can use the expression body syntax

Static Constructors
	only called by the CLR before any instance created or static members is referenced
	there can be only 1 static constructor, which cant be overloaded or inherited
	all static members are default initialized if not static constructor
	also they are called when static method related to when event or delegate is envoked (and not when assigned)
	static constructor throwing exception is not called again and members remain uninitialized
	TypeInitializationException will be thrown if cant initialize type or unhandled exception occurs in static constructor
	static readonly : are constant statics initialized at the time of declaration or in constructor
	initializing static members when declaring rather than through static constructors could save runtime

Expression body syntax
	constructor
	public Person(string name) => Name = name;

	read only property
	public string FirstName => name;

	property
	public string FirstName
	{
		get => name;
		set => Name = name;
	}

	method
	public string Concatinated() => $"{name} {surname}".Trim()

	indexers
	public string this[int i] 
	{
		get => type[i];
		set => type[i] = value;
	}

	finalizers ie destructors
	public Person() => System.Console.WriteLine($"Person is dying : {name}");

Properties
	first class members of the class
	Easy to encapuslate the private members while giving get set access to clients

# Questions
Why structs are more efficient than classes
	https://stackoverflow.com/questions/13049/whats-the-difference-between-struct-and-class-in-net
	value type lives on stack, reference type variable lives on stack which contains reference or pointer to heap memory where actual body of the 
	reference type lives

	value types memory is freed automatically and deterministic
	refernce types freed at runtime after all refernces get exausted and its still non-deterministic when they are freed

	struct have default public access specifier, class have private?
	structs cant be inherit from except from System.ValueType
	struct can not be base class either : ie sealed
	Abstract and sealed modifiers are not allowed and struct member cannot be protected or protected internals.
	No abstract or virtual members. Only override the methods from the System.ValueType (or System.Object ? check)
	A struct can implement interfaces
	A struct can be used as a nullable type and can be assigned a null value.
	
	struct is made to copy the whole object efficiently
	class are big and made to copy only reference. So any change via one reference to same object is visible via another reference variable

	https://stackoverflow.com/questions/7484735/c-struct-vs-class-faster
	Do not define a structure unless the type has all of the following characteristics:

	It logically represents a single value, similar to primitive types (integer, double, and so on).
	It has an instance size smaller than 16 bytes.
	It is immutable.
	It will not have to be boxed freque

Why int is boxed to object while passing to the WriteLine
	https://stackoverflow.com/questions/27132042/is-boxing-involved-when-calling-tostring-for-integer-types
	WriteLine accepts the string and array of Objects. To convert value type into object you box it


Boxing and unboxing
	https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/types/boxing-and-unboxing#:~:text=Boxing%20is%20used%20to%20store,value%20into%20the%20new%20object.
	Boxing is used to store value types in the garbage-collected heap.
	Boxing allocates the mem on heap and copy the value into new object
	Explcite boxing is possible but never required	

	Unboxing is reverse way. You copy the value in the object to the value type variable
	conversion from object to value
	Be careful object might have null reference can cause NullReferenceException
	And convert to correct type of value type otherwise InvalidCastExcpetion


	



