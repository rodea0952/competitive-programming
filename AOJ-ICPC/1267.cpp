#include <iostream>
#include <complex>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;

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

Point getCrossPointLL(Line l1, Line l2){
    double a = cross(l1.second - l1.first, l2.second - l2.first);
    double b = cross(l1.second - l1.first, l1.second - l2.first);
    if(abs(a) < EPS && abs(b) < EPS) return l2.first;
    return l2.first + (l2.second - l2.first) * (b / a);
}

Polygon convexCut(Polygon pol, Line l){
    Polygon q;
    int n = pol.size();
    for(int i=0; i<n; i++){
        Point a = pol[i];
        Point b = pol[(i+1)%n];
        if(ccw(l.first, l.second, a) != CLOCKWISE) q.emplace_back(a);
        if(ccw(l.first, l.second, a) * ccw(l.first, l.second, b) < -EPS){
            q.emplace_back(getCrossPointLL(Line(a, b), l));
        }
    }

    return q;
}

double convexArea(Polygon pol){
    int n = pol.size();
    double S = 0;
    for(int i=0; i<n; i++){
        S += cross(pol[i], pol[(i+1)%n]);
    }

    return S / 2;
}

int solve(Polygon pol){
    Polygon ps;
    ps.emplace_back(0, 0);
    ps.emplace_back(10000, 0);
    ps.emplace_back(10000, 10000);
    ps.emplace_back(0, 10000);

    int n = pol.size();
    for(int i=0; i<n; i++){
        ps = convexCut(ps, Line(pol[i], pol[(i+1)%n]));
    }

    if(convexArea(ps) < EPS) return 0;
    else return 1;
}

int main(){
    while(1){
        int n; cin>>n;
        if(n == 0) return 0;

        Polygon pol;
        for(int i=0; i<n; i++){
            double x, y; cin>>x>>y;
            pol.emplace_back(x, y);
        }

        cout << solve(pol) << endl;
    }
}