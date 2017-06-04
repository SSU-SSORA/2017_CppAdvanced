#include <iostream>

template<class Type>
bool Integral() {
	return std::is_integral<Type>::value;
}

int main(void) {
	std::cout << std::boolalpha;
	std::cout << Integral<float>() << std::endl;
	std::cout << Integral<int>() << std::endl;

}