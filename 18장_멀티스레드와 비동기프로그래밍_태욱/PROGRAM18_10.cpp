#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>
std::mutex cout_mutex;

void InThread(const char * name) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::lock_guard<std::mutex> lock(cout_mutex);
	std::cout << name << "������ ���̵� : "
		<< std::this_thread::get_id() << std::endl;
}

int main() {
	std::cout << "�ϵ���� CPU �ھ� �� : "
		<< std::thread::hardware_concurrency() << std::endl;
	std::thread thread1(InThread, "Thread1");
	std::thread thread2 = std::thread(InThread, "Thread2");

	//�Ʒ��� 
	std::thread thread3([&](int nParam) {
		std::cout << "Thread3 : " << std::this_thread::get_id() << std::endl;
		for (int i = 0; i < nParam; ++i)
			std::cout << "Thread3 Parameter : " << nParam << std::endl;
	}, 4);
	/*
	thread1.join();
	thread2.join();
	thread3.join();
	*/
	return 0;
}