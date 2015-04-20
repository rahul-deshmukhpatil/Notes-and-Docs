#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef std::map<int, int> container;

template <unsigned n>
class fact
{
	public:
	enum{value= n + fact<n-1>::value};
};

template <>
class fact<0>
{
	public:
	enum{value=0};
};

void insert(container& c, int key, int val)
{
	auto itr = c.insert(make_pair(key,val));
	if(!itr.second)
	{
		cout << "re-insert " << "[" << key << "," << val << "]" << "!!!" << endl;
#if 0
		c.erase(itr.first);
		c.insert(make_pair(key,val));
#else
		itr.first->second = val;
#endif
	}
}

void print(container& c)
{
	cout << "Container has : ";
	for(auto itr:c)
	{
		cout << "[" << itr.first << "," << itr.second << "]" << " "; 	
	}
	cout << endl;
}

void print(std::vector<int>& c)
{
	cout << "Container has : ";
#if 1
	for(auto itr:c)
	{
		cout << itr << " "; 	
	}
	cout << endl;
#else
	for (std::vector<int>::iterator it = c.begin() ; it != c.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
#endif
}
int main()
{
	std::vector<int> val = {1, 2 ,4 };
	container intContainer;
	insert(intContainer, 5, 50);
	insert(intContainer, 1, 10);
	insert(intContainer, 5, 10);
	print(intContainer);
	print(val);
	cout<<"fact<5> : " << fact<122333>::value << endl;
}



