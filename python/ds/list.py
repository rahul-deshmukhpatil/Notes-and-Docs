'''
https://docs.python.org/3/tutorial/datastructures.html

append(element)
extend(another_list)
insert(at_index, element)   : insert element at index shifting elements to right 

remove(element)             : ValueError if x is not present in list
del list[index or slice]    : deletes the value at index or slice range
                            : index : IndexError if index out of range
                            : while slice range succeeds for any value
                            : del can also be used to delete entire variables ie del list

pop(index = -1)             : remove element from back or at index
clear()                     : clear contents of list
index(x, [start, stop])     : find an element in list within range specified
                            : if its not found  ValueError irrespective of
                            : invalid/out of bound index start stop values

count(x)                    : count of x in list, no search range is supported
sort(reverse, key)
reverse()
copy()                      : Equivalent to a[:]
'''
from collections import Counter
from typing import Any, Callable, Union


def wrapper():
    l = [4, 6, 7, 6, 8, 3, 2, 5, 9]

    print(f'l = {l}')
    del l[100:200]
    print(f'del l[100:200] = {l}')

    print(f'l.index(2) = {l.index(2)}')


def tricks():
    l = [4, 6, 7, 6, 8, 3, 2, 5, 9]
    isEven = lambda x: x % 2 == 0
    isEvensList = list(map(isEven, l))
    print(f'is even {isEvensList}')
    evensList = list(filter(isEven, l))
    print(f'only even {evensList}')

    l = [4, 6, 7, 6, 8, 7, 7, 5, 9]
    mostAppeared = max(set(l), key=l.count)
    print(f'most appeared number is list={l} is {mostAppeared=}')

    lDict = Counter(l)
    print(f'count of numbers {lDict=}')
    dictList = list(lDict.items())
    print(f'list of counter of appearance : {dictList=}')
    dictList.sort(reverse=True, key=lambda x: x[1])
    print(f'sorted list as per count : {dictList}')


if __name__ == '__main__':
    wrapper()
    tricks()
