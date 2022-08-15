#include <iostream>

int main(int argc, char const *argv[])
{
    int i;
    std::cin >> i;
    std::cout << i * 2 / 2 << std::endl;
    return 0;
}
// 编译器会优化上面的式子为std::cout << i << std::endl;

// clang++ -O2 example8.cpp -o example8 && ./example8
// g++ -O2 example8.cpp -o example8 && ./example8
// clang++ -O2 -fsanitize=undefined example8.cpp -o example8 && ./example8