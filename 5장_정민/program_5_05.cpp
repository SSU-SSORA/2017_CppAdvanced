/*
static 변수 -> read/write segment 영역
static 상수 -> read-only segment영억
*/
//<read/write segment 영역 내 정적 변수와 스택 내 저장되는 일반 변수의 차이 >
#include<iostream>

class MyClass {
public:
	MyClass(int i, int j) {
		x = i;
		y = j;
	}

	void ShowXY() {
		std::cout << "The field values are " << x << "&" << y << std::endl;
	}
private:
	int x;
	int y;
};

int main()
{
	MyClass ms1(10, 20);
	MyClass ms2(30, 50);
	ms1.ShowXY();
	ms2.ShowXY();
}