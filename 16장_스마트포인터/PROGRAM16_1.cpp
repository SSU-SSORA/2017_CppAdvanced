#include <iostream>
#include <memory>
#include <cassert>

struct Sample {
	Sample(int content = 0) : _content(content) {
		std::cout << "Constructing Sample(" << _content << ")" << std::endl;
	}
	~Sample() {
		std::cout << "Deleting Sample(" << _content << ")" << std::endl;
	}
	int getContent() {
		return _content;
	}

private:
	int _content;
};

struct Deleter {
	Deleter() {
		std::cout << "Deleter ��ü�� �����Ǿ���.\n";
	}
	void operator()(Sample *p) const {
		std::cout << "Sample(" << p->getContent()
			<< ")��ü�� ������Ű�� ���� ȣ���Ѵ�....\n";
		delete p;
	}
};

int main() {
	std::unique_ptr<Sample, Deleter> up0(new Sample(11));

	std::unique_ptr<Sample> u1 = std::make_unique<Sample>(3);

	std::unique_ptr<int> u2(new int(10), std::default_delete<int>());

	*u2 = 20;
	std::cout << "u2 = *u2" << '\n';
	return 0;
}