/*
상수표현식은 인라인 함수와 동일한 기능(데이터 처럼 인식하는 식)
처리속도 빠르고 상대적으로 적은 메모리 사용

<constexpr 지정자 사용 조건>
- constexpr 지정자로 선언된 변수는 const 지정자처럼 변수를 상수로 만듬
  만약, constexpr 지정자로 선언된 변수의 값을 수정하는 문장이 프로그램 내 존재하면 에러 발생
- constexpr 지정자는 함수 및 클래스의 생성자에도 적용 가능
  함수에 constexpr을 붙일 경우 inline 함수로 인식 => 재귀함수에서 주로사용
- constexpr 지정자로 선언된 함수가 반환하는 데이터는 리터럴 타입
  constexpr 함수의 본문은 다음과 같은 문장 사용불가 (p.203)  
*/

#include<iostream>

struct complex {
	constexpr complex(double r, double i) : re(r), im(i){}
	constexpr double real() const { return re; }
	constexpr double imag() const { return im; }
private:
	double re;
	double im;
};

constexpr double square(double x) { return x*x; }

int main()
{
	constexpr complex comp(0.0, 1.0); //comp변수는 상수로 사용
	double x = 1.0;

	//constexpr complex cx1(x, 0); // 에러, constexpr지정자로 선언한 변수는 상수이므로 생성자의 인수로 변수를 사용한다면 x의 값을 알더라도 에러 발생

	complex cx1(x, 10); //constexpr지정자가 없으므로 변수
	std::cout << "실수 : " << cx1.real() << ", 허수 : " << cx1.imag() << std::endl;

	const complex cx2(x, 1); //cx2 변수는 const상수로 선언되어 있기 때문에 허용 

	//comp변수는 constexpr 지정자로 상수로 선언되어 있으므로 내부 멤버변수 역시 모두 상수로 인식된다.
	constexpr double cr = comp.real(); 
	constexpr double ci = comp.imag();
	std::cout << "실수 : " << cr << ", 허수 : " << ci << std::endl;

	complex cx3(2, 4.6);
	const int dmv = 17;
	int var = 17;

	constexpr double max1 = 1.4*square(dmv); //const상수를 인수로 사용하므로허용

	//constexpr double max2 = 1.4*square(var); //에러, constexpr은 상수, 함수의 인수인 var은 변수이므로 에러발생


	//const상수는 변수를 사용하더라도 변수가 초기화되어 있다면 허용
	double max2 = 1.4*square(var);
	const double max3 = 1.4*square(var);
	std::cout << "제곱 : " << max3 << std::endl;
}


/*
constexpr상수와 const상수의 차이

1. 상수표현식 상수는 컴파일 하는 시점부터 상수로 인식
2. const 상수는 프로그램이 실행되는 시점에 상수로 인식
3. 상수표현식 지정자는 성능을 보장하기 위해 사용
4. const 지정자는 안전성을 확보하기 위해 사용
5. 


*/
