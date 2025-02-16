list

list.append(x): Adds x to the end of the list. Example: my_list.append(5)

list.extend(iterable): Adds all items from iterable to the end of the list. Example: my_list.extend([1][2][3])

list.insert(i, x): Inserts x at position i in the list. Example: my_list.insert(0, 'start')

list.remove(x): Removes the first occurrence of x from the list. Example: my_list.remove('item')

list.pop([i]): Removes and returns item at index i (or last item if i not specified). Example: last_item = my_list.pop()

list.clear(): Removes all items from the list. Example: my_list.clear()

list.index(x[, start[, end]]): Returns index of first occurrence of x (optionally within start:end range). Example: index = my_list.index('item')

list.count(x): Returns number of occurrences of x in the list. Example: count = my_list.count('item')

list.sort(*, key=None, reverse=False): Sorts the list in place. Example: my_list.sort(reverse=True)

list.reverse(): Reverses the list in place. Example: my_list.reverse()

list.copy(): Returns a shallow copy of the list. Example: new_list = my_list.copy()

======================================================

set(): Creates a set. Usage: my_set = set([1][2][3])

frozenset(): Creates an immutable set. Usage: my_frozenset = frozenset([1][2][3])

len(s): Returns set size. Usage: size = len(my_set)

x in s: Checks membership. Usage: is_present = 2 in my_set

isdisjoint(other): Checks for no common elements. Usage: is_disjoint = set1.isdisjoint(set2)

issubset(other): Checks if subset. Usage: is_subset = set1.issubset(set2)

issuperset(other): Checks if superset. Usage: is_superset = set1.issuperset(set2)

union(*others): Combines sets. Usage: combined = set1.union(set2, set3)

intersection(*others): Finds common elements. Usage: common = set1.intersection(set2, set3)

difference(*others): Removes elements. Usage: diff = set1.difference(set2, set3)

symmetric_difference(other): Elements in either but not both. Usage: sym_diff = set1.symmetric_difference(set2)

copy(): Creates a shallow copy. Usage: new_set = my_set.copy()

update(*others): Adds elements in-place. Usage: my_set.update(set2, set3)

intersection_update(*others): Keeps only common elements in-place. Usage: my_set.intersection_update(set2, set3)

difference_update(*others): Removes elements in-place. Usage: my_set.difference_update(set2, set3)

symmetric_difference_update(other): Updates with elements in either but not both. Usage: my_set.symmetric_difference_update(set2)

add(elem): Adds an element. Usage: my_set.add(4)

remove(elem): Removes an element, raises KeyError if not found. Usage: my_set.remove(2)

discard(elem): Removes an element if present. Usage: my_set.discard(2)

pop(): Removes and returns an arbitrary element. Usage: element = my_set.pop()

clear(): Removes all elements. Usage: my_set.clear()

======================================================

Dict


Python dictionary operations and methods in one line with usage:

list(d): Returns a list of all keys. Example: keys_list = list(my_dict)

len(d): Returns number of items. Example: dict_size = len(my_dict)

d[key]: Retrieves value for key. Example: value = my_dict['key']

d[key] = value: Sets value for key. Example: my_dict['new_key'] = 'new_value'

del d[key]: Removes key-value pair. Example: del my_dict['key']

key in d: Checks if key exists. Example: if 'key' in my_dict:

key not in d: Checks if key doesnt exist. Example: if 'key' not in my_dict:

iter(d): Returns iterator over keys. Example: for key in iter(my_dict):

clear(): Removes all items. Example: my_dict.clear()

copy(): Returns shallow copy. Example: new_dict = my_dict.copy()

fromkeys(iterable, value): Creates new dict with keys from iterable. Example: new_dict = dict.fromkeys(['a', 'b', 'c'], 0)

get(key, default): Returns value for key or default. Example: value = my_dict.get('key', 'default')

items(): Returns view of (key, value) pairs. Example: for key, value in my_dict.items():

keys(): Returns view of keys. Example: for key in my_dict.keys():

pop(key[, default]): Removes and returns value for key. Example: value = my_dict.pop('key', 'default')

popitem(): Removes and returns last (key, value) pair. Example: last_item = my_dict.popitem()

reversed(d): Returns reverse iterator over keys. Example: for key in reversed(my_dict):

setdefault(key, default): Returns value for key, sets if not present. Example: value = my_dict.setdefault('key', 'default')

update([other]): Updates dict with key/value pairs from other. Example: my_dict.update({'new_key': 'new_value'})
other could be list of tuples
replace value in destination if already exits

values(): Returns view of values. Example: for value in my_dict.values():

d | other: Creates new dict merging d and other. Example: merged_dict = dict1 | dict2

d |= other: Updates d with keys and values from other. Example: my_dict |= {'new_key': 'new_value'}
replace value in destination if already exits
