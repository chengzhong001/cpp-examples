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

void test2(){
    
}

int main(int argc, char const *argv[])
{
    /* code */

    return 0;
}

// clang++ -O2 example14.cpp -o example14 && ./example14
// g++-12 -O2 example14.cpp -o example14 && ./example14
// clang++ -O2 -fsanitize=undefined example14.cpp -o example14 && ./example14