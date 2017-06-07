#include <iostream>
#include <locale>

//��κ��� �����Ϸ��� �����ڵ�ó���� ���� wchar_t Ÿ������ UTF-16�� �����

int main(void) {
#if defined __linex__ || define __CYGWIN__
	setlocale(LC_ALL, "ko_KR.utf8");
	std::wcout << L"setlocate(LC_ALL, \"ko_KR.utf8\");" << std::endl;
#elif defined(WIN32)
	std::wcout.imbue(std::locale("kor"));
	std::wcin.imbue(std::locale("kor"));
	std::cout << "std::wcout.imbue (std::locate(\"kor\"));" << std::endl;
#endif



	wchar_t en[] = L"Hello World!";//L :�������� ASCIIŸ���� wchat_t Ÿ������ ��ȯ�ϱ� ���� ��ɾ�
	//���� wchar_t Ÿ���� ���ڸ� ��½�Ű���� std::wcout�� ����ؾ� �Ѵ�.
	std::wcout << "wchar_t " << en << L", wchar_t ����Ʈ ũ�� : "
		<< sizeof(wchar_t) << std::endl;

	std::wcin >> en;

	std::cout << "std::cout�� ����ϸ� ";
	for (int i = 0; en[i]; i++) {
		std::cout << (char)en[i];
	}
	std::cout << std::endl;

	//wcout ������ ����Ѵٸ� �����ڵ� ���ڴ� ���ڵ��� ���߾� ���� ����� �̷������.
	std::wcout << L"�׷��� std::wcout�� ����ϸ�\'" << en << "'" << std::endl;

	wchar_t wc1[] = L"�ѱ�ȭ �۾�";
	std::wcout << wc1 << std::endl;

	int i = 0;
	while (wc1[i]) {
		std::cout << (char)wc1[i];
		++i;
	}
	std::cout << std::endl;

	//\u�� �����ڵ� ���ڸ� ���� �Է��� �� ����Ѵ�
	const wchar_t *wc2 = L"\ud55c\uae00ȭ �۾�"; 
	std::wcout << wc2 << L", ���� ũ�� : " << wcslen(wc2) << std::endl;
	return 0;
}