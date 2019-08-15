#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

typedef pair<int, int> P;

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
typedef vector<Point> Polygon;

struct Segment{
    Point p1, p2;
    Segment(Point p1, Point p2): p1(p1), p2(p2) {}
};

typedef Segment Line;

struct Circle{
    Point c;
    double r;

    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

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

double arg(Vector p){
    return atan2(p.y, p.x);
}

Vector polar(double a, double r){
    return Point(cos(r) * a, sin(r) * a);
}

pair<Point, Point> getCrossPointsCC(Circle c1, Circle c2){
    double d = abs(c1.c - c2.c);
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
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

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0){
            return 0;
        }

        vector<Circle> cir;
        for (int i = 0; i < n; i++){
            double x, y, r;
            cin >> x >> y >> r;
            cir.emplace_back(Point(x, y), r);
        }

        vector<Point> po;

        po.emplace_back(cir[0].c.x, cir[0].c.y);

        vector<Segment> seg;
        for (int i = 0; i < n - 1; i++){
            auto crosspoint = getCrossPointsCC(cir[i], cir[i + 1]);
            po.emplace_back(crosspoint.first.x, crosspoint.first.y);
            po.emplace_back(crosspoint.second.x, crosspoint.second.y);
            seg.emplace_back(crosspoint.first, crosspoint.second);
        }

        po.emplace_back(cir[n - 1].c.x, cir[n - 1].c.y);

        int m = po.size();
        vector<double> dist(m, 1e9);
        dist[0] = 0;

        for (int i = 1; i < m; i++){
            for (int j = 0; j < i; j++){
                // from j to i

                Segment s1 = {po[j], po[i]};

                int nsegid = (i - 1) / 2;
                int psegid = (j - 1) / 2;
                int needinter = max(0, nsegid - psegid - 1);
                if(j == 0){
                    needinter = nsegid;
                    psegid = -1;
                }

                int cntinter = 0;
                for (int k = psegid + 1; k < nsegid; k++){
                    if(intersect(s1, seg[k])){
                        cntinter++;
                    }
                }

                if(needinter == cntinter){
                    double cdist = abs(po[i] - po[j]);
                    dist[i] = min(dist[i], dist[j] + cdist);
                }
            }
        }

        printf("%.10f\n", dist[m - 1]);
    }
}