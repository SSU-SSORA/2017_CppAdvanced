#include<iostream>

class SimpleClass {
public:
	int xval;// 접근제한자가 public이므로 외부함수에서의 접근이 가능
};

int main()
{
	SimpleClass ss;//SimpleClass 클래스 타입의 ss변수를 선언
	ss.xval = 5;
	std::cout << "객체에 저장된 값은" << ss.xval << "이다,\n";

}
/*
멤버변수의 접근제한자를 private으로 하는 이유:
유지보수, 버그를 수정하기 위해 클래스 내 멤버를 삭제하거나 수정한다면 해당 멤버에 접근하여 
데이터의 입출력을 수행하던(ex. line 11, 12) 모든 외부 함수나 프로그램들에 대한 수정이 필요
"내가 사용하지 않는 기능을 위해 비용을 지불하지 말아야 한다"

클래스는 외부로부터 받을 수 있는 영향력을 최소화해야

*/