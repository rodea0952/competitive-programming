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

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

Point project(Segment s, Point p){
    Vector base = s.second - s.first;
    double r = dot(p - s.first, base) / norm(base);
    return s.first + base * r;
}

pair<Point, Point> getCrossPoints(Circle c, Line l){
    Vector pr = project(l, c.first);
    Vector e = (l.second - l.first) / abs(l.second - l.first);
    double base = sqrt(c.second * c.second - norm(pr - c.first));
    return make_pair(pr + e * base, pr - e * base);
}

int main(){
    double cx, cy, r; cin>>cx>>cy>>r;
    Circle c1 = {Point(cx, cy), r};
    int q; cin>>q;
    while(q--){
        double x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        Line l1 = {Point(x1, y1), Point(x2, y2)};
        pair<Point, Point> ansp = getCrossPoints(c1, l1);
        Point p1 = min(ansp.first, ansp.second);
        Point p2 = max(ansp.first, ansp.second);
        printf("%.10f %.10f %.10f %.10f\n", p1.X, p1.Y, p2.X, p2.Y);
    }
}