#include <iostream>
#include <locale>

//대부분의 컴파일러는 유니코드처리를 위한 wchar_t 타입으로 UTF-16을 사용함

int main(void) {
#if defined __linex__ || define __CYGWIN__
	setlocale(LC_ALL, "ko_KR.utf8");
	std::wcout << L"setlocate(LC_ALL, \"ko_KR.utf8\");" << std::endl;
#elif defined(WIN32)
	std::wcout.imbue(std::locale("kor"));
	std::wcin.imbue(std::locale("kor"));
	std::cout << "std::wcout.imbue (std::locate(\"kor\"));" << std::endl;
#endif



	wchar_t en[] = L"Hello World!";//L :오른쪽의 ASCII타입을 wchat_t 타입으로 변환하기 위한 명령어
	//위의 wchar_t 타입의 문자를 출력시키려면 std::wcout를 사용해야 한다.
	std::wcout << "wchar_t " << en << L", wchar_t 바이트 크기 : "
		<< sizeof(wchar_t) << std::endl;

	std::wcin >> en;

	std::cout << "std::cout을 사용하면 ";
	for (int i = 0; en[i]; i++) {
		std::cout << (char)en[i];
	}
	std::cout << std::endl;

	//wcout 변수를 사용한다면 유니코드 문자는 인코딩에 맞추어 정상 출력이 이루어진다.
	std::wcout << L"그러나 std::wcout을 사용하면\'" << en << "'" << std::endl;

	wchar_t wc1[] = L"한글화 작업";
	std::wcout << wc1 << std::endl;

	int i = 0;
	while (wc1[i]) {
		std::cout << (char)wc1[i];
		++i;
	}
	std::cout << std::endl;

	//\u는 유니코드 문자를 직접 입력할 때 사용한다
	const wchar_t *wc2 = L"\ud55c\uae00화 작업"; 
	std::wcout << wc2 << L", 문자 크기 : " << wcslen(wc2) << std::endl;
	return 0;
}