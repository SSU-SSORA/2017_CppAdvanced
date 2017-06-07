#include <iostream>

#define USE_ILINE 1
//책에 있는 코드이지만 컴파일이 안됨
namespace AppVersion {
	namespace version1 {
		void display() {
			std::cout << "display() 함수 version1" << std::endl;
		}
	}
	namespace version2 {
		void display() {
			std::cout << "display() 함수 version2" << std::endl;
		}
	}
#if USE_INLINE
	inline
#endif
	namespace version3 {
		void display() {
			std::cout << "display() 함수 version 3" << std::endl;
		}
	}
	namespace version3 {
		void whatsUp() {
			std::cout << "whatsup() 함수 version 3 " << std::endl;
		}
	}
}


int main() {
	AppVersion::display();
	AppVersion::whatsUp();
	return 0;
}
