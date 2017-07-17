#include <iostream>
#include <cstdio>

struct Complex {
public:
	//아래 인수는 실수로 인식한다.
	Complex(double x) : real(x), imaginary(0.0) {
		printf(" Complex(double %.2f) 호출\n", x);
	}

	//첫 번쨰 인수는 실수, 두 번째 인수는 실수가 된다.
	Complex(double x, double y) :real(x), imaginary(y) {
		printf("Complex(doiuble %.2f, double %.2f) 호출\n", x, y);
	}

private:
	double real;
	double imaginary;
};

int main() {
	Complex a1 = 1;
	Complex a2(2);
	Complex a3{ 4,5 };
	Complex a4 = { 4,5 };
	Complex a5 = (Complex)1;
	Complex *a6 = new Complex(4, 5);
	delete a6;
}