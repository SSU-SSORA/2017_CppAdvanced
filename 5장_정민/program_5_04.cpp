/*
<���� ��� ����>
1. ����(static)���� ����� ������ ����� Ŭ���� �ܺο��� �ʱ�ȭ �ؾ���
2. ����(static)���� ����� ����� ��ü ���������� �̹� �����ϴ� ���̱� ������
   �����ڸ� ����Ͽ� ���� ����� �ʱ�ȭ��ų �� ����.
*/
#include<iostream>

class Something {
private:
	static int s_value; // ���� �������
	static const int c_value;// ���� ������

public:
	static int getValue() { return s_value; }
	static const int getConst() { return c_value; }
	/*
	���� �Լ��� ȣ�� �� ��� ������ ����� ���� ��� ������ ���� ��� ���,
	���� �Լ��� ��ü�� �������� �ʴ��� ȣ���� ����, �Ϲ� ��������� ����� �� ����.
	*/
};

int Something::s_value = 1; // ���� ������� �ʱ�ȭ
const int Something::c_value = 10;// ���� ��� ��� �ʱ�ȭ
 
int main()
{
	//Ŭ������ ���� ������ ���� �ϴ��� ���� ������ ������ ����� ����
	std::cout << "Something::getValue() = " << Something::getValue() << std::endl;
	std::cout << "Something::getConst() = " << Something::getConst() << std::endl;

}
