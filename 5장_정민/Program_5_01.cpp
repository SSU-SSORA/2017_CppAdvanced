#include<cstdlib>
#include<cstdio>
#include<cstring>

struct Account {
	Account(const char*id, const char*name, int bal) {
		strcpy(this->account, id);
		strcpy(this->name, name);
		this->balance = bal;
	}
	void Print(){
		printf("계좌: %s, 소유자: %s", account, name);
		printf(", 잔액:%i\n", balance);
	}
	void Deposit(int money){
		balance += money;
	}
	void Withdraw(int money) {
		balance -= money;
	}
private:
	char account[20];
	char name[20];
	int balance;
};

int main() {
	char id[] = "120-345-129099";
	char name[] = "홍길동";
	Account hong = Account(id, name, 60000);
	hong.Withdraw(10000);
	hong.Print();

	printf("계좌: %s, 소유자: %s", hong.account, hong.name); // 접근제한자 private 때문에 에러발생, 외부 함수의 접근 시 에러가 발생(main 함수)
	printf(", 잔액:%i\n", hong.balance);
	return 0;
}