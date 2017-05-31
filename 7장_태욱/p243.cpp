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
	cout << "최댓값 : " << max(3, 7) << endl;
	cout << "최소값 : " << min(3.5, 7.6) << endl;
	cout << "최대값 : " << max<double>(3, 7.0) << endl;

	cout << "최소값 : " << min('a', 'b') << endl;
	cout << "최대값 : " << max<string>("Hello World", "안녕하세요") << endl;

}