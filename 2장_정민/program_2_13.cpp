#include <cstring>
#include <cstdlib>
#include <iostream>

int main() {
	const char *cc = "���ڿ��� �Է��մϴ�. This is a string";
	char cb[17];
	char *str;

	memcpy(cb, cc, 17);
	str = (char *)malloc(strlen(cc) + 1);
	strcpy(str, cc);

	std::cout << "cb = " << cb << ", ���ڿ��� ũ��� " << strlen(cb) << std::endl;
	std::cout << "str = " << str << ", ���ڿ��� ũ��� " << strlen(str) << std::endl;
	free(str);
}