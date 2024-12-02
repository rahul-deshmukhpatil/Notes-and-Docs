#!/usr/bin/python3

class A:
    def __init__(self, a):
        self.a = a
'''
add(elem)
Add element elem to the set.

remove(elem)
Remove element elem from the set. Raises KeyError if elem is not contained in the set.

discard(elem)
Remove element elem from the set if it is present.

pop()
Remove and return an arbitrary element from the set. Raises KeyError if the set is empty.

clear()
Remove all elements from the set.
'''

def wrapper():
    print(''' 
    list(d) : Return a list of all the keys used in the dictionary d.

    len(d) : Return the number of items in the dictionary d.

    d[key] : Return the item of d with key key. Raises a KeyError if key is not in the map.

    iter(d) : Return an iterator over the keys of the dictionary. This is a shortcut for iter(d.keys()).

    clear() : Remove all items from the dictionary.
   
    get(key[, default]) : Return the value for key if key is in the dictionary, else default. If default is not given,
     it defaults to None, so that this method never raises a KeyError.
    
    items : returns (key, value) pair
    
    keys() : new view of dict keys
    values() :  new view of dict values 
    
    pop(key [, default_value]): If key is in the dictionary, remove it and return its value, else return default.
     If default is not given and key is not in the dictionary, a KeyError is raised.
    
    popitem(): Remove and return a (key, value) pair from the dictionary. Pairs are returned in LIFO order.
    popitem() is useful to destructively iterate over a dictionary, as often used in set algorithms. 
    If the dictionary is empty, calling popitem() raises a KeyError.
    Changed in version 3.7: LIFO order is now guaranteed. In prior versions, popitem() would return an arbitrary key/value pair.
    
    reversed(d) : Return a reverse iterator over the keys of the dictionary. This is a shortcut for reversed(d.keys()).
    
    setdefault(key[, default]) : If key is in the dictionary, return its value. 
    If not, insert key with a value of default and return default. default defaults to None.
    
    update([other]) : update dict with other dictionary values
    
    ''')
    a = {'a': 1, 'b': 2}
    print(f'a = {{\'a\': 1, \'b\': 2}} = f{a}')
    a = dict(a=1, b=2)
    print(f'a = dict(a=1, b=2)= f{a}')

    a = dict([('a', 1), ('b', 2)])
    print(f'a = {{[(\'a\', 1), (\'b\', 2)]}}= f{a}')

    a = {'a': 1, 'b': 2}
    b = {'b': 3, 'd': 4}
    print(f'a => {a}')
    print(f'b => {b}')
    #print(f'a | b = f{a | b}')
    a.update(b)
    print(f'a.update(b) = f{a}')


if __name__ == '__main__':
    wrapper()
