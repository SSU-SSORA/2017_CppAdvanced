#include <iostream>
#include <cstdio>
using namespace std;


int main(void) {
	int a = 10;
	cout << a << endl;

	int b(20);//함수의 생성자
	cout << b << endl;

	int c{ 30 };//c++11이후부터 가능
	cout << c << endl;

	int d = int(40);
	cout << d << endl;

	//비주얼은 에러, g++에선 정상동작
	//변수 e에는 무슨 값이 들어있는지 알 수 없음
	//int e();
	//cout << e << endl;

	int f = int();
	cout << f << endl;//이렇게하면 0으로 초기화

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