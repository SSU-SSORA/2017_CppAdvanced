#include <iostream>
#include <vector>

int main() {
	std::vector<int> myvector(5);

	int *p = myvector.data();

	*p = 10;
	for (int i = 1; i < myvector.size(); ++i)
		p[i] = p[i - 1] * i;
	*(++p) += 20;

	std::cout << "myvector�� ������ : ";
	for (auto& i : myvector)
		std::cout << i << ' ';
	std::cout << std::endl;

	std::vector<std::string> mystring(5);
	std::string *s = mystring.data();

	*s = "Hello World!";
	s[1] = "���� ���";
	s[2] = "����� ���";
	s[3] = "���ο� ������� ����";

	std::cout << "myString�� ������ : ";
	for (auto& a : mystring)
		std::cout << a.c_str() << ", ";
	std::cout << std::endl;
	return 0;
}