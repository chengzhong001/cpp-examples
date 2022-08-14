#include <stdio.h>

int main(int argc, char const *argv[])
{
    bool b;
    if(b)
        printf("true\n");
     if(!b)
        printf("false\n");
    return 0;
}
// clang++ -O2 example4.cpp -o example4 && ./example4
// g++ -O2  example4.cpp -o example4 && ./example4
// clang++ -O2 -fsanitize=undefined example4.cpp -o example4 && ./example4