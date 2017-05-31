#include <iostream>
#include <vector>

template<typename T, size_t size>
constexpr size_t GetArrLength(T(&)[size]) {
	return size;
}//�迭�� ���̸� �˾Ƴ��� ���
//constexpr : const�� ����ϳ� ����θ� �ʱ�ȭ ����
//http://sweeper.egloos.com/3147813 ������ ��
//inline���� ó����

template<class T, int N>
void LinkedList(T(&arr)[N]) {
	for (int i(0); i < N; ++i)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

template<const int * pci, size_t size>
struct Array {
	void Print() {
		for (int i(0); i < size; ++i)
			std::cout << pci[i] << ' ';
		std::cout << std::endl;
	}
};

int ai[10];

int main(void) {
	int a[] = { 4,6,8,32,19 };

	std::cout << "�迭�� ũ�� : " << GetArrLength(a) << std::endl;
	LinkedList<int>(a);

	//int * dynamic = new int[5];
	//std::cout << GetArrLength(dynamic);

	//std::vector<int> vec(5);
	//std::cout << GetArrLength(vec);

	for (int i = 0; i < 10; ++i) ai[i] = a[i % 5];
	Array<ai, 10> xi;
	xi.Print();
}