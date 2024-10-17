functions have
	- type
	- name
	- parameter list  (after array-to-pointer and function-to-pointer transformations)
	- cv qualification (for non-static member functions)

but function type does not have cv qualification
	i.e function can return const/volatile value
	but you cant say function itself is a const type or 

	to be explicit: the const/volatile class member functions, the object calling them is a const/volatile
	not that function is const volatile, this is why only non-static funcions can have cv ref

	may be this is due to functions are not objects. and only objects could be const/volatile,
	so functions may have type and are only addressible

	const int func();  // Valid: returns const int
	const (int func());  // Invalid: attempting to create a const function type

functions are not objects, no arrays of actual functions.
though functions pointers and references are allowed: functions are addressable

functions are addressible:
	Functions and references to functions are not function object types, 
	but can be used where function object types are expected 
	due to function-to-pointer implicit conversion.

	you can pass any of below to in the parameter list, where functor is expcted
		1. lambda
		2. function pointer/reference
		3. functor
