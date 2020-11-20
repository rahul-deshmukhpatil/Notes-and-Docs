CTS  defines how types are defined, used managed during runtime. Its also part of the runtime support for cross language intergration

. framework for cross language intergration, type safty and high performance
. OO Model for the implementation
. Defines rules which language m,ust follow so Objects in diff language could interact
. Primitive types lib with definitions for the Boolean, Byte, Char, Int...

Types in .Net
	Value Types or referecne types
	ValueTypes: stored in stack, small in size, 
	Reference types: reference to actual type object on the heap

	Type categories

	class,
		one or more characterstics of sealed, implements, abstract, inherits, exported
		derived from System.Object implicitely
	struct
		derived from Systm.ValueTypes which is inturn derived from  the System.Object
		all primitive types ie Boolean, Byte, Char, ....Int32, Float, Decimal are defined as struct
		cant inherit from any other type and cant be inherited ie. sealed 
		Boxed : when you pass value type to the function accepting System.Object
		Unboxed: converts back isntance of a class back to instnace of value type
	enum
		System.Enum
		have underlying types
		Flags attibute you have a bitfield behavior
	interface
		define "can do" or "has a" relationships
	delegate
