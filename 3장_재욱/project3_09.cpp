#include <iostream>

int i = 7;

int main(int argc, char *argv[])
{
    int i = 5;
    std::cout << "i ���� ������ ���� " << i << std::endl;
    std::cout << "i ���� ������ ���� " << ::i << std::endl;
}