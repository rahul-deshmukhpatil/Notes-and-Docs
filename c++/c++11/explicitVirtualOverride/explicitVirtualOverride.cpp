/*
 * Program demonstrates use of static and final member
*/

#include <iostream>
#include <memory>

using namespace std;

class base
{
	float f;
	public:
		base(float data = 0.1):f(data){ cout << "base constr" << endl;}
		~base(){ cout << "base destrctr: " << this << endl;}
		virtual void func(float f) { cout << "base::func(float)" << endl; }
		virtual void finalFunc(float f) final { cout << "base::func(float)" << endl; }
};

class derived:public base
{
	public:
		derived(float data=0.1){ cout << "derived constr" << endl;}
		~derived(){ cout << "derived destrctr: " << this << endl;}
		void func(int d) override { cout << "derived::func(int)" << endl; }
		void finalFunc(float f) {};
};

int main()
{
	cout << "main starts" << endl;
	derived d;
	base *b = &d;
	b->func(0.5);
	cout << "main ends" << endl;
	return 0;
}
