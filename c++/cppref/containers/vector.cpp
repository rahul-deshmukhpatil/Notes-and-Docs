contigious mem.
automatic expansion & always extra mem allocated than needed.

reserve(): because allocat are costly

constexpr vectors example.

elements must be erasable requirement

Incomplete type T, vector<T> if allowed if allocator is complete type

difference-type ptrdiff_t, can have negative value

*rbegin() == *std::prev(std::end()).
but reverse and forwared iterators are diff types

resize : might erase elements if shortened due to small new size

assign 
assign_range

at -> returns ref and checks bounds

erase
pop_back

emplace_back
append_range
swap: swaps the memory data ptr, iterators remain valid pointing to original vector

three way operator.

erase and remove idom
	remove: does not erase but shifts the elements
	erase: truncates the vector
	
	std::erase(
		/* from */
		std::remove(v.begin(), v.end(), [](const auto x){ return x%2 == 0;}),
		/* till */
		v.end());