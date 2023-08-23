#include <iostream>
#include <iomanip>
using namespace std;

bool isValidInput(int value, int minValue, int maxValue) {
    return value >= minValue && value <= maxValue;
}
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

class date_time{
private:
    int day;
    int month;
    int year;
    bool typeday;
    bool typemonth;

public:
    date_time(int d = 1, int m = 1, int y = 1, bool td = false, bool tm = false) : day(d), month(m), year(y), typeday(td), typemonth(tm){}

    void setDay(int d) {
        day = d;
    }
    void setMonth(int m) {
        month = m;
    }
    void setYear(int y) {
        year = y;
    }

    int getDay() const {
        return day;
    }
    int getMonth() const {
        return month;
    }
    int getYear() const {
        return year;
    }

    void setTypeDay(bool type) {
        typeday = type;
    }
    void setTypeMonth(bool type) {
        typemonth = type;
    }
    bool getTypeDay() const {
        return typeday;
    }
    bool getTypeMonth() const {
        return typemonth;
    }

    void findNextDay() {
        if (typeday && typemonth) {
            year ++;
            day = 1;
            month = 1;
        }
        else if (typeday) {
            month ++;
            day = 1;
        }
        else
            day ++;
    }
};
istream& operator>>(istream& in, date_time &dt) {
    int d, m, y;
    while(true) {
        in >> d >> m >> y;
        if ((m % 2 == 1 && m < 8) || (m % 2 == 0 && m > 7)) {
            if (m == 12)
                dt.setTypeMonth(true);
            if (d == 31) 
                dt.setTypeDay(true);
            if (isValidInput(d, 1, 31))
                break;
        } 
        else if (m == 2)
            if (isLeapYear(y)) {
                if (d == 29) 
                    dt.setTypeDay(true);
                if (isValidInput(d, 1, 29))
                    break;
            }
            else {
                if (d == 28) 
                    dt.setTypeDay(true);
                if (isValidInput(d, 1, 28))
                    break;
            }        
        else {
            if (d == 30) 
                dt.setTypeDay(true);
            if (isValidInput(d, 1, 30))
                break;
        }
        cout << "error" << endl; 
    }
    dt.setDay(d);
    dt.setMonth(m);
    dt.setYear(y);
    return in;
}

ostream& operator<<(ostream& out, const date_time dt) {
    out << setfill('0');
    out << setw(2) << dt.getDay() << " / " << setw(2) << dt.getMonth() << " / " << dt.getYear();
    return out;
}

int main() {
    date_time dt;
    cin >> dt;
    dt.findNextDay();
    cout << dt;
    return 0;
}