#include <iostream>
#include <cstdio>
using namespace std;


int main(void) {
	int a = 10;
	cout << a << endl;

	int b(20);//�Լ��� ������
	cout << b << endl;

	int c{ 30 };//c++11���ĺ��� ����
	cout << c << endl;

	int d = int(40);
	cout << d << endl;

	//���־��� ����, g++���� ������
	//���� e���� ���� ���� ����ִ��� �� �� ����
	//int e();
	//cout << e << endl;

	int f = int();
	cout << f << endl;//�̷����ϸ� 0���� �ʱ�ȭ

	int g = { 50 };
	cout << g << endl;

	int *h =  new int;

	cout << *h << endl;

	int *i = new int();
	cout << *h << endl;

	int *j = new int(50);
	cout << *j << endl;

	//boolalpha, noboolalpha
}