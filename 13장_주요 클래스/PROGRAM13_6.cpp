#include <functional>
#include <string>
#include <iostream>

double my_divide(double x, double y) { return x / y; }

void goodbye(const std::string & s) {
	std::cout << "GoodBye" << s << '\n';
}

class Object {
public:
	void hello(const std::string& s) {
		std::cout << "Hello " << s << '\n';
	}
};

int main(int argc, char *argv[]) {
	Object instance;
	std::string str("World");
	auto f1 = std::bind(&Object::hello, &instance, str);
	f1();

	auto fn = std::bind(my_divide, 10, 2);
	std::cout << fn() << '\n';

	auto f2 = std::bind(&goodbye, str);
	f2();
	return 0;

}