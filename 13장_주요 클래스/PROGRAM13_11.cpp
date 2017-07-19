#include <tuple>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

typedef std::tuple<std::string, std::string, int> Account;

void print(Account& val) {
	std::string account;
	std::string name;
	int bal;
	std::tie(account, name, bal);

	std::printf("°è ÁÂ : %s, ¼ÒÀ¯ÀÚ : %s", account.data(), name.data());
	std::printf(",\t ÀÜ ¾× : %d\n", bal);
}

bool Compare(const Account &i, const Account& j) {
	return std::get<2>(i) < std::get<2>(j);
}

int main() {
	std::vector<Account> array = {
		std::make_tuple("120-345-129099","È«±æµ¿",60000),
		std::make_tuple("120-345-129099","±èÈ«µµ",60000),
		std::make_tuple("120-345-129099","½Å»çÀÓ´ç",60000)
	};

	Account lee("156-734-002391", "ÀÌ¼ø½Å", 20000);
	Account kim("316-374-002391", "ÀÌ¼ø½Å", 20000);

	std::string name;
	int bal;

	std::tie(std::ignore, name, bal) = lee;
	std::cout << name << ", " << bal << std::endl;

	auto myNums = std::tuple_cat(lee, kim);
	std::cout << "Value 1 : " << std::get<0>(myNums) << ", "
		<< std::get<1>(myNums) << ", " << std::get<2>(myNums) << std::endl;
	std::cout << "Value 2 : " << std::get<3>(myNums) << ", "
		<< std::get<4>(myNums) << ", " << std::get<5>(myNums) << std::endl;

	array.push_back(lee);
	array.push_back(kim);
}