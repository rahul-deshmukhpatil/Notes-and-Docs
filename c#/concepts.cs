https://docs.microsoft.com/en-us/archive/msdn-magazine/2003/july/c-csharp-what-you-need-to-know-to-move-from-c-to-csharp
https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/
https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/types/boxing-and-unboxing

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
		set => name = value;
	}

	method
	public string Concatinated() => $"{name} {surname}".Trim();

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
Auto-Implemented Properties
	compiler creates a private, anonymous backing field that can only be accessed through the property's get and set accessors.
	public double TotalPurchases { get; set; }

Boxing and unboxing
	https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/types/boxing-and-unboxing#:~:text=Boxing%20is%20used%20to%20store,value%20into%20the%20new%20object.
	Boxing is used to store value types in the garbage-collected heap.
	Boxing allocates the mem on heap and copy the value into new object
	Explcite boxing is possible but never required	

	Unboxing is reverse way. You copy the value in the object to the value type variable
	conversion from object to value
	Be careful object might have null reference can cause NullReferenceException
	And convert to correct type of value type otherwise InvalidCastExcpetion

Overloading	
	in refs are read only.
	its not possible to oveload based on the in,out and ref
	its possible to overload the base type and in-ref and plain type

	you can specify the in-ref while calling to select in-ref overload, otherwise plain value based overload has a priority

Interface
	A group of related functionalities. Its signatures to services the implementer of interface provides

	Can have:
		Methods can have default implementation, event, properties(without implement/body), indexers 
		static methods must have definition
		static constants, fields and operators 
		can have static constructor for the static feilds
	
	Cant have
		instance fields, properties or properties like events
		instance constructor or finalizer 
	
	interface members are public by default

	class or struct can inherit multiple interfaces

	class inheriting interface must define the non static interface methods which dont have implementation
	if base class implements the interface derived inherits that interface implementation (if you override the base class implementation
	the method called via interface will still call to the base class method. i.e interface methods are not implicitely virtual)	

	properties and indexers can define extra accessors for property or indexers
	however if class explicitely implement the property or indexers, accessors must match : Not clear, do you mean signature should match?
	interface properties does not define auto-implemenation of variables in the interface. It goes to the class that implements the interface

	interfaces can inherit.
	class must implement the interface and base interfaces of immeadiate interface
	class could be implicitely converted to interface or base interface of immeadiate interface
	a class can inherit an interface via multiple paths of interface inheritances or class multilevel inheritance
	but implementation can be done only once

	if you inherit a class from base class you inherit the interface implementation from base class. you can not override the base clas
	interface implementation in dervived class.
	howeve derived class can only re-implement the virtual interface members. Non-virtuals are used only from the base class

	default implementation in interface is inherited by classes, repeated above.
	implementations defined in the interfaces are virtual (could be silent virtual) and the implmenting class may override them

	a base class can also implement (re-implement?) the interface members using virtual members and derived class can change the behavior
	by overriding virtual member
	https://stackoverflow.com/questions/13516264/can-a-child-class-implement-the-same-interface-as-its-parent

	interaces cant be instantiated directly. A class or struct implements it and class objects could be casted as interface type objects.

Explicit Interface Implementation
	What if two methods or two properties or Property and Method is two different interfaces have same name, no default implementation
	and these two interfaces are inherited by a single class.  

	You use explicit interface format ie. IPoint1.A {get; set;} and IPoint2.A {get;set;} syntax to implement the
	interface member with common name A.

	An explicitely implemented interface methods can not be called via class object, unlike default implemented members. 
	so its better if your names do not clash or re/-implement the interface by calling another implementation method in class

Extension Methods
	To extend exisiting class with the new methods outside of it (without deriving, recompiling or modifying original type)
	with static methods which could be just called as member methods
	Useful if you want to implement an interface to existing system interface for struct

Enum constraints
	you can also specify the System.Enum type as a base class constraint. The CLR always allowed this constraint, but the C# language disallowed it.


Value Semantics:
	Value types. they contain the instance of type
	by default copied on assingment, passing to func, return from  func

default value expression
	default operator usage.. int i = default(int)
	default literal usage .. void func(int i = default) // compiler knows the type

Null-conditional operators ?. and ?[]
	evaluate expression to 
	1> null,  a is null in expression a?.x or a?[x]
	2> valid value if a is not null in a?.x or a?[x], but a?.x or a?[x] might throw any valid exception such as IndexOutOfRangeException
	
!null-forgiving operator
	used to suppress the compiler warning that about the expression x which is sure to be null at static time as not-null i.e null! or x!
	so compiler please forgive me for passing null and dont complain

https://docs.microsoft.com/en-us/dotnet/standard/garbage-collection/fundamentals
https://docs.microsoft.com/en-us/dotnet/standard/managed-code
