#include <iostream>
#include <complex>
#include <utility>
#include <algorithm>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

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

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a, b) < -EPS) return CLOCKWISE;
    if(dot(a, b) < -EPS) return ONLINE_BACK;
    if(norm(a) < norm(b)) return ONLINE_FRONT;

    return ON_SEGMENT;
}

// 線分の交差判定
bool intersect(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2){
    return intersect(s1.first, s1.second, s2.first, s2.second);
}

double getDistanceLP(Line l, Point p){
    return abs(cross(l.second - l.first, p - l.first) / abs(l.first - l.second));
}

double getDistanceSP(Segment s, Point p){
    if(dot(s.second - s.first, p - s.first) < 0.0) return abs(p - s.first);
    if(dot(s.first - s.second, p - s.second) < 0.0) return abs(p - s.second);
    return getDistanceLP(s, p);
}

double getDistanceSS(Segment s1, Segment s2){
    if(intersect(s1, s2)) return 0.0;
    return min({getDistanceSP(s1, s2.first), getDistanceSP(s1, s2.second), getDistanceSP(s2, s1.first), getDistanceSP(s2, s1.second)});
}

int main(){
    int q; cin>>q;
    while(q--){
        double x0, y0, x1, y1, x2, y2, x3, y3;
        cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3;
        Segment s1 = {Point(x0, y0), Point(x1, y1)};
        Segment s2 = {Point(x2, y2), Point(x3, y3)};
        
        printf("%.10f\n", getDistanceSS(s1, s2));
    }
}