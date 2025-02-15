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
	P p1{.x=1, .y=2}; // only for aggregate types without user defined constr

template syntax for lambdas
	auto l = []<typename T>(T x) { std::cout << typeid(x).name() << "\n"; };

	l(1);
	l.template operator()<double>(1)

range-based for loop with initializer
	for (auto v = std::vector{1, 2, 3}; auto& e : v) {
	  std::cout << e;
	}
	
[[likely]] and [[unlikely]] attributes
	[[ likely ]] case x:
	if (x == y) [[ likely ]]

deprecate implicit capture of this
	Implicitly capturing this in a lambda capture using [=] is now deprecated;
	
	prefer capturing explicitly 
	by ref: using [=, this]
	by value:  [=, *this]

class types in non-type template parameters
	template<A a={}>
	struct B;

	B<A{.x=42}> b;

	
constexpr virtual functions
	virtual functions can be constexpr

	constexpr can override non-constexpr base virtual
	constexpr virtual v() {}; // base::v is non-constexpr virtual
		
	non-constexpr can override constexpr base virtual
	virtual v() {}; // base::v is constexpr virtual


explicit(bool)
	make constr explcit for some static constexpr expression

consteval or immediate functions
	must be evaluated at compile time
	square(5); // ok 
	square(x); // not ok
	while constepxr are only evaluated at compile time if
	args are constexpr
	
using enum
	std::string_view toString(Color c)
	{
		using Color;
		switch (c){
			case red: return "red";
		}
	}

lambda capture of parameter pack
	void f(Args&&... args)
	{
		return [&args...=std::forward<Args&&(args)] () {};
	}
	
char8_t
constinit
	variable must be initialized at the compile time
	or their init value is calculted at compile time
	but constinit var can be modified at runtime

	while constexpr values cant be modified as they are implicitely const


__VA_OPT__
