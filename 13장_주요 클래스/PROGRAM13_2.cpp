#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

int main() {
	std::chrono::system_clock::time_point now =
		std::chrono::system_clock::now();

	std::time_t epoch = std::chrono::system_clock::to_time_t(now);

	std::cout << "����ũ �ð� : " << epoch << std::endl;

	//localtime�Լ��� ����Ͽ� ���� �ð����� �ٲپ� ���
	std::cout << "���� �ð� :" << std::put_time(std::localtime(&epoch), "%c %Z")
		<< std::endl;

	//���� �ð��� 24�ð��� ���� ���� �ð��� ȯ���Ѵ�
	std::time_t now_c =
		std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
	std::cout << "���� �ð� : "
		<< std::put_time(std::localtime(&now_c), "%F %T") << '\n';
}