#include<iostream>

class Base
{
	public:
		Base() { std::cout << this << " Base::Base()" << '\n';}
		~Base() { std::cout << this << " Base::~Base()" << '\n';}
	
	private:
		int a;
		int b;
};

class Derv : public Base
{
	public:
		Derv() { std::cout << this << " Derv::Derv()" << '\n';}
		~Derv() { std::cout << this << " Derv::~Derv()" << '\n';}
	private:
		int a;
		int b;
};

class Base2
{
	public:
		Base2() { std::cout << this << " Base2::Base2()" << '\n';}
		~Base2() { std::cout << this << " Base2::~Base2()" << '\n';}
	private:
		int a;
		int b;
};

class Derv12 : public Base, public Base2
{
	public:
		Derv12() { std::cout << this << " Derv12::Derv12()" << '\n';}
		~Derv12() { std::cout << this << " Derv12::~Derv12()" << '\n';}
	private:
		int a;
		int b;
};

