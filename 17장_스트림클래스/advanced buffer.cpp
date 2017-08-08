#include <iostream>
#include <fstream>

int MakeFile(const char * input, const char * output) {
	std::ifstream infile(input);
	if (infile.fail()) {
		std::cout << input << "������ �� �� �����ϴ�." << std::endl;
		return 1;
	}

	std::ofstream outfile(output);
	if (outfile.fail()) {
		std::cout << output << "������ �� �� �����ϴ�. " << std::endl;
		return 1;
	}

	std::filebuf* infub = infile.rdbuf();
	outfile << infub;

	infile.close();
	outfile.close();
	return 0;
}