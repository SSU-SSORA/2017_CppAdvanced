#include <iostream>

const int CalcConstant() {
	int foo = 0;
	std::cout << "초기값을 입력하시기 바랍니다. ";
	std::cin >> foo;
	return foo;
}

int main() {
	const int maxarray = CalcConstant();
	char store[maxarray];//왜 에러나지?
	
	std::cout << "문자열을 입력하세요. ";
	std::cin >> store;

	std::cout << maxarray << ", " << store << std::endl;
	return 0;
}