#include <iostream>


struct Data {
	int age;
	char name[100];
	int balance;
};
void Print(Data user) {
	std::cout << user.age << ", " << user.name << ",�ܾ� : "
		<< user.balance << std::endl;
}

int main(void) {
	//Data user-2 = (33, "�̼���", 20000);
	
	Data user03{ 53,"�̼���",20000 };
	Print(user03);

	//Data user04 = Data(53, "�̼���", 20000);

	//Data user05();

	Data user06 = Data();
	Print(user06);

	Data user07 = { 21,"ȫ�浿",10000 };
	Print(user07);//C���� ����

	//Data user08;
	//Print(user08);

	Data *user09 = new Data;
	Print(*user09);

	Data *user10 = new Data();
	Print(*user10);

}