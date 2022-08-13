#include <stdio.h>


int main(int argc, char const *argv[])
{
    int i;  //编译的时候会假设i的值大于100，然后编译的时候就直接扔掉for循环
    for(; i< 100; ++i)
        printf("%d\n", i);
    printf("%d\n", i);
    return 0;
}



// clang++ -O2  example1.cpp -o example1 &&  ./example1
// g++ -O2  example1.cpp -o example1 &&  ./example1