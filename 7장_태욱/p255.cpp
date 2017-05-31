#include <iostream>
using namespace std;
template <int i>
class A {
	int array[i];
	const int length = i;
public:
	A() { memset(array, 0, i * sizeof(int)); }
};


int main(void) {
	A<10> a;
}