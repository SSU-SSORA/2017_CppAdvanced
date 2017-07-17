#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include "12_2.hpp"

int main() {
	Array<std::string> foo(3);
	Array<std::string> bar{ "one", "two","three" };

	//Array ��ü�� Ÿ���� ����Ͽ� move_iterator ���ø� �μ��� Ÿ����
	//�����Ѵ�.
	typedef Array<std::string>::iterator Iter;
	std::copy(std::move_iterator<Iter>(bar.begin()),
		std::move_iterator<Iter>(bar.end()),
		foo.begin());

	//bar��ü�� ��� �̵��ϰ� �ǹǷ� ��� �ְ� �ȴ�.
	std::cout << "bar : ";
	for (std::string& x : bar) std::cout << ' ' << x;
	std::cout << std::endl;

	std::cout << "foo : ";
	for (std::string& x : foo) std::cout << ' ' << x;
	std::cout << std::endl;

}