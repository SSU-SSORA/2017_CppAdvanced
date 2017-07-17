#include <iostream>
#include <initializer_list>//std::initializer_list 클래스템플릿

struct MyClass {
	MyClass(int x, int y) : x(x), y(y) {}
	MyClass(std::initializer_list<int> nums) {
		std::cout << "MyClass(std::initializer_list<int> nums" << std::endl;

		auto it = nums.begin();
		x = *it++;
		y = *it;
	}
	void print() {
		std::cout << "x = " << x << " , y = " << std::endl;
	}
private:
	int x, y;
};

int main() {
	MyClass bar(10, 20);
	bar.print();
	MyClass foo{ 10,20 };
	foo.print();
}








