#include <iostream>
#include <future>

int main() {
	auto f = []() {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "�۾� ����" << std::endl;
	};

	auto handle = std::async(f);
	std::cout << "�񵿱��Լ� ȣ�� " << std::endl;
	return 0;
}