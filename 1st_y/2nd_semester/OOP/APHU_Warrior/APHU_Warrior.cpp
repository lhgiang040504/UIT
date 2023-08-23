#include <bits/stdc++.h>
using namespace std;
static float HP_aphu = 0;
static float currHP_aphu = 0;

class Weapon {
protected:
    float Damage;
    int Times;
public:
    Weapon(float damage = 0.0, int times = 0) :
    Damage(damage), Times(times) {}

    virtual void Input() {    cin >> Damage >> Times;    }
    
    virtual float Dam_Calculate() = 0;
    
    bool is_Usable() {    return Times > 0;    }
};
class Knife : public Weapon {
private:
    float Length;
public:
    void Input() override {
        Weapon::Input();
        cin >> Length;
    }

    float Dam_Calculate() override {
        Times = Times - 1;
        return Damage * Length;
    }
};
class Archery : public Weapon {
private:
    int Arrow;
public:
    Archery(float damage = 0.0, int times = 0, int arrow = 0) :
    Weapon(damage, times), Arrow(arrow) {}

    void Input() override {
        Weapon::Input();
        cin >> Arrow;
    }

    float Dam_Calculate() override {
        Times = Times - 2;
        return Damage * Arrow / 2.0;
    }
};
class Hand : public Weapon {
public:
    Hand(float damage = 0.0, int times = 1) :
    Weapon(damage, times) {}

    float Dam_Calculate() override {
        currHP_aphu = currHP_aphu - HP_aphu * (1.0 / 10.0);
        return HP_aphu / 10.0;;
    }
};

class Danger {
protected:
    float HP;
    float Damage;
public:
    Danger(float hp = 0.0, float damage = 0.0) :
    HP(hp), Damage(damage) {}

    void set_HP(float damage) {    HP = HP - damage;    }
    
    virtual void Input() {    cin >> HP >> Damage;    }

    virtual float Dam_Calculate() = 0;
    
    virtual bool is_Alive() {    return HP > 0;    }
};
class Gaur : public Danger {
private:
    int Times;
public:
    Gaur(float hp = 0.0, float damage = 0.0, int times = 0) :
    Danger(hp, damage), Times(times) {}

    void Input() override {
        Danger::Input();
        cin >> Times;
    }

    bool is_Alive() override {    
        Times --;
        return HP > 0 && Times > 0;
    }

    float Dam_Calculate() override {    return Damage;    }

};
class Tiger : public Danger {
public:
    Tiger(float hp = 0.0, float damage = 0.0) :
    Danger(hp, damage) {}

    void Input() override {    Danger::Input();    }

    bool is_Alive() override {    return HP > 0;    }

    float Dam_Calculate() override {    return Damage * 1.5;    }
};
    
class APhu {
public:
    void Input() {    
        cin >> HP_aphu;
        currHP_aphu = HP_aphu;
    }

    float get_HP() {     return currHP_aphu;      }

    void set_HP(float damaged) {    currHP_aphu = currHP_aphu - damaged;  }

    bool is_Alive() {    return currHP_aphu > 0;    }
};

int main() {
    APhu* man = new APhu();
    man->Input();
    
    int n;
    cin >> n;
    vector<Weapon*> his_Weapon(n + 1);
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1)
            his_Weapon[i] = new Knife();
        else 
            his_Weapon[i] = new Archery();
        his_Weapon[i]->Input();
    }
    his_Weapon[n] = new Hand();

    int m;
    cin >> m;
    vector<Danger*> his_Danger(m);
    for (auto& danger : his_Danger) {
        int type;
        cin >> type;
        if (type == 1)
            danger = new Gaur();
        else 
            danger = new Tiger();
        danger->Input();
    }

    // Each round of attack
    int i = 0;
    int j = 0;
    if (m != 0) {
        do {
            // Attacking
            his_Danger[j]->set_HP(his_Weapon[i]->Dam_Calculate());
            if (!his_Weapon[i]->is_Usable())
                i ++;
            if (!(his_Danger[j]->is_Alive())){
                j ++;
                continue;
            }
            // Attacked
            man->set_HP(his_Danger[j]->Dam_Calculate());
        } while (man->is_Alive() && j < m);
    }
    if (j == m) 
        cout << "A Phu chien thang, hp con lai: " << currHP_aphu << ", so vu khi con lai: " << n - i;
    else    
        cout << "A Phu that bai, so thu du con lai: " << m - j;
    
    // Clean up memory
    delete man;
    
    for (int k = 0; k < n; k++)
        delete his_Weapon[k];
    delete his_Weapon[n];
    
    for (int k = 0; k < m; k++)
        delete his_Danger[k];

    return 0;
}