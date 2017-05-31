#include <iostream>
using namespace std;
#include <string>


template <class Type>
class Calc {
public:
	Type multiply(Type x, Type y);
	Type add(Type x, Type y);
};

template <class T>
class K {
public:
	static T x;
	static T GetData();
};

template <class T> T K<T>::x;
template <class T> T K<T>::GetData() {
	return x;
}


int main(void) {
	K<int>::x = 0;

	cout << K<int>::GetData() << endl;

	Calc<int> calcInt;
	cout << calcInt.multiply(10, 2) << endl;

	Calc<char> calcChar;
	cout << calcChar.add('a', 'b') << endl;
	cout << calcChar.multiply('a', 'b') << endl;
	return 0;
}

template <class Type>
Type Calc<Type>::multiply(Type x, Type y) {
	return x*y;
}

template <class Type>
Type Calc<Type>::add(Type x, Type y) {
	return x + y;
}