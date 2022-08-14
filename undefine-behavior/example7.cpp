#include <iostream>

static void (*fp)() = nullptr;

void f()
{
    std::cout << "f" << std::endl;
}

void set_fp(){
    fp = f;
}

void g() {
    std::cout << "g" << std::endl;
}

void set_fp2(){
    fp = g;
}

int main(int argc, char const *argv[])
{
    fp();
    return 0;
}

// clang++ -O2 example7.cpp -o example7 && ./example7
// g++ -O2 example7.cpp -o example7 && ./example7
// clang++ -O2 -fsanitize=undefined example7.cpp -o example7 && ./example7