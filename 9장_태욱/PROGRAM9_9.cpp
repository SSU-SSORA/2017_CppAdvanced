#include <cstdlib>
#include <random>
#include <iostream>

int main() {
	int array[10];
	int i;

	std::random_device rd;
	srand((unsigned)rd());//난수 발생 장치를 이용해 초기화 값을 구한다
	for (int i = 0; i < 10; ++i) {
		array[i] = std::rand() % 1000;
	}

	std::cout << "sort 전 : ";
	for (int i = 0; i < 10; ++i) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
	
	auto sorter = [](const void * first, const void * second)->int {
		return (*(int *)first - *(int *)second);
	};
	qsort(array, 10, sizeof(int), sorter);
	std::cout << "sort 후 : ";
	for (int i = 0; i < 10; ++i) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;


}



