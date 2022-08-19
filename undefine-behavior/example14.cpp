#include <stdio.h>
#include <iostream>

void test1()
{
    int a, b, x;
    std::cin >> x;
    if (x)
        a = 123;
    else
        b = 456;

    std::cout << (x ? a : b) << std::endl;
}

void test2()
{
    // 没有未定义行为
    int a;
    float *b = (float *)&a;
    *b = 1.23;
    std::cout << *b * *b << std::endl;
    a = 456;
    std::cout << a * a << std::endl;
}

// char main[] = {0xe, 0xf};

int main(int argc, char const *argv[])
{
    /* code */
    test2();
    return 0;
}

// clang++ -O2 example14.cpp -o example14 && ./example14
// g++-12 -O2 example14.cpp -o example14 && ./example14
// clang++ -O2 -fsanitize=undefined example14.cpp -o example14 && ./example14