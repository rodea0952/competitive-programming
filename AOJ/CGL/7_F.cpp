#include <iostream>
#include <complex>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;
typedef pair<Point, double> Circle;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

namespace std{
    bool operator<(const Point &a, const Point &b){
        return !equals(a.X, b.X) ? a.X < b.X : a.Y < b.Y;
    }
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

double arg(Vector p){
    return atan2(p.Y, p.X);
}

Vector polar(double a, double r){
    return Point(cos(r) * a, sin(r) * a);
}

pair<Point, Point> getCrossPoints(Circle c1, Circle c2){
    double d = abs(c1.first - c2.first);
    double a = acos((c1.second * c1.second + d * d - c2.second * c2.second) / (2 * c1.second * d));
    double t = arg(c2.first - c1.first);
    return make_pair(c1.first + polar(c1.second, t + a), c1.first + polar(c1.second, t - a));
}

pair<Point, Point> getTangents(Circle c1, Point p1){
    Circle c2 = Circle(p1, sqrt(norm(c1.first - p1) - c1.second * c1.second));
    pair<Point, Point> p2 = getCrossPoints(c1, c2);
    if(p2.second < p2.first) swap(p2.first, p2.second);
    return p2;
}

int main(){
    double px, py; cin>>px>>py;
    Point p1 = {px, py};
    double cx, cy, r; cin>>cx>>cy>>r;
    Circle c1 = {Point(cx, cy), r};

    pair<Point, Point> p = getTangents(c1, p1);
    printf("%.10f %.10f\n%.10f %.10f", p.first.X, p.first.Y, p.second.X, p.second.Y);
}