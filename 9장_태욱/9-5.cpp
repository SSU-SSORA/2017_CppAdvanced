#include <iostream>

int main() {
	auto funa = [] {
		std::cout << "Hello, ����!(lambda)" << std::endl;
	};
	funa();

	auto funb = [](int n) {
		std::cout << "���� : " << n << std::endl;
	};

	funb(333);
	return 0;
}