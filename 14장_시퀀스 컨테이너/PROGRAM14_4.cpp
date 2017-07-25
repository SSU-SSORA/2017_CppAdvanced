#include <iostream>
#include <algorithm>
#include <deque>

int main() {
	std::deque<int> que = { 7,5,16,8 };
	{
		//초기화
		que.emplace_back(1);
		que.emplace_back(2);
	}


	std::cout << "deque size = " << que.size() << " : ";
	for (auto& i : que)
		std::cout << i << ' ';
	std::cout << '\n';

	int * variable = &que[3];
	std::cout << "variable : " << *variable << std::endl;
	*variable = 156;

	for (int i = 3; i < 8; ++i)
		que.push_back(i*i);

	std::cout << "확장된 quetor size = " << que.size() << " : ";

	std::deque<int>::iterator v = que.begin();
	while (v != que.end()) {
		std::cout << *v << " ";
		++v;
	}
	std::cout << std::endl;

	std::cout << "삭제 예정인 que[2]  = " << que[2] << std::endl;
	que.erase(que.begin() + 2);


	std::deque<int>::iterator it = std::find(que.begin(), que.end(), 5);
	if (it != que.end()) {
		std::cout << "발견한 숫자의 삭제 = " << *it << std::endl;
		que.erase(it);
	}

	it = que.insert(it, 200);
	it = que.insert(it, 2, 300);
	it = que.emplace(que.end(), 234);

	int size = que.size();
	int arr[100];
	std::copy(que.begin(), que.end(), arr);
	std::cout << "array size = " << size << " : ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
	return 0;
}