#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>

#define SECOND 1
#define MINUTE (60*(SECOND))
#define HOUR (60*(MINUTE))
#define DAY (24*(HOUR))

int main() {
    std::unordered_map<std::string, std::pair<int, int>> month_map;
    std::string month, time, day_s;
    int day, year;
    std::cin >> month >> day_s >> year >> time;
    day = std::stoi(day_s);
    int hour = std::stoi(time.substr(0, 2));
    int minute = std::stoi(time.substr(3, 2));
    bool yoon = (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    int sec_cur = 0;
    int sec_total = yoon ? 366*DAY : 365*DAY;
    std::string months[] = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
        "November", "December"
    };
    int month_days[] = { 31, (yoon ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for(int i=0; months[i] != month; i++) {
        sec_cur += month_days[i] * DAY;
    }
    sec_cur += (day-1)*DAY + hour * HOUR + minute * MINUTE;
    std::cout << std::setprecision(12) << (long double)100*sec_cur/sec_total << '\n';
    return 0;
}