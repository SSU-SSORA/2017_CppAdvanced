#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Account {
	char *account;
	char *name;
	int balance;

	void Print() {
		printf("�� �� : %s, ������ : %s", account, name);
		printf(", ���� : %i\n", balance);
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

	char * newid = new char[strlen(id) + 1];//\0 ���� ����
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
	cout << "Account ��ü�� �����Ͽ����ϴ�." << endl;
	return temp;
}

int CloseAcct(Account *acct) {
	cout << "Account ��ü�� �����Ͽ����ϴ�." << endl;
	delete[] acct->account;
	delete[] acct->name;
	delete acct;
	return 1;
}

int main() {

	Account *hong = OpenAcct("120-345-123099", "ȫ�浿", 60000);
	if (nullptr == hong)
		return -1;

	Account *kim = OpenAcct("120-345-123099", "��ȫ��", 0);
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