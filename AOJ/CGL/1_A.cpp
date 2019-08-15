#include <iostream>
#include <complex>
#include <utility>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;

#define X real()
#define Y imag()

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

Point project(Segment s, Point p){
    Vector base = s.second - s.first;
    double r = dot(p - s.first, base) / norm(base);
    return s.first + base * r;
}

int main(){
    double x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    Line li = {Point(x1, y1), Point(x2, y2)};
    int q; cin>>q;
    while(q--){
        double x, y; cin>>x>>y;
        Point ansp = project(li, Point(x, y));
        printf("%.10f %.10f\n", ansp.X, ansp.Y);
    }
}