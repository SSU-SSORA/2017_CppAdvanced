#include <iostream>
#include <queue>
#include <vector>

inline void NewLine() {
	std::cout << std::endl;
}
int main() {
	std::vector<int> myqueue{ 100,36,19,25,1,2,17,3,7 };
	std::priority_queue<int> mypq;

	std::cout << "ÃÊ±â v : ";
	for (auto i : myqueue) {
		std::cout << i << ' ';
		mypq.push(i);
	}
	NewLine();

	std::make_heap(myqueue.begin(), myqueue.end());
	while (!myqueue.empty()) {
		for (auto i : myqueue) std::cout << i << ' ';
		std::cout << std::endl;

		std::pop_heap(myqueue.begin(), myqueue.end());
		myqueue.pop_back();//mypq.pop()
	}

	std::cout << "priority queue contains : ";
	while (!mypq.empty()) {
		std::cout << ' ' << mypq.top();
		mypq.pop();
	}
	NewLine();
}