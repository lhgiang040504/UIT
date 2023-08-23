#include <iostream>
#include <cmath>
using namespace std;

class frac{
private:
    int numerator;
    int denominator;
    float value;
public:
    // Constructor to initialize two data of 1 object
    frac(int n = 0, int d = 1) : numerator(n), denominator(d), value(n / float(d)) {}
    
    frac(float v) {
        value = v;
        int i = 0;
        while (v != int(v)) {
            v = v * 10;
            i++;
        }
        if (i != 0) {
            numerator = v;
            denominator = pow(10, i);
        }
        else {
            numerator = v;
            denominator = 1;
        }
        this->Compact();
    }

    void setNumerator(int n) {
        numerator = n;
    }
    void setDenominator(int d) {
        if (d != 0)    
            denominator = d;
    }
    int getNumerator() const {
        return numerator;
    }
    int getDenominator() const {
        return denominator;
    }

    float getfloatValue() const {
        return numerator / float(denominator);
    }

    int GCD();
    void Compact() {
        int gcd = this->GCD();
        numerator /= gcd;
        denominator /= gcd;
    }
    bool operator > (frac sub) {
        return (numerator * sub.denominator) > (sub.numerator * denominator);
    }
    frac operator+(const frac& other) const {
        int commonDenominator = denominator * other.denominator;
        int sumNumerator = (numerator * other.denominator) + (other.numerator * denominator);
        return frac(sumNumerator, commonDenominator);
    }

    frac operator-(const frac& other) const {
        int commonDenominator = denominator * other.denominator;
        int diffNumerator = (numerator * other.denominator) - (other.numerator * denominator);
        return frac(diffNumerator, commonDenominator);
    }

    frac operator*(const frac& other) const {
        int productNumerator = numerator * other.numerator;
        int productDenominator = denominator * other.denominator;
        return frac(productNumerator, productDenominator);
    }

    frac operator/(const frac& other) const {
        int quotientNumerator = numerator * other.denominator;
        int quotientDenominator = denominator * other.numerator;
        return frac(quotientNumerator, quotientDenominator);
    }
};
int frac::GCD() {
    int a = getNumerator();
    int b = getDenominator();
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    while (a!=b){
        if (a > b) a-=b;
        else b-=a; 
    }
    return a;
}
istream& operator >> (istream& in, frac& f) {
    int n, d;
    in >> n >> d;
    f.setNumerator(n);
    f.setDenominator(d);
    return in;
}

ostream& operator << (ostream& out, const frac& f) {
    out << f.getNumerator() << " / " << f.getDenominator();
    return out;
}    

int main() {
    frac f;
    float n;
    cin >> n;
    f = frac(n);
    cout << f;
    return 0;
}