#include <stdio.h>

void foo(int *p)
{
    int dead = *p; 
    dead *= 0x7fffffff;
    *p = dead / 0x7fffffff;
    // dead 死变量前面三行相当于啥都没干
    if (p != nullptr)
        printf("ok\n");
    printf("%d\n", dead / dead);
    // 编译器认为任何整数除以自身都是1，直接将dead / dead 优化成1
}

int main(int argc, char const *argv[])
{
    foo(nullptr);
    return 0;
}

// clang++ -O2 example9.cpp -o example9 && ./example9
// g++ -O2 example9.cpp -o example9 && ./example9
// clang++ -O2 -fsanitize=undefined example9.cpp -o example9 && ./example9