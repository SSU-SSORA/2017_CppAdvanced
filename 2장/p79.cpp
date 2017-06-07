#include <iostream>
#include <cstddef>
void f(int * pi) {
	std::cout << "정수를 가리킨다.\n";
}

void f(double *pd) {
	std::cout << "실수를 가리킨다.\n";
}
void f(std::nullptr_t ptr) {
	std::cout << "null 포인트이다.\n";
}

int main() {
	int pi = 0; double pd = 0.0;

	f(&pi);
	f(&pd);
	f(nullptr);
	//f(NULL);
}