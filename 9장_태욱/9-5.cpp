#include <iostream>

int main() {
	auto funa = [] {
		std::cout << "Hello, 람다!(lambda)" << std::endl;
	};
	funa();

	auto funb = [](int n) {
		std::cout << "정수 : " << n << std::endl;
	};

	funb(333);
	return 0;
}