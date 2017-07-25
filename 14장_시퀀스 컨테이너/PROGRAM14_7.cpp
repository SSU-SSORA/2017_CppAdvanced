#include <iostream>
#include <forward_list>
#include <iomanip>

const size_t MAX_WIDTH = 80;
typedef std::pair<std::string, int> Boxing;

template <typename T>
void print(const char *str, std::forward_list<T>& myList) {
	std::cout << str;
	for (auto& item : myList) std::cout << item << " ";
	std::cout << std::endl;
}

int main() {
	std::forward_list<int> myList01 = { 3,52,25,90,500 };

	auto it = myList01.insert_after(myList01.begin(), 2, 20);//52�� ����Ŵ
	print<int>("ù ��° myList01 : ", myList01);

	std::forward_list<int> myList02 = { 100,10,30,5,1 };
	print<int>("ù ��° myList02 : ", myList02);

	std::cout << "splice_after �۾� �� : \n";
	myList02.splice_after(myList02.before_begin(), myList01, it);

	print<int>("�� ��° myList01 : ", myList01);
	print<int>("�� ��° myList02 : ", myList02);
	std::cout << "merge �۾� �� :\n";

	std::forward_list<int> myList03(myList01);
	std::forward_list<int> myList04(myList02);

	myList03.sort(std::less<int>());
	myList04.sort(std::less<int>());

	myList03.merge(myList04);
	print<int>("�� ��° myList03 : ", myList03);
	print<int>("�� ��° myList04 : ", myList04);
}