#include <iostream>
#include <chrono>
#include <thread>

void independentThread() {
	std::cout << "independentThread()\n";

	//2�� ����
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "���� independentThread()\n";
}

void Caller() {
	std::cout << "caller() �Լ� ȣ��.\n";
	std::thread thread(independentThread);
	thread.detach();

	//2�ʰ� �������� �۾��� ����Ų��.
	std::this_thread::sleep_for(std::chrono::seconds(2));

	if (thread.joinable())
		thread.join();//join�Լ� ȣ�� ���ɿ��� Ž��
	std::cout << "caller �Լ� ���� " << std::endl;
}

int main() {
	//���� �����带 ����� �Լ��� �����Ű�� ��� �����带 �и���Ų��
	std::thread(Caller).detach();
	std::chrono::system_clock::time_point StartTime
		= std::chrono::system_clock::now();//���� �ð� ����
	std::chrono::seconds dura_sec(3);
	//�����尡 �и��� ���� ���� �����尡 �����Ѵٸ� �Ϲ� �����嵵 �����
	//���� 3�ʰ� ���
	std::this_thread::sleep_until(StartTime + dura_sec);
	std::cout << "���� ������ ����..\n";
}