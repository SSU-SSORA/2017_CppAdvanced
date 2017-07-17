#include <iostream>
#include <chrono>
#include <thread>

void independentThread() {
	std::cout << "independentThread()\n";

	//2초 지연
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "종료 independentThread()\n";
}

void Caller() {
	std::cout << "caller() 함수 호출.\n";
	std::thread thread(independentThread);
	thread.detach();

	//2초간 스레드의 작업을 대기시킨다.
	std::this_thread::sleep_for(std::chrono::seconds(2));

	if (thread.joinable())
		thread.join();//join함수 호출 가능여부 탐색
	std::cout << "caller 함수 종료 " << std::endl;
}

int main() {
	//무명 스레드를 만들고 함수를 실행시키는 즉시 스레드를 분리시킨다
	std::thread(Caller).detach();
	std::chrono::system_clock::time_point StartTime
		= std::chrono::system_clock::now();//현재 시간 저장
	std::chrono::seconds dura_sec(3);
	//스레드가 분리된 이후 메인 스레드가 종료한다면 일반 스레드도 종료됨
	//따라서 3초간 대기
	std::this_thread::sleep_until(StartTime + dura_sec);
	std::cout << "메인 쓰레드 종료..\n";
}