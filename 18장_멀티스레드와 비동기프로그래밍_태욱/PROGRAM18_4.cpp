#include <chrono>
#include <iostream>
#include <thread>

int global = 0;
#define MAX_THREAD 2

void function(int func, int loops) {
	
	for (int i = 0; i < loops; ++i) {
		++global;

		if ((i % 10) == 0)
			std::this_thread::yield();
	}

	printf("%d. global = %d\n", func, global);
}

int main() {
	std::thread t[MAX_THREAD];

	for (int i = 0; i < MAX_THREAD; ++i) {
		t[i] = std::thread(function, i, 10000);
		t[i].join();
	}
	
	printf("global = %d\n", global);
}