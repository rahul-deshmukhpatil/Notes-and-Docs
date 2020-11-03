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
	

