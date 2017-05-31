#include <iostream>
#include <type_traits>

int main() {
	std::cout << std::boolalpha;
	std::cout << std::is_same<int, int32_t>::value << std::endl;
	std::cout << std::is_same<int, int64_t>::value << std::endl;
	std::cout << std::is_same<float, int32_t>::value << std::endl;

}