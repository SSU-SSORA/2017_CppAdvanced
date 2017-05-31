/*
<정적 멤버 변수>
1. 정적(static)으로 선언된 변수와 상수는 클래스 외부에서 초기화 해야함
2. 정적(static)으로 선언된 상수는 객체 생성이전에 이미 존재하는 값이기 때문에
   생성자를 사용하여 정적 상수를 초기화시킬 수 없다.
*/
#include<iostream>

class Something {
private:
	static int s_value; // 정적 멤버변수
	static const int c_value;// 정적 멤버상수

public:
	static int getValue() { return s_value; }
	static const int getConst() { return c_value; }
	/*
	정적 함수의 호출 시 사용 가능한 멤버는 정적 멤버 변수나 정적 멤버 상수,
	정적 함수는 객체가 생성되지 않더라도 호출이 가능, 일반 멤버변수를 사용할 수 없다.
	*/
};

int Something::s_value = 1; // 정적 멤버변수 초기화
const int Something::c_value = 10;// 정적 멤버 상수 초기화
 
int main()
{
	//클래스의 변수 선언이 없다 하더라도 정적 변수는 언제라도 사용이 가능
	std::cout << "Something::getValue() = " << Something::getValue() << std::endl;
	std::cout << "Something::getConst() = " << Something::getConst() << std::endl;

}
