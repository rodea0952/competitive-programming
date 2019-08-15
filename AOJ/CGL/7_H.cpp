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

Point project(Segment s, Point p){
    Vector base = s.second - s.first;
    double r = dot(p - s.first, base) / norm(base);
    return s.first + base * r;
}

double getDistanceLP(Line l, Point p){
    return abs(cross(l.second - l.first, p - l.first) / abs(l.first - l.second));
}

double getDistanceSP(Segment s, Point p){
    if(dot(s.second - s.first, p - s.first) < 0.0) return abs(p - s.first);
    if(dot(s.first - s.second, p - s.second) < 0.0) return abs(p - s.second);
    return getDistanceLP(s, p);
}

pair<Point, Point> getCrossPoints(Circle c, Line l){
    Vector pr = project(l, c.first);
    Vector e = (l.second - l.first) / abs(l.second - l.first);

    if(equals(getDistanceLP(l, c.first), c.second)){
        return make_pair(pr, pr);
    }

    double base = sqrt(c.second * c.second - norm(pr - c.first));
    return make_pair(pr - e * base, pr + e * base);
}

double areaCP(Circle c, Polygon pol){
    double S = 0;
    double r = c.second;
    int n = pol.size();
    for(int i=0; i<n; i++){
        pol[i] -= c.first;
    }

    for(int i=0; i<n; i++){
        if(abs(pol[i] * pol[(i+1)%n]) < EPS) continue;
        double d = arg(pol[(i+1)%n] / pol[i]);
        S += r * r * d / 2.0;

        if(getDistanceSP(Segment(pol[i], pol[(i+1)%n]), Point(0, 0)) < r - EPS){
            pair<Point, Point> cps = getCrossPoints(Circle(Point(0, 0), r), Line(pol[i], pol[(i+1)%n]));
            Point a, b;
            if(ccw(pol[i], pol[(i+1)%n], cps.first) == 0 && ccw(pol[i], pol[(i+1)%n], cps.second) == 0){
                a = cps.first, b = cps.second;
            }
            else if(!ccw(pol[i], pol[(i+1)%n], cps.first)){
                a = cps.first, b = pol[(i+1)%n];
            }
            else if(!ccw(pol[i], pol[(i+1)%n], cps.second)){
                a = pol[i], b = cps.second;
            }
            else{
                a = pol[i], b = pol[(i+1)%n];
            }

            if(abs(a * b) < EPS) continue;
            d = arg(b / a);
            S += cross(a, b) / 2.0 - r * r * d / 2.0;
        }
    }

    return S;
}

int main(){
    int n; cin>>n;
    double r; cin>>r;
    Circle cir = {Point(0, 0), r};
    Polygon pol;
    for(int i=0; i<n; i++){
        double x, y; cin>>x>>y;
        pol.emplace_back(Point(x, y));
    }

    printf("%.10f\n", areaCP(cir, pol));
}