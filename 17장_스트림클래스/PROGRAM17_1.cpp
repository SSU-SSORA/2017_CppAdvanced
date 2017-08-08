#include <iostream>

class Distance {
private:
	int meters;
	int centimeters;

public:
	Distance(int f = 0, int i = 0) {
		SetDistance(f, i);
	}
	void SetDistance(int f = 0, int i = 0) {
		if (i >= 100) {
			centimeters = i % 100;
			meters = (i / 100) + f;
		}
		else {
			meters = f;
			centimeters = i;
		}
	}

	int GetMeters() const {
		return meters;
	}
	int GetCentiMeters() const {
		return centimeters;
	}

	friend std::ostream &operator<<(std::ostream &output, const Distance& d) {
		output << d.meters << "m " << ",\t" << d.centimeters << "cm";
		return output;
	}
	friend std::istream &operator>>(std::istream &input, Distance &d) {
		int m, cm;
		std::cout << "���� : ";
		input >> m;
		std::cout << "��Ƽ���� : ";
		input >> cm;
		d.SetDistance(m, cm);
		return input;
	}
};

int main() {
	Distance d1(8, 10), d2(6, 11), d3;

	std::cin >> d3;
	std::cout << "ù ��° �õ� ���� �ٱ� �Ÿ� : " << d1 << std::endl;
	std::cout << "�� ��° �õ� ���� �ٱ� �Ÿ� : " << d2 << std::endl;
	std::cout << "�� ��° �õ� ���� �ٱ� �Ÿ� : " << d3 << std::endl;
}