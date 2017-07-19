#include <iostream>
#include <cmath>
#include <chrono>

constexpr unsigned long fibonacci(unsigned long i) {
	return (i <= 1u) ? i : fibonacci(i - 1) + fibonacci(i - 2);
}


using Chrono = std::chrono::steady_clock;

int main() {
	Chrono::time_point start = Chrono::now();
	std::cout << "f(42) = " << fibonacci(42) << '\n';

	Chrono::time_point end = Chrono::now();

	std::chrono::duration<double> defaultTime = end - start;
	std::cout << "�Ǻ���ġ���� ���� �ð� : "
		<< defaultTime.count() << "��(default)" << std::endl;

	std::chrono::nanoseconds nano =
		std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "�Ǻ���ġ���� ���� �ð� : " << nano.count() <<
		"���� ��" << std::endl;

	std::chrono::seconds sec =
		std::chrono::duration_cast<std::chrono::seconds>(end - start);
	std::chrono::minutes min =
		std::chrono::duration_cast<std::chrono::minutes>(end - start);
	std::cout << "�Ǻ���ġ���� ���� �ð� : " << sec.count() << "��" << std::endl;
	std::cout << "�Ǻ���ġ���� ���� �ð� : " << min.count() << "��" << std::endl;

	using minutes = std::chrono::duration<double, std::ratio<60, 1> >;
	minutes custom = std::chrono::duration_cast<minutes>(end - start);
	std::cout << "�Ǻ���ġ���� ���� �ð� : " << custom.count() << "��(����)" << std::endl;
	return 0;

}