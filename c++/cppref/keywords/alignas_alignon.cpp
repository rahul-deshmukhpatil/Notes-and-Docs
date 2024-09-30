#include <cstddef>
#include <iostream>
 

struct alignas(32) S
{};

int main()
{
    std::cout << "alignof(std::max_align_t):" << alignof(std::max_align_t) << '\n';
    std::cout << "alignof(S): "<< alignof(S) << '\n';
}
