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
    print(5);                //print(int i) �Լ��� ȣ��ȴ�.
    print(500.263);          //print(double f) �Լ��� ȣ��ȴ�.
    print("Hello world");    //print(const char* c) �Լ��� ȣ��ȴ�.
    return 0;
}