#!/usr/bin/python3

'''
https://docs.python.org/3/tutorial/datastructures.html#nested-list-comprehensions
'''
def wrapper():
    a = [1, 2, 3]
    b = [4, 5, 6]

    c = [(x, y) for x, y in zip(a, b)]
    print(f'a = {a}')
    print(f'b = {b}')
    print(f'c = [(x,y) for x,y in zip(a, b)] = {c}')

    print('[f(x) if condition else g(x) for x in sequence]')

    c = [(x, y) for x in a for y in b]
    print(f'cross product : [(x,y) for x in a for y in b] = {c}')

    c = [(x, y) for x in a for y in a]
    print(f'self product  : [(x,y) for x in a for y in a] = {c}')

    c = [(a[i], a[j]) for i in range(len(a)) for j in range(len(a)) if j >= i]
    print(f'Diagonal self half matrix : [(a[i], a[j]) for i in range(len(a)) for j in range(len(a)) if j >= i] = {c}')

    c = {x: x * x for x in a}
    print(f'building dict : {{x:x*x for x in a}} = {c}')

    c = set([x * x for x in a])
    print(f'building set of squares:  set([x*x for x in a]) = {c}')

    matrix = [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]]

    c = [[x for x in row] for row in matrix]
    print(f'rebuild  matrix : [[x for x in row] for row in matrix] => {c}')

    c = [[x*x for x in row] for row in matrix]
    print(f'matrix square : [[x*x for x in row] for row in matrix]i =>  {c}')

    c = [[(i,j) for j,x in enumerate(row)] for i,row in enumerate(matrix)]
    print(f'co-ordinate tuple row wise : [[i,j for j,x in enumerate(row)] for i,row in enumerate(matrix)] => {c}')

    c = [(i,j) for i,row in enumerate(matrix) for j,x in enumerate(row)]
    print(f'co-ordinate tuple whole matrix :  [(i,j) for i,row in enumerate(matrix) for j,x in enumerate(row)] => {c}')

    c = {(i,j):x for i,row in enumerate(matrix) for j,x in enumerate(row)}
    print(f'co-ordinate tuple dict: {{(i,j):x for i,row in enumerate(matrix) for j,x in enumerate(row)}} => {c}')

    c = {i:{j:x for j,x in enumerate(row)} for i,row in enumerate(matrix)}
    print(f'co-ordinate dict of dict:{{i:{{j:x for j,x in enumerate(row)}} for i,row in enumerate(matrix)}} => {c}')

    c = {i:{j:x for j,x in enumerate(row)} for i,row in enumerate(matrix)}
    print(f'co-ordinate dict of dict: => {c}')
    

if __name__ == '__main__':
    wrapper()
