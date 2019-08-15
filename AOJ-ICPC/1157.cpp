#include <bits/stdc++.h>
using namespace std;
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

struct Point{
    double x, y;
    
    Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (double a) { return Point(a * x, a * y); }
    Point operator / (double a) { return Point(x / a, y / a); }

    double norm() {return x * x + y * y; }
    double abs() {return sqrt(norm()); }

    bool operator < (const Point &p) const{
        return (x != p.x ? x < p.x : y < p.y);
    }

    bool operator == (const Point &p) const{
        return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
    }
};

typedef Point Vector;

struct Segment{
    Point p1, p2;
    Segment(Point p1, Point p2): p1(p1), p2(p2) {}
};

typedef Segment Line;

double dot(Vector a, Vector b){
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

double norm(Vector a){
    return a.x * a.x + a.y * a.y;
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
    if(a.norm() < b.norm()) return ONLINE_FRONT;

    return ON_SEGMENT;
}

bool intersect(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2){
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double getDistanceLP(Line l, Point p){
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double getDistanceSP(Segment s, Point p){
    if(dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
    if(dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
    return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2){
    if(intersect(s1, s2)) return 0.0;
    return min({getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2), getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)});
}

int main(){
    while(1){
        int n; cin>>n;
        if(n == 0) return 0;
        double sx, sy, ex, ey;
        cin>>sx>>sy>>ex>>ey;
        Segment s0 = {Point(sx, sy), Point(ex, ey)};

        double minx = min(sx, ex);
        double miny = min(sy, ey);
        double maxx = max(sx, ex);
        double maxy = max(sy, ey);

        double ans = 1e9;
        for(int i=0; i<n; i++){
            double x1, y1, x2, y2, h;
            cin>>x1>>y1>>x2>>y2>>h;

            if(x1 <= minx && y1 <= miny && maxx <= x2 && maxy <= y2){
                ans = 0;
                continue;
            }

            Point p1 = {x1, y1};
            Point p2 = {x2, y1};
            Point p3 = {x2, y2};
            Point p4 = {x1, y2};

            Segment s1 = {p1, p2};
            Segment s2 = {p2, p3};
            Segment s3 = {p3, p4};
            Segment s4 = {p4, p1};

            double dist1 = getDistance(s0, s1);
            double dist2 = getDistance(s0, s2);
            double dist3 = getDistance(s0, s3);
            double dist4 = getDistance(s0, s4);

            double mindist = min({dist1, dist2, dist3, dist4});

            if(mindist <= h){
                ans = min(ans, mindist);
            }
            else{
                double r = (h * h + mindist * mindist) / 2 / h;
                ans = min(ans, r);
            }
        }

        printf("%.10f\n", ans);
    }
}