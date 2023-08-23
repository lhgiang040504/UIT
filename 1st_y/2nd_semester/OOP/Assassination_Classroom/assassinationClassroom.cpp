#include <bits/stdc++.h>
using namespace std;

class School {
private:
    string name;
public:
    School(string name = "") : name(name) {}
    
};

class Teacher : public School {
protected:
    int expYear;
public:
    Teacher(string name = "", int expYear = 0) : School(name), expYear(expYear) {}
    
    virtual int getSalary() = 0;
};

class Homeroom : public Teacher {
private:
    string homeroomName;
public:
    Homeroom(string name = "", int expYear = 0, string homeroomName = "") : Teacher(name, expYear), homeroomName(homeroomName) {}

    int getSalary() override { return expYear * 2000000 + 1000000;  }
};

class subjectTeacher : public Teacher {
private:
    string subjectName;
public:
    subjectTeacher(string name = "", int expYear = 0, string subjectName = "") : Teacher(name, expYear), subjectName(subjectName) {}

    int getSalary() override {  return expYear * 2000000;   }
};

class Student : public School {
protected:
    
    int math, physic, chemistry;
public:
    // to sort string
    string nameClass;

    Student(string name = "", string nameClass = "", int math = 0, int physic = 0, int chemistry = 0) :
    School(name), nameClass(nameClass), math(math), physic(physic), chemistry(chemistry) {}

    virtual bool promoted() {
        float sum = (math + physic + chemistry) / 3.0;
        return sum > 5.0;
    }
    
    virtual int getRestudyMoney() = 0;
};

class Normal : public Student {
public:
    Normal(string name = "", string nameClass = "", int math = 0, int physic = 0, int chemistry = 0) : 
    Student(name, nameClass, math, physic, chemistry) {}

    int getRestudyMoney() override {
        int re_studyMoney = 0;
        if (math < 5)       re_studyMoney += 1000000;
        if (physic < 5)     re_studyMoney += 1000000;
        if (chemistry < 5)  re_studyMoney += 1000000;
        return re_studyMoney;
    }
    bool promoted() override {
        float sum = (math + physic + chemistry) / 3.0;
        return sum > 5.0;
    }
};

class Special : public Student {
public:
    Special(string name = "", string nameClass = "", int math = 0, int physic = 0, int chemistry = 0) : 
    Student(name, nameClass, math, physic, chemistry) {}

    int getRestudyMoney() override { return 0;   }
    bool promoted() override {
        float sum = (math + physic + chemistry) / 3.0;
        return sum > 5.0;
    }
};

int main() {
    int m;
    cin >> m;
    vector<Teacher*> teachers(m);
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            string name, homeroomName;
            int expYear;
            cin >> name >> expYear >> homeroomName;
            teachers[i] = new Homeroom(name, expYear, homeroomName);
        }
        else {
            string name, subjectName;
            int expYear;
            cin >> name >> expYear >> subjectName;
            teachers[i] = new subjectTeacher(name, expYear, subjectName);
        }
    }

    int n;
    cin >> n;
    vector<Student*> students(n);
    for (int i = 0; i < n; i++) {
        string name, homeroomName, classroomName;
        int type, math, physic, chemistry;
        cin >> type >> name >> classroomName >> math >> physic >> chemistry;
        if (type == 1) 
            students[i] = new Normal(name, classroomName, math, physic, chemistry);
        else
            students[i] = new Special(name, classroomName, math, physic, chemistry);
    }

    // fee of re-study
    int fee = 0;

    // group
    map<string, vector<Student*>> groups;
    vector<string> classOrder;

    for (const Student* student : students) {
        string className = student->nameClass;

        // check exit
        bool classExists = false;
        for (const string& cls : classOrder) {
            if (cls == className) {
                classExists = true;
                break;
            }
        }

        
        if (!classExists) {
            classOrder.push_back(className);
            groups[className] = vector<Student*>();
        }

        groups[className].push_back(const_cast<Student*>(student));
    }

    // print
    for (const string& className : classOrder) {
        const vector<Student*>& classStudents = groups[className];

        cout << "Lop: " << className;

        int count = 0;
        for (const auto& student : classStudents) {
            if (student->promoted()) {
                count++;
            } else {
                fee += student->getRestudyMoney();
            }
        }

        cout << ", so hoc sinh len lop: " << count;
        cout << ", so hoc sinh dup: " << classStudents.size() - count;
        cout << endl;
    }


    // calculate the salary of all teacher
    int salary = 0;
    for (const auto& teacher : teachers) {
        salary += teacher->getSalary();
    }

    if (fee < salary)
        cout << "Khong du chi tra luong";
    else
        cout << "Du " << fee - salary << "d";

    for (Student* student : students) {
        delete student;
    }

    return 0;
}

