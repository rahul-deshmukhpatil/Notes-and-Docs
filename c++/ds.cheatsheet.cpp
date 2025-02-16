vector

Constructor: Creates a new vector. Example: vector<int> v(5, 10); creates a vector with 5 elements, all set to 10.

Destructor: Automatically called to free memory when vector goes out of scope. Example: ~vector() is implicitly called.

operator=: Assigns one vector to another. Example: v1 = v2; copies contents of v2 to v1.

assign: Assigns new values to vector elements. Example: v.assign(5, 10); assigns 5 elements with value 10.

assign_range (C++23): Assigns a range of values. Example: v.assign_range(other.begin(), other.end());

get_allocator: Returns the allocator. Example: auto alloc = v.get_allocator();

at: Accesses element with bounds checking. Example: int x = v.at(2);

operator[]: Accesses element without bounds checking. Example: int x = v[2];

front: Returns first element. Example: int first = v.front();

back: Returns last element. Example: int last = v.back();

data: Returns pointer to underlying array. Example: int* ptr = v.data();

begin/cbegin: Returns iterator to first element. Example: auto it = v.begin();

end/cend: Returns iterator to one past last element. Example: auto it_end = v.end();

rbegin/crbegin: Returns reverse iterator to last element. Example: auto rit = v.rbegin();

rend/crend: Returns reverse iterator to one before first element. Example: auto rit_end = v.rend();

empty: Checks if vector is empty. Example: bool isEmpty = v.empty();

size: Returns number of elements. Example: size_t n = v.size();

max_size: Returns maximum possible number of elements. Example: size_t max = v.max_size();

reserve: Reserves storage capacity. Example: v.reserve(100);

capacity: Returns current storage capacity. Example: size_t cap = v.capacity();

shrink_to_fit: Reduces capacity to fit size. Example: v.shrink_to_fit();

clear: Removes all elements. Example: v.clear();

insert: Inserts elements at specified position. Example: v.insert(v.begin(), 5);

insert_range (C++23): Inserts a range of elements. Example: v.insert_range(v.begin(), other.begin(), other.end());

emplace: Constructs element in-place. Example: v.emplace(v.begin(), 5);

erase: Removes elements. Example: v.erase(v.begin());

push_back: Adds element to end. Example: v.push_back(10);

emplace_back: Constructs element at end. Example: v.emplace_back(10);

append_range (C++23): Adds range to end. Example: v.append_range(other);

pop_back: Removes last element. Example: v.pop_back();

resize: Changes number of elements. Example: v.resize(10);

swap: Exchanges contents with another vector. Example: v1.swap(v2);



=====================================================================
=====================================================================

map

Constructor: Creates a new map. Example: std::map<int, string> m = {{1, "one"}, {2, "two"}};

Destructor: Automatically called to free memory when map goes out of scope. Example: ~map() is implicitly called.

operator=: Assigns one map to another. Example: map1 = map2;

get_allocator: Returns the allocator. Example: auto alloc = m.get_allocator();

at: Accesses element with bounds checking. Example: string value = m.at(1);

operator[]: Accesses or inserts element. Example: m[3] = "three";

begin/cbegin: Returns iterator to first element. Example: auto it = m.begin();

end/cend: Returns iterator to one past last element. Example: auto it_end = m.end();

rbegin/crbegin: Returns reverse iterator to last element. Example: auto rit = m.rbegin();

rend/crend: Returns reverse iterator to one before first element. Example: auto rit_end = m.rend();

empty: Checks if map is empty. Example: bool isEmpty = m.empty();

size: Returns number of elements. Example: size_t n = m.size();

max_size: Returns maximum possible number of elements. Example: size_t max = m.max_size();

clear: Removes all elements. Example: m.clear();

insert: Inserts elements. Example: m.insert({4, "four"});

insert_range: Inserts a range of elements. Example: m.insert_range(other.begin(), other.end());

insert_or_assign: Inserts or updates element. Example: m.insert_or_assign(5, "five");

emplace: Constructs element in-place. Example: m.emplace(6, "six");

emplace_hint: Constructs element in-place with hint. Example: m.emplace_hint(m.begin(), 7, "seven");

try_emplace: Inserts if key doesn't exist. Example: m.try_emplace(8, "eight");

erase: Removes elements. Example: m.erase(1);

swap: Exchanges contents with another map. Example: m1.swap(m2);

extract: Extracts nodes from the map. Example: auto node = m.extract(2);

merge: Merges nodes from another map. Example: m1.merge(m2);

count: Counts elements with specific key. Example: size_t c = m.count(3);

find: Finds element with specific key. Example: auto it = m.find(4);

contains: Checks if key exists. Example: bool has_key = m.contains(5);

equal_range: Returns range of elements with specific key. Example: auto range = m.equal_range(6);

lower_bound: Returns iterator to first element not less than key. Example: auto it = m.lower_bound(7);

upper_bound: Returns iterator to first element greater than key. Example: auto it = m.upper_bound(8);

key_comp: Returns key comparison function. Example: auto comp = m.key_comp();

value_comp: Returns value comparison function. Example: auto comp = m.value_comp();

erase:
erase_if :

================================================================================
================================================================================

set

Constructor: Creates a new set. Example: std::set<int> s = {1, 2, 3};

Destructor: Automatically called to free memory when set goes out of scope.

operator=: Assigns one set to another. Example: set1 = set2;

get_allocator: Returns the allocator. Example: auto alloc = s.get_allocator();

begin/cbegin: Returns iterator to first element. Example: auto it = s.begin();

end/cend: Returns iterator to one past last element. Example: auto it_end = s.end();

rbegin/crbegin: Returns reverse iterator to last element. Example: auto rit = s.rbegin();

rend/crend: Returns reverse iterator to one before first element. Example: auto rit_end = s.rend();

empty: Checks if set is empty. Example: bool isEmpty = s.empty();

size: Returns number of elements. Example: size_t n = s.size();

max_size: Returns maximum possible number of elements. Example: size_t max = s.max_size();

clear: Removes all elements. Example: s.clear();

insert: Inserts elements. Example: s.insert(4);

insert_range: Inserts a range of elements. Example: s.insert_range(other.begin(), other.end());

emplace: Constructs element in-place. Example: s.emplace(5);

emplace_hint: Constructs element in-place with hint. Example: s.emplace_hint(s.begin(), 6);

erase: Removes elements. Example: s.erase(1);

swap: Exchanges contents with another set. Example: s1.swap(s2);

extract: Extracts nodes from the set. Example: auto node = s.extract(2);

merge: Merges nodes from another set. Example: s1.merge(s2);

count: Counts elements with specific key. Example: size_t c = s.count(3);

find: Finds element with specific key. Example: auto it = s.find(4);

contains: Checks if key exists. Example: bool has_key = s.contains(5);

equal_range: Returns range of elements with specific key. Example: auto range = s.equal_range(6);

lower_bound: Returns iterator to first element not less than key. Example: auto it = s.lower_bound(7);

upper_bound: Returns iterator to first element greater than key. Example: auto it = s.upper_bound(8);

key_comp: Returns key comparison function. Example: auto comp = s.key_comp();

value_comp: Returns value comparison function. Example: auto comp = s.value_comp();


