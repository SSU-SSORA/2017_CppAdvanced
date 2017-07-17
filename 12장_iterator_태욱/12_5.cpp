#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include "12_2.hpp"

int main() {
	Array<std::string> foo(3);
	Array<std::string> bar{ "one", "two","three" };

	//Array 객체의 타입을 사용하여 move_iterator 템플릿 인수의 타입을
	//선언한다.
	typedef Array<std::string>::iterator Iter;
	std::copy(std::move_iterator<Iter>(bar.begin()),
		std::move_iterator<Iter>(bar.end()),
		foo.begin());

	//bar객체는 모두 이동하게 되므로 비어 있게 된다.
	std::cout << "bar : ";
	for (std::string& x : bar) std::cout << ' ' << x;
	std::cout << std::endl;

	std::cout << "foo : ";
	for (std::string& x : foo) std::cout << ' ' << x;
	std::cout << std::endl;

}