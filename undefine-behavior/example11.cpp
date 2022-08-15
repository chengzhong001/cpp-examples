#include <stdio.h>

void f(int *a, float *b)
{
    *a = 123;
    *b = 1.23;
    printf("%d %f\n", *a, *b);
    // 对于不相似的类型，编译器优化的时候会做假设，不会当成一个地址，激进优化
}

void g(int *a, unsigned int *b)
{
    *a = 123;
    *b = 456;
    printf("%d %u\n", *a, *b);
    // 对于相似的类型，编译器优化的时候不做假设，可以当成一个地址
}

void h(int *a, char *b)
{
    *a = 123;
    b[0] = b[1] = b[2] = b[3] = 1;
    printf("%d %s\n", *a, b);
    // 特殊情况，编译器不做假设 char* void*
}

void f(int *a, float *b, char *p, char *q)
{
    *a = 123;
    *b = 1.23;
    *p = *q;
    printf("%d %f\n", *a, *b);
    // *p = *q 编译器认为 a, b, p, q可能会指向同一块地址，故不做激进优化
}

int main(int argc, char const *argv[])
{
    int a;
    // f(&a, (float *)&a);
    f(&a, (float *)&a, (char *)&a, (char *)&a);
    // g(&a, (unsigned int *)&a);
    // h(&a, (char *)&a);
    return 0;
}

// clang++ -O2 example11.cpp -o example11 && ./example11
// g++ -O2 example11.cpp -o example11 && ./example11
// clang++ -O2 -fsanitize=undefined example11.cpp -o example11 && ./example11