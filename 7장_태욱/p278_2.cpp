#include <iostream>
#include <type_traits>

class A {};

int main() {
	std::cout << std::boolalpha;
	std::cout << std::is_fundamental<A>::value << std::endl;//기본 타입인지 확인
	std::cout << std::is_fundamental<int>::value << std::endl;
	std::cout << std::is_fundamental<int&>::value << std::endl;
	std::cout << std::is_fundamental<int*>::value << std::endl;
	std::cout << std::is_fundamental<float>::value << std::endl;
	std::cout << std::is_fundamental<float&>::value << std::endl;
	std::cout << std::is_fundamental<float*>::value << std::endl;
	
	
}