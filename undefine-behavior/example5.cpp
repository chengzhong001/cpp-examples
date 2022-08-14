#include <stdio.h>

bool foo()
{
    static const int MAX = 1000;
    int a = 1, b = 1, c = 1;
    for (;;)
    {
        if (a * a * a == b * b * b + c * c * c)
        {
            printf("disprove!\n");
            return false;
        }

        a++;
        if (a > MAX)
        {
            a = 1;
            b++;
        }
        if (b > MAX)
        {
            b = 1;
            c++;
        }
        if (c > MAX)
        {
            c = 1;
        }
    }
    return true;
    // 编译器优化认为上面for循环是死循环，编译器就会将for循环内容优化掉，只输出了一个disprove!
}
int main(int argc, char const *argv[])
{
    foo();
    return 0;
}
// 原理：
// 当一个函数作用不到外面
// 对外没有作用的死循环，编译器认为就是一个未定义行为


// clang++ -O2 example5.cpp -o example5 && ./example5
// g++ -O2  example5.cpp -o example5 && ./example5
// clang++ -O2 -fsanitize=undefined example5.cpp -o example5 && ./example5