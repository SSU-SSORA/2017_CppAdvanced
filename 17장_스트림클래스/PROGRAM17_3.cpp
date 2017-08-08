#include <iostream>
#include <fstream>
#include <string>
#include <locale>

int makeFile(const char * input, const char* output) {
	std::ifstream input_file(input); 
	if (!input_file.is_open()) {
		std::cout << input << "������ �� �� �����ϴ�.\n";
		return 1;
	}

	std::ofstream output_file(output);
	if (!output_file.is_open()) {
		std::cout << output << "������ �� �� �����ϴ�." << std::endl;
		return 1;
	}

	char data[100];

	while (input_file >> data) {
		output_file << data;
	}

	input_file.close();
	output_file.close();
	return 0;
}

int ReadFile(const char *input) {
	std::ifstream input_file(input);
	if (!input_file.is_open()) {
		std::cout << input << "������ �� �� �����ϴ�.\n";
		return 1;
	}

	std::string data;
	while (input_file >> data) {
		std::cout << data << std::endl;
	}

	input_file.close();
	return 0;
}

int main(int argc, char * argv[]) {
	if (argc < 2) {
		std::cout << "���ϸ��� �Է��Ͻñ� �ٶ��ϴ�. " << std::endl;
		return 1;
	}
	const char* file = "output.txt";
	if (makeFile(argv[1], file)) {
		std::cout << argv[1] << "���� �۾� �� ������ �߻��߽��ϴ�. "
			<< std::endl;
		return 1;
	}

	if (ReadFile(argv[1])) {
		std::cout << file << "���� �۾� �� ������ �߻��Ͽ����ϴ�." << std::endl;
		return 1;
	}
	return 0;

}