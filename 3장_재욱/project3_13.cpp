#include <iostream>

void print(int i) {
    std::cout << "int   : " << i << std::endl;
}

void print(double f) {
    std::cout << "float    : " << f << std::endl;
}

void print(const char* c) {
    std::cout << "const char    : " << c << std::endl;
}

void print(char* c) {
    std::cout << "char    : " << c << std::endl;
}

int main()
{
    print(5);                //print(int i) 함수가 호출된다.
    print(500.263);          //print(double f) 함수가 호출된다.
    print("Hello world");    //print(const char* c) 함수가 호출된다.
    return 0;
}