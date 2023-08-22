#include <bits/stdc++.h>
using namespace std;

class Apartment {
protected:
    string Name;
    int numFloors;
    float Acreage;
    string Proxy;
    string Owner;
public:
    Apartment(string name = "Unknow", int num = 0, float acreage = 0.0, string proxy = "Unknow", string owner = "Unknow") :
    Name(name), numFloors(num), Acreage(acreage), Proxy(proxy), Owner(owner) {}

    void Ouput() {    cout << Proxy << "-" << Name << "-" << Owner;    }
    void Input();
    virtual float get_Cost() = 0;
};
class VinHome : public Apartment {
public:
    VinHome() {    Owner = "Vinhomes";    }
    float get_Cost();
};
class Bcon : public Apartment {
public:
    Bcon() {   Owner = "Bcons";    }
    float get_Cost();
};

void Input(Apartment**, int, int);
void Export_Infor(Apartment**, int);

void DeleteApartments(Apartment** Apartments, int size) {
    for (int i = 0; i < size; i++) {
        delete Apartments[i];
    }
    delete[] Apartments;
}

int main() {
    int count_VinHomes, count_Bcons;
    cin >> count_VinHomes >> count_Bcons;

    int totalSize = count_VinHomes + count_Bcons;

    Apartment** Apartments = new Apartment*[totalSize];
    Input(Apartments, count_VinHomes, count_Bcons);
    Export_Infor(Apartments, totalSize);

    // Memory deallocation
    DeleteApartments(Apartments, totalSize);

    return 0;
}
// Random function to get cost of apart which is a random value between min and max
int Random(int min, int max) {
    static bool first = true;
    if (first) {
        srand(static_cast<unsigned>(time(0)));
        first = false;
    }
    return min + rand() % (max - min + 1);
}
// Input format of each apart
void Apartment::Input() {
    getline(cin, Name);
    cin >> numFloors >> Acreage;
	cin.ignore();
    getline(cin, Proxy);
}

float VinHome::get_Cost() {    return ((Acreage > 600)? Random(10, 15) : Random(6, 10)) * 6 * numFloors;    }
float Bcon::get_Cost()    {    return ((Acreage > 600)? Random(8, 12) : Random(5, 8))   * 6 * numFloors;    }

// Input function
void Input(Apartment** Apartments, int count_VinHomes, int count_Bcons) {
    for (int i = 0; i < count_VinHomes; i++) {
        Apartments[i] = new VinHome();
        Apartments[i]->Input();
    }
    for (int i = count_VinHomes; i < count_VinHomes + count_Bcons; i ++) {
        Apartments[i] = new Bcon();
        Apartments[i]->Input();
    }
}

void Export_Infor(Apartment** Apartments, int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += Apartments[i]->get_Cost();
    }
    cout << "Total cost of all apartments: " << total << endl;

}
