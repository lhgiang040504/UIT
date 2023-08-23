#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

class Birth {
private:
    int day, month, year;
public:
    Birth(int d = 1, int m = 1, int y = 1) : day(d), month(m), year(y) {}
    
    friend istream& operator >> (istream &in, Birth &b) {
        return in >> b.day >> b.month >> b.year;
    }
    friend ostream& operator << (ostream &out, Birth b) {
        return out << setw(2) << b.day << " / " << setw(2) << b.month << " / " << b.year;
    }

};
class Score {
private:
    float math, liter, english;
public:
    Score(float m = 0, float l = 0, float e = 0) : math(m), liter(l), english(e) {}

    friend istream& operator >> (istream &in, Score &s) {
        return in >> s.math >> s.liter >> s.english;
    }
    friend ostream& operator << (ostream &out, Score s) {
        out << s.math << " - " << s.liter << " - " << s.english;
        return out;
    }

    float Sum() {
        return math + liter + english;
    }
};

class Candidate {
private:
    string id;
    string name;  
    Birth birth;
    Score score;
public:
    Candidate(const string& id1 = ".", const string& name1 = ".", Birth b1 = Birth(), Score s1 = Score()) : id(id1), name(name1), birth(b1), score(s1) {}
    
    friend istream& operator >> (istream &in, Candidate &candi) {
        getline(in >> ws, candi.id);
        getline(in >> ws, candi.name);
        in >> candi.birth;
        in >> candi.score;
        return in;
    }
    friend ostream& operator << (ostream &out, Candidate candi) {
        out << setw(5) << candi.id << setw(20) << candi.name << setw(10) << candi.birth << setw(10) << candi.score;
        return out;
    }

    float scoreSum() {
        return score.Sum();
    }
    
};

int main() {
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;
    cin.ignore();  // clear input buffer
    
    vector<Candidate> candidates(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin " << i + 1 << endl;
        cin >> candidates[i];
    }
       
    for (int i = 0; i < n; i++)
        if (candidates[i].scoreSum() > 15)
            cout << candidates[i] << endl;

    return 0;
}