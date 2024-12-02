#!/usr/bin/python3

class A:
    def __init__(self, a):
        self.a = a

    def __eq__(self, other):
        return self.a == other.a

def wrapper():
    print('''A set is an unordered collection with no duplicate elements. Basic uses include membership testing and 
    eliminating duplicate entries. Set objects also support mathematical operations like union, intersection, 
    difference, and symmetric difference.''')

    a = set([1, 4, 5, 6])
    b = set([2, 5])

    print(f'a = {a}')
    print(f'b = {b}')

    print(f'a - b = {a - b}')
    print(f'a & b = {a & b}')
    print(f'a | b = {a | b}')
    print(f'a ^ b = {a ^ b}')
    a.update(b)
    print(f'a.update(b) = {a}')

    a = set([1, 4, 5, 6])
    b = set([1, 4, 5, 6])
    isEqual = a == b
    print(f'a == b = {isEqual}')

    a = [A(4)]
    b = [A(4)]
    isEqual = a == b
    print(f'[A(4)] == [A(4)] = {[A(4)] == [A(4)]}')
    print(f'A(4) == A(4) = {A(4) == A(4)}')
    print(f'A(4) is A(4) = {A(4) is A(4)}')

    if A(4) in a:
        print('YEs')
    else:
        print('No')


if __name__ == '__main__':
    wrapper()
