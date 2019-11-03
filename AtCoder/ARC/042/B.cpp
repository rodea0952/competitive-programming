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

Point project(Segment s, Point p){
    Vector base = s.second - s.first;
    double r = dot(p - s.first, base) / norm(base);
    return s.first + base * r;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int tx, ty; cin>>tx>>ty;
    Point tp = Point(tx, ty);
    int n; cin>>n;
    vector<Point> xy;
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        xy.emplace_back(x, y);
    }

    vector<Segment> seg;
    for(int i=0; i<n; i++){
        seg.emplace_back(xy[i], xy[(i+1)%n]);
    }

    double ans = inf;
    for(int i=0; i<n; i++){
        Point po = project(seg[i], tp);
        chmin(ans, abs(tp - po));
    }

    printf("%.10f\n", ans);

    return 0;
}