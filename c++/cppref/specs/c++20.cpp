coroutines
concepts

three-way comparison

provides three type of ordering
	strong_ordering:  equal and equivalent
	weak_ordering: only equivalent
	partial_ordering: cant guarantee order

	define the <=> operator with the ordering policy
	use the space spaceship opeartor directly
	if (auto cmp = p1 <=> p2; cmp == 0)

	or and default the comparison operators == to use the <=>
	for compiler generateor operator ==
	p1 == p2
	

	struct P
	{
		int x{};
		int y;

		std::strong_ordering  operator<=>(const P& other) const
		{
			if (auto cmp = x<=> other.x; cmp!=0)
				return cmp;
			return y <=> other.y;
		}

		bool operator==(const P& other) const = default;
	};



designated initializers
template syntax for lambdas
range-based for loop with initializer
[[likely]] and [[unlikely]] attributes
deprecate implicit capture of this
class types in non-type template parameters
constexpr virtual functions
explicit(bool)
immediate functions
using enum
lambda capture of parameter pack
char8_t
constinit
__VA_OPT__
