#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
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
    friend Point operator - (const Point& p1, const Point& p2) {
        return Point(p1.hori - p2.hori, p1.verti - p2.verti);
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

class Polygon{
private:
    vector<Point> vertices;
public:
    Polygon() {}

    void addVertex(const Point& p) {
        vertices.push_back(p);
    }

    void move(float dx, float dy) {
        for (Point &vertex : vertices) {
            vertex.translation(dx, dy);
        }
    }

    Point getCentroid() {
        Point p;
        int n = vertices.size();
        if (n < 3) {    throw invalid_argument("Polygon must have at least 3 vertices");    }
        else {
            for (const Point &vertex : vertices) {    p = p + vertex;   }
            return p / n;
        }
        
    }

    void rotate(float angle) {
        Point centroid = getCentroid();
        
        for (Point& vertex : vertices) {
            vertex.projectPoint(centroid, angle);
        }
    }
    void zoomIn(float scalar) {
        Point centroid = getCentroid();

        for (Point& vertex : vertices) {
            vertex = centroid + (vertex - centroid) * scalar;
        }
    }
    void zoomOut(float scalar) {
        Point centroid = getCentroid();
        for (Point& vertex : vertices) {
            vertex = centroid + (vertex - centroid) * scalar;
        }
    }
    friend ostream& operator << (ostream& out, const Polygon& polygon) {
        for (const Point& vertex : polygon.vertices) {
            out << vertex << " ";
        }
        return out;
    }
};

int main() {
    Polygon polygon;

    int numVertices;
    cout << "Enter the number of vertices of the polygon: ";
    cin >> numVertices;

    for (int i = 0; i < numVertices; ++i) {
        Point p;
        cout << "Enter the coordinates of vertex " << i + 1 << ": ";
        cin >> p;
        polygon.addVertex(p);
    }

    float dx, dy;
    cout << "Enter the translation distances (dx dy): ";
    cin >> dx >> dy;

    float angle;
    cout << "Enter the rotation angle (in radians): ";
    cin >> angle;

    float scalar;
    cout << "Enter the zoom scalar: ";
    cin >> scalar;

    try {
        polygon.move(dx, dy);
        polygon.rotate(angle);
        polygon.zoomIn(scalar);
        polygon.zoomOut(scalar);

        cout << "Polygon after transformations: " << polygon << endl;
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}



