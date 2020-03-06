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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

// 垂直二等分線
Line bisector(Point a, Point b){
    Point A = (a + b) * Point(0.5, 0);
    return Line(A, A + (b - a) * Point(0, pi / 2));
}

// 直線と直線の交点
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
    while(n--){
        double x1, y1, x2, y2, x3, y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Point p1 = Point(x1, y1), p2 = Point(x2, y2), p3 = Point(x3, y3);
        Line l1 = bisector(p1, p2), l2 = bisector(p1, p3);
        Point p = getCrossPointLL(l1, l2);
        double r = abs(p - p1);
        printf("%.3f %.3f %.3f\n", p.X, p.Y, r);
    }

    return 0;
}