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

	std::printf("�� �� : %s, ������ : %s", account.data(), name.data());
	std::printf(",\t�� �� : %d\n", bal);
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
		std::make_tuple("120-345-129099", "ȫ�浿",60000),
		std::make_tuple("120-345-129099", "��ȫ��",60000),
		std::make_tuple("120-345-129099", "�Ż��Ӵ�",60000),
	};

	std::cout << "std::set<Account, Compare>\n";
	for (const Account& a : s) {
		print(a);
	}

	std::unordered_set<Account, KeyHash> ms;

	ms.insert(Account("156-734-002391", "�̼���", 20000));
	ms.emplace("316-374-203191", "������", 10000);

	std::copy(s.begin(), s.end(), std::inserter(ms, ms.begin()));
	std::cout << "std::unordered_set<Account, KeyHash>\n";
	for (const Account& a : ms) {
		print(a);
	}
	return 0;
}