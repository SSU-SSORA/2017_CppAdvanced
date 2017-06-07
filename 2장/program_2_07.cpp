#include<iostream>

struct Something {
	static int s_value;
	static int getSValue() { return s_value; }

	int value;
	int getValue() { return value; }
};

int Something::s_value = 1;

int main()
{
	//���� ����Լ��� ����ü�� ����� ������ ��� �Ʒ�ó�� ȣ�� ����
	std::cout << Something::getSValue() << std::endl;

	//���� ��������� �ƴ� �Ϲ� ��������� ������ ���� �ʱ�ȭ��ų���ִ�.
	Something s = { 100 };

	//���� ��� �Լ��� �Ϲ� ��� �Լ��� �����ϰ� �Լ��� ȣ���� ������ ����.
	std::cout << s.getSValue() << ", " << s.getValue() << std::endl;
	return 0;
}