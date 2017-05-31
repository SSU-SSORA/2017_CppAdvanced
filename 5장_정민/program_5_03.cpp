#include<iostream>
class MyClass {
public:
	MyClass(const char *label, int id) : label(label), id(id){ }
	MyClass() = default;

	void DisplayX() {
		std::cout << "Ŭ���� �� label��" << label.data()
			      << "�̰� id��" << id << "�̴�.\n";
	}

private:
	std::string label;
	const int id = 3; //const�� ����� Ŭ������ ����� ��Ģ������ ����� ���ÿ� �ʱⰪ�� �Է½����ְų� �տ��� ����� �����ڿ� �ʱ�ȭ ����Ʈ�� ����Ͽ� �ʱ�ȭ ���������
};

int main()
{
	MyClass s("cc", 3);
	//s.label = "cc"; label�� private�̹Ƿ� �ܺ��Լ����� ���ٺҰ�
	s.DisplayX();
}
/*
Ŭ���� �� �������� private���� ������ �� ����
1. �ܺο��� ������ ���� ������ �����Ͽ� ���� �� �� ����
2. ������ Ŭ���� ���� �����ڳ� Ŭ���� ���� �Լ��� ���� ������ ����
3. �����ڸ� ����Ͽ� �ѹ� ������ Ŭ���� �� ������ ���� �Լ��� �������� �ʴ� �� 
   ������ ����Ͽ� ���� �� �ִ� ��� ������ �������� �ʴ´�.

*/