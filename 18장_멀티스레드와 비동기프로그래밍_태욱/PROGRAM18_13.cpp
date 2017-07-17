#include <thread>
#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

void accumulate_block_worker(int *data, size_t size, int * result) {
	*result = std::accumulate(data, data + size, 0);
}

std::vector<std::thread> launch_workers(std::vector<int>& v,
	std::vector<int> * results) {
	std::vector<std::thread> threads;

	threads.emplace_back(accumulate_block_worker, v.data(), v.size() / 2, &((*results)[0]));

	threads.emplace_back(accumulate_block_worker, v.data() + v.size()/2, v.size() / 2, &((*results)[1]));

	return threads;
}

int main() {
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	std::vector<int> results(2, 0);
	std::vector<std::thread> threads = launch_workers(v,&results);
	for (auto &t : threads)
		t.join();

	std::cout << "�� �� �迭�� ���� " << results[0] << " �� " << results[1] << std::endl;
	std::cout << "�� �� �迭�� ���� " << results[0] + results[1] << std::endl;
	return 0;

}