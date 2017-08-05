#include <tuple>
#include <string>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <iterator>


typedef std::tuple<std::string, std::string, int> Account;

void print(const Account & val) {
	std::string account;
	std::string name;
	int bal;
	std::tie(account, name, bal) = val;

	std::printf("°è ÁÂ : %s, ¼ÒÀ¯ÀÚ : %s", account.data(), name.data());
	std::printf(",\tÀÜ ¾× : %d\n", bal);
}

struct Compare {
	bool operator()(const Account& i, const Account& j) {
		return std::get<1>(i) < std::get<1>(j);
	}
};

struct KeyHash {
	std::size_t operator()(const Account& val)const {
		std::string account;
		std::string name;
		int balance;
		std::hash<std::string> hash;
		std::tie(account, name, balance) = val;

		return ((hash(account) ^ hash(name) << 1) >> 1)
			^ (std::hash<int>()(balance) << 1);
	}
};

bool operator==(const Account& lhs, const Account& rhs) {
	return std::get<0>(lhs) == std::get<0>(rhs) &&
		std::get<1>(lhs) == std::get<1>(rhs);
}

int main() {
	KeyHash();
	std::set<Account, Compare> s = {
		std::make_tuple("120-345-129099", "È«±æµ¿",60000),
		std::make_tuple("120-345-129099", "±èÈ«µµ",60000),
		std::make_tuple("120-345-129099", "½Å»çÀÓ´ç",60000),
	};

	std::cout << "std::set<Account, Compare>\n";
	for (const Account& a : s) {
		print(a);
	}

	std::unordered_set<Account, KeyHash> ms;

	ms.insert(Account("156-734-002391", "ÀÌ¼ø½Å", 20000));
	ms.emplace("316-374-203191", "±èÀ¯½Å", 10000);

	std::copy(s.begin(), s.end(), std::inserter(ms, ms.begin()));
	std::cout << "std::unordered_set<Account, KeyHash>\n";
	for (const Account& a : ms) {
		print(a);
	}
	return 0;
}