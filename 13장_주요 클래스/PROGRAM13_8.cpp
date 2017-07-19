#include <iostream>
#include <functional>
#include <string>

double my_divide(double x, double y) { return x / y; }

void goodbye(const std::string& s) {
	std::cout << "goodBye" << s << std::endl;
}

class Object {
public:
	void hello(const std::string &s) {
		std::cout << "Hello " << s << '\n';
	}
};

int main(int argc, char* argv[]) {
	Object instance;
	std::string str = "Hello";
	auto f1 = std::bind(&Object::hello, &instance, std::placeholders::_1);
	f1(str);

	auto fn = std::bind(my_divide, std::placeholders::_1, std::placeholders::_2);
	std::cout << fn(10, 2) << '\n';

	auto f2 = std::bind(&goodbye, std::placeholders::_1);
	f2(str);
	return 0;
}