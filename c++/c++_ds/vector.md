
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
	swap, move, copy/assignment operations could invalidate either all, part of elements till middle, or end().

