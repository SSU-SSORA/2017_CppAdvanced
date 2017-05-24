/*
 * typeid.cpp
 *
 *  Created on: 2017. 5. 24.
 *      Author: TaeWook
 */

#include <iostream>
#include <typeinfo>  //typeid를 사용하기 위한 헤더
class BaseClass {
public:
	virtual ~BaseClass() {
	}
};
class DerivedClass: public BaseClass {

};

int main() {
	BaseClass base;
	DerivedClass derived;
	BaseClass *ptr = &derived;
	BaseClass &ref = derived;

	std::cout << "typeid(base)    " << typeid(base).name() << std::endl;
	std::cout << "typeid(derived) " << typeid(derived).name() << std::endl;
	std::cout << "typeid(ptr)     " << typeid(ptr).name() << std::endl;
	std::cout << "typeid(*ptr)    " << typeid(*ptr).name() << std::endl;
	std::cout << "typeid(ref)     " << typeid(ref).name() << std::endl;

	std::cin.get();
	return 0;
}

