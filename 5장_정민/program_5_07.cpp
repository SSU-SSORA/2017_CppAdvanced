/*
���ǥ������ �ζ��� �Լ��� ������ ���(������ ó�� �ν��ϴ� ��)
ó���ӵ� ������ ��������� ���� �޸� ���

<constexpr ������ ��� ����>
- constexpr �����ڷ� ����� ������ const ������ó�� ������ ����� ����
  ����, constexpr �����ڷ� ����� ������ ���� �����ϴ� ������ ���α׷� �� �����ϸ� ���� �߻�
- constexpr �����ڴ� �Լ� �� Ŭ������ �����ڿ��� ���� ����
  �Լ��� constexpr�� ���� ��� inline �Լ��� �ν� => ����Լ����� �ַλ��
- constexpr �����ڷ� ����� �Լ��� ��ȯ�ϴ� �����ʹ� ���ͷ� Ÿ��
  constexpr �Լ��� ������ ������ ���� ���� ���Ұ� (p.203)  
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
	constexpr complex comp(0.0, 1.0); //comp������ ����� ���
	double x = 1.0;

	//constexpr complex cx1(x, 0); // ����, constexpr�����ڷ� ������ ������ ����̹Ƿ� �������� �μ��� ������ ����Ѵٸ� x�� ���� �˴��� ���� �߻�

	complex cx1(x, 10); //constexpr�����ڰ� �����Ƿ� ����
	std::cout << "�Ǽ� : " << cx1.real() << ", ��� : " << cx1.imag() << std::endl;

	const complex cx2(x, 1); //cx2 ������ const����� ����Ǿ� �ֱ� ������ ��� 

	//comp������ constexpr �����ڷ� ����� ����Ǿ� �����Ƿ� ���� ������� ���� ��� ����� �νĵȴ�.
	constexpr double cr = comp.real(); 
	constexpr double ci = comp.imag();
	std::cout << "�Ǽ� : " << cr << ", ��� : " << ci << std::endl;

	complex cx3(2, 4.6);
	const int dmv = 17;
	int var = 17;

	constexpr double max1 = 1.4*square(dmv); //const����� �μ��� ����ϹǷ����

	//constexpr double max2 = 1.4*square(var); //����, constexpr�� ���, �Լ��� �μ��� var�� �����̹Ƿ� �����߻�


	//const����� ������ ����ϴ��� ������ �ʱ�ȭ�Ǿ� �ִٸ� ���
	double max2 = 1.4*square(var);
	const double max3 = 1.4*square(var);
	std::cout << "���� : " << max3 << std::endl;
}


/*
constexpr����� const����� ����

1. ���ǥ���� ����� ������ �ϴ� �������� ����� �ν�
2. const ����� ���α׷��� ����Ǵ� ������ ����� �ν�
3. ���ǥ���� �����ڴ� ������ �����ϱ� ���� ���
4. const �����ڴ� �������� Ȯ���ϱ� ���� ���
5. 


*/
