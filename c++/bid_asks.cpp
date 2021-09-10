#include <bits/c++config.h>
#include <set>

class SpreadTracker
{
	struct Spread
	{
		int bid;
		int ask;
	};

	struct SpreadBidCompare 
	{
		bool operator()(const Spread& s1, const Spread s2) const
		{
			return s1.bid < s2.bid;
		};
	};

	struct SpreadAskCompare 
	{
		bool operator()(const Spread& s1, const Spread s2) const
		{
			return s1.ask < s2.ask;
		};
	};

	std::multiset<Spread, SpreadBidCompare> bidSpreads;
	std::multiset<Spread, SpreadAskCompare> askSpreads;
	std::size_t overlappingCount{0};

public:
	std::size_t findBidCount(Spread newSpread)
	{
		auto itr = bidSpreads.lower_bound(newSpread);

		if(itr == bidSpreads.end())
			return 0;

		const auto dummySpread = Spread{newSpread.ask, newSpread.ask};

		auto lastItr = bidSpreads.lower_bound(dummySpread);
		
		return std::distance(itr, lastItr);
	}

	std::size_t findAskCount(Spread newSpread)
	{
		auto itr = askSpreads.lower_bound(newSpread);

		const auto dummySpread = Spread{newSpread.bid, newSpread.bid};

		auto firstItr = askSpreads.lower_bound(dummySpread);
		
		return std::distance(firstItr, itr);
	}

	void add(int bid, int ask)
	{
		Spread newSpread{bid, ask};
	
		overlappingCount += findBidCount(newSpread);
		overlappingCount += findAskCount(newSpread);

		bidSpreads.insert(newSpread);		
		askSpreads.insert(newSpread);		
	}

	int count()
	{
		return overlappingCount;
	}
};

int main()
{
	SpreadTracker s;
	s.add(1,3);
	cassert(0 == s.count());
	s.add(2,9);
	cassert(1 == s.count());
	s.add(3,5);
	cassert(3 == s.count());
	s.add(4,6);
	cassert(5 == s.count());

	return 0;
}
