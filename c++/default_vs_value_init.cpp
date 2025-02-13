https://abseil.io/tips/146

Concepts
	A a2;  // Default initialization

	A a1{};  // Value initialization
	A a1 = {};  // Value initialization
	A a1 = A();  // Value initialization

3 types of const
	Support value initialization
	1. compiler provided: supports value init
	2. inline defaulted: declared inside class, treated as compiler provided

	do not support value initialization
	3. out of line defaulted : constr defined out of class, treated as user provided
	4. user provided

to be sure if the members are going to be value init every time
provide data member init list
class A
{
	int a{};
	int b=1;
	int b={2};
};
