#include <bits/stdc++.h>
using namespace std;

class Friend {
private: // protected: derived classes can to accsess
    string name;
    int age;
public:
    Friend(string name = "", int age = 0.0) : name(name), age(age) {}

    virtual float getTimeSpent() = 0; // ??

    // virtual that can overrider by derive class
    virtual void displayInfo() {
        cout << "Ten: " << name << ", tuoi: " << age;
    }
};

class BestFriend : public Friend {
private:
    string phone;
public:
    BestFriend(string name = "", int age = 0.0, string phone = "0") : Friend(name, age), phone(phone) {}

    float getTimeSpent() override { return 5.0; }

    void displayInfo() {
        Friend::displayInfo();
        cout << ", so dien thoai: " << phone;
    }

};

class BoyFriend : public Friend {
private:
    float income;
public:
     BoyFriend(string name = "", int age = 0.0, float incom = 0.0) : Friend(name, age), income(income) {}

    float getTimeSpent() override { return 5 * income / 10000000.0; }

    void displayInfo() {
        Friend::displayInfo();
        cout << ", thu nhap: " << income << "d";
    }

};

class OtherBoy : public Friend {
private:
    float attractiveness;
public:
    OtherBoy(string name = "", int age = 0.0, float attractiveness = 1.0) : Friend(name, age), attractiveness(attractiveness) {}

    // ??
    float getTimeSpent() override { return attractiveness * 20; }

    void displayInfo() {
        Friend::displayInfo();
        string attraction;
        if (attractiveness >= 0.7) attraction = "cao";
        else if (attractiveness < 0.4) attraction = "thap";
        else attraction = "trung binh";
        cout << ", do thu hut: " << attraction;
    }
};

int main() {
    int totalFriends;
    cin >> totalFriends;
    vector<pair<int, Friend*>> manage(totalFriends);
    float bestFriendTime, boyFriendTime, otherBoyTime;
    bestFriendTime = boyFriendTime = otherBoyTime = 0.0;

    for (int i = 0; i < totalFriends; i++) {
        cin >> manage[i].first;
        if (manage[i].first == 1) {
            string name;
            int age;
            string phone;
            cin >> name >> age >> phone;
            manage[i].second = new BestFriend(name, age, phone);
            bestFriendTime += manage[i].second->getTimeSpent();
        }
        else if (manage[i].first == 2) {
            string name;
            int age;
            float income;
            cin >> name >> age >> income;
            manage[i].second = new BoyFriend(name, age, income);
            boyFriendTime += manage[i].second->getTimeSpent();
        }
        else {
            string name;
            int age;
            float attractiveness;
            cin >> name >> age >> attractiveness;
            manage[i].second = new OtherBoy(name, age, attractiveness);
            otherBoyTime += manage[i].second->getTimeSpent() / totalFriends;
        }
    }
    
    cout << "Thong ke:\n";
    cout << "- Thoi gian cho ban than: " << bestFriendTime << " h\n";
    cout << "- Thoi gian cho ban trai: " << boyFriendTime << " h\n";
    cout << "- Thoi gian cho ban trai khac: " << otherBoyTime << " h\n";


    cout << "Nguoi ban quan trong nhat:\n";
    
    sort(manage.begin(), manage.end(), greater<pair<int, Friend*>>());

    int i = 0;
    do {
        manage[i].second->displayInfo();
        cout << endl;
        i ++;
    } while (i < manage.size() && manage[i-1].second->getTimeSpent() == manage[i].second->getTimeSpent());

    // Clean up dynamic memory
    for (int i = 0; i < totalFriends; i++) {
        delete manage[i].second;
    }
 
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

class Friend {
private:
    string name;
    int age;

public:
    Friend(string name = "", int age = 0) : name(name), age(age) {}

    virtual float getTimeSpent() = 0;

    virtual void displayInfo() {
        cout << "Ten: " << name << ", tuoi: " << age;
    }
};

class BestFriend : public Friend {
private:
    string phone;

public:
    BestFriend(string name = "", int age = 0, string phone = "0") : Friend(name, age), phone(phone) {}

    float getTimeSpent() override {
        return 5.0;
    }

    void displayInfo() {
        Friend::displayInfo();
        cout << ", so dien thoai: " << phone;
    }
};

class BoyFriend : public Friend {
private:
    long income;

public:
    BoyFriend(string name = "", int age = 0, long income = 0.0) : Friend(name, age), income(income) {}

    float getTimeSpent() override {
        return 5 * income / 10000000.0;
    }

    void displayInfo() {
        Friend::displayInfo();
        cout << ", thu nhap: " << income << "d";
    }
};

class OtherBoy : public Friend {
private:
    float attractiveness;

public:
    OtherBoy(string name = "", int age = 0, float attractiveness = 1.0) : Friend(name, age), attractiveness(attractiveness) {}

    float getTimeSpent() override {
        return attractiveness * 20;
    }

    void displayInfo() {
        Friend::displayInfo();
        string attraction;
        if (attractiveness >= 0.7)
            attraction = "cao";
        else if (attractiveness < 0.4)
            attraction = "thap";
        else
            attraction = "trung binh";
        cout << ", do thu hut: " << attraction;
    }
};

bool compareByTime(const pair<int, Friend*>& a, const pair<int, Friend*>& b, int totalFriends) {
    float x = a.second->getTimeSpent();
    float y = b.second->getTimeSpent();
    if (a.first == 3) 
        x = x / totalFriends;
    if (b.first == 3) 
        y = y / totalFriends;
    
    return x > y;
}

int main() {
    int totalFriends;
    cin >> totalFriends;
    vector<pair<int, Friend*>> manage(totalFriends);
    float bestFriendTime = 0.0, boyFriendTime = 0.0, otherBoyTime = 0.0;

    for (int i = 0; i < totalFriends; i++) {
        cin >> manage[i].first;
        if (manage[i].first == 1) {
            string name;
            int age;
            string phone;
            cin >> name >> age >> phone;
            manage[i].second = new BestFriend(name, age, phone);
            bestFriendTime += manage[i].second->getTimeSpent();
        } else if (manage[i].first == 2) {  // Corrected condition
            string name;
            int age;
            long income;
            cin >> name >> age >> income;
            manage[i].second = new BoyFriend(name, age, income);
            boyFriendTime += manage[i].second->getTimeSpent();
        } else {
            string name;
            int age;
            float attractiveness;
            cin >> name >> age >> attractiveness;
            manage[i].second = new OtherBoy(name, age, attractiveness);
            otherBoyTime += (manage[i].second->getTimeSpent()) / totalFriends;
        }
    }

    cout << "Thong ke:\n";
    if (bestFriendTime != 0)
        cout << "-Thoi gian cho ban than: " << bestFriendTime << " h\n";
    if (boyFriendTime != 0)
        cout << "-Thoi gian cho ban trai: " << boyFriendTime << " h\n";
    if (otherBoyTime != 0)    
        cout << "-Thoi gian cho ban trai khac: " << otherBoyTime << " h\n";

    cout << "Nguoi ban quan trong nhat:\n";

    sort(manage.begin(), manage.end(), [&](const pair<int, Friend*>& a, const pair<int, Friend*>& b) {
        return compareByTime(a, b, totalFriends);
    });  // Corrected comparison
    
    int i = 0;
    do {
        manage[i].second->displayInfo();
        cout << endl;
        i ++;
    } while (i < manage.size() && manage[i-1].second->getTimeSpent() == manage[i].second->getTimeSpent());
    
    // Clean up dynamic memory
    for (int i = 0; i < totalFriends; i++) {
        delete manage[i].second;
    }
 
    return 0;
}


*/
