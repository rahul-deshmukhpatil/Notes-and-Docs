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


