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
	//정적 멤버함수는 구조체로 선언된 변수가 없어도 아래처럼 호출 가능
	std::cout << Something::getSValue() << std::endl;

	//정적 멤버변수가 아닌 일반 멤버변수는 다음과 같이 초기화시킬수있다.
	Something s = { 100 };

	//정적 멤버 함수든 일반 멤버 함수든 무관하게 함수의 호출은 다음과 같다.
	std::cout << s.getSValue() << ", " << s.getValue() << std::endl;
	return 0;
}