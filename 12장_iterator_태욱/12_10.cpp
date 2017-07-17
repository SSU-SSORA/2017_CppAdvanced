#include <algorithm>
#include <iostream>
#include "12_2.hpp"

struct Sum {
	Sum() : sum{ 0 } {}
	void operator()(int n) { sum += n; }
	int sum;
};

struct myclass {
	void operator() (int i) {
		std::cout << i;
		if (0 != i) std::cout << " + ";
	}
}myObject;

int main() {
	Array<int> nums{ 3,4,2,8,15,267 };
	Sum s = std::for_each(nums.begin(), nums.end(), Sum());
	std::cout << s.sum << " = ";

	std::for_each(nums.begin(), nums.end(), myObject) (0);
	std::cout << std::endl;

	int myArr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int mycount = std::count_if(myArr, myArr + 12, [](int &n) ->bool {
		return ((n % 2) == 1);
	});
	std::cout << " 배열 내 모두 " << mycount << " 홀수가 존재한다.";
}