#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class employee{
private:
    string employeeCode;
    string fullName;
    string department;
    int baseSalary;
    int bonus;
public:
    employee(string employeeCode_para = "default", string fullName_para = "default", string department_para = "default", int baseSalary_para = 0, int bonus_para = 0) : 
     employeeCode(employeeCode_para), fullName(fullName_para), department(department_para), baseSalary(baseSalary_para), bonus(bonus_para)  {}

    void setEmployeeCode(string employeeCode_para) {
        employeeCode = employeeCode_para;
    }
    void setFullName(string fullName_para) {
        fullName = fullName_para;
    }
    void setDepartment(string department_para) {
        department = department_para;
    }
    void setBaseSalary(int baseSalary_para) {
        baseSalary = baseSalary_para;
    }
    void setBonus(int bonus_para) {
        bonus = bonus_para;
    }

    string getEmployeeCode() const {
        return employeeCode;
    }
    string getFullName() const {
        return fullName;
    }
    string getDepartment() const {
        return department;
    }
    float getBaseSalary() const {
        return baseSalary;
    }
    int getBonus() const {
        return bonus;
    }

    


};

istream& operator >> (istream& in, employee& f) {
    string employeeCode_para;
    string fullName_para;
    string department_para;
    int baseSalary_para;
    int bonus_para;

    in >> employeeCode_para;
    in.ignore();
    getline(in, fullName_para, '\n');
    getline(in, department_para, '\n');
    in >> baseSalary_para;
    in >> bonus_para;

    f.setEmployeeCode(employeeCode_para);
    f.setFullName(fullName_para);
    f.setDepartment(department_para);
    f.setBaseSalary(baseSalary_para);
    f.setBonus(bonus_para);

    return in;
}

ostream& operator << (ostream& out, const employee f) {
    out << setw(5) << f.getEmployeeCode() << setw(20) << f.getFullName() << setw(20)  << f.getDepartment() << setw(5) << f.getBaseSalary() << setw(5) << f.getBonus();
    return out;
}

bool compareByValue(const std::pair<int, int>& pair1, const std::pair<int, int>& pair2) {
    return pair1.second < pair2.second; // Sort by values in ascending order with second part
}


int main() {
    int n;
    cin >> n;
    employee *pe = new employee[n];
    map<int, int> myMap;

    for (int i = 0; i < n; i++) {
        cin >> pe[i];
        myMap.insert(make_pair(i, pe[i].getBaseSalary()));
    }
        
    vector<pair<int, int>> vec(myMap.begin(), myMap.end());
    sort(vec.begin(), vec.end(), compareByValue);
    
    for(pair<int, int> p : vec) 
        cout << pe[p.first] << endl;

    delete[] pe;
    return 0;
}