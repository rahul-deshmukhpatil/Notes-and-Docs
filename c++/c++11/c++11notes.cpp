
====================================================================================
Strongly Typed Enums:
	// this code will compile (if your compiler supports C++11 strongly typed enums)
	enum class Color {RED, GREEN, BLUE}; 
	enum class Feelings {EXCITED, MOODY, BLUE};
	
	The use of the word class is meant to indicate that each enum type really is 
	different and not comparable to other enum types. Strongly typed enums, enum 
	classes, also have better scoping. Each enum value is scoped within the name 
	of the enum class. In other words, to access the enum values, you must write:

	Color color = Color::GREEN;
	if ( Color::RED == color )
	{
	    // the color is red
	}

	Enum classes have another advantages over old-style enums. 
		1> You can have a forward declaration to a strongly typed enum, meaning that you can write code like:

			enum class Mood;
			void assessMood (Mood m);
			// later on:
			enum class Mood { EXCITED, MOODY, BLUE };

		2> you can set the size of your enum--you can use any signed or unsigned integer type. 
			It defaults to int, but you can also use char, unsigned long, etc. 
			This will ensure some measure of compatibility across compilers.

			// we only have three colors, so no need for ints!
			enum class Colors : char { RED = 1, GREEN = 2, BLUE = 3 };

====================================================================================
<cstdint>

	 In C++11, the C99 header file stdint.h has been included as cstdint. 
	 It enables to have more specific integer types uint32_t, int64_t etc.
	 which could be provided as type of above strongly typed enums
	
====================================================================================
nullptr
	In C++11, nullptr is a new keyword that can (and should!) be used to represent NULL pointer
std::nullptr_t
	


########################################################################################

Member function templates:
	1> Destructors and copy constructors cannot be templates, but other special member functions can be
	2> A member function template cannot be virtual, and a member function template in a derived class cannot override a virtual member function from the base class.
		class Base {
			virtual void f(int);
		};
		struct Derived : Base {
			// this member template does not override B::f
			template <class T> void f(T);
		 
			// non-member override can call the template:
			void f(int i) override {
				 f<>(i);
			}
		};

	3> A non-template member function and a template member function with the same name may be declared. In case of conflict (when some template specialization matches the non-template function signature exactly), use of that name and type refers to the non-template member unless an explicit template argument list is supplied.
		template<typename T>
		struct A {
			void f(int); // non-template member
			template<typename T2> void f(T2); // member template
		};
		 
		int main()
		{
			A<char> ac;
			ac.f('c'); // calls template function A<char>::f<char>(int)
			ac.f(1);   // calls non-template function A<char>::f(int)
			ac.f<>(1); // calls template function A<char>::f<int>(int)
		}
	
