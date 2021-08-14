https://www.youtube.com/watch?v=teUA5U6eYQY
CppCon 2019: Ben Saks “Better Code with C++ Attributes”


provided by compilers 
	you can place them at begining or at end, depends on attribute

	if not supported then compiler just ignores whatever inside [[ attr_name ]]
	this provides backward and fw, cross compiler compatibility of code.
	Its just that code wont be that optimized if they are ignored

	usually these are suggestions, so could be ignored even after supported

	may be compiler specefic, so declared in compilers own logical attribute namespace 
	or naming convetions so that if introduced by C++ in future, name does not collide
	[[gnu::cold]] etc

	usually have single flag to turn these off warnings by these flags if you spell
	the attribute names wrong or attribute is not supported


# if __cpp_attributes && __has_cpp_attribute(nodiscard)
	#define NODISCARD [[nodiscard]]
#else
	#define NODISCARD 
#endif


[[noreturn]]  void foo();
	returning void is also returning via same return mechanisms
	cant declaring them as no return 
	
	really means you wont return via normal return meachnism
	Well either you can call another noreturn func i.e. std::exit()
	or throw from inside foo, so that compiler doesnt complain that you are returning from
	[[noreturn]] func

	1. normal returning from [[noreturn]] is undef behavior
	2. compiler warns above case but cant catch it in all cases


[[depricated]]
	1. function, variables, types, typedefs, aliases, enum, explicit specialization
	2. use to tell programmers, to remove func in future, and not in single 1 version replace of
		every use
	3. takes string as attribute as description


[[fallthrough]]
	1. intentionally falling through is ok, but unintended is warned without break at end of case
	2. can be used inside `if` block , while `else` will contain break;


[[maybe_unused]]
	1. assert parameter is not considered as usage as only compiled in debug mode.
	2. can be used with function, variables, types, typedefs, aliases, enum, explicit specialization
	3. its compiler request like inline or constexpr, compiler still might compile

[[nodiscard]]
	memset, returns copy of first element
	1. funciton returning invalid op error code, incorrect result etc must be nodiscard
	2. opposite of maybe_unused
	3. if not using search result, boolean return, invalid input or output (std::npos, EOF)return codes, must be handled
	4. can be used with class and enum, which makes functions returning these bydefault [[nodiscard]]
	
[[likely]] C++20 feature
	1. assist compiler that its going to be most likly situation, so may optimized
	2. can be used in switch case, rather than reordering enums case handling 
	3. Use any of attributes judiciously otherwise can cause increase in latency


===================================================================================================

Policy Based design. 
	pass allocator and compare as type_traits or template param
	policies can not be base class because what if they dont have virtual destrucutor

Class objects must have atleast 1 byte.
	policies are type_traits, so no datamembers, but size is 1 as min obj size of C++
	so use [[no_uniq_address]] and non-static members of class_type(class, union, struct) can be of 0 size

struct Little  // total size 8, with  3 bytes alignment at end
{
	int i;
	char c; 
};

struct Big // 8 bytes with optimization
{
	[[no_unique_address]] Little l; // do not pad at the end
	char id[3]; // use 3 bytes at the end

	// !!! please do not do memset with sizeof(Little), it will reset `id` bytes
	// !!! use memset(sizeof(Big::id))
};

Empty objects of the same type can not have same address so no_unique_address does not take into effect
what if you have array of empty objects? elements must have diffrent address right, so that you could iterate











	


	




