#include <iostream>
#include <string>
#include <cstring>
#include <memory>

class MyString {
public:
	MyString(const char *n);
	MyString(const MyString &my);
	~MyString();

	MyString& operator=(const MyString& other);
	void SetString(const char * n);
	const char * GetString() const;
	int GetLength() const;

private:
	std::unique_ptr<char[]> data;
	int length;
};

MyString::MyString(const char *n) : data(nullptr), length(0) {
	SetString(n);
	printf("MyString::MyString(const char '%s')\n", n);
}

MyString::MyString(const MyString & other) : data(nullptr), length(0) {
	SetString(other.GetString());
	printf("MyString::MyStirng(const MyString & '%s'\n", data.get());
}

MyString::~MyString() {
	if (nullptr != data) {
		printf("MyString::MyString('%s') ¼Ò¸êÀÚ È£Ãâ\n", data.get());
		data.reset(nullptr);
		length = 0;
	}
}

MyString& MyString ::operator= (const MyString& other) {
	if (this != &other) {
		data.reset();
		SetString(other.GetString());
	}
	printf("MyString& MyString::operator = (MyString '%s')\n", this->data.get());
	return *this;
}


void MyString::SetString(const char * n) {
	if (nullptr == n) return;

	int mLength = std::strlen(n);
	if (0 == mLength) return;

	data = std::make_unique<char[]>(mLength + 1);

	std::strcpy(data.get(), n);
	length = mLength;
}

const char * MyString::GetString() const {
	return data.get();
}

int MyString::GetLength() const {
	return length;
}

void display(MyString& obj) {
	std::cout << obj.GetString() << std::endl;
}

int main() {
	MyString s1("Hello WOrld!");
	display(s1);
	MyString obj = s1; return 0;
}