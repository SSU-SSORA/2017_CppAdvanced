#include <iostream>
#include <vector>

int main() {
	std::vector<int> first;

	std::vector<int> second(4,100);

	std::vector<int> third(second.begin(), second.end());

	std::vector<int> fourth(third);

	fourth.resize(10);
	printf("벡터의 크기를 %d으로 재조정한다.\n", fourth.capacity());

	std::cout << "fourth 벡터의 요소 수 : " << fourth.size() << std::endl;
	std::cout << "fourth 벡터의 요소 : ";
	for (auto& i : fourth)
		std::cout << i << ' ';
	std::cout << std::endl;

	fourth.clear();
	printf("clear함수 호출 후 크기는 %d이다.\n", fourth.capacity());
	fourth.shrink_to_fit();//객체의 크기를 요소의 수에 맞추어 줄인다.
	printf("shrink_to_fit 함수 호출 후 크기는 %d이다.\n", fourth.capacity());
	return 0;
}