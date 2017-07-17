#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <initializer_list>
#include "12_2.hpp"

int main() {
	Array<double> array = { 2.3, 3.2, 4.3 };
	for (Array<double>::iterator i = array.begin(); i != array.end();
		++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	Array<double>::iterator a = array.begin() + 2;
	std::cout << "array.begin() + 2" << *a << std::endl;
	return 0;
}