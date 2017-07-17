#include <iostream>
#include <string>



class Shape {
public:
	virtual void Draw() {}

	//정적 객체 생성 함수
	static Shape*  Create(std::string type);
};

class Circle :public Shape {
public:
	void Draw() { std::cout << "원입니다. " << std::endl; }
};

class Square :public Shape {
public:
	void Draw() { std::cout << "정사각형입니다. " << std::endl; }
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