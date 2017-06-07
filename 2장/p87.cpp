#include <iostream>
#include <string>

int main() {
	const char * cc = "문자열을 입력합니다. This is  a string";
	std::string str;

	str = cc;
	std::cout << "str = " << str.data() << ",문자열의 크기는 " << str.length() << std::endl;

	str = "클래스 내부에서 공간을 잡는다.";

	str += "따라서 별도 메모리 공간을 잡지 않아도 사용이 가능하다.";
	std::cout << "str = " << str.data() << " 문자열의 크기는 " << str.length() << std::endl;
}