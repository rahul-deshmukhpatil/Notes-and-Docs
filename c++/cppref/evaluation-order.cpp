Order of evaluation before c++17 for the subexpressions in c++ wasnt not fix

The compiler can evaluate operands and other subexpressions in any order, and may choose another order when the same expression is evaluated again.

But after c++17 its left to right.

