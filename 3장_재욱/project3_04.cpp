#include <iostream>

enum Days { Sunday = 0, Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday = 6};
enum class Month : short { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

const char* week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

const char* DayName(Days day) {
    if (day < Sunday || day > Saturday)
        return "알수없는 주";
    return week[day];
}

int main()
{
    Days today = Thursday;

    Days tomorrow = (Days) (Thursday + 1);

    std::cout << DayName(today) << "은 " << today + 1 << "번째 요일이다." << std::endl;
    std::cout << DayName(tomorrow) << "은 " << tomorrow + 1 << "번째 요일이다." << std::endl;

    today = (Days) (Saturday + Friday);
    std::cout << DayName(today) << "는 " << (int) today << "번째 요일이다." << std::endl;

    Month thisMonth = Month::Dec;
    Month nextMonth = (Month) ((short) Month::Dec - 12 + 1);
    short monthNumber = (short) thisMonth;

    std::cout << "Dec 월은 " << monthNumber << "번째 월이다." << std::endl;
    std::cout << "Jan 월은 " << (int) nextMonth << "번째 월이다." << std::endl;
}