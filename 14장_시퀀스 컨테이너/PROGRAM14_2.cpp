#include <iostream>
#include <memory>
#include <string>

int main() {
	const int size = 10;

	std::allocator<int> a1;

	int *a = a1.allocate(size);

	for(int i = 0; i < size; ++i)
		a[i] = i * i;

	for(int i = 0; i < size; ++i)
		std::cout << a[i] << ' ';
	std::cout << std::endl;

	a1.deallocate(a, size);

	decltype(a1)::rebind<std::string>::other a2;

	std::string *s2 = a2.allocate(size);
	

	//s2[0] = "Hello World!";
	a2.construct(s2, "Hello World!");
	a2.construct(s2 + 1, "foo bar");
	a2.construct(s2 + 2, "construct() 함수를 사용하였다면 destroy() 함수를 호출해야 한다.");
	std::cout << s2[0] << ", " << s2[1] << std::endl;
	std::cout << s2[2] << std::endl;

	for (int i = 0; i < 3; i++)
		a2.destroy(s2 + i);

	a2.deallocate(s2,size);

}