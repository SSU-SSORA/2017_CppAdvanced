#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

int main() {
	std::chrono::system_clock::time_point now =
		std::chrono::system_clock::now();

	std::time_t epoch = std::chrono::system_clock::to_time_t(now);

	std::cout << "에포크 시간 : " << epoch << std::endl;

	//localtime함수를 사용하여 지역 시간으로 바꾸어 출력
	std::cout << "현재 시간 :" << std::put_time(std::localtime(&epoch), "%c %Z")
		<< std::endl;

	//현재 시간에 24시간을 빼서 어제 시간을 환산한다
	std::time_t now_c =
		std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
	std::cout << "어제 시간 : "
		<< std::put_time(std::localtime(&now_c), "%F %T") << '\n';
}