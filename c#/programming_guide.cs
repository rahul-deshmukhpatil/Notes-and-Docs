inside c# program
	coding convention	
		Naming Conventions
			prefer namespace rather than importing them via using
		Layout
			add a line between Property and Method definition
			one declaration per line
			indent by spaces or 4 spaces per tab replaced
			use of parenthesis around expressions in if condition
		Comment
			// The comment always on separate line.
		String
			use string interpolation
			and use StringBuilder for repeated parts

		Implicit Typed local var
			use var when right side expression result is obvious
			dont use var for function return types, functions might change
			use var in for loop
			dont use var in foreach

		Use int rather than unsigned int, its common in c# and compatible for communication with other libs
		arrays
			string[] s = {"a", "b"}
			var s = new string[] {"a", "b"}
			var vowels3 = new string[5];
		
		Delegates
			first define delegate type and then declare corrosponding function
		
		static members
			call static members in base calss with Base.StaticMethod, while Derived.StaticMethod could 
			also work and compile, this might break in future if Derived introduces StaticMethod
	
		LinQ Queries
			use meaningfull names
			Use aliases to make sure that property names of anonymous types are correctly capitalized, using Pascal casing.
				var localDistributors =
				    from customer in customers
					join distributor in distributors on customer.City equals distributor.City
					select new { Customer = customer, Distributor = distributor };


		Rename properties to meaningful names
		implicit typing for result queries and range
		align query to "from" in clause
		use "where" first in order to apply further operations on filtered data
		Use multiple from clauses instead of a join clause to access inner collections.
			// Use a compound from to access the inner sequence within each element.
			var scoreQuery = from student in students
			                from score in student.Scores
							where score > 90
							select new { Last = student.LastName, score };



Programming concepts
	Asynchronous programming
		async main made easy
	
	Attributes
		you can apply attribute to any declaration ie [Serializable] for class whose objects you want to write in file or db
		they add meta data into your program
		you can queury the attributes in your program using something called reflection
		attributes can accept arguments, can have default arguments
		you can use attribute with the named parameters
	
		You can specify the attribute target. Generally they apply to variable or method declaration on the next line.
		[target : attribute-list]
		targets could be assembly, module, field, evnt method, param, propertym return, type
	
		usage
			serilize
			Controlling optimizations by the just-in-time
			obtaining info about caller to method

	Collection
		you can create dynamically resizing collections of objects
		if you want collection of only one type of objects System.Collections.Generic, System.Linq

		System.Collection.Generic
			List<T>, Dictionary<K,V>, Queue<T>, Stack<T>, SortedList<TK,TV> sorted using IComparer<T>
		System.Collections.Concurrent
			parallel implementation of the above + System.Collections
		System.Collections
			Dont store elements of specefic types but object references 
			ArrayList
			HashTable
			Queue
			Stack

	static class
		only static members and static constructor.
		cant have instance ,default constructor is private
		its sealed
	
	Partial class
		can be written among multiple source files

	Extention method could be defined only in generic static class
	        public static T[] Populate<T>(this T[] arr, Func<T> func)


Classes
	overview
	are reference types and allocated on the heap 
	copied shallowed 
	When object is created by new, reference is passed back to the variable

	inheritance
		can inherit only one class but multiple interfaces
		abstract class may have abstract methods
		must implement all interface methods only once
	struct vs reference
		memory for structs on stack is reclaimed after function is done,
		this is why they are copied deep
		
	Objects
		Object identity vs value equality
		class objects uses the Equals method to determine if they point to same object on heap
		structs must determine if they have same values in fields of the objects
		in order for classes to compare value implement the virtual Equals method from Object
		valueType Equals methos is in System.ValueType which uses reflection to compare all fields
		in the struct. This could be slow so use custom implementation for efficiency
		You may implement the interface IEquatable<T> or IEqualityComparer<T> for it

		if you want to use == syntax rather than the method you will have to override the operator==.
		overided operators are always public static
		

	Inheritance
		class can inherit single class,
		struct cant
		Abstract class: if a class has single abstract method, class must be declared abstract
		abstract methos are implicitely virtual but you cant use virtual with them
		Interfaces: one can implement
		Preventing further derivation : sealed
		Derived class hiding of base class members : use new keyword
	
	Polymorphism
		hide the base class member with the "new"
		use sealed methods to stop the virtual inheritance, in this case virtual inheritance will
		work till this class only. While any further derived class must use "new" to start new inheritance
		hierarchy for the same name function
	
		versioning and override an new
		basically even if you update the package which has base class virtual member added for same name function signature
		in the derived class, things wont take effect until you recompile

		When you try to recompile compiler will give you warn, how do you want to treat the newly added method
		do you want to override, or  use keyword new in derived class or remove the method implementation from derived class
	
		Override and Method Selection
		in derived class if you have same name and signature for two methods one overrides and one defines new implementation
		the new implementation is preferred over override.
		The new keyword ends the effect of the virtual method and only method with new keyword will be inherited in further
		inheritance.

		you cant use override keyword until its a virtual method with same signature in base class. This is compilation error.

		virtual method in the base class does not replace call with method in derived class with just "new" keyword
		to call virtual implementation of derived class with base class object, derived method must be with override 
		new keyword ends the effect of virtual right there.

		override the ToString method
		public override string ToString()
		{
			return "default";
		}
	
	Members:
		Abstract class
			if single method is abstract, class must be abstract declared
			its a base implementation but cant create object

		Abstract method:
			no body, do default implementation
			implicitely virtual and must be overridden otherwise compilation error
			you cant call base abstract method from derived class, nope. not possible

		Sealed class
			can not be inherited

		static class and members
			static class instance is not possible
			only static methods, fields, properties
			static constructor
			static class does not maintain any state and methods only operate on input ie System.Math
			
			when static members of class are initialized and constructor is called is undefined
			but gurateed to happen before class is referenced first time

			static classes are by default sealed
			struct can not be singleton because you cant override default constructor
			static class can be singleton, comipler guatantees that there is only single instance of it

		static members
			belong to class
			can initialize
			const members are behave like static and belong to the class
			no static local variables
			static methods can be overloaded can not be overridden as they belong to class
			static constructor does not have access modifiers and it can not be called explicitely

			static members are initialized before used for first time or before static constructor is called
			static constructor is called only once before the first intsance of class is created or any of static 
			member is referenced
			static methods use call instruction in MSIL vs instance methods generating callvirt for null check


		access modifiers
			public
			protected
			private
			internal : accessible within same assembly
			protected internal : accessible within internal as well as any derived class
			private protected : accssible only in derived classes in (current private) assembly

		classes and struct
			Both can be public and internal. default internal
			derived class cant be more accessible than the parent

			nested classes/struct are private by dafault, but could be internal or public

			members could be of any of 6 above. while default class or struct members are private
			members can not be more accessible than their type itself.
			derived or overridden members as well cant be more accessible than base class
			interface members are by default public as they meant to override
			static fields, members are public by default
			userdefined operators must be public static

			Enums members are always public.
			delegates behave like class. Public or default internal. And public, private, internal when nested
			you may use public interface to access the unaccessible/internal members

	
		Finalizers
			dont accept argument, only one finalizer per class
			no access modifier
			cant be overloaded or overridden or inherited
			cant be called explicitely, called automatically and non-deterministically before GC releases memory
			structs cant have them

		
	indexers
		fall in between Property and Methods
		can have access modifiers
		accept arguments
		can be overloaded and can accept multiple arguments
		arguments could be of non integer type
		return a type T
		can use expression bodied syntax
		can not be static


	Properties
		They are get and set methods for the private methods
		auto implemented properies declare anonymous private variable for them
		expression body property 
		Properies can have any of 6 access modifiers
		Properties get and set accessor can have different public/private acess
		properties can be static or virtual or abstract
		properties can be part of interface
		if you declare virtual property as sealed, then you can not override it further as it is no longer virtual

	Delegates
		type safe, secure and object oriented function pointers
		they encapsulate both object and method
		they are used for the async callbacks
		they are sealed implicitely, can not be overrided, inherited
		as they store object on which instance method to call, they work with instance as well as static methods
		as long as signature matches
		Delegate is a class object derived from System.Delegate
		you can assign more than one method/obj.method to single delgate using += or + operator
		and delegete will call all methods which belong to it, called as Multicasting delegate ie Syste.MulticastDelegate 
		which is derived from System.Delegate
		you can also subtract method from the  delgate in order to remove it from event handling
		since delegate is class object of System.Delegate, it has own methods as well like InvokedCount etc

		
	Events
		mechanism to raise events via Publisher to Subscriber 
		you can implement the interface for the event
		Events are raised with the help of delegates
		typical syntax is for delegate is

		public delegate retType DelName(args);
		public event DelName _eventName;

		you can implement the  event property
		public event DelegateName EventProperty
		{
			add => _eventName += value;
			remove  => _eventName -= value;
		}

		you can raise the base publisher event from the derived publisher using a virtual method to Invoke event 
	
	strings
		they are immutable
		all string modify operations return a new string
		verbatim strings for not replacing the characters
		string interpolation
		emtpty string : var str = string.Empty;
		var substr = str.SubStrint(start, count);
		str.Replace("src", "dst")
		str.Index("substr")

		var sb = new StringBuilder();
		sb.append(newStr);

	Array
		just like every other type, arrays are derived from Object
		they can be multidimentional
		Publisher[,] pubArray = new Publisher[5,10];
		or jagged ie. Array of array...

		Publisher[][] pubArray = new Publisher[5][];
		for(int i =0; i< pubArray.Length; i++)
			pubArray[i] = new Publisher[10];

		you can not change the size of array once intiatiated
		arrays are treated as "collections of variables" so values[0] is variable
		while List is collection of values
