sequential
associative
unordered associative

container adaptors : use other to mimick functionality
	stack
	queue
	priority queue

	flat set,map,multi set, multi map

views
	span : non owning, read only view of contegious mem
	mdspan: multi dimentional span

Iterator invalidation

	references may be valid but they might point to diff element in after 

	for sequential:
		if size of container changes all are invalidated
		iterators including and afer the erased element including past-the-end are invalidated

	for associative:
		only erased elements iterator is invalidated
		but the iterators are udpated to point to correct next or prev iteractor 
			either in cased of 
			1. inserting the new values before or after iterator
			2. erasing the values before or after

	for unordered containers
		rehash invalidates all iterators
		if rehashed unordered container end() is invalidated

	clear op:
		never invalidates the std::set end()
		always invalidaes for vector

Thread sefety
	1. diff thread: different container
	2. diff thread: const method on same container
	3. diff thread: different elments modification
	4. container ops which invalidates iterator are not thread safe
		4.1 iterators ops which used to read only elements are safe
		4.2 iterator increment/decrement is thread safe
	5. std lib, does not allow to access or modify the elements
		other than whose iterator was passed to container method
