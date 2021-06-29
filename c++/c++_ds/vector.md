
- Continuous allocated storage, so random access is possible
- allocates more than required storage to accomodate future growth
- Can `reserve` the size if known before hand
- Can `shrink_to_fit` or forcefully `resize` to required number of elements 


Template parameters
T : must support actual operations in the functions you use.
	generally complete type and `Erasable`

Allocator:
	must satisfy `Allocator` requirements. Allocator::value_type
	must be T otherwise in c++17 its undefined behavior
	in c++20 its ill-formed program

Specializations : std::vector<bool>

Iterator invalidation
	- None of read operations invalidate operator
	- All of the write(insert, emplace, delete), 
	swap, move copy, copy/assignment operations could invalidate either all, part of elements after middle, or end().
	
	swap : end()



Member functions:

Capacity:
	empty
	size	: num of elements
	max_size: max possible elements
	capacity: num of elemetns currently allocated storage can held
	reserve(n) : increase capacity to hold atleast `n` elements
				may throw std::length_error if n > max_size
	shrink_to_fit: Its non-binding, implementation dependant request to reduce capacity() to size(). if re-allocation occurs elements are moved.
				If an exception is thrown other than by T's move constructor, there are no effects.

Modifiers:
	clear : erase all elements in linear complexity. does not change capacity.

	insert(pos, value)					: insert before pos in all functions, iterator to inserted position
											complexity distance(pos,end)
	insert(pos, count, value)			: insert before pos in all functions or pos if count == 0 
											complexity count + distance(pos, end)
	insert(pos, first, last)			: iterator to the first inserted element or pos if first == last
											complexity distance(first, last) + distance(pos, end) 
	insert(pos, initializer_list)		: iterator to the first inserted element or pos if intializer_list is empty
											complexity size(initializer_list) + distance(pos, end) 

	No Exception if its CopyInsertible or std::is_nothrow_move_constructible<T>,
	Might cause reallocation which invalidates all iterators, pointers and references
	Otherwise all iterators before insertion point i.e. pos remain valid
	
emplace(pos, args...) : inserts before position by constr(args...), copy/move constr, returns iterator to new emplaced element 
							complexity distance(pos,end)
							reallocation might happen.
							if pos is already occupied, first construct the element and then move copy.
							else may use placement new if not realloacted

	strong exception guarantee if its CopyInsertible or std::is_nothrow_move_constructible<T> or excpetion is thrown other than copy constr, move constr, operator=, move assigment. 
	If not then no guarantee and effects are unspecified

	
push_back : may reallocated if capacity is already full. invalidates iter,ptrs,refs
			may throw exception if copy, move constr throws or storage is full Allocator::allocate(), 
			amortized_constant complexity , O(1) or O(n)

emplace_back: may use placement new if not realloacted.
			strong exception safe gurantee. if T move constr is not noexcept or not copyInsertable then it will use throwing move constr and exception guarantee is waived offand effects are unspecified


resize: either add the extra default or value copies or reduce the size by erasing elemets at the end.
		strong exception safe guarantee (no effect seen) if T is noexcept move cosntructible
		returns void
		never reduces capacity because that will cause reallcation and it invalidates
		all the iter, pointers, ref than past the resize count
