#include <bits/stdc++.h>
using namespace std;

class Time {
private:
    int hour, minute, sec;
public:
    Time(int h = 0, int m = 0, int s = 0) :
    hour(h), minute(m), sec(s) {}

    Time operator ++ () {
        sec += 1;
        normalizeTime();
        return *this;
    }
 
    Time operator -- () {
        sec = 1;
        normalizeTime();
        return *this;
    }

    Time operator + (int add) {
        Time result = *this;
        result.sec += add;
        result.normalizeTime();
        return result;
    }

    Time operator - (int sub) {
        Time result = *this;
        result.sec -= sub;
        result.normalizeTime();
        return result;
    }
    
    void Input() {    cin >> hour >> minute >> sec;    }
    void Output() {    cout << hour << " " << minute << " " << sec;    }
    
    void normalizeTime() {
        while (sec < 0 || sec > 59) {
            if (sec < 0) {
                sec += 60;
                minute --;
            }
            else {
                sec -= 60;
                minute ++;
            }
        }

        while (minute < 0 || minute > 59) {
            if (minute < 0) {
                minute += 60;
                hour --;
            }
            else {
                minute -= 60;
                hour ++;
            }
        }

        while (hour < 0 || hour > 23) {
            if (hour < 0)    hour += 24;
            else    hour -= 24;
        }
    }
};

int main() {
    Time time;
    time.Input();
    time.normalizeTime(); 

    int direction;
    cin >> direction;
    cin.ignore();
    for (int i = 0; i < direction; i++) {
        string direct;
        getline(cin, direct);

        if (direct == "++")
            ++ time;
        else if (direct == "--")
            -- time;
        else if (direct[0] == '+')
            time = time + stoi(direct.substr(2));
        else
            time = time - stoi(direct.substr(2));
    }

    time.Output();
    return 0;
}
