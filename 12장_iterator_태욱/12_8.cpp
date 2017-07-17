#include <iostream>
#include <algorithm>
#include <iterator>
#include "12_2.hpp"



int main() {
	const int n1 = 3;
	Array<int> v{ 0,1,2,3,4 };
	auto result1 = std::find(std::begin(v), std::end(v), n1);
	if (result1 != std::end(v))
		std::cout << "v �迭��" << n1 << " �� ���� �ִ�.\n";
	else
		std::cout << "v �迭��" << n1 << " �� ���� �ִ�.\n";

	Array<int>::iterator it = std::find_if(v.begin(), v.end(), 
		[](int i)->bool {return ((i % 2) == 1); }
	);
	std::cout << "ó�� ������ Ȧ���� " << *it << "�̴�.\n";
}