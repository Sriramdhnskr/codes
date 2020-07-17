#include "meetup.h"

int get_day_index(const char *day) {
    if (strcmp(day, "Monday") == 0) {
        return 1;
    } else if (strcmp(day, "Tuesday") == 0) {
        return 2;
    } else if (strcmp(day, "Wednesday") == 0) {
        return 3;
    } else if (strcmp(day, "Thursday") == 0) {
        return 4;
    } else if (strcmp(day, "Friday") == 0) {
        return 5;
    } else if (strcmp(day, "Saturday") == 0) {
        return 6;
    } else {
        return 0;
    }
}

int get_days_of_month(int year, int month) {
    int days_of_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_of_month = days_of_months[month - 1];
    if (month == 2 && year % 4 == 0) { // leap year
        days_of_month = 29;
    }
    return days_of_month;
}

int handle_type(int day, const char* type, int days_of_month, struct tm *date) {
    if (strcmp(type, "first") == 0) {
        return day;
    }
    if (strcmp(type, "second") == 0 && day > 7) {
        return day;
    }
    if (strcmp(type, "third") == 0 && day > 14) {
        return day;
    }
    if (strcmp(type, "fourth") == 0 && day > 21) {
        return day;
    }
    if (strcmp(type, "fifth") == 0 && day > 28) {
        return day;
    }
    if (strcmp(type, "last") == 0 && day > days_of_month - 7) {
        return day;
    }
    if (strcmp(type, "teenth") == 0 &&
            date->tm_mday > 12 &&
            date->tm_mday < 20) {
        return day;

    }
    return -1;
}

struct tm *convert_to_date(int year, int month, int day) {
    struct tm current;
    memset(&current, 0, sizeof(current));
    current.tm_year = year - 1900;
    current.tm_mon = month - 1;
    current.tm_mday = day;
    current.tm_hour = 12;
    time_t current_tstamp = mktime(&current);
    return gmtime(&current_tstamp);
}

int meetup_day_of_month(int year, int month, const char* type, const char* day) {
    int days_of_month = get_days_of_month(year, month);
    for (int i = 1; i <= days_of_month; i++) {
        struct tm *date = convert_to_date(year, month, i);
        int dayIndex = get_day_index(day);
        if (date->tm_wday == dayIndex) {
            if (handle_type(i, type, days_of_month, date) != -1) {
                return i;
            }
        }
    }
    return 0;
}
int main()
{
int n=meetup_day_of_month(2010,10,"teenth","Tuesday");
printf("%d",n);
return 0;
}
