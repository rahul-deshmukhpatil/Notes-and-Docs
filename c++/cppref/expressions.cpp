Expressions
	has operand and operator

	produce output which
	value category	: lvalue, rvalue
	type 			: int, double, class type


	operators percedence
		conversions:
			special operators : with name
			casts
			cstyle cast
			implicite and explicite conversion
		new delete
		Other
			compile time constant expressions
			sizeof
			alignof
			typeid
			throw expression
			noexcept
	
literals : are const values of basic data types

primary expression: 
		literals 1, 1.0, 'a' etc
		dont have operand

Full-expressions:
		either braced init list int a{5}, vec{a, b+c, d}
		or parentisized int a(5), vec(5, 0);

Potentially-evaluated expressions
	which gets evaluated during runtime
	except : sizeof, alignof, typeid, noexcept: which dont get evaluated at runtime

Discarded-value expressions
	foo(); // The return value of foo() is discarded
	x + y; // The result of the addition is discarded

	Left Operand of Comma Operator:
	a = b, c = d; // The result of (a = b) is discarded
	
	Explicit Void Cast
	(void)important(); // Explicitly discarding the return value

	Handling [[nodiscard]]
		(void)important(); // Suppresses nodiscard warning
		[[maybe_unused]] auto&& unused = important();

		Using std::ignore (proposed for C++26):
		std::ignore = important()

		Using [[discard]] (proposed for C++26):
		[[discard]] important();

			





		



