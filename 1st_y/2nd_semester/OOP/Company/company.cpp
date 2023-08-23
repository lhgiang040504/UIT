#include <bits/stdc++.h>
using namespace std;

class Member {
protected:
    int ID;
    string Name;
    int Coin;
    int Type;
    vector<int> History;
public:
    Member(int id = -1, string name = "Unknow", int type = 0, int coin = 0, vector<int> history = {}) :
    ID(id), Name(name), Type(type), Coin(coin), History(history) {}

    void setCoin(int coin) {    Coin += coin;    }
    virtual int getProfit(int coin) = 0;

    int getType() {    return Type;     }
};

class Director : public Member {
public:
    Director(int id = -1, string name = "Unknow", int type = 0, int coin = 0) :
    Member(id, name, type, coin) {}
    
};

class Distributor : public Member {
private:
    int Level;
public:
    Distributor(int id = -1, string name = "Unknow", int type = 0, int coin = 0, int Level = -1) :
    Member(id, name, type, coin), Level(Level) {}

    int getProfit(int Coin) override {
        int percentage = 5 + Level * 3;
        int profit = ceil(percentage * Coin /  100.0);
        return profit;
    }

};
class Investor : public Member {
private:
    int ID_of_Distributor;
public:
    Investor(int id = -1, string name = "Unknow", int type = 0, int coin = 0, int idDistributor = -1) :
    Member(id, name, type, coin), ID_of_Distributor(idDistributor) {}

    int getID_Distributor() {   return ID_of_Distributor;   }

    
};

int main() {
    int num_Member, months;
    vector<Member*> member(num_Member);
    
    for (int i = 0; i < num_Member; i++) {
        int ID, Type;
        string Name;
        cin >> ID >> Type >> Name;
        if (Type == 1) member[ID] = new Director(ID, Name, Type);
        else if (Type == 2) {
            int level;
            cin >> level;
            member[ID] = new Distributor(ID, Name, Type, level);
        }
        else {
            int ID_of_Distributor;
            cin >> ID_of_Distributor;
            member[ID] = new Investor(ID, Name, Type, ID_of_Distributor);
        }
    }

    for (int i = 0; i < months; i ++) {
        int ID, Coin;
        cin >> ID >> Coin;
        int profit;
        member[ID]->History.push_back(Coin);
        if (member[ID]->getType() == 3) {
            ID = member[ID]->getID_Distributor();
            profit = member[ID]->getProfit();

            member[ID]->setCoin(profit);
            Coin = Coin - profit;
        }
        
        member[0]->setCoin(Coin);
    }
    
    
    
    return 0;
}

