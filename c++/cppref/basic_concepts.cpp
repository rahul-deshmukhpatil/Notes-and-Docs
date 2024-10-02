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

