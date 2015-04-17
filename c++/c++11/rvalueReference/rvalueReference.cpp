/*
 * Program demonstrates use of use of the rvalue reference 
*/

#include <iostream>
#include <memory>

using namespace std;

class base
{
	float f;
	public:
		base(float data = 0.1):f(data){ cout << "base constr" << endl;}
		base(const base &b){ cout << "Normal constructor" << endl;}
		base(base&& b){ cout << "Rvalue constructor" << endl;}
		~base(){ cout << "base destrctr: " << this << endl;}
};

class derived:public base
{
	public:
		derived(float data=0.1){ cout << "derived constr" << endl;}
		~derived(){ cout << "derived destrctr: " << this << endl;}
};


//Here I am purposefully creating two objects and returning based upon val,
// so that return value optimization does not come into scenario
base func(bool val)
{
	base b(4.5);
	base b1(5.0);
	if(val) 
		return b;
	return b1;
}


int main()
{
	cout << "main starts" << endl;
	base b(1);
	base b1(b);
	base b2(func(false));
	cout << "main ends" << endl;
	return 0;
}
