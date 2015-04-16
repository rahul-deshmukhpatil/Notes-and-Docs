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
		float operator+(){return f;}
};

void f(std::unique_ptr<base> ptr)
{
	std::unique_ptr<base> np = std::move(ptr);
}

int main()
{
	std::unique_ptr<base> up(new base(5.5));
	f(std::move(up));
	cout << "exiting main" << endl;
	return 0;
}
