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
		base(base& b){ cout << "Rvalue constructor" << endl;}
	private:
		~base(){ cout << "base destrctr: " << this << endl;}
};

class derived:public base
{
	public:
		derived(float data=0.1){ cout << "derived constr" << endl;}
		~derived(){ cout << "derived destrctr: " << this << endl;}
};



int main()
{
	base b(1);
	cout << "main ends" << endl;
	return 0;
}
