# C++20/17/14/11

## Overview
Many of these descriptions and examples come from various resources (see [Acknowledgements](#acknowledgements) section), summarized in my own words.

C++20 includes the following new language features:
- [coroutines](#coroutines)
- [concepts](#concepts)
- [designated initializers](#designated-initializers)
- [template syntax for lambdas](#template-syntax-for-lambdas)
- [range-based for loop with initializer](#range-based-for-loop-with-initializer)
- [likely and unlikely attributes](#likely-and-unlikely-attributes)
- [deprecate implicit capture of this](#deprecate-implicit-capture-of-this)
- [class types in non-type template parameters](#class-types-in-non-type-template-parameters)
- [constexpr virtual functions](#constexpr-virtual-functions)
- [explicit(bool)](#explicitbool)
- [immediate functions](#immediate-functions)
- [using enum](#using-enum)
- [lambda capture of parameter pack](#lambda-capture-of-parameter-pack)
- [char8_t](#char8_t)

C++20 includes the following new library features:
- [concepts library](#concepts-library)
- [synchronized buffered outputstream](#synchronized-buffered-outputstream)
- [std::span](#stdspan)
- [bit operations](#bit-operations)
- [math constants](#math-constants)
- [std::is_constant_evaluated](#stdis_constant_evaluated)
- [std::make_shared supports arrays](#stdmake_shared-supports-arrays)
- [starts_with and ends_with on strings](#starts_with-and-ends_with-on-strings)
- [check if associative container has element](#check-if-associative-container-has-element)
- [std::bit_cast](#stdbit_cast)
- [std::midpoint](#stdmidpoint)
- [std::to_array](#stdto_array)

C++17 includes the following new language features:
- [template argument deduction for class templates](#template-argument-deduction-for-class-templates)
- [declaring non-type template parameters with auto](#declaring-non-type-template-parameters-with-auto)
- [folding expressions](#folding-expressions)
- [new rules for auto deduction from braced-init-list](#new-rules-for-auto-deduction-from-braced-init-list)
- [constexpr lambda](#constexpr-lambda)
- [lambda capture this by value](#lambda-capture-this-by-value)
- [inline variables](#inline-variables)
- [nested namespaces](#nested-namespaces)
- [structured bindings](#structured-bindings)
- [selection statements with initializer](#selection-statements-with-initializer)
- [constexpr if](#constexpr-if)
- [utf-8 character literals](#utf-8-character-literals)
- [direct-list-initialization of enums](#direct-list-initialization-of-enums)
- [fallthrough, nodiscard, maybe_unused attributes](#fallthrough-nodiscard-maybe_unused-attributes)

C++17 includes the following new library features:
- [std::variant](#stdvariant)
- [std::optional](#stdoptional)
- [std::any](#stdany)
- [std::string_view](#stdstring_view)
- [std::invoke](#stdinvoke)
- [std::apply](#stdapply)
- [std::filesystem](#stdfilesystem)
- [std::byte](#stdbyte)
- [splicing for maps and sets](#splicing-for-maps-and-sets)
- [parallel algorithms](#parallel-algorithms)

C++14 includes the following new language features:
- [binary literals](#binary-literals)
- [generic lambda expressions](#generic-lambda-expressions)
- [lambda capture initializers](#lambda-capture-initializers)
- [return type deduction](#return-type-deduction)
- [decltype(auto)](#decltypeauto)
- [relaxing constraints on constexpr functions](#relaxing-constraints-on-constexpr-functions)
- [variable templates](#variable-templates)
- [\[\[deprecated\]\] attribute](#deprecated-attribute)

C++14 includes the following new library features:
- [user-defined literals for standard library types](#user-defined-literals-for-standard-library-types)
- [compile-time integer sequences](#compile-time-integer-sequences)
- [std::make_unique](#stdmake_unique)

C++11 includes the following new language features:
- [move semantics](#move-semantics)
- [variadic templates](#variadic-templates)
- [rvalue references](#rvalue-references)
- [forwarding references](#forwarding-references)
- [initializer lists](#initializer-lists)
- [static assertions](#static-assertions)
- [auto](#auto)
- [lambda expressions](#lambda-expressions)
- [decltype](#decltype)
- [type aliases](#type-aliases)
- [nullptr](#nullptr)
- [strongly-typed enums](#strongly-typed-enums)
- [attributes](#attributes)
- [constexpr](#constexpr)
- [delegating constructors](#delegating-constructors)
- [user-defined literals](#user-defined-literals)
- [explicit virtual overrides](#explicit-virtual-overrides)
- [final specifier](#final-specifier)
- [default functions](#default-functions)
- [deleted functions](#deleted-functions)
- [range-based for loops](#range-based-for-loops)
- [special member functions for move semantics](#special-member-functions-for-move-semantics)
- [converting constructors](#converting-constructors)
- [explicit conversion functions](#explicit-conversion-functions)
- [inline-namespaces](#inline-namespaces)
- [non-static data member initializers](#non-static-data-member-initializers)
- [right angle brackets](#right-angle-brackets)
- [ref-qualified member functions](#ref-qualified-member-functions)
- [trailing return types](#trailing-return-types)
- [noexcept specifier](#noexcept-specifier)
- [char32_t and char16_t](#char32_t-and-char16_t)
- [raw string literals](#raw-string-literals)

C++11 includes the following new library features:
- [std::move](#stdmove)
- [std::forward](#stdforward)
- [std::thread](#stdthread)
- [std::to_string](#stdto_string)
- [type traits](#type-traits)
- [smart pointers](#smart-pointers)
- [std::chrono](#stdchrono)
- [tuples](#tuples)
- [std::tie](#stdtie)
- [std::array](#stdarray)
- [unordered containers](#unordered-containers)
- [std::make_shared](#stdmake_shared)
- [std::ref](#stdref)
- [memory model](#memory-model)
- [std::async](#stdasync)
- [std::begin/end](#stdbeginend)

## C++20 Language Features

### Coroutines

## C++11 Language Features

### Move semantics
for optimization, you can copy resources from temporories rvalues or expiring xvalues (specified by std::move)
	
### Rvalue references
rvalues can be bound to rvalue ref or const lvalue ref.

passing rvalue without std::move, will pass it as a lvalue
```c++
int&& rrx = 5;
f(rrx); // Will call f(int&) 
f(std::move(rrx)); // Will call f(int&&) 
```

### Forwarding references
universal_references, applies rules of the reference collapsing
* `T& &` becomes `T&`
* `T&& &` becomes `T&`

* `T& &&` becomes `T&`
* `T&& &&` becomes `T&&`

`auto` type deduction with lvalues and rvalues:
```c++
int x = 0; // `x` is an lvalue of type `int`
auto&& al = x; // `al` is an lvalue of type `int&` -- binds to the lvalue, `x`
auto&& ar = 0; // `ar` is an lvalue of type `int&&` -- binds to the rvalue temporary, `0`
```

Template type parameter deduction with lvalues and rvalues:
```c++
// Since C++14 or later:
void f(auto&& t) {
  // ...
}

// Since C++11 or later:
template <typename T>
void f(T&& t) {
  // ...
}

int x = 0;
f(0); // T is int, deduces as f(int &&) => f(int&&)
f(x); // T is int&, deduces as f(int& &&) => f(int&)

int& y = x;
f(y); // T is int&, deduces as f(int& &&) => f(int&)

int&& z = 0; // NOTE: `z` is an lvalue with type `int&&`.
f(z); // T is int&, deduces as f(int& &&) => f(int&)
f(std::move(z)); // T is int, deduces as f(int &&) => f(int&&)
```

See also: [`std::move`](#stdmove), [`std::forward`](#stdforward), [`rvalue references`](#rvalue-references).

### Variadic templates

template parameter pack can accept variadic types, values(non-types) or templates
also sizeof...() operator

```c++
template <typename First, typename... Args>
auto sum(const First first, const Args... args) -> decltype(first) {
  const auto values = {first, args...};
  const auto size = sizeof...(Args); 
    return std::accumulate(values.begin(), values.end(), First{0});
	}

```

### initializer list
to intialize vectors easily or as a separate data type
auto list = {1, 2, 3}; // auto = std::initializer_list
std::vector v_list = {1,2,3};

### Static assertions
expressions in static assertions must be constexpr

### auto
readable and easy to update code
in c++11, auto functions return types must be specified using
decltype traiing return type

```c++
auto&& e = 1; // int&&
auto&& f = b; // int&
auto g = new auto(123); // int*
const auto h = 1; // const int
auto i = 1, j = 2, k = 3; // int, int, int
```

### lamda
unnamed function objects.
These are acutally implemented as templates with function opeartors

```c++
* `[]` - captures nothing.
* `[=]` - capture local objects (local variables, parameters) in scope by value.
* `[&]` - capture local objects (local variables, parameters) in scope by reference.
* `[this]` - capture `this` by reference.
* `[a, &b]` - capture objects `a` by value, `b` by reference.

```

### decltype
```c++
int a = 1; // `a` is declared as type `int`
decltype(a) b = a; // `decltype(a)` is `int`
const int& c = a; // `c` is declared as type `const int&`
decltype(c) d = a; // `decltype(c)` is `const int&`
decltype(123) e = 123; // `decltype(123)` is `int`
int&& f = 1; // `f` is declared as type `int&&`
decltype(f) g = 1; // `decltype(f) is `int&&`
decltype((a)) h = g; // `decltype((a))` is int&
```
```c++
template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) {
  return x + y;
}
add(1, 2.0); // `decltype(x + y)` => `decltype(3.0)` => `double`
```

### Type aliases
Semantically similar to using a `typedef` however, type aliases with `using` are easier to read and are compatible with templates.
```c++
template <typename T>
using Vec = std::vector<T>;
Vec<int> v; // std::vector<int>

using String = std::string;
String s {"foo"};
```
### nullptr
C++11 introduces a new null pointer type designed to replace C's `NULL` macro. `nullptr` itself is of type `std::nullptr_t` and can be implicitly converted into pointer types, and unlike `NULL`, not convertible to integral types except `bool`.
```c++
void foo(int);
void foo(char*);
foo(NULL); // error -- ambiguous
foo(nullptr); // calls foo(char*)
```

### Attributes
Attributes provide a universal syntax over `__attribute__(...)`, `__declspec`, etc.

```c++
// `noreturn` attribute indicates `f` doesn't return to the caller
// i.e. either exit from application or is infinite loop.
[[ noreturn ]] void f() {
  throw "error";
}
```
It helps compiler to optimize code better or finding
dead code. and skip some compilation warning

### constexpr
All `constexpr` variables are implicitely const.


### Delegating constructors

### Explicit virtual overrides

### Final specifier

### Deleted functions
  A(const A&) = delete;

### Range-based for loops
```c++
std::array<int, 5> a {1, 2, 3, 4, 5};
for (int& x : a) x *= 2;
// a == { 2, 4, 6, 8, 10 }
```

### Special member functions for move semantics
  A(A&& o) : s{std::move(o.s)} {}

### Converting constructors
Note that the braced list syntax does not allow narrowing:
```c++
  A(int) {}

	A b {1.1}; // Error narrowing conversion from double to int
```
Note that if a constructor accepts a std::initializer_list, it will be called instead:


### Explicit conversion functions
```c++
struct B {
  explicit operator bool() const { return true; }
};

B b;
if (b); // OK calls B::operator bool()
bool bb = b; // error copy-initialization does not consider B::operator bool()
```

### Inline namespaces
All members of an inline namespace are treated as if they were part of its parent namespace, allowing specialization of functions and easing the process of versioning. This is a transitive property, if A contains B, which in turn contains C and both B and C are inline namespaces, C's members can be used as if they were on A.

```c++
namespace Program {
  namespace Version1 {
    int getVersion() { return 1; }
    bool isFirstVersion() { return true; }
  }
  inline namespace Version2 {
    int getVersion() { return 2; }
  }
}

int version {Program::getVersion()};              // Uses getVersion() from Version2
int oldVersion {Program::Version1::getVersion()}; // Uses getVersion() from Version1
bool firstVersion {Program::isFirstVersion()};    // Does not compile when Version2 is added
```

### Non-static data member initializers
member initialization for the default constructor

### Right angle brackets

### Ref-qualified member functions
Member functions can now be qualified depending on whether `*this` is an lvalue or rvalue reference.

```c++
struct Bar {
  // ...
};

struct Foo {
  Bar getBar() & { return bar; }
  Bar getBar() const& { return bar; }
  Bar getBar() && { return std::move(bar); }
private:
  Bar bar;
};

Foo foo{};
Bar bar = foo.getBar(); // calls `Bar getBar() &`

const Foo foo2{};
Bar bar2 = foo2.getBar(); // calls `Bar Foo::getBar() const&`

Foo{}.getBar(); // calls `Bar Foo::getBar() &&`
std::move(foo).getBar(); // calls `Bar Foo::getBar() &&`

std::move(foo2).getBar(); // calls `Bar Foo::getBar() const&&`
```

### Trailing return types
C++11 allows functions and lambdas an alternative syntax for specifying their return types.
```c++
int f() {
  return 123;
}
// vs.
auto f() -> int {
  return 123;
}
```
```c++
auto g = []() -> int {
  return 123;
};
```
This feature is especially useful when certain return types cannot be resolved:
```c++
// NOTE: This does not compile!
template <typename T, typename U>
decltype(a + b) add(T a, U b) {
    return a + b;
}

// Trailing return types allows this:
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}
```
In C++14, `decltype(auto)` can be used instead.


### Noexcept specifier
The `noexcept` specifier specifies whether a function could throw exceptions. It is an improved version of `throw()`.

```c++
void func1() noexcept;        // does not throw
void func2() noexcept(true);  // does not throw
void func3() throw();         // does not throw

void func4() noexcept(false); // may throw
```

Non-throwing functions are permitted to call potentially-throwing functions. Whenever an exception is thrown and the search for a handler encounters the outermost block of a non-throwing function, the function std::terminate is called.

```c++
extern void f();  // potentially-throwing
void g() noexcept {
    f();          // valid, even if f throws
    throw 42;     // valid, effectively a call to std::terminate
}
```

### Raw string literals
C++11 introduces a new way to declare string literals as "raw string literals". Characters issued from an escape sequence (tabs, line feeds, single backslashes, etc.) can be inputted raw while preserving formatting. This is useful, for example, to write literary text, which might contain a lot of quotes or special formatting. This can make your string literals easier to read and maintain.

A raw string literal is declared using the following syntax:
```
R"delimiter(raw_characters)delimiter"
```
where:
* `delimiter` is an optional sequence of characters made of any source character except parentheses, backslashes and spaces.
* `raw_characters` is any raw character sequence; must not contain the closing sequence `")delimiter"`.

Example:
```cpp
// msg1 and msg2 are equivalent.
const char* msg1 = "\nHello,\n\tworld!\n";
const char* msg2 = R"(
Hello,
	world!
)";
```

## C++11 Library Features

### std::move
A definition of `std::move` (performing a move is nothing more than casting to an rvalue reference):
```c++
template <typename T>
typename remove_reference<T>::type&& move(T&& arg) {
  return static_cast<typename remove_reference<T>::type&&>(arg);
}
```

Transferring `std::unique_ptr`s:
```c++
std::unique_ptr<int> p1 {new int{0}};  // in practice, use std::make_unique
std::unique_ptr<int> p2 = p1; // error -- cannot copy unique pointers
std::unique_ptr<int> p3 = std::move(p1); // move `p1` into `p3`
                                         // now unsafe to dereference object held by `p1`
```

### std::thread

### std::to_string 
for float and int conversion to string

### Type traits
```c++
static_assert(std::is_integral<int>::value);
static_assert(std::is_same<int, int>::value);
static_assert(std::is_same<std::conditional<true, int, double>::type, int>::value);
```

### Smart pointers
std::weak_ptr

### std::chrono

### Tuples
Tuples are a fixed-size collection of heterogeneous values. Access the elements of a `std::tuple` by unpacking using [`std::tie`](#stdtie), or using `std::get`.
```c++
// `playerProfile` has type `std::tuple<int, const char*, const char*>`.
auto playerProfile = std::make_tuple(51, "Frans Nielsen", "NYI");
std::get<0>(playerProfile); // 51
std::get<1>(playerProfile); // "Frans Nielsen"
std::get<2>(playerProfile); // "NYI"
```

### std::tie
Creates a tuple of lvalue references. Useful for unpacking `std::pair` and `std::tuple` objects. Use `std::ignore` as a placeholder for ignored values. In C++17, structured bindings should be used instead.
```c++
// With tuples...
std::string playerName;
std::tie(std::ignore, playerName, std::ignore) = std::make_tuple(91, "John Tavares", "NYI");

// With pairs...
std::string yes, no;
std::tie(yes, no) = std::make_pair("yes", "no");
```

### std::array
`std::array` is a container built on top of a C-style array. Supports common container operations such as sorting.
```c++
std::array<int, 3> a = {2, 1, 3};
std::sort(a.begin(), a.end()); // a == { 1, 2, 3 }
for (int& x : a) x *= 2; // a == { 2, 4, 6 }
```
### Unordered containers
These containers maintain average constant-time complexity for search, insert, and remove operations. In order to achieve constant-time complexity, sacrifices order for speed by hashing elements into buckets. There are four unordered containers:
* `unordered_set`
* `unordered_multiset`
* `unordered_map`
* `unordered_multimap`


## Acknowledgements
 * https://github.com/AnthonyCalandra/modern-cpp-features/graphs/contributors

## Content Contributors
See: https://github.com/AnthonyCalandra/modern-cpp-features/graphs/contributors

## License
MIT
