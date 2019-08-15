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

int main(){
    double c1x, c1y, c1r; cin>>c1x>>c1y>>c1r;
    double c2x, c2y, c2r; cin>>c2x>>c2y>>c2r;

    Circle c1 = {Point(c1x, c1y), c1r};
    Circle c2 = {Point(c2x, c2y), c2r};

    pair<Point, Point> ansp = getCrossPoints(c1, c2);
    Point p1 = min(ansp.first, ansp.second);
    Point p2 = max(ansp.first, ansp.second);

    printf("%.10f %.10f %.10f %.10f\n", p1.X, p1.Y, p2.X, p2.Y);
}