#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Character {
protected:
    static int countNhan_loai;
    float ATK, DEF, HP;
    string name;

public:
    Character(string name = "Unknown", float atk = 0.0, float def = 0.0, float hp = 0.0) :
        name(name), ATK(atk), DEF(def), HP(hp) {}

    float get_HP() { return HP; }
    bool is_Dead() { return HP <= 0; }
    void attack(Character& enemy) {
        if (ATK - enemy.DEF > 0) {
            enemy.HP -= ATK - enemy.DEF;
        }
    }
    void print_Info() {
        cout << name << " " << HP << endl;
    }

    virtual void bootStrength() {}
    virtual void input() {
        cin >> name >> HP >> ATK >> DEF;
    }

    virtual ~Character() = default;
};
int Character::countNhan_loai = 0;

class Nhan_loai : public Character {
private:
    string Job;
public:
    Nhan_loai(string name = "Unknown", float atk = 0.0, float def = 0.0, float hp = 0.0, string job = "Unknown") :
        Character(name, atk, def, hp), Job(job) {}

    void input() override {
        Character::input();
        cin >> Job;
        countNhan_loai++;
    }
};
class Human : public Nhan_loai {};
class Elf : public Nhan_loai {
public:
    void bootStrength() override {
        DEF *= 1.5;
        return;
    }
};

class Ban_nhan : public Character {
private:
    string Racial;
public:
    Ban_nhan(string name = "Unknown", float atk = 0.0, float def = 0.0, float hp = 0.0, string racial = "Unknown") :
        Character(name, atk, def, hp), Racial(racial) {}

    void input() override {
        Character::input();
        cin >> Racial;
    }
};
class Orc : public Ban_nhan {
public:
    void bootStrength() override {
        HP *= 1.5;
        return;
    }
};
class Golbin : public Ban_nhan {
public:
    void bootStrength() override {
        ATK *= 1.1;
        return;
    }
};

class Di_hinh : public Character {};
class Vampire : public Di_hinh {
public:
    void bootStrength() override {
        HP += HP * 0.1 * countNhan_loai;
        return;
    }
};
class Devil : public Di_hinh {
private:
    static int countDevil;
public:
    void input() override {
        Character::input();
        countDevil++;
    }
    void bootStrength() override {
        ATK += ATK * 0.1 * countDevil;
        DEF += DEF * 0.1 * countDevil;
        return;
    }
};
int Devil::countDevil = 0;

class Boss : public Character {};

Character* init(int type) {
    switch (type) {
    case 1:
        return new Human();
    case 2:
        return new Elf();
    case 3:
        return new Orc();
    case 4:
        return new Golbin();
    case 5:
        return new Vampire();
    case 6:
        return new Devil();
    default:
        return nullptr;
    }
    // Add a default return statement here
    return new Character();
}

class Guild {
private:
    Character** manage;
    int size = 0;

public:
    void Input() {
        cin >> size;
        manage = new Character * [size];
        for (int i = 0; i < size; i++) {
            int type;
            cin >> type;
            manage[i] = init(type);
            manage[i]->input();
        }
        for (int i = 0; i < size; i++) { manage[i]->bootStrength(); }
    }

    int get_Size() { return size; }

    void Print() {
        for (int i = 0; i < size; i++) {
            if (!manage[i]->is_Dead())
                manage[i]->print_Info();
        }
    }

    void ALL_attack(Character& enemy) {
        for (int i = 0; i < size; i++) {
            if (manage[i]->is_Dead()) {
                delete manage[i];
                manage[i] = nullptr;
            }
            else {
                manage[i]->attack(enemy);
            }
        }
        int currentIndex = 0;
        for (int i = 0; i < size; i++) {
            if (manage[i] != nullptr) {
                manage[currentIndex] = manage[i];
                currentIndex++;
            }
        }
        size = currentIndex;
    }

    void sort_HP() {
        sort(manage, manage + size, [](Character* a, Character* b) {
            return a->get_HP() < b->get_HP();
        });
    }

    ~Guild() { delete[] manage; }

    Character* weakest() { return manage[0]; }
};

int main() {
    Guild guild;
    guild.Input();

    Boss boss;
    boss.input();

    int i = 1;
    do {
        if (i != 1) {
            boss.attack(*(guild.weakest()));
        }
        guild.ALL_attack(boss);
        guild.sort_HP();
        i++;
    } while (!boss.is_Dead() && i <= 100 && guild.get_Size() != 0);

    if (boss.is_Dead()) {
        guild.Print();
    }
    else {
        boss.print_Info();
    }

    return 0;
}
