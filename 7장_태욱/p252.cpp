#include <iostream>
using namespace std;

template <typename T>
void print(const T t) {
	cout << t << endl;
}

template <typename First, typename... Rest>
void print(const First first, const Rest... rest) {
	cout << first << ", ";
	print(rest...);
}

int main(void) {
	print(1);
	print(10, 20);
	print(100, 200, 300);
	print("first", 2, "third", 3.141592);
}