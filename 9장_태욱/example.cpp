#include <iostream>
struct S2 {
	void Func(int i);
	int a;
};

void S2::Func(int i) {
	[&] {};//디폴트 참조 캡쳐
	[=] {};//디폴트 값 캡쳐
	[&, i] {};//i변수를 제외하고 모두 값을 캡쳐함
	[=, &i] {};//i 변수는 참조 캡쳐로 사용하고 나머지는 값 캡처

	//[&, &i] {};//에러, 참조 캡처가 중복됨

	//this는 자기 자신을 가리키는 포인터
	[=, this] {this->a = i; };//OK, this포인터를 사용한다.
	
	//()함수 호출 연산자를 이용하여 람다를 정의하면서 동시에 호출
	[&, this] {
		this->a = i;
		std::cout << "i = " << i << std::endl;
	}();
	std::cout << "a = " << a << std::endl;

	//[i, i]{}; i가 중복선언됨
}