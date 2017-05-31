/*
static ���� -> read/write segment ����
static ��� -> read-only segment����
*/
//<read/write segment ���� �� ���� ������ ���� �� ����Ǵ� �Ϲ� ������ ���� >
#include<iostream>

class MyClass {
public:
	MyClass(int i, int j) {
		x = i;
		y = j;
	}

	void ShowXY() {
		std::cout << "The field values are " << x << " & " << y << std::endl;
	}
private:
	static int x;
	int y;
};

int MyClass::x = 0; //���� ������ Ŭ������ �ν��Ͻ����� �ʴ��� �ʱ�ȭ�ϰų� ������ �����ϴ�.

int main()
{
	MyClass ms1(10, 20);
	MyClass ms2(30, 50); // ���������� �ʱ�ȭ �� x���� 30�̹Ƿ� �Ѵ� 30���
	ms1.ShowXY();
	ms2.ShowXY();
}

/*
Ŭ������ ���� ����Լ��� �̹� �����ϱ� ������ ��ü�� �������� �ʴ��� ȣ���� ����(ex. new)
Ŭ������ ���� ��������� ���� ������ ����
���� ��������� ��� Ŭ������ �ν��Ͻ��� �����ϴ� ��� �Ǵ� ������ ���� �� �ַ� ���

���� �Լ��� ����� Ŭ������ ���� �ʿ䰡 ���� �Լ���� ���ӽ����̽� �� ���� �Լ��� �����Ͽ� ����� ���� �ǰ�
*/