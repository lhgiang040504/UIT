#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string&);

class Birth {
protected:
    int day;
    int month;
    int year;
public:
    Birth(int d = 1, int m = 1, int y = 1) : 
    day(d), month(m), year(y) {}

    bool isLeapYear(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0)
                    return true;
                else
                    return false;
            } else {
                return true;
            }
        } else {
            return false;
        }
    }

    bool is_Valid() {
        if (year < 1)
            return false;

        if (month < 1 || month > 12)
            return false;

        if (day < 1)
            return false;

        switch (month) {
            case 1: // January
            case 3: // March
            case 5: // May
            case 7: // July
            case 8: // August
            case 10: // October
            case 12: // December
                return (day <= 31);
            case 4: // April
            case 6: // June
            case 9: // September
            case 11: // November
                return (day <= 30);
            case 2: // February
                if (isLeapYear(year))
                    return (day <= 29);
                else
                    return (day <= 28);
            default:
                return false;
        }
    }

    void Input() {
        
        string daytime;

        getline(cin, daytime);
        vector<string> tokens = split(daytime);
        
        day = stoi(tokens[0]);
        month = stoi(tokens[1]);
        year = stoi(tokens[2]);

        if (!is_Valid())
            Input();
    }

    int get_Age() {
        Birth curr(1, 1, 2023);       
        int age = curr.year - year;

        if (curr.month < month || (curr.month == month && curr.day < day)) 
            // Subtract 1 from age if the current date is before the birthdate
            age--;

        return age;
    }

    bool Condition() {    return get_Age() >= 17;    }
};

class Score {
protected:
    float score_Midterm;
    float score_Final;
public:
    Score(float score_Midterm = 0.0, float score_Final = 0.0) :
    score_Midterm(score_Midterm), score_Final(score_Final) {}

    bool is_Valid() {
        if (score_Midterm >= 0 && score_Midterm <= 10 && score_Final >= 0 && score_Final <= 10)
            return true;
        return false;
    }

    void Input() {        cin >> score_Midterm >> score_Final;        }

    float conclusive_Score() {    return (score_Final * 7 / 10.0) + (score_Midterm * 3 / 10.0);    }

    bool Condition() {    return conclusive_Score() >= 7 && score_Final >= 5 && score_Midterm >= 5;    }
};

class Student {
protected:
    string Name;
    Birth* Time;
    Score* Math;
    Score* Liter;
    Score* Eng;
public:
    Student(string name = "Unknow", Birth* time = new Birth(), Score* math = new Score(), Score* liter = new Score(), Score* eng = new Score()) :
    Name(name), Time(time), Math(math), Liter(liter), Eng(eng) {}
    void Input() {
        
        cin.ignore();
        getline(cin, Name);
        
        do {
            Time->Input();
        } while (!Time->is_Valid());
        do {
            Math->Input();
            Liter->Input();
            Eng->Input();
        } while (!Math->is_Valid() || !Liter->is_Valid() || !Eng->is_Valid());
            
    }
    
    float get_Average() {
        float average = (Math->conclusive_Score() + Liter->conclusive_Score()+ Eng->conclusive_Score()) / 3.0;
        return average;
    }
    
    void Output() {
        cout << "Ho ten: " << Name << " - Diem trung binh: " << setprecision(3) << get_Average() << endl;
    }

    bool Condition() {
        return Time->Condition() && get_Average() >= 8 && Math->Condition() && Liter->Condition() && Eng->Condition();
    }
};

bool compareAverage(Student* i1, Student* i2) {
    return (i1->get_Average() > i2->get_Average());
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<Student*> list_Student(n);
    vector<Student*> good_Student;
    for (auto& student : list_Student) {
        student = new Student();
        student->Input();
        if (student->Condition())
            good_Student.push_back(student);
    }

    sort(good_Student.begin(), good_Student.end(), compareAverage);

    if (k > good_Student.size())
        k = good_Student.size();
    for (int i = 0; i < k; i++)
        good_Student[i]->Output();

    return 0;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find("/", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}