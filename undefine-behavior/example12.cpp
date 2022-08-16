#include <stdio.h>

size_t *p[1000];

void f()
{
    for (size_t i = 0; i < 1000; i++)
        p[0][i] = 0;
}

int main(int argc, char const *argv[])
{
    p[0] = (size_t *) p;
    f();
    return 0;
}

// clang++ -O2 example12.cpp -o example12 && ./example12
// g++ -O2 example12.cpp -o example12 && ./example12
// clang++ -O2 -fsanitize=undefined example12.cpp -o example12 && ./example12

// -fno-strict-aliasing
