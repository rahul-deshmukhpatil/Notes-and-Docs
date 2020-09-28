
io manipulators
	The manipulators that are invoked without arguments are implemented as functions that take a reference to a stream as their only argument.  are the only addressable functions in the standard library. (since C++20)
	The manipulators that are invoked with arguments are implemented as functions returning objects of unspecified type. eg  std::cout << std::setw(10);

std::endl vs "\n"
	std::endl causes flush. This is costly operation. In many implementations, standard output is line-buffered, and writing '\n' causes a flush anyway, unless std::ios::sync_with_stdio(false) was executed. In those situations, unnecessary endl only degrades the performance of file output, not standard output.

Double dispatch
	Double Dispatch in C++ is a mechanism that dispatches a function call to different concrete functions depending on the runtime types of two objects involved in the call. 
	Single dispatch is handled by the c++ virtual functions. But virtual functions can not overload properly at run time as overloading is static time and could be done at only compile time.



C++ partial class and function template
	you can not overload class template. You can always use partial template instead of overloading. Just pass void as parameter you dont want to pass if at all any.

	template <typename Key, typename Value>
	class KeyValuePair {};

	//Full spec
	template<>
	class KeyValuePair<std::string, int> {};

	//partial spec
	template<typename Key>
	class KeyValuePair<Key, int> {};
	template<typename Value>
	class KeyValuePair<std::string, Value> {};

	//derive from base class
	template <typename Key>
	class KeyStringPair : public KeyValuePair<Key, std::string> {};

	while you can not have partial template function. Think of use case and you will find you can use function overload instead of partial template function.


