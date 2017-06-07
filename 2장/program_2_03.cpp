#include<iostream>

namespace {
	void SampleMethod() {
		std::cout << "���� ���ӽ����̽� �� SampleMethod �Լ��Դϴ�." << std::endl;
	}
}

namespace sample {
	void SampleMethod() {
		::SampleMethod(); //���� ���ӽ����̽� �� SampleMethod() �Լ� ȣ��
		std::cout << "> sample ���ӽ����̽� �� SampleMethod �Լ��Դϴ�." << std::endl;
	}
	namespace nested {
		void SampleMethod() {
			std::cout << ">> nested ���ӽ����̽� �� SampleMethod �Լ��Դϴ�." << std::endl;
		}
	}
}

int main()
{
	sample::SampleMethod();
	sample::nested::SampleMethod();
	SampleMethod();
	::SampleMethod();
	return 0;
}
/*
���� ���ӽ����̽�(ex. std)
- main�Լ��� ���ӽ����̽� �Ҽӵ��� ����

���� ���ӽ����̽� �� �Լ��� ���� ȣ�� ���
- ::hello();, hello();

���� ���ӽ����̽�
- ���� ���ӽ����̽�ó�� �Լ��� ������ ȣ���ϴ� ����� ����
*/