#include <iostream>

void Print_int(int x) {
	printf("%d 인수는 %s입니다.\n", x, (x) ? "참" : "거짓");
}

//bool 타입의 인수 사용
void Print_bool(bool x) {
	std::cout << x << " 인수는 " << (x ? "참" : "거짓") << "입니다." << std::endl;

	std::cout << "bool 타입의 데이터는 " << std::boolalpha << x << "와" << !x
		<< "로 표시할 수 있습니다." << std::endl;
}

int main() {
	bool ok = true;
	bool notOk = false;

	Print_int(100);
	Print_bool(ok);

	//noboolalpha : boolalpha 해제
	std::cout << notOk << ' ' << std::noboolalpha << notOk << std::endl;

	//상수를 사용하지 않는다면 다음과 같이 함수를 사용할 수 있다.
	std::boolalpha(std::cout);
	std::cout << notOk << std::endl;

	//데이터로 입력받고 싶다면 다음과 같이 하면 된다.
	bool istrue;
	std::cin //>> std::boolalpha 
		>> istrue;
	std::cout << istrue << " = " << (istrue == true) << std::endl;
}