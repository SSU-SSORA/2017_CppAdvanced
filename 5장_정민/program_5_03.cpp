#include<iostream>
class MyClass {
public:
	MyClass(const char *label, int id) : label(label), id(id){ }
	MyClass() = default;

	void DisplayX() {
		std::cout << "클래스 내 label은" << label.data()
			      << "이고 id는" << id << "이다.\n";
	}

private:
	std::string label;
	const int id = 3; //const로 선언된 클래스의 상수는 원칙적으로 선언과 동시에 초기값을 입력시켜주거나 앞에서 언급한 생성자와 초기화 리스트를 사용하여 초기화 시켜줘야함
};

int main()
{
	MyClass s("cc", 3);
	//s.label = "cc"; label은 private이므로 외부함수에서 접근불가
	s.DisplayX();
}
/*
클래스 내 변수들을 private으로 선언할 때 장점
1. 외부에서 누구나 쉽게 변수를 접근하여 수정 할 수 없다
2. 오로지 클래스 내부 생성자나 클래스 내부 함수를 통해 수정이 가능
3. 생성자를 사용하여 한번 생성된 클래스 내 변수는 별도 함수로 제공하지 않는 한 
   수정을 비롯하여 읽을 수 있는 방법 조차도 제공되지 않는다.

*/