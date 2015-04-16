/*
 * Program demonstrates use of std::unique_ptr 
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

int main()
{
	base b(5.5);
	cout << "Subscript op : " <<  b[1]<< endl;
	cout << "exiting main" << endl;
	return 0;
}
