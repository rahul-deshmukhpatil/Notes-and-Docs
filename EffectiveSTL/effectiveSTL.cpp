========================================================
Introduction:
========================================================

Defining, Using and Extending STL:
	STL is containers work with iterator, algorithms like
	find, bind, Functors.
	It doesnt include standard container adaptors like
	stack, queue. It does not include valarray, bitset due
	to lack of iterator support

	It also excludes standard hashed containers, sll,
	ropes. But you need to know these extended features
	to be efficient programmer.

	STL is designed to extended, But you should focus on
	using already available things than extending it for
	own use.

STL and standards:
	A STL platform is both compiler and STL version.
	Sometimes compilers fail to compile valid code. It
	could be because of both compiler or STL implementation
	that you face some problems.
	Improve your code quality via using same source code
	compiled with different compilers. 
	Be sure about undefined behaviours which could lead
	to anything like seg fault, subtle mem leak.

Reference Counting:
	Whenever pointers containers come in scenario it is
	unvoidable to discuss the reference counters.

string and wString:
	string and wString are instantiations of basic_string
	in STL. So almost whatever applies to string applies
	to wString	

Terms:
	standard Sequence containers: vector, string, deque
	standard assosciative containers: set, multiset, map
	multimap.
	Iterators:
		input: 		read only one place one time.
		output: 	write only one place one time.
		fw iterators: read/write one location mutiple times
						but in only foraward direction as
						they do not support -- operator
						Move one step at a time.
		bidirections iterators:
						forward iterators with capability to
						move backward, operator -- is supported
						but only move one step at a time.
		random iterators:
					read/write in both directions with jump to
					any location in single step.
		
		code that works with functor class objects, works well
		with the functor classes.

	Binder functions: bind1st and bind2nd
	
Time/Space complexity
	Usually time/space complexity of STL containers and functions
	is already defined and it is irrespective of initialization
	type of containers. Amortized constant time complexity is
	operations sometimes takes more time than constant time. 
	Here contant time is time irrespective of size of containers
	and not literal meaning of "constant time".
	Most search operations on the assosciative containers are in
	logarithmic time.
	Sometimes algorithm with theorotically worst time performs
	better practically.		

Questions:
	What are valarrays and bit set.
	what is undefined behaviours in STL?
	Example of code works well with functor objects and 
		real c++ functions.


========================================================
Item 1: Choose containers with care
========================================================
1> STL sequence containers: vector, string, deque and list
2> STL assosciative containers: map, set, multimap, multiset
3> Non standard sequence containers: rope, slist
4> Non standard assosciative hashed containers:
		hash_map, hash_set, hash_multimap, hash_multiset
5> vector<char> replacement for string  
6> vector<char> replacement for standard assosciative container
7> standard non STL container: arrays, bitset, valarray, stack,
								queue, priority_queue 

Terminologies
Introduction:
1> Standard sequence containers
2> Standard assosciative containers
3> function call operator, functor 
4> functor class and functor objects
5> Binder functions

========================================================
Item 2: Beware of container-independant code 
========================================================
	STL is generalisation
		of arrays into containers
		of functions into algorithms.
	
	Containers are not replacible
	Each has some unique set of functions.
	Even if function names are same, they accept parameters or return differently.	
	Thier rules for invalidation of pointer, reference or iterationrs are different
	Each one has different complexity for space and time.

	To write container independant code use either typedefs or wrapper container classes

	typedef vector<Widget> WidgetContainer;
	
	or
	
	class WidgetContainer
	{
		public:
			insert(){}
			size(){}
	}

	by this way atleast you could ensure that if not you, clients of class could write
	some container independant code.

Terminologies:
	custom allocators
	nth_element

========================================================
Item 3: Make copying cheap and correct for obj containers 
========================================================
	Containers do not store exact same objects what you pass to them,
	Neither they return exact same object what they store.
	They accept and return copies of objects via copy constructors.
	So make sure that copy constrctors are cheap, otherwise insertion
	and extraction of objects from containers would be bottleneck.

	Do not store derived class objects into base object containers
	as it will cause object slicing.

	Arrays of objects will initialise all the objects in array at the
	point of definition. if you use, vectors then this will not happen
	as vector will be empty until and unless you put something in it.

	Try to use containers of pointers to be correct, immune and prevent
	from slicing.

========================================================
Item 4: Call empty instead of checking size() 
========================================================
	Size might iterate over the every element in the container if there
	is not extra size field mainained by the implementation of the STL
	Same container could have different implementation in diff STL implementation.
	So changing STL implementation could cuase difference in performance if
	you are using size()
	
	Empty will see if size is atleast greter than 0. Empty is supposed to
	be constant time operation in every standard cotainer.
	
========================================================
Item 5: Use range member functions over thier single element counterparts 
========================================================
	One should use range member functions, which are available for
	every STL container, over the single member functions which use
	inserter, front_inserter, back_inserter
		- Range member functions do not demand frequent allocations
			Calculates how much memory its going to require in single step
		- Range member functions do not do frequent copying/moving
			It moves elements into final position in single step
		- It avoid unneccessory inserter callbacks 
			Could be inlined, but in case of list, frequent pointer reassignments
			are inenvitable	
		- In case of associative containers, theory says that range
			members could have been optimized.

	Range Construction:
		container::container(InputIterator begin, InputIterator end);	
	Range Insertion:
		void container::insert(Iterator pos, InputIterator begin, InputIterator end);
	Range Erase:
		Sequence: 
		Iterator container::erase(InputIterator begin, InputIterator end);
		Associative:
		void container::erase(InputIterator begin, InputIterator end);

Questions:
	See if range member functions are optimized in case of associative containers 
		

========================================================
Item 6:	Be alert for C++ most vexing parse 
========================================================
	ifstream dataFile("sam.txt");
	list<int> data(istream_iterator<int>(dataFile), istream_iterator<int>())
	1> data is function and first parameter dataFile is of type istream_iterator<int>
	2> second one is function pointer returning istream_iterator<int>

	so always use
	list<int> data((istream_iterator<int>(dataFile)), istream_iterator<int>())
	1> now first parameter is lists constructor
	some buggy compilers wont allow to compile above definition

	so better way to define data is 
	istream_iterator<int> dataBegin(dataFile);
	istream_iterator<int> dataEnd();
	list<int> data(dataBegin, dataEnd);

Questions:
	list<int> data((istream_iterator<int>(dataFile)), istream_iterator<int>())
	what does second parameter do in the above function declaration?

========================================================
Item 7: Do not forget to delete pointer in contianers while deleting container	
========================================================
	When container having pointers is deleted pointers inside it are not deleted
	so you have to take care of deleting them
	1> Delete explicitly them
	2> Or use the shared_ptr, or any resource counting smart pointer containers
		instead of plain pointers.

	Dynamically allocated arrays are always inferior to the vectors and strings
	

========================================================
Item 8: Never use auto_ptr containers 
========================================================
	1> While inserting and getting back the data from containers, copy
		operations are performed.
	2> When copy is performed on auto_ptr, the source pointer gets NULL
	3> So if you perform sort on container of auto_ptr which calls compare
		function inside it, which takes parameters by value, then the
		container will contain NULL values.
	

========================================================
Item 8: Never use auto_ptr containers 
========================================================
	1> While inserting and getting back the data from containers, copy
		operations are performed.
	2> When copy is performed on auto_ptr, the source pointer gets NULL
	3> So if you perform sort on container of auto_ptr which calls compare
		function inside it, which takes parameters by value, then the

========================================================
Item 9: Choose carefully among erasing options 
========================================================
	1> Erasing the member of containers might invalidate the iterator/s
		depending upon type of container
	2> If want to erase a particular element
		seqContainer: use erase-remove
		list		: remove 
		associative containers: erase
	3> Conditional erase
		seqContainer: use erase-remove_if
		list		: remove_if 
		associative containers: walk over and erase with post incriment
	4> Do something in loop:
		seqContainer: use return value of erase
		associative containers: walk over and erase with post incriment
========================================================
Suggestions:
========================================================
	Page3: "An STL platform", this should be "A STL Platform"
	Page3: end: what is undefined behaviours in STL?
	page4: end: Example of code works well with functor objects 
			and  c++ functions
	page37: Item7: explain how does DeleteObject<Widget> calls functor
	page43: How does erase-remove works. twice used c.end(), is bit confusing
			What remove returns?
	page44: not clear by meaning of c.remove_if(badValue)
========================================================
