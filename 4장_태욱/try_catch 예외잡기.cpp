#include <iostream>

int main(void) {
	char * temp = nullptr;

	try {
		temp = new char[2000000000];
	}
	catch (std::bad_alloc e){
		std::cout << e.what() << '\n';
	}

}