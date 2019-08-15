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

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

Point project(Segment s, Point p){
    Vector base = s.second - s.first;
    double r = dot(p - s.first, base) / norm(base);
    return s.first + base * r;
}

double getDistanceLP(Line l, Point p){
    return abs(cross(l.second - l.first, p - l.first) / abs(l.first - l.second));
}

pair<Point, Point> getCrossPoints(Circle c, Line l){
    Vector pr = project(l, c.first);
    Vector e = (l.second - l.first) / abs(l.second - l.first);

    if(equals(getDistanceLP(l, c.first), c.second)){
        return make_pair(pr, pr);
    }

    double base = sqrt(c.second * c.second - norm(pr - c.first));
    return make_pair(pr + e * base, pr - e * base);
}

vector<Line> tangent(Circle c1, Circle c2){
    vector<Line> l1;
    if(c1.second < c2.second) swap(c1, c2);
    double g = norm(c1.first - c2.first);
    if(equals(g, 0)) return l1;
    Point u = (c2.first - c1.first) / sqrt(g);
    Point v = {-u.Y, u.X};

    for(int i=1; i>=-1; i-=2){
        double h = (c1.second + i * c2.second) / sqrt(g);

        if(equals(1 - h * h, 0)){
            l1.emplace_back(c1.first + u * c1.second, c1.first + (u + v) * c1.second);
        }
        else if(1 - h * h > EPS){
            Point uu = u * h;
            Point vv = v * sqrt(1 - h * h);
            l1.emplace_back(c1.first + (uu + vv) * c1.second, c2.first - (uu + vv) * c2.second * Point(i, i));
            l1.emplace_back(c1.first + (uu - vv) * c1.second, c2.first - (uu - vv) * c2.second * Point(i, i));
        }
    }

    return l1;
}

int main(){
    double c1x, c1y, c1r; cin>>c1x>>c1y>>c1r;
    double c2x, c2y, c2r; cin>>c2x>>c2y>>c2r;

    Circle c1 = {Point(c1x, c1y), c1r};
    Circle c2 = {Point(c2x, c2y), c2r};

    vector<Line> l1 = tangent(c1, c2);

    Polygon pol;
    for(auto i : l1){
        pol.emplace_back(getCrossPoints(c1, i).first);
    }

    sort(pol.begin(), pol.end());

    for(auto i : pol){
        printf("%.10f %.10f\n", i.X, i.Y);
    }
}