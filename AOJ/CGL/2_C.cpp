#include <iostream>
#include <complex>
#include <utility>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;

#define X real()
#define Y imag()

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

Point getCrossPoint(Segment s1, Segment s2){
    Vector base = s2.second - s2.first;
    double d1 = abs(cross(base, s1.first - s2.first));
    double d2 = abs(cross(base, s1.second - s2.first));
    double t = d1 / (d1 + d2);
    return s1.first + (s1.second - s1.first) * t;
}

int main(){
    int q; cin>>q;
    while(q--){
        double x0, y0, x1, y1, x2, y2, x3, y3;
        cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3;
        Segment s1 = {Point(x0, y0), Point(x1, y1)};
        Segment s2 = {Point(x2, y2), Point(x3, y3)};

        Point ansp = getCrossPoint(s1, s2);
        
        printf("%.10f %.10f\n", ansp.X, ansp.Y);
    }
}