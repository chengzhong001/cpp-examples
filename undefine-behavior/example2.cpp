#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int i;
    for (int j = i; j < 100; j++)
        printf("%d\n", j);
    // 编译器认为i没有赋初值，任意值都可以，只要大于100 就可以将整个for循环优化掉
    // 下面只要小于10，也可以将for循环优化掉
    for (int j = i; j > 10; j--)
        printf("%d\n", j);

    return 0;
}

// clang++ -O2 example4.cpp -o example4 && ./example4
// g++ -O2  example4.cpp -o example4 && ./example4
// clang++ -O2 -fsanitize=undefined example4.cpp -o example4 && ./example4