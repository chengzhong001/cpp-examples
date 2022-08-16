#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *p = (int *)malloc(sizeof(int));
    int *q = (int *)realloc(p, sizeof(int));
    *p = 1;
    *q = 2;
    printf("%d, %d, %d\n", p == q, *p, *q);
    return 0;
}

// clang++ -O2 example13.cpp -o example13 && ./example13
// g++-12 -O2 example13.cpp -o example13 && ./example13
// clang++ -O2 -fsanitize=undefined example13.cpp -o example13 && ./example13
