#include <bits/stdc++.h>
using namespace std;

class Vehicle {
protected:
    string id, type, origin;
    float weight;
    int year;
public:
    Vehicle(string id, string type, float wetght, string origin, int year) {
        this->id = id;
        this->type = type;
        this->weight = wetght;
        this->origin = origin;
        this->year = year;
    }

    virtual float getCost(float length) = 0;

    void print_Infor() {
        cout << "Ma phuong tien: " << id << endl;
        cout << "Loai xe: " << type << endl;
        cout << "Trong tai: " << weight << " tan" << endl;
        cout << "Xuat xu: " << origin << endl;
        cout << "Thoi gian san xuat: " << year << " nam" << endl;
    }
};

class Containner : public Vehicle {
public:
    Containner(string id, string type, float wetght, string origin, int year) :
    Vehicle(id, type, wetght, origin, year) {}

    float getCost(float length) override {
        return weight * 150 * length;
    }
};

class Truck : public Vehicle {
public:
    Truck(string id, string type, float wetght, string origin, int year) :
    Vehicle(id, type, wetght, origin, year) {}

    float getCost(float length) override {
        return weight * 5000 * length;
    }
};

class freezTruck : public Vehicle {
public:
    freezTruck(string id, string type, float wetght, string origin, int year) :
    Vehicle(id, type, wetght, origin, year) {}

    float getCost(float length) override {
        return weight * 200 * length;
    }
};

class Route {
private:
    int id;
    string name;
    float length;
public:
    Route(int id = 0, string name = "", float length = 0.0) :
    id(id), name(name), length(length) {}
    
    int getId()         { return id;        }
    string getName()    {  return name;     }
    float getLength()   { return length;    }
};

class Manage {
private:
    int id;
    Vehicle* vehicle;
    string time;
public:
    Route* route;
    Manage(int id = 0, Vehicle* vehicle = nullptr, Route* route = nullptr, string time = "") : 
    id(id), vehicle(vehicle), route(route), time(time) {}

    float getCost() {
        float length = route->getLength();
        float cost = vehicle->getCost(length);
        return cost;
    }

    void print_Infor() {
        cout << "Ma chuyen hang: " << id << endl;
        cout << "Thong tin phuong tien:" << endl;
        vehicle->print_Infor();
        cout << "Thong tin tuyen duong:" << endl;
        cout << "Ma tuyen: " << route->getId() << endl;
        cout << "Ten tuyen: " << route->getName() << endl;
        cout << "So km: " << route->getLength() << endl;
        cout << "Thoi gian chay: " << time << endl;
    }
};

int main() {
    // Khởi tạo danh sách phương tiện
    vector<Vehicle*> listVehicle;
    listVehicle.push_back(new Containner("CTN001", "Xe Container", 30, "Vietnam", 2021));
    listVehicle.push_back(new Truck("XB001", "Xe Ben", 18, "Vietnam", 2020));
    listVehicle.push_back(new freezTruck("XDL001", "Xe Dong Lanh", 2.5, "Vietnam", 2019));

    // Khởi tạo danh sách tuyến đường
    vector<Route*> listRoute;
    listRoute.push_back(new Route(1, "Kho Linh Trung - Điện gió Bạc Liêu", 150));
    listRoute.push_back(new Route(2, "Kho Linh Trung - Cảng Cát Lái", 80));
    listRoute.push_back(new Route(3, "Cảng Cát Lái - Cảng Sài Gòn", 30));

    // Khởi tạo danh sách quản lý xe
    vector<Manage*> listManage;
    listManage.push_back(new Manage(1, listVehicle[0], listRoute[0], "01/06/2023"));
    listManage.push_back(new Manage(2, listVehicle[1], listRoute[1], "02/06/2023"));
    listManage.push_back(new Manage(3, listVehicle[2], listRoute[2], "03/06/2023"));
    
    for (Manage* manage : listManage) {
        float cost = manage->getCost();
        cout << "Tien cuoc cua chuyen hang " << (manage->route)->getId() << ": " << cost << endl;
        manage->print_Infor();
        cout << endl;
    }

    for (Vehicle* vehicle : listVehicle) {
        delete vehicle;
    }
    listVehicle.clear();

    for (Route* rout : listRoute) {
        delete rout;
    }
    listRoute.clear();

    for (Manage* manage : listManage) {
        delete manage;
    }
    listManage.clear();

    return 0;
}