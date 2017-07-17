#include <iostream>
#include <string>



class Shape {
public:
	virtual void Draw() {}

	//���� ��ü ���� �Լ�
	static Shape*  Create(std::string type);
};

class Circle :public Shape {
public:
	void Draw() { std::cout << "���Դϴ�. " << std::endl; }
};

class Square :public Shape {
public:
	void Draw() { std::cout << "���簢���Դϴ�. " << std::endl; }
};

Shape * Shape::Create(std::string type) {
	if (type == "circle") return new Circle();
	if (type == "square") return new Square();
	return NULL;
}

int main() {
	Shape * obj1 = Shape::Create("circle");
	Shape * obj2 = Shape::Create("square");

	obj1->Draw();
	obj2->Draw();
}