/*
 * Effective STL
 * item 5: using range memebers
 */
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <typeinfo>
#include <algorithm>
#include <sys/time.h>
#include <stdio.h>

using namespace std;

class base
{
	int data;
	public:
		base(int a)
		{
			data = a;
		}
		base(const base& A)
		{
			printf("Copy Constr: %d\n", A.data);
			data = A.data;
		}
		base& operator =(const base A)
		{
			printf("Operator = : %d\n", A.data);
			data = A.data;
			return *this;
		}
		
		friend std::ostream& operator << (std::ostream&, base&);
};

std::ostream& operator<<(std::ostream& o, base& A)
{
	o<<A.data;
	return o;
}


#if defined(TYPE)
	typedef TYPE BASETYPE;
#else
	typedef base BASETYPE;
#endif

#if defined(SET)
	typedef std::set container;
	#pragma warning compiling program as set !!!
#elif defined(LIST)
	typedef std::list container;
	#pragma warning compiling program as map !!!
#else
	typedef std::vector<BASETYPE> container;
	#pragma warning compiling program as vector !!!
#endif

struct timeval globalClock;
long int tv_sec;
long int tv_usec;

long int tv_sec_end;
long int tv_usec_end;

void recordStartTime()
{
	gettimeofday(&globalClock,0);	
	tv_sec = globalClock.tv_sec;
	tv_usec = globalClock.tv_usec;
} 

void recordEndTime()
{
	gettimeofday(&globalClock,0); 	
	tv_sec_end = globalClock.tv_sec;
	tv_usec_end = globalClock.tv_usec;
}

void printTimeDiff()
{
	long int sec = tv_sec_end - tv_sec;
	double diff = sec + ((tv_usec_end - tv_usec) * 0.000001);
	printf("Time Now : %ld.%06ld\n", tv_sec, tv_usec);
	printf("Time Now : %ld.%06ld: Total Time: %f\n", globalClock.tv_sec, globalClock.tv_usec, diff);
}

template <class T>
class printClass
{
	public:
		void operator()(T obj)
		{
			cout << ' ' << obj;
		}
};

template<class T, class InputIterator>
void printContainer(InputIterator first, InputIterator last)
{
	printClass<T> printObj;
	printf("Container: ");
	for_each(first, last, printObj);
	cout << endl;
}

int main()
{
	container iv;
	container ivb;

	iv.push_back(65);
	iv.push_back(66);
	iv.push_back(67);

	ivb.push_back(75);
	ivb.push_back(76);
	ivb.push_back(77);

	cout << "constructed bothe the vectors: " << endl;
#ifdef INSERT
	iv.insert(iv.end(), ivb.begin(), ivb.end());
	cout << "concatinated via insert" << endl;
#else
	copy(ivb.begin(), ivb.end(), back_inserter(iv));
	cout << "concatinated via copy" << endl;
#endif
	printContainer<BASETYPE>(iv.begin(), iv.end());
	return 0;
}
