#include <iostream>
using namespace std;

class Complex {
private:
    float real, image;
public:
  
    Complex(float r = 0, float i = 0) : real(r), image(i) {}

    float getReal() const {
        return real;
    }
    float getImage() const {
        return image;
    }
    void setReal(float r) {
        real = r;
    }
    void setImage(float i) {
        image = i;
    }

    Complex operator + (const Complex& c) {
        return Complex(real + c.real, image + c.image);
    }
    Complex operator - (const Complex& c) {
        return Complex(real + c.real, image + c.image);
    }

    Complex operator * (const Complex& c) {
        float r = real * c.real - image * c.image;
        float i = real * c.image + image * c.real;
        return Complex(r, i);
    }

    Complex operator / (const Complex& c) {
        float denom = c.real * c.real + c.image * c.image;
        float r = (real * c.real + image * c.image) / denom;
        float i = (image * c.real - real * c.image) / denom;
        return Complex(r, i);
    }
};

istream& operator >> (istream& in, Complex& c) {
    float r, i;
    in >> r >> i;
    c.setReal(r);
    c.setImage(i);
    return in;
}

ostream& operator << (ostream& out, const Complex& c) {
    out << c.getReal() << " + i*" << c.getImage();
    return out;
}    

int main() {
    Complex c1, c2, sum, diff, prod, quot;

    cin >> c1;
    cin >> c2;

    diff = c1 - c2;
    prod = c1 * c2;
    quot = c1 / c2;


    cout << "Tổng: " << c1 + c2 << endl;
    cout << "Hiệu: " << c1 - c2 << endl;
    cout << "Tích: " << c1 * c2 << endl;
    cout << "Thương: " << c1 / c2;

    return 0;
}