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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


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

bool isConvex(Polygon pol){
    int n = pol.size();

    for(int i=0; i<n; i++){
        if(ccw(pol[i], pol[(i+1)%n], pol[(i+2)%n]) == CLOCKWISE){
            return false;
        }
    }

    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    double x1, y1, x2, y2, x3, y3, x4, y4;
    char a;
    while(cin>>x1>>a>>y1>>a>>x2>>a>>y2>>a>>x3>>a>>y3>>a>>x4>>a>>y4){
        Point p1 = Point(x1, y1), p2 = Point(x2, y2), p3 = Point(x3, y3), p4 = Point(x4, y4);
        Polygon pol1, pol2;
        pol1.emplace_back(p1);
        pol1.emplace_back(p2);
        pol1.emplace_back(p3);
        pol1.emplace_back(p4);

        pol2.emplace_back(p1);
        pol2.emplace_back(p4);
        pol2.emplace_back(p3);
        pol2.emplace_back(p2);

        cout << (isConvex(pol1) || isConvex(pol2) ? "YES" : "NO") << endl;
    }

    return 0;
}