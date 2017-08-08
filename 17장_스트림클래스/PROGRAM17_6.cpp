#include <iostream>
#include <fstream>

int main(int argc, char * argv[]) {
	if (argc < 3) {
		std::cout << "���ϸ��� �Է��Ͻñ� �ٶ��ϴ�." << std::endl;
		return 1;
	}

	std::ifstream input;
	input.open(argv[1], std::ios::binary | std::ios::in);

	std::ofstream output;
	output.open(argv[2], std::ios::binary | std::ios::out);

	if (input.is_open() && output.is_open()) {
		std::streambuf *inbuf = input.rdbuf();
		std::streambuf *outbuf = output.rdbuf();

		//������ ũ�⸦ �˾ƺ���.
		std::streamsize length = inbuf->pubseekoff(0, input.end);
		//(������, ����)
		inbuf->pubseekoff(0, input.beg);
		/* ���� �ѹ��� �����͸� �Է½�Ű���� ������ ���� ���α׷��Ѵ�.
		* char * contents = new char[length];
		* int count = infub->sgetn(contents, length);
		* outbuf->sputn(contents, length);
		*/

		char buffer[1024];
		std::streamsize cnt;
		int count = 0;

		while ((cnt = inbuf->sgetn(buffer, sizeof(buffer))) > 0) {
			outbuf->sputn(buffer, cnt);
			count += cnt;
		}

		if (length == count)
			std::cout << "������ ��ü ũ�� : " << length << std::endl;
		else {
			std::cout << "������ ��ü ũ�� : " << length
				<< ", error: only " << count << "�� ����" << std::endl;
		}
		input.close();
		output.close();
	}
	return 0;
}
