/*
 * Program demonstrates use of the decltype and auto for type inference.
*/

#include <iostream>

using namespace std;

class base
{
	float f;
	public:
		base(float data):f(data){}
		float operator+(){return f;}
};

template<class T>
auto print(T data) -> decltype(+data)
{
	return +data;
}

int main()
{
	base f=4.55;
	cout << print(f) << endl;
	cout << print(6) << endl;
	cout << print("sdfsdf") << endl;
	return 0;
}
