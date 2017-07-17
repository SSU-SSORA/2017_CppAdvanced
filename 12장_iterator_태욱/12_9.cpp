#include <string>
#include <algorithm>
#include <iostream>
#include "12_2.hpp"

template<typename Container>
bool quote(Container& cont, const std::string& s) {
	return std::search(cont.begin(), cont.end(), s.begin(), s.end())
		!= cont.end();
}

bool mypredicate(int i, int j) {
	return (i == j);
}

int main() {
	std::string str = "�������� ��� ��� ���솫 �����͸� �׷����� ���� �����ϴ� ������� �迭�� �ִ�.";
	std::cout << std::boolalpha << quote(str, "�迭") << std::endl
		<< quote(str, "����") << '\n';

	Array<char> vec(str.begin(), str.end());
	std::cout << quote(vec, "�迭") << '\n' << quote(vec, "����") << '\n';

	Array<char> stack;
	//stack : 10 20 30 40 50 60 70 80 90
	for (int i = 1; i < 10; ++i) stack.push_back(i * 10);

	int needle2[] = { 50,60,70 };

	Array<char>::iterator it = 
		std::search(stack.begin(), stack.end(), needle2, needle2 + 3, mypredicate);

	if (it != stack.end())
		std::cout << "{50,60,70}�� ���� ��ġ " << (it - stack.begin()) << '\n';
	else
		std::cout << "ã�� �� �����ϴ�. \n";

}



