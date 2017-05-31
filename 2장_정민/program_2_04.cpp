/*
<변수>
auto, decltype => 초기화없이 사용할 수 없는 데이터 타입
- auto name = "Seoul" //name은 char타입의 배열로 인식된다
- int foo=0; auto bar = foo; //bar변수는 foo변수의 데이터 타입으로 인식된다
- decltype(foo)bar; //bar변수는 위의 foo변수의 타입과 같은 정수타입으로 인식

*/

#include<iostream>

void Print_int(int x) {
	printf("%d 인수는 %s 입니다.\n", x, (x) ? "참" : "거짓");
}

void Print_bool(bool x) {
	std::cout << x << " 인수는 " << (x ? "참" : "거짓") << "입니다." << std::endl;
	//std::boolalpha는 화면 출력시 1과0이 아닌 true, false의 문자로 만들어주는 기능
	std::cout << "bool 타입의 데이터는 " << std::boolalpha << x << "와" << !x 
		      << "로 표시할 수 있습니다." << std::endl;
}

int main()
{
	bool ok = true;
	bool notok = false;

	Print_int(100);
	Print_bool(ok);

	//화면에 true와 false를 해제하려면 std::noboolalpha 사용
	std::cout << notok << ' ' << std::noboolalpha << notok << std::endl;

	//상수를 사용하지 않는다면 다음과 같이 함수 사용 가능
	std::boolalpha(std::cout);
	std::cout << notok << std::endl;

	//입력 스트림을 통해 입력된 문자열을 변수에 bool타입의 데이터로 입력받고자 할 때
	bool istrue;
	std::cin >> std::boolalpha >> istrue;
	std::cout << istrue << " = " << (istrue == true) << std::endl;


}