#include <bits/stdc++.h>
using namespace std;

class BloodGroup {
protected:
    string name;
    bool Rh;
public:
    BloodGroup(string name = "Unknow", bool Rh = true) :
    name(name), Rh(Rh) {}

    virtual int getType() = 0;
};
class AGroup : public BloodGroup {
public:
    AGroup(string name = "Unknow", bool Rh = true) :
    BloodGroup(name, Rh) {}
    int getType() {
        if (Rh)
            return 1;
        return -1;
    }
};
class BGroup : public BloodGroup {
public:
    BGroup(string name = "Unknow", bool Rh = true) :
    BloodGroup(name, Rh) {}
    int getType() {
        if (Rh)
            return 2;
        return -2;
    }
};
class ABGroup : public BloodGroup {
public:
    ABGroup(string name = "Unknow", bool Rh = true) :
    BloodGroup(name, Rh) {}
    int getType() {
       if (Rh)
            return 3;
        return -3;
    }
};
class OGroup : public BloodGroup {
public:
    OGroup(string name = "Unknow", bool Rh = true) :
    BloodGroup(name, Rh) {}
    int getType() {
        if (Rh)
            return 4;
        return -4;
    }
};

class Human {
private:
    string name;
    BloodGroup* bl;
public:
    Human(string name = "Unknow", BloodGroup* bl = nullptr) :
    name(name), bl(bl) {}
    

    BloodGroup* getBloodGroup() {    return bl;  }

};

class BloodGroupCompatibility {
public:
    bool isCompatible(Human donor, Human recipient) {
        vector<vector<int>> adjList{
                                        {0, 1, 2, 3, 5, 6, 7, 8},
                                        {1, 7},
                                        {2, 6, 1, 7},
                                        {3, 5, 1, 7},
                                        {},
                                        {5, 7},
                                        {6, 7},
                                        {7},
                                        {5, 6, 7, 8}
                                    };

        int typeDonor = donor.getBloodGroup()->getType() + 4;
        int typeRecipient = recipient.getBloodGroup()->getType() + 4;

        for (auto type : adjList[typeDonor])
            if (type == typeRecipient)
                return true;
    }

    bool generate(Human father, Human mother, Human son) {
        int fatherType = abs(father.getBloodGroup()->getType());
        int motherType = abs(mother.getBloodGroup()->getType());
        int sonType = abs(son.getBloodGroup()->getType());

        switch (fatherType * motherType) {
            case 1:
                if (sonType == 1 || sonType == 4)
                    return true;
            case 2:
                return true;
            case 3:
                if (sonType != 4)
                    return true;
            case 4:
                if (fatherType != 2)
                    if (sonType == 1 || sonType == 4)
                        return true;
                    else 
                        if (sonType ==  2 || sonType == 4)
                            return true;
            case 6:
                if (sonType != 4)
                    return true;
            case 8:
                if (sonType ==  2 || sonType == 4)
                    return true;
            case 9:
                if (sonType != 4)
                    return true;
            case 12:
                if (sonType == 1 || sonType == 2)
                    return true;
            case 16:
                if (sonType == 4)
                    return true;
            }
        
        return false;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Human*> people(n);
    for (int i = 0; i < n; i++) {
        string name;
        string blgroup;
        bool Rh;

        cin >> name >> blgroup >> Rh;
        
        BloodGroup* bloodGroupPtr;
        if (blgroup == "A") {
            bloodGroupPtr = new AGroup("A", Rh);
        } else if (blgroup == "B") {
            bloodGroupPtr = new BGroup("B", Rh);
        } else if (blgroup == "AB") {
            bloodGroupPtr = new ABGroup("AB", Rh);
        } else if (blgroup == "O") {
            bloodGroupPtr = new OGroup("O", Rh);
        } else {
            bloodGroupPtr = nullptr;
        }

        people[i] = new Human(name, bloodGroupPtr);
    }
    
    BloodGroupCompatibility compatibility;
    if (n >= 2) {
        bool compatible = compatibility.isCompatible(*people[0], *people[1]);
        cout << "Compatibility between person 1 and person 2: ";
        cout << (compatible ? "Compatible" : "Not compatible") << endl;
    }

    // Clean up memory
    for (int i = 0; i < n; i++) {
        delete people[i]->getBloodGroup();
        delete people[i];
    }

}
    