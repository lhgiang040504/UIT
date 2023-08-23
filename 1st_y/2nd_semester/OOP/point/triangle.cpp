#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point{
private:
    float hori, verti;
public:
    Point(float h = 0.0, float v = 0.0) : hori(h), verti(v) {}
    float getHori() const { return hori; }
    float getVerti() const { return verti; }
    void setHori(float h) { hori = h; }
    void setVerti(float v) { verti = v; }

    friend istream& operator >> (istream& in, Point &p){
        return in >> p.hori >> p.verti;
    }

    friend ostream& operator << (ostream& out, Point p){
        return out << p.hori << ", " << p.verti << endl;
    }

    void translation(float dx, float dy) {
        hori += dx;
        verti += dy;
    }

    friend Point operator + (const Point& p1, const Point& p2) {
        return Point(p1.hori + p2.hori, p1.verti + p2.verti);
    }
    friend Point operator / (const Point& p, float scalar) {
        if (scalar == 0) {
            // Handle division by zero
            throw invalid_argument("Division by zero");
        }
        return Point(p.hori / scalar, p.verti / scalar);
    }
    friend Point operator * (const Point& p, float scalar) {
        return Point(p.hori * scalar, p.verti * scalar);
    }

    void projectPoint(Point f, float angle) {
        float x = f.hori + (hori - f.hori)*cos(angle) - (verti - f.verti)*sin(angle);
        float y = f.verti + (hori - f.hori)*sin(angle) + (verti - f.verti)*cos(angle);
        hori = x;
        verti = y;
    }
};

class Triangle{
private:
    Point a, b, c;
public:
    Triangle() : a(), b(), c() {}
    Triangle(Point p1, Point p2, Point p3) : a(p1), b(p2), c(p3) {}

    Point getA() const {return a;}
    Point getB() const {return b;}
    Point getC() const {return c;}
    void setA(Point p) {a = p;}
    void setB(Point p) {b = p;}
    void setC(Point p) {c = p;}

    void move(float dx, float dy) {
        a.translation(dx, dy);
        b.translation(dx, dy);
        c.translation(dx, dy);
    }

    Point getCentroid() {
        return (a + b + c) / 3;
    }

    void rotate(float angle) {
        Point f = this->getCentroid();
        a.projectPoint(f, angle);
        b.projectPoint(f, angle);
        c.projectPoint(f, angle);
    }
    void zoomIn(float scalar) {
        a = a * scalar;
        b = b * scalar;
        c = c * scalar;
    }
    void zoomOut(float scalar) {
        a = a / scalar;
        b = b / scalar;
        c = c / scalar;
    }
};

int main() {
    Point p1, p2, p3;
    cout << "Enter the coordinates of Point 1: ";
    cin >> p1;
    cout << "Enter the coordinates of Point 2: ";
    cin >> p2;
    cout << "Enter the coordinates of Point 3: ";
    cin >> p3;

    Triangle triangle(p1, p2, p3);

    float dx, dy;
    cout << "Enter the translation distances (dx dy): ";
    cin >> dx >> dy;
    triangle.move(dx, dy);

    float angle;
    cout << "Enter the rotation angle (in radians): ";
    cin >> angle;
    triangle.rotate(angle);

    cout << "Triangle after translation and rotation:" << endl;
    cout << "Point 1: " << triangle.getA();
    cout << "Point 2: " << triangle.getB();
    cout << "Point 3: " << triangle.getC();

    return 0;
}



