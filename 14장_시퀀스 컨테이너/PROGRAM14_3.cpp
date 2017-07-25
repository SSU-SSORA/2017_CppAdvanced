#include <iostream>
#include <vector>

int main() {
	std::vector<int> first;

	std::vector<int> second(4,100);

	std::vector<int> third(second.begin(), second.end());

	std::vector<int> fourth(third);

	fourth.resize(10);
	printf("������ ũ�⸦ %d���� �������Ѵ�.\n", fourth.capacity());

	std::cout << "fourth ������ ��� �� : " << fourth.size() << std::endl;
	std::cout << "fourth ������ ��� : ";
	for (auto& i : fourth)
		std::cout << i << ' ';
	std::cout << std::endl;

	fourth.clear();
	printf("clear�Լ� ȣ�� �� ũ��� %d�̴�.\n", fourth.capacity());
	fourth.shrink_to_fit();//��ü�� ũ�⸦ ����� ���� ���߾� ���δ�.
	printf("shrink_to_fit �Լ� ȣ�� �� ũ��� %d�̴�.\n", fourth.capacity());
	return 0;
}