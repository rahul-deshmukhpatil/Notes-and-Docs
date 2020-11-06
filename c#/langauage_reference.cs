Types
	Value Types
		integral
			sbyte, byte, short, ushort, int, uint, long, ulong
			var decimalLiteral = 42;
			var hexLiteral = 0x2A;
			var binaryLiteral = 0b_0010_1010;
		floating
			float, double, decimal

		Implicit numeric conversions
			from int's float and longs to double may cause precision loss but not magnitute
		bool
		char unicode 16 bytes

		enum 
			default values start with 0, 
			can have underlying size and custom values
			cant have methods, but see extention methods
			can be converted explicitly from and to underlying type
			Enum.isDefined to check if string is defined
			enum Type : ushort
			{
				None = 0,
				Alpha = 1,
				Beta = 2,
			}
		Enumeration types as bit flags
		public enum Days
		{
			None      = 0b_0000_0000,  // 0
			Monday    = 0b_0000_0001,  // 1
			Tuesday   = 0b_0000_0010,  // 2
			Wednesday = 0b_0000_0100,  // 4
			Thursday  = 0b_0000_1000,  // 8
			Friday    = 0b_0001_0000,  // 16
			Saturday  = 0b_0010_0000,  // 32
			Sunday    = 0b_0100_0000,  // 64
			Weekend   = Saturday | Sunday
		}

		System.Enum :  abstract base class of all enumeration


		structs:
		they are value types and follow value Semantics. they contain the instance of type
		by default copied on assingment, passing to func, return from  func 
	
		readonly structs: cant modify the fields, properies have only read-only acessors
		readonly members: methods, properties, indexers which dont change state of struct
			can apply readonly to methods overridden from base. ie ToString from System.Object
			compiler defined get accessor of auto implemented property is always readonly
		
		you must instantiate struct as it cant be null unless its nullable type value.
		compiler give you implicite default cstor  which inits fields to default values.
		default cstor will be called with new Struct()
		you can explicitely initialize the fields without constructor, but then you must initialize
		all fields in the struct before its 1st usage

		Limitations
			no explicit default contructor
			cstor must initialize all fields
			fields, properties cant have default value except field is static, const or property is static
			cant inherit or be inherited

		pass structs by the ref, in, out if they are heavy
		ref struct
	
	var:	
		its is a implicit, strongly typed, compiler deduced anonymous type
			var i = 10; // int

		if var is used when nullable ref is enabled it C# 9.0 it represent the nullable ref type even if result is not null
		common use is with cstors new declarations

		with c# 9.0 you have target typed new declarations
		List<int> i = new();
		List<int>? i = new();

		// zQueury is anonymous type. see use of new to return it
		// if you return string, then you can use it in foreach statement
		Could be used with the sql like query syntax
		var zQuery = from x in Persons
				where x.Name.StartsWith("Z")
				select new {x.Name, x.Surname}
		foreach (var completeName in zQuery)
		{
			Console.WriteLine($"I am {completeName.Name} {completeName.Surname}")
		}

	unmanaged types:
		simple types, which are just
		1. any of defined intergral, float, bool type + char
		2. enum
		3. pointer
		4. any struct which contains only unmanged type

		public struct MyList<T>
		{
			T a;
			T b;
		}

		MyList<int> lI; // Unmanaged
		MyList<Object> lO; // managed as Object is not unmanaged

		public struct UMyList<T> : unmanaged
		{
			T a;
			T b;
		}
		UMyList<Object>  a; // Not possible, see unmanaged constrain
	
	Default values:
		0 for integrals
		0.0 for floats
		false for bool
		'\0' for char
		E(0) for enum
		struct respective fields have thier default values
		ref type : null
		nullable value type: instance whose hasValue is false and Value property is undefined
				its also null value of nullable value type

		default operator 
		int i = default(int);
		default literal
		int i = default;
		
		implicit default/parameter less  cstor gives default value
	

c# Keywords
	reserved : cant use as identifier, but can if used @ at beginning ie @if, @while are valid
	contextual : cant used as identifier in particular context, outside of context its ok to use as identifier name

	finally:
		finally block appears after the try. It always runs in case of normal execution of try block, break, goto, continue, return.
		you can clean up resources allocated in try block in finally block ie. close the file handle if its fH was succesfully opened.
	
		handled exceptions : guranteed finally block executions
		unhandled exceptions : depends on how exception unwinding happens i.e depends on how your computer is setup

		one sure way is to handle exception in catch in same function or up in function stack.
		if exception is not caught then it depends upon if OS triggers stack unwinding operation 

	throw and rethrowing exception:
		rethrow = plain "throw;" will rethrow the exception it received
	
	as:
		convert give expression value to ref type or nullable value type
		if conversion is not possible returns null.
		unlike cast operation does not throw exception
		used for reference, boxing, unboxing, nullable conversions
		for user defined coversion you cant use "as", use cast operator


	null:
		represent the null reference, one which does not refer to any object
		Person p; // is null
		represents default value of the reference types
		except for value types which are nullable value types ie T?, int?, long?

	nullable value type:
		T? represent all values of underlying value type T, and one more value "null"
		so nullable bool ie bool? can have false, true, null
		they are instance of System.Nullable<T>

	nullable reference type:
		introduced with c#8.0
		available in  nullable aware context along with null static analysis warning and null forgiving operator

		nullable aware context
		T is equal to null is not allowed. must initialize with non-null before use
		T? could be initialized/assinged null, but required to check against null before dereferencing
		T? m; is non null after applying null-forviging operator to m!

		String s;
		String& s ;
		seems like this is compiler feature as Nullable and plain type are stored as String ie same type
	
	stackalloc
		to allocate block of memory on stack
		cant free, automatically freed when function returns
		not garbage collected
		Span<int> numbers = stackalloc int[length];

	unchecked
		compiler gives error if all terms in expression are constant or known at compile time and expression causes overflow
		to supress this, use unchecked.

		const int a = int.MaxValue
		int b = a + 10; // a and 10 are known at compile time
		int b = unchecked(a+10); // no compilation error

	base
		to 
		1> call the exact base class constructor among many base class constructors with initializer list sytax in c++
		2> to call base class method implementation from  derived class
		
		in c# base means only immediated base class
	
	extern
		to declare a method that is implemented externally

	params
		method parameter which represents variable number of parameters
		No other parameter after params
			1. while calling you can call with list of comma separated
			2. array of type
			3. empty parameters, then Length of params will be 0

		public static void Method(params int[] p);
		public static void Method(object int[] p);
		object[] myObjArray = { 2, 'b', "test", "again" };
		Method(myObjArray);
	
	readonly
		instance field cant be assigned after declaration or after constructor assignment
		readonly struct is immutable
		readonly member method cant change state
		readonly ref return type can not be modified
	
	sealed
		prevents class from inheritance
		when applied to virutal methods and properties in base class, derived class can not override them
		When applied to a method or property, the sealed modifier must always be used with override.
		structs are implictly sealed
		it is an error to use abtract with sealed as abstract is only meant to be inherited by another class

	volatile
		variable could be modified by the another thread and not meant to be optimized for the reads and writes by compiler


Operators
	() (invocation) : this is function or delegate invocation operator
	.. is range operator
		int[] subset = numbers[start..(start + amountToTake)];
		You can omit any of the operands of the .. operator to obtain an open-ended range

	[^] this is index from end operator
		int[] inner = numbers[margin..^margin];

	Type testing operators
	
	is 
		(E is T)
		returns true if runtime type of the expression E result is non null and is convertible to type T
		by reference conversion, boxing conversion or unboxing conversion
		E is T v : saves result of E into variable T v
	
	as 
		E as T
		if result of runtime expression E is convertible to T returns converted result otherwise null
		T must be of nullable value type or reference

		is same as =>  E is T ? (T)(E) : (T)null

	Cast expression
		checks if convertions from (T) E is posssible. if no explicit conversion present at compile time, its a compile time error
		at runtime it will throw an exception if cast is not possible.

	
	typeof
		The typeof operator obtains the System.Type instance for a type.
		void PrintType<T>() => Console.WriteLine(typeof(T));
	Type testing with the typeof operator
		object b = new Giraffe();
		Console.WriteLine(b is Animal);  // output: True
		Console.WriteLine(b.GetType() == typeof(Animal));  // output: False

		Console.WriteLine(b is Giraffe);  // output: True
		Console.WriteLine(b.GetType() == typeof(Giraffe));  // output: True
	The is, as, and typeof operators cannot be overloaded.


	Implicit and Explicit conversion	
		implicit dont need cast converstion syntax
		implicit dont throw, so same for user defined implicit conversions

		public static implicit operator byte(Digit d) => d.digit;
		public static explicit operator Digit(byte b) => new Digit(b);
	
	Pointer operators
		they work in unsafe blocks and compiled with unsafe enabled
		*, &, for array pointers [], 
		+, - with ints, ++, -- 
		subtract two pointers
		comparision of pointers is comparison of their unsinged integers value
	
	Lambda
		Action del = () = a[0] = 0;
	Lambda expressions
		Action del = () = {a[0] = 0;};
		 Func<int, int> square = x => { x *x;}
	Lambda tuples
		Func<(int, int, int), (int, int, int)> doubleThem = ns => (2 * ns.Item1, 2 * ns.Item2, 2 * ns.Item3);
	
	Lambdas with the standard query operators
		
		int oddNumbers = numbers.Count(n => n % 2 == 1);
		var firstNumbersLessThanSix = numbers.TakeWhile(n => n < 6);

	await operator
		for the code in async methods
		within async method, you cant use operator in the body of synchronous function
		Basically you call four with one of the  .net Operand
			ValueTask => void returns
			ValueTask<ResultT> returns System.Result
			Task	=> void  returns
			Task<ResultT> => returns System.Result
		
		any exception thrown in the await operand method is rethrown

	@ special character serves as a verbatim identifier	
		1. when prefixed to keywords can use them as identifiers
		2. when used with strings, turns out the hexadecimal, \\ and unicode characters literally as characters

	compiler options	
		There are no object (.obj) files created as a result of invoking the C# compiler; output files are created directly. As a result of this, the C# compiler does not need a linker.


