/*
 * Effective STL
 */
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <typeinfo>
#include <sys/time.h>
#include <stdio.h>

using namespace std;

#if	defined(VECTOR)
typedef std::vector<DATATYPE> dataType ;
#pragma warning compiling program as vector !!!
#elif defined(SET)
typedef std::set<DATATYPE> dataType;
#pragma warning compiling program as set !!!
#elif defined(LIST)
typedef std::list<DATATYPE> dataType;
#pragma warning compiling program as map !!!
#endif
 

int main()
{
	dataType iv;

	dataType::iterator it = iv.begin();
// Insert the element COUNT times.	
	iv.insert(it, COUNT, VALUE);
	
	struct timeval globalClock;
	gettimeofday(&globalClock,0);
	long int tv_sec = globalClock.tv_sec;
	long int tv_usec = globalClock.tv_usec;


#if defined(SIZE) 
	if(iv.size() == 0)
#elif defined(EMPTY)
	if(iv.empty())
#endif
	{
		cout << "DataType: " << typeid(iv).name() << "is empty" << endl;
	}
	else
	{
		gettimeofday(&globalClock,0);
		long int sec = globalClock.tv_sec - tv_sec;
		double diff = sec + ((globalClock.tv_usec - tv_usec) * 0.000001);
		printf("Time Now : %ld.%06ld\n", tv_sec, tv_usec);
		printf("Time Now : %ld.%06ld: Total Time: %f\n", globalClock.tv_sec, globalClock.tv_usec, diff);
		cout << "DataType: " << typeid(iv).name() << "is not empty: size " << iv.size() << endl;
	}

	return 0;
}
