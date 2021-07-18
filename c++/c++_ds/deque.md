std::deque
	- pronounced ad De`Q or dec
	- index sequenced but not contigious storage, uses chunks of fixed size arrays
	- which needs additional book keeping and because of this indexed access is via 2 ptr dereferences
	- can grow in either direction
	- insertion at front or end is O(1) and doesnt invalidate iters, pointers, refs
	- initial minial size is bit large (either equal to 8 elements on libstdc++ or largest of 16 elements/4096 bytes on libc++)
	
swap or std::swap : invalidates ends()

shrink_to_fit, insert, emplace, push_front* push_back* = > always

erase: at begin, at end : only single iterator and past the end
	 : in the middle : cant say which one
	
resize: if smaller then erased elements and end
		if size is bigger than old one > all
		otherwise none
	
pop_front/back : only erased and end() if applicable

front/back : calling on empty is undefined

insert(pos, value)
insert(pos, count, value)
insert(pos, first, last)
insert(ilist)
	All iterators are invalidated, 
	iterator pointing to new element or existing pos if no element in inserted
	complexity (1, count, last-first, ilist.size()) + lesser(pos-begin, pos-end)
	strong exception safe gurantee while inserting at ends

emplace(pos, Args...): if position is occupied first construct then move elements to make space and then move-copy element
	iterators are invalidated, except its emplaced at front or back
	exception thrown while creating,copying, moving elements, or its front/back insertion then no effect. otherwise unspecified

resize: if current size is lesser than count allocate more storage
		otherwise either create default elements or elements with value

		O (count - current size)

swap : not individual elements are moved.
		past the ends are invalidated

	





