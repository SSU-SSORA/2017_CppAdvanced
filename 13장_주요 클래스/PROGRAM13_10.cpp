#include <utility>
#include <string>
#include <algorithm>
#include <tuple>
#include <iostream>
#include <vector>

typedef std::pair<std::string, double> myPair;
bool Compare(const myPair& i, const myPair& j) {
	return i.second < j.second;
}

int main() {
	myPair product1;
	myPair product2("tomatoes", 2.30);
	myPair product3(product2);
	myPair product4;

	product1 = std::make_pair(std::string("lightbulbs"), 5.99);
	product4.first = "shoes";
	product4.second = 30.90;

	std::vector<myPair> product;
	product.push_back(product1);
	product.push_back(product2);
	product.push_back(product3);
	product.push_back(product4);
	product.push_back(std::make_pair<std::string, double>("apple", 3.10));

	std::sort(product.begin(), product.end(), Compare);

	for (int i = 0; i < 5; ++i) {
		std::cout << i << ". " << product[i].first << "�� ������"
			<< product[i].second << "�̴�." << std::endl;
	}
	return 0;
}