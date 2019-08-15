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

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

string ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS) return "COUNTER_CLOCKWISE";
    if(cross(a, b) < -EPS) return "CLOCKWISE";
    if(dot(a, b) < -EPS) return "ONLINE_BACK";
    if(norm(a) < norm(b)) return "ONLINE_FRONT";

    return "ON_SEGMENT";
}

int main(){
    double x0, y0, x1, y1; cin>>x0>>y0>>x1>>y1;
    Point p0 = {x0, y0};
    Point p1 = {x1, y1};
    int q; cin>>q;
    while(q--){
        double x2, y2; cin>>x2>>y2;
        Point p2 = {x2, y2};

        cout << ccw(p0, p1, p2) << endl;
    }
}