#include <stdio.h>
#include <iostream>

int hash(const signed char *s)
{
    int h = 1;
    for (; *s != 0; ++s)
    {
        h = h * 131 + *s;
    }
    if (h < 0)
        h = -(h + 1);

    return h;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", hash((const signed char *)argv[1]));
    std::cout << hash((const signed char *)argv[1]) << std::endl;
    return 0;
}

// clang++ -O2 example10.cpp -o example10 && ./example10
// g++ -O2 example10.cpp -o example10 && ./example10
// clang++ -O2 -fsanitize=undefined example10.cpp -o example10 && ./example10