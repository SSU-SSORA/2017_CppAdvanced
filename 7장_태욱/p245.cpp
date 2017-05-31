#include <iostream>
using namespace std;


template<typename T, typename U=T>
T min(T a, U b) {//디폴트 인수
	return (a < b) ? a : b;
}


int main(void) {
	cout << "최소값 : " << min(3, 7) << endl;
	cout << "최소값 : " << min<double>(3.5, 7.6) << endl;

	cout << "최소값 : " << min<int, double>(3, 7.0) << endl;
}