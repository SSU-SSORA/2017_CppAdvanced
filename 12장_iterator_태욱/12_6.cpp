#include <iostream>
#include <iterator>
#include "12_2.hpp"

int main() {
	Array<int> myArray;
	for (int i = 0; i < 10; ++i) myArray.push_back(i);

	typedef Array<int>::iterator iter_type;

	//������ ���� ��ġ�� ���� �ٲپ� ��ü�� �������ϸ� �˾Ƽ� ��ġ�� ���߾��ش�
	std::reverse_iterator<iter_type> rev_from(myArray.end());
	std::reverse_iterator<iter_type> rev_until(myArray.begin());

	std::cout << "myArray : ";
	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout << '\n';
	return 0;
}