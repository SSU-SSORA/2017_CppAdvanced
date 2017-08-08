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
	char buffer[100];

	std::cout << "���� : ";
	std::cin.getline(buffer, 100);
	int m = strtol(buffer, 0, 10);

	std::cout << "��Ƽ���� : ";
	std::cin.getline(buffer, 100);
	int cm = strtol(buffer, 0, 10);

	Distance d1(8, 10), d2(6, 11), d3(m, cm);

	int size = sprintf(buffer, "ù ��° �õ� ���� �ٱ� �Ÿ� : %dm,\t\
		%dcm\n", d1.GetMeters(), d1.GetCentiMeters());

	std::cout.write(buffer, size);

	int size2 = sprintf(buffer, "�� ��° �õ� ���� �ٱ� �Ÿ� : %dm,\t\
		%dcm\n", d2.GetMeters(), d2.GetCentiMeters());

	std::cout.write(buffer, size2);

	int size3 = sprintf(buffer, "�� ��° �õ� ���� �ٱ� �Ÿ� : %dm,\t\
		%dcm\n", d3.GetMeters(), d3.GetCentiMeters());

	std::cout.write(buffer, size3);
}