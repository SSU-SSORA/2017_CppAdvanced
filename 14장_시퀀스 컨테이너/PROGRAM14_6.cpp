#include <iostream>
#include <vector>
#include <deque>

typedef std::pair <std::string, int> Boxing;

int main() {
	std::vector<Boxing> myVector;

	myVector.push_back(std::make_pair(std::string("�丶��"), 800));
	
	myVector.emplace(myVector.begin(), "���", 1000);
	myVector.emplace_back("�ٳ���", 3000);

	std::deque<Boxing> myDeque;
	while (!myVector.empty()) {
		myDeque.push_back(myVector.back());
		myVector.pop_back();
	}
	std::cout << "myVector�� ������ : ";
	for (auto& item : myVector)
		std::cout << '(' << item.first.data() << " : " << item.second << ')' << ' ';
	std::cout << std::endl;

	std::cout << "myDeque�� ������ : ";
	for (auto& item : myDeque)
		std::cout << '(' << item.first.data() << " : " << item.second << ')' << ' ';
	std::cout << std::endl;
}