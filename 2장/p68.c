#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Rec {
	char account[20];
	char name[20];
	int balance;

	void(*Desposit)();
	void(*Withdraw)();
};

typedef struct Rec Account;

void Deposit(Account *this, int money) {
	this->balance += money;
}

void Withdraw(Account *this, int money) {
	this->balance -= money;
}

void OpenAcct(Account *this,
	const char * id, const char  * name, int bal) {
	strcpy(this->account, id);
	strcpy(this->name, name);
	this->balance = bal;

	this->Desposit = &Deposit;
	this->Withdraw = &Withdraw;
}

void Print(Account * this) {
	printf("°è ÁÂ : %s, ¼ÒÀ¯ÀÚ : %s", this->account, this->name);
	printf(", ÀÜ¾× : %i\n", this->balance);
}

int main() {
	Account hong;
	OpenAcct(&hong, "120-345-129099", "È«±æµ¿", 60000);
	hong.Withdraw(&hong, 10000);
	Print(&hong);
	return 0;
}