
operator= 	copy assign, move assign or ilist assign

assign(count, value)
assign(firstItr, lastItr) : // assign elements from std::map
assign(ilist)

at(index) :	returns ref, throws std::out_of_range 
operator[] : returns ref, const & non const, never inserts element 

empty
size
max_size		: max elements possible
capacity		: current elemetns capacity
reserve(new_cap): doesnt change size, add elements. if new_cap > current capacity()
					reallocation happens invalidating all iters

shrink_to_fit	: non-binding request to release extra memory, 
					if relloation happens invalidates all iters

Modifiers
clear:	erase all elements, doesnt change capacity
insert(posItr, value) : inserts value before position
insert(posItr, count, value) 
insert(posItr, firstItr, lastItr)
insert(pos, ilist)

emplace(pos, Args) : remember Args could be for copy, move constr, some any user defined constr 

erase(pos)		   : pos must be valid and dereferenciable, end() is not dereferencible
erase(first, last) : could be used to delete count/n number of elements using last = pos + count
					 or the first non-deleted element after range.

push_back	 : same as below, returns nothing
emplace_back : if noexcept move constr or copy constritble strong exception safe gurantee
				otherwise throwing move is used and effects are unspecified

pop_back : just pops last element. end itr is invalidated, nothing returned.

resize(count, [value=T()]): if count > size add additional elements at the end with default T() or value
					or if count < size deletes additional elements at the end 

Non member functions:
	all <, <, <= etc are evaluated as lexicographical comparison
	also <=> implemented with the c++20

C++ 20
std::erase(v, value)		: implement the erase-remove idom
std::erase(v, predicate)	: both return count of deleted elements


