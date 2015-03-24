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



========================================================
Terminologies
========================================================
Introduction:
1> Standard sequence containers
2> Standard assosciative containers
3> function call operator, functor 
4> functor class and functor objects
5> Binder functions
========================================================


========================================================
Suggestions:
========================================================
	Page3: "An STL platform", this should be "A STL Platform"
	Page3: end: what is undefined behaviours in STL?
	page4: end: Example of code works well with functor objects 
			and  c++ functions
========================================================
