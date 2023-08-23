#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class student{
private:
    string Name;
    float math_Mark;
    float literature_Mark;
public:
    student(string name = "no name", float ma_mark = 0, float liter_mark = 0) : Name(name), math_Mark(ma_mark), literature_Mark(liter_mark) {}

     void setName(string name) {
        Name = name;
    }
    void setMathScore(float ma_mark) {
        math_Mark = ma_mark;
    }
    void setLitScore(float liter_mark) {
        literature_Mark = liter_mark;
    }

    string getName() const {
        return Name;
    }
    float getMathScore() const {
        return math_Mark;
    }
    float getLitScore() const {
        return literature_Mark;
    }

    float calcAverage() const {
        return (math_Mark + literature_Mark) / 2.0;
    }

};

istream& operator >> (istream& in, student& f) {
    string name;
    float ma_mark, liter_mark;
    getline(in, name);
    in >> ma_mark >> liter_mark;
    f.setName(name);
    f.setMathScore(ma_mark);
    f.setLitScore(liter_mark);
    return in;
}

ostream& operator << (ostream& out, const student f) {
    out << setw(10) << f.getName() << setw(5) << f.getMathScore() << setw(5) << f.getLitScore();
    return out;
}

int main() {
    student s1;
    cin >> s1;
    cout << s1.calcAverage();
    return 0;
}
/*
    string s;
    string S;
    getline(cin, s);
    getline(cin, S);
    cout << s << endl;
    cout << S;
    return 0;
*/