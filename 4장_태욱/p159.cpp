#include <iostream>
#include <cstdlib>
#include <cstring>

class MyString {
public:
	char *mData;
	size_t mLength;

	const char * getData() {
		return mData;
	}


};



int main(void) {
	const char  *mString = "new �����ڿ� malloc()�Լ��� ����";
	unsigned short len = strlen(mString) + 1;

	//new
	MyString *s2 = new MyString();
	s2->mData = new char[len];
	memcpy(s2->mData, mString, len);
	printf("s2 ������ : 0x%p, s2->mData������ : 0x%p\n���� : %s\n", s2, s2->getData(), s2->getData());
	delete[] s2->mData;
	delete s2;

	size_t n = sizeof(MyString);
	std::cout << n << std::endl;

	MyString *s3 = (MyString *)malloc(n);
	s3->mData = (char *)malloc(len);
	memcpy(s3->mData, mString, len);
	printf("s3 ������ : 0x%p, s3->mData������ : 0x%p\n���� : %s\n", s3, s3->getData(), s3->getData());
	free(s3->mData);
	free(s3);
	return 0;


}