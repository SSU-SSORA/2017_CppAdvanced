/*
공용체 union은 하나의 메모리 저장소를 여러개의 데이터 타입을 가진 멤버들이 공유한다.
구조체는 하나의 저장소를 공유하는 것이 아니라 멤버들이 각자의 영역을 갖고 서로 분리
*/

#include<iostream>
#include<cstring>

union DataValue01 {
	int v_int;
	float v_float;
	char v_string[4];
};

struct DataValue02 {
	int v_int;
	float v_float;
	char v_string[4];
};

int main()
{
	std::cout << "공용체의 크기 = " << sizeof(DataValue01) << std::endl;
	std::cout << "구조체의 크기 = " << sizeof(DataValue02) << std::endl;
}