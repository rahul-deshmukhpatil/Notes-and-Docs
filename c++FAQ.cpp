+===============================================================================================+
|Chapter0: 	Very fundamentals of c++															|
+===============================================================================================+
0.1	why do you need default constructor
		In case of composite class or inherited class default constructor is called for these child
		classes first. eg.
		class A;
		class B;
		class C:public A
		{
			B bObj;
			public:	
			B()
			{
				//class A constuctor will be called to initialize part of A in C.
				//class B consturctor will be called to initialize 'bObj';
			}
		};




+===============================================================================================+
|Chapter5: Object Oriented Fundamentals															|
+===============================================================================================+

5.2	OO can handle changes effectively.
5.3 Benifits of using OO
		Multiparadigm language: Use programming style sutaible for the task
		.Porcedural langauages are just: structured analysis, 	design  and
		program. OO handles changes effectively
	
		Perf and memory efficient if designed efficiently
		Low level access to the skilled programmers to exploit system specs.
		
		Superset of C
	
		Developement and maintainance time is less with STL and boost.
		Upgrade 3rd party STL libararies for performance, latest updates without any break.
		
		Great developement community

5.4 Fundamental Concepts of OO Lang
		Object, classes and inheritance. And polymorphism and dynamic binding
		fecilitated by the inheritance.
		Polymorphism supports the functonality of the one type of object to appear
		like another(its base) type object. Other are overloaded functions.
		Dynamic binding is calling function based on the actual object type.

5.5	Class importance.
		Object/Class Keeps the state(data) and behaviour/service(functions) togather. 
		Whenever need to change the behaviour of system according to changed business 
		requirement you need to change just one file of related class.

5.7	Desirable Qualities of Object
		Alive, active and lives its full life providing service, rather than just
		sitting in some memory.

5.8	Object Vs struct, function, module
		Struct: class could be extended. Mature structure grows to class. Subtyped-inherited.
		function: all are grouped togather. Changes as per requirement are concentrated in a file
		module: class uses same funtions and inline functions for set of instances of class.

5.9 Purpose of composition
		Re-use source code according to task to perform. Assemble components rather than
		crafting new one.

5.10 Purpose of inheritance
		Subtyping/Specialisation and dynamic binding, polymorphism. Code reuse without any code 
		copying	with common part in base class.



			
			

