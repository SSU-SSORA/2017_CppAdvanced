#include <iostream>
#include <random>
#include <cstdlib>
#include <fstream>

int main() {
	std::random_device rd;
	srand((unsigned)rd());
	
	std::ofstream out("random.txt");
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j)
			out << rand() % 10;
		out << '\n';
	}
	out.close();
}