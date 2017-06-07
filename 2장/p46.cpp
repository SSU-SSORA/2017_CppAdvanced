#include <iostream>

#define USE_ILINE 1
//å�� �ִ� �ڵ������� �������� �ȵ�
namespace AppVersion {
	namespace version1 {
		void display() {
			std::cout << "display() �Լ� version1" << std::endl;
		}
	}
	namespace version2 {
		void display() {
			std::cout << "display() �Լ� version2" << std::endl;
		}
	}
#if USE_INLINE
	inline
#endif
	namespace version3 {
		void display() {
			std::cout << "display() �Լ� version 3" << std::endl;
		}
	}
	namespace version3 {
		void whatsUp() {
			std::cout << "whatsup() �Լ� version 3 " << std::endl;
		}
	}
}


int main() {
	AppVersion::display();
	AppVersion::whatsUp();
	return 0;
}
