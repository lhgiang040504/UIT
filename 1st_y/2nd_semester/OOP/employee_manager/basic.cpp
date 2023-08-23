#include<bits/stdc++.h>
using namespace std;
struct Birth {
	int Day, Month, Year;
};

class Employee {
private:
	string Name;
	Birth Time;
	double Salary;
public:
	Employee() {
		Name = "";
		Time.Day = 0;
		Salary = 0;
	}
	virtual void Input() {
		cout << "Nhap ho ten:"; cin >> this->Name;
		cout << "Nhap ngay sinh: "; cin >> this->Time.Day;
		cout << "Nhap Thang sinh: "; cin >> this->Time.Month;
		cout << "Nhap Nam sinh: "; cin >> this->Time.Year;
	}
	virtual void Output() {
		cout << "Ong/Ba : " << this->Name << " sinh ngay "
			<< Time.Day << "-" << Time.Month << "-" << Time.Year;
		cout << "Co so luong la: " << this->calculate_Salary() << endl;
	}
	virtual double calculate_Salary() = 0;
	~Employee() {}

};

class Officer : virtual public Employee {
private:
	int Workdays;
public:
	Officer() { Workdays = 0; }
	void Input() {
		Employee::Input();
		cout << "Nhap so ngay lam viec: "; cin >> this->Workdays;
	}
	/*virtual void Xuat() {


	}*/
	virtual double calculate_Salary() {
		return 0;
	}
};

class Producer  : virtual public Employee {
private:
	double basic_Salary, num_Production;
public:

	Producer() { basic_Salary = 0; num_Production = 0; }
	void Input() {
		Employee::Input();
		cout << "Nhap luong co ban: "; cin >> this->basic_Salary;
		cout << "Nhap san pham: "; cin >> this->num_Production;
	}
	/*virtual void Xuat() {

	}*/
	virtual double calculate_Salary() { return 0; }
};


class Manage {

	int num;
	Employee** employee;
public:

	Manage(){ }
	void Input() {
		int i = 0, n = 0;
		int type;
		cout << "Nhap so nhan vien: "; cin >> this->num;

		employee = new Employee * [num];

		while (i < num) {
			cin.ignore();
			cout << "Nhap nhom nhan vien: "; cin >> type;
			if (type == 0)
			{
				employee[i] = new Officer();
				employee[i]->Input();
				i++;
			}
			else {
				employee[i] = new Producer();
				employee[i]->Input();
				i++;
			}
		}

	}
	void Output() {
		int i;
		for (i = 0; i < this->num; i++) {
			employee[i]->Output();
		}
	}
	~Manage() {

	}

};

int main() {
	Manage manage;
	manage.Input();
	manage.Output();
	return 0;
}
