#include <iostream>
using namespace std;


template<typename T, typename U=T>
T min(T a, U b) {//����Ʈ �μ�
	return (a < b) ? a : b;
}


int main(void) {
	cout << "�ּҰ� : " << min(3, 7) << endl;
	cout << "�ּҰ� : " << min<double>(3.5, 7.6) << endl;

	cout << "�ּҰ� : " << min<int, double>(3, 7.0) << endl;
}