#include <iostream>
#include <typeinfo>

int m(1);

template<class T> class A {};

template<int i> class B {};

class C {
public:
	int x;
};


template<class T> void f(T&) {
	std::cout << m++ << ". T&, 타입 : " << typeid(T).name() << std::endl;
}


template<class T> void f(T*) {
	std::cout << m++ << ". T*, 타입 : " << typeid(T).name() << std::endl;
}


template<class T> void f(const T&) {
	std::cout << m++ << ". const T&, 타입 : " << typeid(T).name() << std::endl;
}

template<class T> void f(A<T>) {
	std::cout << m++ << ". A<T>, 타입 : " << typeid(T).name() << std::endl;
}


template<int T> void f(B<T>) {
	std::cout << m++ << ". B<i>" << std::endl;
}


template<class T, class U> void f( T(*)(U) ) {
	std::cout << m++ << ". T(*) (U), 타입 : " << typeid(T).name() <<
		". U 타입 : " << typeid(U).name() << std::endl;
}


void f(int x) {
	std::cout << "void f(int) = " << x << std::endl;
}


int main(void) {
	C a = { 0 };
	const C b = { 0 };
	A<char> c;
	C &d = a;
	const C& e = b;

	C array[10][20];
	B<20> b2;

	f(a); f(&a); f(b); f(&b); f(C{ 10 });
	f(c); f(d); f(e); f(C{ 11 });

	f(array);
	f(b2);

	std::cout << std::endl << "멤버 변수---------------------------------" << std::endl;
	f(&a.x);

	std::cout << std::endl << "함수 포인터 ------------------------------" << std::endl;
	void(*c_pfunct1)(int) = f;
	f(c_pfunct1);
}