#include <iostream>
enum Days { Sunday = 0, Monday, TuesDay, Wednesday, Thursday, Friday, Saturday = Sunday + 6 };

const char * week[] = { "Sunday" , "Monday", "TuesDay", "Wednesday", "Thursday", "Friday", "Saturday" };

template<Days D>
class Select {
public:
	const char * DayName() {
		return week[D];
	}
};



int main() {
	Select<Sunday> today;
	std::cout << today.DayName() << "�� " << Sunday + 1 << "��° �����̴�." << std::endl;
}