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

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

int intersection(Circle c1, Circle c2){
    double dist = abs(c1.first - c2.first);
    if(c1.second + c2.second < dist) return 4;
    if(equals(c1.second + c2.second, dist)) return 3;
    if(abs(c1.second - c2.second) < dist && dist < c1.second + c2.second) return 2;
    if(equals(abs(c1.second - c2.second), dist)) return 1;
    else return 0;
}

int main(){
    double c1x, c1y, c1r; cin>>c1x>>c1y>>c1r;
    double c2x, c2y, c2r; cin>>c2x>>c2y>>c2r;
    Circle c1 = {Point(c1x, c1y), c1r};
    Circle c2 = {Point(c2x, c2y), c2r};

    cout << intersection(c1, c2) << endl;
}