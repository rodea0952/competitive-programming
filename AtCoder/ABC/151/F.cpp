#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;
typedef pair<Point, double> Circle;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

// 角度 -> ラジアン
double torad(int deg){
    return 1. * deg * pi / 180;
}

// ラジアン -> 角度
double todeg(double ang){
    return ang * 180 / pi;
}

namespace std{
    bool operator<(const Point &a, const Point &b){
        return !equals(a.X, b.X) ? a.X < b.X : a.Y < b.Y;
    }

    bool cmp_y(const Point &a, const Point &b) {
        return !equals(a.Y, b.Y) ? a.Y < b.Y : a.X < b.X;
    }
}

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

// 直交判定
bool isOrthogonal(Vector a, Vector b){
    return equals(dot(a, b), 0);
}

// 平行判定
bool isParallel(Vector a, Vector b){
    return equals(cross(a, b), 0);
}

// 射影
Point project(Segment s, Point p){
    Vector base = s.second - s.first;
    double r = dot(p - s.first, base) / norm(base);
    return s.first + base * r;
}

// 反射
Point reflect(Segment s, Point p){
    return p + (project(s, p) - p) * 2.0;
}

// ベクトルと点の位置関係
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

// 線分の交差判定
bool intersect(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2){
    return intersect(s1.first, s1.second, s2.first, s2.second);
}

// 線分と線分の交点
Point getCrossPointSS(Segment s1, Segment s2){
    Vector base = s2.second - s2.first;
    double d1 = abs(cross(base, s1.first - s2.first));
    double d2 = abs(cross(base, s1.second - s2.first));
    double t = d1 / (d1 + d2);
    return s1.first + (s1.second - s1.first) * t;
}

Line bisector(Point a, Point b){
    Point A = (a + b) * Point(0.5, 0);
    return Line(A, A +(b-a)*Point(0, pi/2));
}

Point getCrossPointLL(Line l1, Line l2){
    double a = cross(l1.second - l1.first, l2.second - l2.first);
    double b = cross(l1.second - l1.first, l1.second - l2.first);
    if(abs(a) < EPS && abs(b) < EPS) return l2.first;
    return l2.first + (l2.second - l2.first) * (b / a);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<double> x(n), y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];

    double ans = INF;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            bool valid = true;
            double cy = (y[i] + y[j]) / 2;
            double cx = (x[i] + x[j]) / 2;

            double r = (cy - y[i]) * (cy - y[i]) + (cx - x[i]) * (cx - x[i]);

            for(int k=0; k<n; k++){
                if(k == i || k == j) continue;
                double cr = (cy - y[k]) * (cy - y[k]) + (cx - x[k]) * (cx - x[k]);
                if(cr > r) valid = false;
            }

            if(valid) ans = min(ans, r);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){

                Point c1 = {(x[i] + x[j]) / 2, (y[i] + y[j]) / 2};
                Point c2 = {(x[i] + x[k]) / 2, (y[i] + y[k]) / 2};

                Line l1 = bisector(Point(x[i], y[i]), Point(x[j], y[j]));
                Line l2 = bisector(Point(x[i], y[i]), Point(x[k], y[k]));

                Point c = getCrossPointLL(l1, l2);

                bool valid = true;

                double r = (c.Y - y[i]) * (c.Y - y[i]) + (c.X - x[i]) * (c.X - x[i]);

                for(int l=0; l<n; l++){
                    if(l == i || l == j || l == k) continue;
                    double cr = (c.Y - y[l]) * (c.Y - y[l]) + (c.X - x[l]) * (c.X - x[l]);
                    if(cr > r) valid = false;
                }

                if(valid) ans = min(ans, r);
            }
        }
    }

    printf("%.10f\n", sqrt(ans));

    return 0;
}
