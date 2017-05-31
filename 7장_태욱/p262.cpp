#include <iostream>
#include <string>

#ifndef __FREETTY_FUNCTION__
#define __PRETTY_FUNCTION__ __FUNCTION__
#endif

template <typename Key, typename Value>
class KeyValuePair {
public:
	KeyValuePair(Key k, Value v) : key(k), value(v) {
		std::cout << "1번 : " << __PRETTY_FUNCTION__ << ':' << "original\n";
	}
private:
	Key key;
	Value value;
};

template<>
class KeyValuePair<int, std::string> {
public:
	KeyValuePair(int k, std::string v) :key(k), value(v) {
		std::cout << "2번 : " << __PRETTY_FUNCTION__ << ':' << "explicit full specialized\n";
	}
private:
	int key;
	std::string value;
};

template <typename Key>
class KeyValuePair<Key, std::string> {
public:
	KeyValuePair(Key k, std::string v) :key(k), value(v) {
		std::cout << "3번 : " << __PRETTY_FUNCTION__ << ':' << "specialized\n";
	}
private:
	Key key;
	std::string value;
};

int main() {
	KeyValuePair<int, int> kvp1(100, 100);

	KeyValuePair<long, std::string> kvp2(100, "템플릿 특수화");

	KeyValuePair<int, std::string> kvp3(100, "템플릿 특수화");
}

