#include <iostream>
#include <typeinfo>

class C {
public:
	int x;
};

int i = 1;

template<class T>
void f(T) {
	std::cout << i++ << ". T е╦ют : " << typeid(T).name() << std::endl;
}

int main() {
	C a = { 0 };
	const C b = { 0 };
	C& c = a;
	const C& d = b;

	f(a); f(&a); f(b); f(&b); f(c); f(d);
	f(C{ 10 });
}