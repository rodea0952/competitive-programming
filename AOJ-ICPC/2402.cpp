#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

const double pi = acos(-1);

double torad(int deg){
    return 1. * deg * pi / 180;
}

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

double norm(Vector a){
    return a.x * a.x + a.y * a.y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

double dot(Vector a, Vector b){
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

Vector polar(double a, double r){
    return Point(cos(r) * a, sin(r) * a);
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

// ベクトルと点の位置関係
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

// 線分と点の距離
double getDistanceSP(Segment s, Point p){
    if(dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
    if(dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
    return getDistanceLP(s, p);
}

// 線分と線分の距離
double getDistance(Segment s1, Segment s2){
    if(intersect(s1, s2)) return 0.0;
    return min({getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2), getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)});
}

int main(){
    while(1){
        int n, m, l; cin>>n>>m>>l;
        if(n == 0) return 0;
        m--, l--;
        vector<vector<Point>> star(n, vector<Point>(5));
        for(int i=0; i<n; i++){
            double x, y, a, r; cin>>x>>y>>a>>r;
            for(int dir=0; dir<5; dir++){
                double angle = 90 + dir * 72 + a;
                Point np = polar(r, torad(angle));
                double nx = x + np.x;
                double ny = y + np.y;
                star[i][dir] = Point(nx, ny);
            }
        }

        vector<vector<double>> dist(n, vector<double>(n, 1e9));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                double cdist = 1e9;
                for(int dir1=0; dir1<5; dir1++){
                    for(int dir2=0; dir2<5; dir2++){
                        Segment s1 = {Point(star[i][dir1]), Point(star[i][(dir1+2)%5])};
                        Segment s2 = {Point(star[j][dir2]), Point(star[j][(dir2+2)%5])};

                        cdist = min(cdist, getDistance(s1, s2));
                    }
                }

                dist[i][j] = cdist;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }

        printf("%.10f\n", dist[m][l]);
    }
}