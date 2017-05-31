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
		std::cout << "The field values are " << x << " & " << y << std::endl;
	}
private:
	static int x;
	int y;
};

int MyClass::x = 0; //정적 변수는 클래스가 인스턴스되지 않더라도 초기화하거나 접근이 가능하다.

int main()
{
	MyClass ms1(10, 20);
	MyClass ms2(30, 50); // 마지막으로 초기화 한 x값이 30이므로 둘다 30출력
	ms1.ShowXY();
	ms2.ShowXY();
}

/*
클래스의 정적 멤버함수는 이미 존재하기 때문에 객체가 생성되지 않더라도 호출이 가능(ex. new)
클래스의 정적 멤버변수는 전역 변수와 유사
정적 멤버변수는 모든 클래스의 인스턴스가 공유하는 상수 또는 변수를 만들 때 주로 사용

정적 함수로 만들어 클래스에 묶을 필요가 없는 함수라면 네임스페이스 내 전역 함수를 선언하여 사용할 것을 권고
*/