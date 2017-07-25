#include <iostream>
#include <list>
#include <iomanip>

const size_t MAX_WIDTH = 80;
typedef std::pair<std::string, int> Boxing;


void print(const char *str, std::list<Boxing>& myList) {
	std::cout << std::left << std::setw(MAX_WIDTH) << std::setfill('-')
		<< str << std::endl;
	for (auto& item : myList) 
		std::cout << '(' << item.first.data() << " : " << item.second << ')' << ' ';
	std::cout << std::endl;
}

int main() {
	
	std::list<Boxing> myList;

	myList.push_front(std::make_pair(std::string("�丶��"), 800));
	myList.push_back(std::make_pair(std::string("����"), 200));
	

	Boxing b = std::make_pair(std::string("�Ź�"), 25000);
	myList.insert(myList.begin(), b);
	myList.insert(myList.begin(), b);

	myList.emplace(myList.begin(), "���", 500);

	myList.emplace_front("¥���", 5000);
	myList.emplace_front("�ع�«��", 7000);
	print("ù ��° myList : ", myList);

	auto s = [](Boxing & b1, Boxing& b2)->bool {
		if (b1.second == b2.second)
			return b1.first < b2.first;
		else return b1.second < b2.second;
	};

	myList.sort(s);
	print("Sort �� myList : ", myList);

	auto u = [](Boxing& b1, Boxing& b2) ->bool {
		return b1.first == b2.first && b1.second == b2.second;
	};

	myList.unique(u);
	print("unique�� �ߺ� ���� �� myList : ", myList);

	myList.pop_front();
	myList.erase(myList.begin());
	print("pop_front�� erase �Լ��� ���� �� myList : ", myList);
	return 0;
}