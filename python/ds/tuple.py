#!/usr/bin/python
from collections import namedtuple

'''
namedtuple

namedtuple(name, fields_list_or_string, *, rename=False, defaults=[], module=None)
fields_list_or_string = ['a b c'] or 'a b c' or 'a, b, c'
rename : if fields contains a keyword replace with corrosponding '_' + integer index ie _1, _2, _3
default : last n default values if not provided while declaring variables
module : module name

nt = _make(another_t) => makes tuple with another_t or another_list or comma 
nt._asdict() => converts named tuple to dict
nt._fields => list of field names

nt._replace(field_name=new_value, nt._replace(**kwargs)
nt._field_defaults => dict of default values of fields


from collections import namedtuple as nt
>>> i = myt(1,3,5)
>>> i
myt(x=1, y=3, z=5)
>>> i = myt(*[1,3,5])
>>> i
myt(x=1, y=3, z=5)
>>> i = myt._make([1,3,5])
>>> i
myt(x=1, y=3, z=5)
>>> d = {'x':4, 'y':5}
>>> i._replace(**d)
myt(x=4, y=5, z=5)
>>> i._asdict()
{'x': 1, 'y': 3, 'z': 5}
>>> i._fields
('x', 'y', 'z')
'''

def wrapper():
    print('''It is not possible to assign to the individual items of a tuple, however it is possible to create tuples 
    which contain mutable objects, such as lists.''')
    t = ([1, 4, 5, 6], [2, 5])

    print(f't = {t}')

    l = t[0]
    print(f'l = t[0]')

    l.append(10)
    print(f'l.append(10) = {l}')
    print(f't = {t}')

    t = 1, 2, 4
    print(f't = 1,2,4  => {t}')

    t = ()
    print(f't=()  => {t}')

    t = 2,
    print(f't=2,  => {t}')

    l = [1, 4, 5, 7]
    t = tuple(l)
    print(f'List to tuple cast {l} => {t}')

    l = list(t)
    print(f'tuple to list cast {t} => {l}')

    def func(a, b):
        print(f'func called with tuple expansion : {a} {b}')
        return a + b

    t = (5, 10)
    print(f'func(t) calling with tuple {t} => result {func(*t)}')

    MyArgs = namedtuple('MyArgs', 'b, a')
    t = MyArgs(5, 10)
    print(f'func(t) calling with tuple {t} t.a={t.a} t.b={t.b} => result {func(*t)}')
    print(f'func(t) calling with tuple {t} t[0]={t[0]} t[1]={t[1]} => result {func(*t)}')

    d = t._asdict()
    print(f'tuple {t}._asdict = {d}')

    Triple = namedtuple('Triple', 'a b c')
    d = {'a': 500, 'c': 200, 'b': 300}
    tr = Triple(**d)
    print(f'd=>{d}, Triple(d)=>{tr}')

    # Triple1 = namedtuple('Triple1', '1 2 3') : field names must be valid identifier
    # Triple1 = namedtuple('Triple1', '_1 _2 _3') : field names must be not start with _


if __name__ == '__main__':
    wrapper()
