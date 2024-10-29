Templates
	- class
	- function
	- variable
	- template alias
	- concept

Template params could be
	- type
	- non-type values i.e int, float
	- template template types

When template class objects or function calls are made,
	- template args types are deduced and substibuted for the template params
	for the specializaion
	- specilization could be
		- full
		- partial : only for class and template variables

	- When object is used or function is called where
	- complete object definition or function definition is needed
	- template is explicitely specialized or explicitely instantiated

	- Identical definitions are merged at the link time

	Explicite instantiation
		template class std::vector<int>;
		template int max<int>(int, int);

		max<int>(5, 10);

	Implicite instantiation
		std::vector v = {1,2};
		std::vector<int> v = {1,2};

		max(5, 10);

	Explicite instantiations create definitions in the lib, which are readily available
	to use and link against when libs are used reducing compilation time

	
