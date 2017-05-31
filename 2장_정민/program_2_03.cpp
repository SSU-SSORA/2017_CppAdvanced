#include<iostream>

namespace {
	void SampleMethod() {
		std::cout << "무명 네임스페이스 내 SampleMethod 함수입니다." << std::endl;
	}
}

namespace sample {
	void SampleMethod() {
		::SampleMethod(); //무명 네임스페이스 내 SampleMethod() 함수 호출
		std::cout << "> sample 네임스페이스 내 SampleMethod 함수입니다." << std::endl;
	}
	namespace nested {
		void SampleMethod() {
			std::cout << ">> nested 네임스페이스 내 SampleMethod 함수입니다." << std::endl;
		}
	}
}

int main()
{
	sample::SampleMethod();
	sample::nested::SampleMethod();
	SampleMethod();
	::SampleMethod();
	return 0;
}
/*
전역 네임스페이스(ex. std)
- main함수는 네임스페이스 소속되지 못함

전역 네임스페이스 내 함수와 변수 호출 방법
- ::hello();, hello();

무명 네임스페이스
- 전역 네임스페이스처럼 함수나 변수를 호출하는 방법은 동일
*/