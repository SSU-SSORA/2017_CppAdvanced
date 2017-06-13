enum Days { Sunday = 0, Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday = 6};
enum class Month : short { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

int main()
{
    Days today = Thursday;
    Days tommorow = (Days) ((int) Thursday + 1);

    Month thisMonth = Month::Dec;
    Month nextMonth = (Month) ((short) Month::Dec - 11);
}