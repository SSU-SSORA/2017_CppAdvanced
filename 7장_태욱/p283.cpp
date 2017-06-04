#include <iostream>
#include <string>

template <class T>
struct Empty {
	typedef T type;
	virtual void Display() = 0;
};

template <class T>
class Optimized :public Empty<T> {
	typename Empty<T>::type data;//클래스 템플릿이 제공하는 자료형을 사용하기 위해서는 typename 키워드가 필요함
public:
	Optimized(typename Empty<T>::type c) :data(c) {}
	typename Empty<T>::type GetData() {
		return data;
	}
	virtual void Display() final;//상속 방지용 코드. http://m.blog.naver.com/psychoria/40184422694 
	//참고
};

int main() {
	Optimized<int> e(100);
	Empty<std::string>::type s = "문자열입력";

	std::cout << "Empty 객 체 : " << e.GetData() << std::endl;
	e.Display();
	std::cout << s << std::endl;
}

template<class T>
void Optimized<T>::Display() {
	std::cout << "Optimized : " << data << std::endl;
}