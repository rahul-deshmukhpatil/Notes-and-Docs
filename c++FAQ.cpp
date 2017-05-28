Built-in / Intrinsic / Primitive Data Types
=============================================
Size of char is always 1 byte. On some platforms 1 byte could contain more than 8 bits.
Byte is something that you could address with. Unit of sizeof is a byte.

POD: plain old data is data type that is compliant with C. It is copied bit by bit.
 To make sure the other rules match, the C++ version must not have virtual functions, base classes, non-static members that are private or protected, or a destructor. It can, however, have static data members, static member functions, and non-static non-virtual member functions.



classes:
=============================================
It is set of data types and operations on it
Object is instance of class and it has memory/storage associated with it.
Good interface hides unnecessory implimentation and gives enough operations to act upon object
Encapsulation is saperating interface(stable accessible to ousider) from implimentation(changing, volatile part)
Encapsulation is for code not people. People can see private members and functions.
Member method can access private members of other objects of same class used for =,<= , +, - etc operators.
Encapsulation prevents mistakes
Struct members are public by default and in class they are private,

C++11
class X {
    constexpr int c1 = 42; // preferred
    static const int c2 = 7;
    enum { c3 = 19 };
}

Normal C++ specs
   class Z {
        static char* p;     // initialize in definition
        const int i;        // initialize in constructor
    public:
        Z(int ii) :i(ii) { }
    };
    char* Z::p = "hello, there";

You can take the address of a static member if (and only if) it has an out-of-class definition:

   class AE {
        // ...
    public:
        static const int c6 = 7;
        static const int c7 = 31;
    };
    const int AE::c7;   // definition
    int f()
    {
        const int* p1 = &AE::c6;    // error: c6 not an lvalue
        const int* p2 = &AE::c7;    // ok
        // ...
    }

To ensure that the addresses of two different objects will be different, empty class will have atleast size 1.
But Empty base class could have size 0, called as Empty Base Class Optimization.
There is an interesting rule that says that an empty base class need not be represented by a separate byte:

    struct X : Empty {
        int a;
        // ...
    };
    void f(X* p)
    {
        void* p1 = p;
        void* p2 = &p->a;
        if (p1 == p2) cout << "nice: good optimizer";
    }

Constructors
=============================================
They build object

List x; //calls constructor
List x(); //function declaration x is functions returns List

Constructor of class can not call constructor same class to initialize same object

If all arguments have have default value, that becomes default constructor.
	Fred(int i=3, int j=5); 

Static allocated or dynamic allocated arrays call default constructors.
	Fred a[10];              // Calls the default constructor 10 times
	Fred* p = new Fred[10];  // Calls the default constructor 10 times

In case of array, you can explicit initialization of arrays with other constructors
int main()
{
  Fred a[10] = {
      Fred(5,7), Fred(5,7), Fred(5,7), Fred(5,7), Fred(5,7),  // The 10 Fred objects are
      Fred(5,7), Fred(5,7), Fred(5,7), Fred(5,7), Fred(5,7)   // initialized using Fred(5,7)
    };
  // ...
}

Constructors should used initializers list to initialized the members. By default if you do not provide
initializers list, constructor will still include default initializer list. It is optimized way of creating object.
Otherwise initializing members in constructor body, will cause default constructor calling in initializer list
and then assignment operator in the body.

Initializers list should have members in order, Immediate base classes (left to right), then member objects (top to bottom).
No matter what order you specify in the initilizers list, they will be still called in above order only.

Do not initialize one member with another member in initializers list. This puts order dependancy
and when class definition changes order of those members, constructor breaks.

this pointer works in constructor, but can not be used to call the derived call function using virtual function.

Named constructors: and functions which return constructed objects.

	class Point {
	public:
	  static Point rectangular(float x, float y);      // Rectangular coord's
	  static Point polar(float radius, float angle);   // Polar coordinates
	  // These static methods are the so-called "named constructors"
	  // ...
	private:
	  Point(float x, float y);     // Rectangular coordinates
	  float x_, y_;
	};
	inline Point::Point(float x, float y)
	  : x_(x), y_(y) { }
	inline Point Point::rectangular(float x, float y)
	{ return Point(x, y); }
	inline Point Point::polar(float radius, float angle)
	{ return Point(radius*std::cos(angle), radius*std::sin(angle)); }

Return by value does not mean extra copies and overhead.
Sometimes compilers have return by value optimization. Function constructs
the return object directly in the storage place of variable catching return value.
Even returning local object of function uses this optimization by creating local
object which is to be returned in storage space of variable catching return value.

Because you must explicitly define your class’s static data members.
If you do not define static data member, you will get linker error  "undefined external".

you can initilize the static const in the declaration.But in order to take address of the
static data member you need to define it exactly one compilation unit.

static initialization order fiasco
When there are two static members in different compilation unit. And one of them initialize 
by calling method of other, y calling method of  x.goBowling().
You can prevent this by using "Construct by first use" idom.
Construct the other static member as function static and then call then function to get static variable.

// File y.cpp
#include "Barney.h"
Barney y;

Barney::Barney()
{
  // ...
  // x.goBowling(); calling method of static object
  x().goBowling();  // calling x() function returning x
  // ...
}

// File x.cpp
#include "Fred.h"
//Fred x; // No global static object

Fred& x()
{
  static Fred* ans = new Fred(); // return static object of function
  return *ans;	//ans will never be freed
}

or 

Fred& x()
{
  static Fred ans; // return static object of function
  return *ans;	//ans will be freed at program termination
				// order of deconstruction can not be controlled
}


"static initialization order fiasco” also exists for class static data members
so use the put the static data member into the static function as local static variable.
And use this function to get the static variable reference or address.

// File X.h
class X {
public:
  // ...
private:
  // static Fred x_; remove this
	static Fred x();
};

Fred& X::x()
{
  static Fred* ans = new Fred();
  return *ans;
}

void X::someMethod()
{
  //x_.goBowling(); x_ might not be initilized when X::someMethod is called for X object
  x().goBowling();
}

"static initialization order fiasco” also exists for intrinsic types
	#include <iostream>
	int f();  // forward declaration
	int g();  // forward declaration
	int x = f();
	int y = g();
	int f()
	{
		std::cout << "using 'y' (which is " << y << ")\n";
		return 3*y + 7;
	}
	int g()
	{
		std::cout << "initializing 'y'\n";
		return 5;
	}

define x and y as static under function as local static member,and use function 
to access thier values to solve this problem.

	#include <iostream>
	int f();  // forward declaration
	int g();  // forward declaration
	int& x()
	{
		static int ans = f();
		return ans;
	}
	int& y()
	{
		static int ans = g();
		return ans;
	}
	int f()
	{
		std::cout << "using 'y' (which is " << y() << ")\n";
		return 3*y() + 7;
	}
	int g()
	{
		std::cout << "initializing 'y'\n";
		return 5;
	}

Named parameter Idiom:
	C++ has fix order of positional paramters. While languages like pythn could
pass the paramters like X(legth=5, width=4) in any order while other parameters
are taken default.

	Named parameter idiom, we introduce functions which set the paratmeter and return 
the reference to object.

	File f = OpenFile("foo.txt")
			   .readonly()
			   .createIfNotExist()
			   .appendWhenWriting()
			   .blockSize(1024)
			   .unbuffered()
			   .exclusiveAccess();

	inline OpenFile& OpenFile::readonly()
	{ readonly_ = true; return *this; }
	inline OpenFile& OpenFile::readwrite()
	{ readonly_ = false; return *this; }
	inline OpenFile& OpenFile::createIfNotExist()
	{ createIfNotExist_ = true; return *this; }
	inline OpenFile& OpenFile::blockSize(unsigned nbytes)
	{ blockSize_ = nbytes; return *this; }

Foo x(Bar()) // is function declaration
Foo x = Bar(); // x is object, This fails if Foo(const Bar &) constructor is explicit.
Foo x{Bar()};  // uniform initialization

The explicit keyword is an optional decoration for constructors and conversion operators to tell the compiler that a certain constructor or conversion operator may not be used to implicitly cast an expression to its class type.


Destructors
#############################################
Destructors are called in reverse order of construction.
Destructors are called automatically for the objects on stack at the end of life span of object.
Destructors for members and base objects are called in reverse order of thier construction.
Destructors can not be overloaded and should not be explicitely called for local objects on stack.
Objects allocated with new are deallocated with delete.
No, there is nothing called as placement delete, Though objects constructed with placement new 
need to be dealloacted explicitly called destructor.
Never call excpetion from destructors that is being called because of stack unwinding, it will lead
to call std::terminate()

Allocating from  pool with placement new has saveral problems:

void sample(Pool& pool)
{
  Foo* p = new(pool) Foo();
    // ...
  p->~Foo();        // explicitly call dtor
  pool.dealloc(p);  // explicitly release the memory
}


1> The memory will leak if Foo::Foo() throws an exception.
2> The destruction/deallocation syntax is different from what most programmers are used to, so they’ll probably screw it up.
3> Users must somehow remember which pool goes with which object. 


Assignment Operator
=============================================
Self assignment is when someone assigns an object to itself. For example,
	b = b;
If you do not implement operator= correctly, self assignment could cause problem
	Fred& operator= (const Fred& f)
	{
		// Bad code: Doesn't handle self-assignment!
		delete p_;                // Line #1
		p_ = new Wilma(*f.p_);    // Line #2
			return *this;
	}

If *this and f are same then you are freeing memory on line #1 later used on line #2
If they are not same but if new Wilma might throw exception, so p_ might become dangling pointer.

solution:
	1. 
	Fred& Fred::operator= (const Fred& f)
	{
	  // This gracefully handles self assignment
	  *p_ = *f.p_; // This calls operator= for Wilma, Deep copying happens
	  return *this;
	}

	2.
	Fred& Fred::operator= (const Fred& f)
	{
	  // This gracefully handles self assignment
	  Wilma* tmp = new Wilma(*f.p_);   // No corruption if this line threw an exception
	  delete p_;
	  p_ = tmp;
	  return *this;
	}

You might want to put extra check for the self assignment in the operator =

	Fred& Fred::operator= (const Fred& f)
	{
		if (this == &f) return *this;   // Gracefully handle self assignment
		// Put the normal assignment duties here...
		return *this;
	}

But this extra check causes run time performance and all assigment are slowed for fewer self assigments.
Anyways solution 1 handles assignment gracefully.

Self-assignment is not valid for move assignment.

Default assigment operators for derived class call base class assimgnet operators automatically.
If you override derived class assigment operator you will have call base class assimgnet operators explicitely.
This is also true for move = operator.

	Derived& Derived::operator= (const Derived& d)
	{
	  // Make sure self-assignment is benign
	  Base::operator= (d);
	  // Do the rest of your assignment operator here...
	  return *this;
	}

	Derived& Derived::operator= (Derived&& d)
	{
	  // self-assignment is not allowed in move assignment
	  Base::operator= (std::move(d));
	  // Do the rest of your assignment operator here...
	  return *this;
	}


Friends
=============================================
friend function or class is allowed to have access to private members of class.
It does not violate encapsulation. It gives access to some non member friend function
or friend class, which is absolutely necessory in some cases. You need 
not to make private members as public or need not to provide get/set method for private
members so that it could be accessed from few outside functions/class. Just make
that function/class as friend.


 Virtual Friend Function Idiom :
 	virtual function accepts the reference to the Base class and calls its virtual
function (resulting into derived class overrided virtual function being called)
, and it looks like friend function is virtual.

friendship isn’t inherited, transitive, or reciprocal
	inherited : derived/base clases are not friend
	transitiveL: If class Fred declares class Wilma as a friend, and class Wilma declares class Betty as a friend, class Betty doesn’t necessarily have any special access rights to Fred objects
	reciprocal : If class Fred declares that class Wilma is a friend, Wilma objects have special access to Fred objects but Fred objects do not automatically have special access to Wilma object


Inheritance
===================================================
It is ok to convert derived class pointer to base class in case of public inheritance.
public interface serves unrelated classes.
while protected interface serves derived classes.
It is ok to have protected data in base class and accessible from derived class as design decision.


Virtual functions
===================================================
Virtual functions are dynamically binded member functions.
The type checking happens at static time but actual call binding happens run time.

Pure virtual functions can have definition, it is just that you can not call
object of class which has pure virtual function.

For each class having virtual function compiler maintains the virtual table
whos pointer  "vptr" is stored in each object of class(and its derived classes)
There is hardly any extra time cost in calling virtual function.

Dervied class function can call same name function in base class 
	void Der::f()
	{
	  Base::f();  // Or, if you prefer, this->Base::f();
	}

When class has virtual function you must have a destructor as virtual so that right 
object is deleted when delete is called with base class pointer actually pointing to derived class.

Virtual constructor:
Constructor itself can not be virtual.
But you can have clone() or create methods which could do the magic for you.

	class Shape {
		public:
			virtual ~Shape() { }                 // A virtual destructor
			virtual void draw() = 0;             // A pure virtual function
			virtual void move() = 0;
			// ...
			virtual Shape* clone()  const = 0;   // Uses the copy constructor
			virtual Shape* create() const = 0;   // Uses the default constructor
	};
	class Circle : public Shape {
		public:
			Circle* clone()  const;   // Covariant Return Types; see below
			Circle* create() const;   // Covariant Return Types; see below
			// ...
	};
	Circle* Circle::clone()  const { return new Circle(*this); }
	Circle* Circle::create() const { return new Circle();      }

	void userCode(Shape& s)
	{
		Shape* s2 = s.clone();
		Shape* s3 = s.create();
		// ...
		delete s2;    // You need a virtual destructor here
		delete s3;
	}

Here clone() and create() methods have different return types.
This is called as  Covariant Return Types. And it is allowed by compilers.

Another method, Factory pattern is used to simulate the virtual constructors.

    struct F {  // interface to object creation functions
        virtual A* make_an_A() const = 0;
        virtual B* make_a_B() const = 0;
    };
    void user(const F& fac)
    {
        A* p = fac.make_an_A(); // make an A of the appropriate type
        B* q = fac.make_a_B();  // make a B of the appropriate type
        // ...
    }
    struct FX : F {
        A* make_an_A() const { return new AX(); } // AX is derived from A
        B* make_a_B() const { return new BX();  } // BX is derived from B
    };
    struct FY : F {
        A* make_an_A() const { return new AY(); } // AY is derived from A
        B* make_a_B() const { return new BY();  } // BY is derived from B
    };
    int main()
    {
        FX x;
        FY y;
        user(x);    // this user makes AXs and BXs
        user(y);    // this user makes AYs and BYs
        user(FX()); // this user makes AXs and BXs
        user(FY()); // this user makes AYs and BYs
        // ...
    }


Proper Inheritance
=================================================================
You can convert derived* to base* safely
but not derived**  to base**. This is wrong

You can not pass derived class array to function expecting
base class array. Compiler would not give any error as 
derived* is silently converted to base* and in C/C++ arrays
is constant pointer. 

Abstract Base Class- ABC
=================================================================
Pure virtual function makes base class as abstract, to be used as interface.
Interface must be stable over the time, that is why it takes more expensive minds to design it.
= 0; at the end of pure virtual function signifies NULL.

If another class has pointer to ABC, then that class assignment operator and copy constructor
must use Virtual Constructor Idom, clone() or create method to copy the ABC pointer.

Suppose Fred has shape* (ABC pointer) as member. Shape could be Circle to Square.
With deep copy you must allocate the right object and copy its content.

class Fred {
public:
  // p must be a pointer returned by new; it must not be NULL
  Fred(Shape* p)
    : p_(p) { assert(p != NULL); }
 ~Fred()
    { delete p_; }
  Fred(const Fred& f)
    : p_(f.p_->clone()) { }
  Fred& operator= (const Fred& f)
    {
      if (this != &f) {              // Check for self-assignment
        Shape* p2 = f.p_->clone();   // Create the new one FIRST...
        delete p_;                   // ...THEN delete the old one
        p_ = p2;
      }
      return *this;
    }
  // ...
private:
  Shape* p_;
};










