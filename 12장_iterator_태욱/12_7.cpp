#include <iostream>
#include <iterator>
#include "12_2.hpp"

int main() {
	Array<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	std::cout << "distance(first, last) = "
		<< std::distance(v.begin(), v.end()) << '\n'
		<< "distance(last, first) = "
		<< std::distance(v.begin(), v.end()) << std::endl;

	auto vi = std::begin(v);

	auto nx = std::next(vi, 2);
	std::cout << *vi << ", " << *nx << ", ";

	auto pv = std::prev(nx, 1);
	std::cout << *pv << ", ";

	std::advance(vi, 5);
	std::cout << *vi << std::endl;

	std::cout << "반대 방향 ";
	std::reverse_iterator<Array<int> > rb = std::rbegin(v);
		
		while (rb != std::rend(v))
		std::cout << *rb++ << ' ';
	std::cout << std::endl;
}