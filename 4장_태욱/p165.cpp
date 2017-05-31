#include <iostream>


struct Data {
	int age;
	char name[100];
	int balance;
};
void Print(Data user) {
	std::cout << user.age << ", " << user.name << ",잔액 : "
		<< user.balance << std::endl;
}

int main(void) {
	//Data user-2 = (33, "이순신", 20000);
	
	Data user03{ 53,"이순신",20000 };
	Print(user03);

	//Data user04 = Data(53, "이순신", 20000);

	//Data user05();

	Data user06 = Data();
	Print(user06);

	Data user07 = { 21,"홍길동",10000 };
	Print(user07);//C에서 유래

	//Data user08;
	//Print(user08);

	Data *user09 = new Data;
	Print(*user09);

	Data *user10 = new Data();
	Print(*user10);

}