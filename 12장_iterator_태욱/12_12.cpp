#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "12_2.hpp"

int main() {
	int myints[] = { 10,20,30,30,20,10,10,20 };
	int* pbegin = myints;
	int*pend = myints + sizeof(myints) / sizeof(myints[0]);

	pend = std::remove(pbegin, pend, 20);

	std::cout << "range contains : ";
	for (int *p = pbegin; p != pend; ++p)
		std::cout << *p << ' ';
	std::cout << std::endl;

	for (int i = 0; i < 8; ++i)
		std::cout << myints[i] << ' ';
	std::cout << std::endl;

	Array<std::string> foo = { "air","water","fire","earth","air","water","air" };

	std::remove(foo.begin(), foo.end(), std::string("air"));
	for (int i = 0; i < foo.size(); ++i)
		std::cout << foo[i] << ' ';
	std::cout << std::endl;
	return 0;
}