#include <iostream>
#include <string>

struct Person {
public:
	Person(std::string n) : name(n) {}
	std::string GetName() {
		return this->name;
	}
private:
	std::string name;
};

class Student :public Person {
public:
	Student(std::string i, std::string n) :Person(n), id(i) {}
	std::string GetID() {
		return this->id;
	}
private:
	std::string id;
};

int main() {
	Student s1("16-31-001", "홍길동");
	std::cout << "학생 ID : " << s1.GetID()
		<< ", 이름 : " << s1.GetName() << std::endl;
}