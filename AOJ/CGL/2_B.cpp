#include <iostream>
#include <complex>
#include <utility>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;

#define X real()
#define Y imag()

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a, b) < -EPS) return CLOCKWISE;
    if(dot(a, b) < -EPS) return ONLINE_BACK;
    if(norm(a) < norm(b)) return ONLINE_FRONT;

    return ON_SEGMENT;
}

bool intersect(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2){
    return intersect(s1.first, s1.second, s2.first, s2.second);
}

int main(){
    int q; cin>>q;
    while(q--){
        double x0, y0, x1, y1, x2, y2, x3, y3;
        cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3;
        Segment s1 = {Point(x0, y0), Point(x1, y1)};
        Segment s2 = {Point(x2, y2), Point(x3, y3)};

        cout << intersect(s1, s2) << endl;
    }
}