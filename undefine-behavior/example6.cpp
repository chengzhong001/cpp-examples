#include <stdio.h>

void foo(int *p){
    int dead = *p;
    
    if(p!=nullptr)
        printf("ok\n");
}

int main(int argc, char const *argv[])
{
    foo(nullptr);
    return 0;
}

// clang++ -O2 example6.cpp -o example6 && ./example6
// g++ -O2 example6.cpp -o example6 && ./example6
// clang++ -O2 -fsanitize=undefined example6.cpp -o example6 && ./example6