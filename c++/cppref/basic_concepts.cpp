declaration: has name and type, declare properties
definition: define properties


Names Look up
	Unqualified Name Lookup : wihout :: on left side
		in order of scope
			block
			function
			class
			namespace
			global namespace
	Qualified Name Lookup with namespace/class::var
		searches var within class or namespace

	
ADL argument dependant lookup
	- only occurs for the unqualified namespace lookup

	- compiler searches for symbol in current or parent and global scope
		if non function entity is found
			ADL is not performed
	
	- if nothing or function is found in current/parent/global namespace
		ADL is performed
	
	ADL does the search in
		- namespaces of each argument 
			- namespace of base classes of arguments
		- if its template func and type is class member,
			- search in the class namespce
		- for class templates, the namespaces of template arguments
		- for pointers arrays, in the class of underlying element

	then for all candidates it find, it does the overload resolution

Elaborated type specifier
	specify the keyword explicitely class or enum to unhide from variable of same name as of class

		class T
		{
		public:
			class U;
		private:
			int U;
		};
 
		int main()
		{
			int T;
			T t; // error: the local variable T is found
			class T t; // OK: finds ::T, the local variable T is ignored
			T::U* u; // error: lookup of T::U finds the private data member
			class T::U* u; // OK: the data member is ignored
		}

	if you specify something as class, and class definition is not available, then that is declaration
	of class definition exists somewhere afterwards.
	eg.
		main () { class A a; } // declaration of A and def of a
		class A {};

	cant apply to template typeparameter T below.

	template<typename T>
	class Node
	{
		friend class T; // error: type parameter cannot appear in an elaborated type specifier;
						// note that similar declaration `friend T;` is OK.
	};
 	
	

Address of an overloaded function
	void f(int){}
	void f(double){}

	struct A{ void f(int){}; void f(double)};

	void (*pf)(int) = f; // f(int) choosen
	void (&rf)(double) = f; // f(double) choosen
	
	void (A::&rmf)(int) = f; // A::f(int)
	void (A::*rmf)(double) = f; // A::f(double)

	void g(ptr_if, ptr_df); // declare
	g(f,f); // f(int), f(double)
	
	template<void (*pf)(int)>
	Temp {};
	Temp<f> a; // pf = f(int)
	

