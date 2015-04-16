/*
 * Program demonstrates use of static member
*/

#include <iostream>
#include <memory>

using namespace std;

class base
{
	float f;
	public:
		base(float data):f(data){ cout << "base constr" << endl;}
		~base(){ cout << "base destrctr: " << this << endl;}
		float operator [](int i) { return f;}
		float operator+(){return f;}
};
void f()
{
	static base b(5.4);
}

int main()
{
	cout << "main starts" << endl;
	f();
	cout << "main ends" << endl;
	return 0;
}
