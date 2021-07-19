std::map
	- associative container
	- contains key,value pair
	- search, removal, insertion has log(N) complexity
	- generally implemented as RB tree

	- uses Compare function which tests equivalence by !comp(a,b) && !comp(b,a)


map(Compare, Alloc)
map(Alloc)
map(first, last, [compare, alloc])
map(map&&)
map(initializer_list, [compare, alloc])
	If serveral keys in intializer_list or map(first,last) are equivalent it
	does not gurantee which K,V will be inserted
	Time complexity is O(log N) but if input is sorted its O(N)


operator= : if old allocator is not same as new allocator, then elements are
	destroyed first and then copied one by one
		linear in this->size() + other.size()

operator=(map&&) : if old allocator is not same as new allocator, then elements are
	destroyed first and then moved one by one
		allocator are equal : this->size()
		allocator dont compare equal and dont propagate : linear in this->size() + other.size()

opertor=(initializer_list):
	O (N log N) : N is this->size + ilist.size()
	ilist is sorted first
	In case of move assigmnet, iter, ptr, ref to this are invalidated while one pointing to other remain valid

clear: O(N) 

<iter, bool> insert([hint], [pair, pair&&]):  insert if K is already not present, prior to the hint
void insert(first, last)
void insert(ilist) : 
iter insert([hint], node_handle): if nh is empty handle does nothing 

	vector or map or any other containers insert, accepts values which could be constructibe to value_type

<iter, bool> insert_or_assign([hint], K, V) : insert only if K is not present
iter insert_or_assign(hint, K&&, V&&) : returns iterator that was either inserted or updated


<iter, bool> emplace(Args...) : first create pair from args and then try to insert only if K is not present
								strong exception safe gurantee. If failed to insert destroy created pair
<iter, bool> emplace_hint(hint, Args...) : try to insert prior to hint, 
									if hint is lower_bound : inserted in amortized constant time
									otherwise no change in time complexity of log N

<iter, bool> try_emplace(& key, Args&&... args): behaves like emplace just diff value constr
iter try_emplace(hint, & key, Args&&... args): behaves like emplace_hint just diff value constr
									1. Unlike emplace does not move rvalue args if insertion does not happen
										so for map<str, uniq_ptr> makes easy to manipulate 
									2. accepts mapped_type arguments saperately



erase(itr): 			removes elements, pos itr must be valid and dereferencible (end is valid but not deref)
erase(first, last):		removes range if itrs belong to *this
erase(key):				with key


