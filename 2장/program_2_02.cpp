#include<iostream>

#define USE_INLINE 1

namespace AppVersion {
	namespace version1 {
		void display() {
			std::cout << "display() 함수 version 1" << std::endl;
		}
	}
	namespace version2 {
		void display() {
			std::cout << "display() 함수 version 2" << std::endl;
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
			std::cout << "whatsUp() 함수 version 3" << std::endl;
		}
	}
}

int main()
{
	AppVersion::display();
	AppVersion::whatsUp();
	return 0;
}

/*
inline을 사용하면 AppVersion::version3::display() 와 AppVersion::display()가 서로 호환이 가능
inline네임스페이스는 특수한 경우가 아니라면 잘 사용하지않음
*/