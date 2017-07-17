#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
static int ranking = 1;

void print(int id) {
	//unique lock ����
	std::unique_lock<std::mutex> umtx(mtx);


	cv.wait(umtx);
	std::cout << ranking++ << ". thread" << id << '\n';
}

int main() {
	std::thread threads[20] = {};

	for (int i = 0; i < 10; ++i) {
		threads[i] = std::thread(print, i);
	}

	std::cout << "10���� �����尡 ���̽� ������ ��ģ��.\n";

	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	{
		std::unique_lock<std::mutex> umtx(mtx);
		cv.notify_all();
	}

	for (auto& th : threads) th.join();
	return 0;

}