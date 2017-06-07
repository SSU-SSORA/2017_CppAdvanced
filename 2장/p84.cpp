#include <cstdlib>
#include <cstdio>
#include <cstring>

struct Account {
	Account(const char * id, const char * n, int bal) {
		strcpy(account, id);
		strcpy(name, n);
		balance = bal;
	}

	void Print() const {
		printf("°è ÁÂ : %s, ¼ÒÀ¯ÀÚ : %s", account, name);
		printf(", ÀÜ ¾× : %i\n", balance);
	}

	void Deposit(int money) {
		balance += money;
	}

	void Withdraw(int money) {
		balance -= money;
	}

	char account[20];
	char name[20];
	int balance;
};