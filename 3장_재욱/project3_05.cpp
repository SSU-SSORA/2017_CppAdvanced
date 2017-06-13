#include <iostream>

enum Days {
    None = 0x00,           // 0000 0000
    Sunday = 1,            // 0000 0001
    Monday = 1 << 1,       // 0000 0010
    Tuesday = 1 << 2,      // 0000 0100
    Wednesday = 1 <<3,     // 0000 1000
    Thursday = 1 << 4,     // 0001 0000
    Friday = 1 << 5,       // 0010 0000
    Saturday = 1 << 6      // 0100 0000
};

const char* week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void DayName(int d) {
    std::cout << d << std::endl;
    for (int i = 0; i < 7; i++) {
        if (d & (1 << i))
            std::cout << week[i] << std::endl;
    }
}

int main()
{
    Days meeting = Days ((int) Thursday | (int) Monday);
    DayName(meeting);
}