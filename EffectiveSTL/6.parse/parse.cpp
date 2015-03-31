/*
 * Effective STL
 * item 6: vex parsing 
 */
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <typeinfo>
#include <algorithm>
#include <sys/time.h>
#include <stdio.h>

class base
{
};

int main()
{
	// data is function
	base data(base i);
	// data1 is function, ignore the parenthesis
	base data1(base (i));
	// data2 is function
	base data2(base);
	
	// df is function
	base df(base (*pf)());
	// df1 is function
	base df1(base pf());
	// df2 is function
	base df2(base ());
	return 0;
}
