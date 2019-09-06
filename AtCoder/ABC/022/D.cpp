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

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

namespace std{
    bool operator<(const Point &a, const Point &b){
        return !equals(a.X, b.X) ? a.X < b.X : a.Y < b.Y;
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

Polygon convexHull(Polygon ps){
    int n = ps.size();
    sort(ps.begin(), ps.end());
    int k = 0;
    Polygon convex(n * 2);
    for(int i=0; i<n; i++){
        while(k >= 2 && ccw(convex[k-2], convex[k-1], ps[i]) == CLOCKWISE) k--;
        convex[k++] = ps[i];
    }
    for(int i=n-2, t=k; i>=0; i--){
        while(k > t && ccw(convex[k-2], convex[k-1], ps[i]) == CLOCKWISE) k--;
        convex[k++] = ps[i];
    }
    convex.resize(k-1);
    return convex;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    Polygon pol1, pol2;
    for(int i=0; i<n; i++){
        double x, y; cin>>x>>y;
        pol1.emplace_back(x, y);
    }
    for(int i=0; i<n; i++){
        double x, y; cin>>x>>y;
        pol2.emplace_back(x, y);
    }

    pol1 = convexHull(pol1);
    pol2 = convexHull(pol2);

    int sz1 = pol1.size();
    int sz2 = pol2.size();

    double side_min1 = INF;
    double side_min2 = INF;

    for(int i=0; i<sz1; i++){
        double side = abs(pol1[i] - pol1[(i+1)%sz1]);
        chmin(side_min1, side);
    }
    for(int i=0; i<sz2; i++){
        double side = abs(pol2[i] - pol2[(i+1)%sz2]);
        chmin(side_min2, side);
    }

    double ans = side_min2 / side_min1;

    printf("%.10f\n", ans);
}