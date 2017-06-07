#include <iostream>

void Print_int(int x) {
	printf("%d �μ��� %s�Դϴ�.\n", x, (x) ? "��" : "����");
}

//bool Ÿ���� �μ� ���
void Print_bool(bool x) {
	std::cout << x << " �μ��� " << (x ? "��" : "����") << "�Դϴ�." << std::endl;

	std::cout << "bool Ÿ���� �����ʹ� " << std::boolalpha << x << "��" << !x
		<< "�� ǥ���� �� �ֽ��ϴ�." << std::endl;
}

int main() {
	bool ok = true;
	bool notOk = false;

	Print_int(100);
	Print_bool(ok);

	//noboolalpha : boolalpha ����
	std::cout << notOk << ' ' << std::noboolalpha << notOk << std::endl;

	//����� ������� �ʴ´ٸ� ������ ���� �Լ��� ����� �� �ִ�.
	std::boolalpha(std::cout);
	std::cout << notOk << std::endl;

	//�����ͷ� �Է¹ް� �ʹٸ� ������ ���� �ϸ� �ȴ�.
	bool istrue;
	std::cin //>> std::boolalpha 
		>> istrue;
	std::cout << istrue << " = " << (istrue == true) << std::endl;
}