#include <iostream>
using namespace std;
#include <string>

template <typename T>
T min(T a, T b) {
	return (a > b) ? b : a;
}

template <class Type>
Type max(Type a, Type b) {
	return (a > b) ? a : b;
}


int main(void) {
	cout << "�ִ� : " << max(3, 7) << endl;
	cout << "�ּҰ� : " << min(3.5, 7.6) << endl;
	cout << "�ִ밪 : " << max<double>(3, 7.0) << endl;

	cout << "�ּҰ� : " << min('a', 'b') << endl;
	cout << "�ִ밪 : " << max<string>("Hello World", "�ȳ��ϼ���") << endl;

}