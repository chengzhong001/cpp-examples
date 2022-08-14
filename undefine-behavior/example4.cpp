#include <stdio.h>

int f()
{
    for (int i = 0; i < 10 ; i++)
        printf("%d\n", i);
    // return 0;
    // 当没有返回值，编译器认为上面是个死循环，那么编译器就会将i<10删掉
}

int main(int argc, char const *argv[])
{
    f();
    return 0;
}


// clang++ -O2 example4.cpp -o example4 && ./example4
// g++ -O2  example4.cpp -o example4 && ./example4
// clang++ -O2 -fsanitize=undefined example4.cpp -o example4 && ./example4