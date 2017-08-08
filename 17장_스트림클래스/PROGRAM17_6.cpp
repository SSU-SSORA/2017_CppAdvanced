#include <iostream>
#include <fstream>

int main(int argc, char * argv[]) {
	if (argc < 3) {
		std::cout << "파일명을 입력하시기 바랍니다." << std::endl;
		return 1;
	}

	std::ifstream input;
	input.open(argv[1], std::ios::binary | std::ios::in);

	std::ofstream output;
	output.open(argv[2], std::ios::binary | std::ios::out);

	if (input.is_open() && output.is_open()) {
		std::streambuf *inbuf = input.rdbuf();
		std::streambuf *outbuf = output.rdbuf();

		//파일의 크기를 알아본다.
		std::streamsize length = inbuf->pubseekoff(0, input.end);
		//(오프셋, 기준)
		inbuf->pubseekoff(0, input.beg);
		/* 만약 한번에 데이터를 입력시키려면 다음과 같이 프로그램한다.
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
			std::cout << "파일의 전체 크기 : " << length << std::endl;
		else {
			std::cout << "파일의 전체 크기 : " << length
				<< ", error: only " << count << "만 읽음" << std::endl;
		}
		input.close();
		output.close();
	}
	return 0;
}
