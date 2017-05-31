#include <iostream>
using namespace std;


template <int &ri>
struct Simple {
	Simple() {
		printf("객체 생성 ri는 %d이다.\n", ri);
	}
	~Simple() {
		printf("객체 소멸 시 ri는 %d이다.\n", ri);
	}
};

int i = 1;

int main(void) {
	Simple<i> s;
	i = 0;
}