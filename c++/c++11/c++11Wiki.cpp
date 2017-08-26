RunTime performance:
	1> Rvalue references
		Rvalue references are used for the move constructor syntax.
		These are temporary objects, which are passed as argument to the constructor,
		which are going to destroyed after constructor gets executed

	2> constexpr
		These are static time evaluated expressions or functions.
		constexpr functions do not take variables as argument, arguments to constexpr functions
		must be constexpr themself

Build Time:
	1> extern templates
		With extern in front of template variable declaration, the instantition of the template
		class is not done assuming that it is done in other translation unit.
		This is analogous to extern variables.

Usability
	1> initializer_list:
		Now for the vector we can pass initializer list to insert multiple elements.
		A special constructor callsed initializer_list constructor accepts a std c++ type
		std::intializer_list<>. 
		This list is statically created, can not be modified and passed as referece to the constructor
		or function (yes it could be passed as parameter to function as well). 


	2> Uniform initialization:
				struct BasicStruct {
					int x;
					double y;
				};

				struct AltStruct {
					AltStruct(int x, double y) : x_{x}, y_{y} {}

					private:
						int x_;
						double y_;
				};

				// Calls initilization of class members in order, type conversion
				// conversions are applied wherever needed
				BasicStruct var1{5, 3.2};

				// Calls one argument constructor as it is provided 
				AltStruct var2{2, 4.3};

				struct IdString {
					std::string name;
					int identifier;
				};

				IdString get_string() {
					return {"foo", 42}; //Note the lack of explicit type.
				}
	
		list initializer constructor takes priority over other forms of constructor.
		std::vector<int> the_vec{4}; // inserts the 4 in vector (does not call 1 argument size constructor for vector)

	3> Type inference:
			auto : to infer type of the complex types such as 
					auto rev_bind = std::bind(&some_fun, _2, _1, some_obj);
					rev_bind();

			decltype:
				const vector<int> v{1, 2};
				decltype(v[1]) b = 1; // b has type const int&, the return type of
                          //   std::vector<int>::operator[](size_type) const
				decltype((c)) f = c;  // f has type int&, because (c) is an lvalue
		
	4> Range based for loop:
			vector<int> v;
			for(auto i: v)
			{
			}

	5> Lambda: anonymous functions
			[capture](parameters) -> return_type { function_body }
			[](int x, int y)->int {return x+y;} // ->int is return type could be ommited 	

	6> Additional function type: Trailing return type as in case of lambas above
			template<class Lhs, class Rhs>
			auto adding_func(const Lhs &lhs, const Rhs &rhs) -> decltype(lhs+rhs) {return lhs + rhs;}
			Use of the keyword “auto” in this case is only part of the syntax and doesn't perform automatic type deduction.[14]

	7> Object construction improvement:
			Constructor could call another constructor of same class ie. constructor delegation
			c++ allows to inherit the base class constructors with keyword 'using BaseClass::BaseClass'
			This will inherit all the constructors (or none if not provided).
			Also, an inherited constructor will be shadowed if it matches the signature of a 
			constructor of the derived class, and restrictions exist for multiple inheritance: 
			class constructors cannot be inherited from two classes that use constructors with the same signature.


			For member initialization, C++11 allows this syntax:
			class SomeClass {
			public:
				SomeClass() {}
				explicit SomeClass(int new_value) : value(new_value) {}

			private:
				int value = 5;
			};

			Any constructor of the class will initialize value with 5, if the constructor 
			does not override the initialization with its own. So the above empty constructor 
			will initialize value as the class definition states, but the constructor that takes an int 
			will initialize it to the given parameter.
			It can also use constructor or uniform initialization, instead of the assignment initialization shown above.

	8> final and override:
			With override keyword for the derived class virtual function, compiler checks a
			virtual function with same signature is present in the base class.

			With final keyword in base class, derived class is prevented from overriding the
			base class virtual function. Non virtuals can not have override or final.

	8> nullptr : is object of type nullptr_t a new type.
			With C, NULL was defined as 0 or ((void *) 0).
			But C++ forbids implicit conversion from void* to other pointers
			so in C++, NULL is defined as 0;
			So in below overloaded functions function with int paramter is called
				void fun(char *);
				void fun(int );
					
				//call
				fun(NULL); // calls int variant

	9> Strongly typed enums
			With C++03, enums and intergers were inter convertible, could be assigned to each other.
			As well underlying type of enums was implemention defined
			With C++, enum class Error : unsigned short {};, enums are strongly typed, with no
			interger conversion and underlying type of enum could be defined.

	10> Right angle bracket in templates
			std::vector<SomeType<SomeOtherType>> x1;  // Gives error for as  >> is treated as insertion operator

	11> explicit for conversion operators:
			explicit was allowed with the constructors only to prevent the non intended use of constructors.
			now that is also allowed with other operators.

	12> Template aliasing
			now templates could be given meaning full name depending upon thier specilization.
			template <typename First, typename Second, int Third>
			class SomeType;

			template <typename Second>
			using TypedefName = SomeType<OtherType, Second, 5>;

			The using syntax can be also used as type aliasing in C++11:
			typedef void (*FunctionType)(double);       // Old style
			using FunctionType = void (*)(double); // New introduced syntax

