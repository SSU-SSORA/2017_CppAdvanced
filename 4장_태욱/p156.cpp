#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Account {
	char *account;
	char *name;
	int balance;

	void Print() {
		printf("°è ÁÂ : %s, ¼ÒÀ¯ÀÚ : %s", account, name);
		printf(", °èÁÂ : %i\n", balance);
	}

	void Deposit(int money) {
		balance += money;
	}

	void WithDraw(int money) {
		balance -= money;
	}
};

Account *OpenAcct(const char *id, const char  * name, int bal) {
	Account *temp = new Account();
	if (nullptr == temp)
		return nullptr;

	char * newid = new char[strlen(id) + 1];//\0 ‹š¹® ¤·¤·
	if (nullptr == newid)
		return nullptr;
	strcpy(newid, id);
	temp->account = (char *)newid;


	char * newName = new char[strlen(id) + 1];
	if (nullptr == newName) 
		return nullptr;
	strcpy(newName, name);
	temp->name = (char *)newName;


	temp->balance = bal;
	cout << "Account °´Ã¼¸¦ »ý¼ºÇÏ¿´½À´Ï´Ù." << endl;
	return temp;
}

int CloseAcct(Account *acct) {
	cout << "Account °´Ã¼¸¦ »èÁ¦ÇÏ¿´½À´Ï´Ù." << endl;
	delete[] acct->account;
	delete[] acct->name;
	delete acct;
	return 1;
}

int main() {

	Account *hong = OpenAcct("120-345-123099", "È«±æµ¿", 60000);
	if (nullptr == hong)
		return -1;

	Account *kim = OpenAcct("120-345-123099", "±èÈ«µµ", 0);
	if (nullptr == kim)
		return -1;

	hong->WithDraw(2000);
	kim->Deposit(2000);
	hong->Print();
	kim->Print();

	CloseAcct(hong);
	CloseAcct(kim);
	return 0;

}