#include <iostream>

const int CalcConstant() {
	int foo = 0;
	std::cout << "�ʱⰪ�� �Է��Ͻñ� �ٶ��ϴ�. ";
	std::cin >> foo;
	return foo;
}

int main() {
	const int maxarray = CalcConstant();
	char store[maxarray];//�� ��������?
	
	std::cout << "���ڿ��� �Է��ϼ���. ";
	std::cin >> store;

	std::cout << maxarray << ", " << store << std::endl;
	return 0;
}