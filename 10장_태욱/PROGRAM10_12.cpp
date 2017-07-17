#include <iostream>
#include <string>
#include <algorithm>

int count = 0;
class MyString {
	std::string data;

public:
	MyString(const char *ptr = nullptr) :data(ptr) {
		std::cout << "Constructor : " << ptr << std::endl;
	}
	//복사 생성자
	MyString(const MyString &obj) : data(obj.data) {
		std::cout << "copy Constructor : " << data.c_str() << std::endl;
	}
	//이동 생성자
	MyString(MyString&&obj) {
		std::swap(this->data, obj.data);
		std::cout << "Move Constructor : " << data.c_str() << std::endl;
		++count;
	}
	~MyString() {
		std::cout << "Destructor : a" << data.c_str() << std::endl;
	}
	MyString & operator=(const MyString & other) {
		if (this != &other) {
			data = other.data;
		}
		printf("MyString & Mystring::operator = (MyString& '%s')\n", this->data);
		++count;
		return *this;
	}

	//이동대입연산자
	MyString& operator=(MyString&& other)noexcept {
		if (this != &other) {
			std::swap(this->data, other.data);
		}
		printf("MyString & MyString::operator = (MyString&& '%s')\n",this->data);
		++count;
		return *this;
	}

};

//