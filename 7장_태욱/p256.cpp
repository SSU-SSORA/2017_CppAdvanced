#include <iostream>
using namespace std;


template <int &ri>
struct Simple {
	Simple() {
		printf("��ü ���� ri�� %d�̴�.\n", ri);
	}
	~Simple() {
		printf("��ü �Ҹ� �� ri�� %d�̴�.\n", ri);
	}
};

int i = 1;

int main(void) {
	Simple<i> s;
	i = 0;
}