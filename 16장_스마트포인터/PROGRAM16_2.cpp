#include <iostream>
#include <memory>

class Box {
public:
	Box(int w = 0, int l = 0, int h = 0) :  length(l), height(h), width(w) {}

	inline int Volume(){ return width * length * height; }

	void SetBox(int w = 0, int  l = 0, int h = 0) {
		width = w;
		length = l;
		height = h;
	}
	friend std::ostream& operator<<(std::ostream & os, Box& v) {
		return os << '{' << "�� : " << v.width
			<< ", ���� : " << v.length
			<< ", ���� : " << v.height << "}";
	}
private:
	int width;
	int length;
	int height;
};

int main() {
	std::unique_ptr<Box> v1 = std::make_unique<Box>();
	std::unique_ptr<Box> v2 = std::make_unique<Box>(10, 5, 2);
	
	std::unique_ptr<Box[]> v3 = std::make_unique<Box[]>(5);
	
	std::cout << "make_unique<Box>() : " << *v1 << '\n'
		<< "make_unique<Box>(10,5,2) ũ�� : " << v2->Volume() << '\n';

	v3[0].SetBox(2, 2, 2);
	v3[4].SetBox(4, 4, 4);
	std::cout << "make_unique<box[]>(5):    " << '\n';
	for (int i = 0; i < 5; ++i) {
		std::cout << "    " << v3[i] << '\n';
	}
}