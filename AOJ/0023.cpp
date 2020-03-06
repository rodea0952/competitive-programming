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

// 円と円の関係（共通接線数）
int intersection(Circle c1, Circle c2){
    double dist = abs(c1.first - c2.first);
    if(c1.second + c2.second < dist) return 4;
    if(equals(c1.second + c2.second, dist)) return 3;
    if(abs(c1.second - c2.second) < dist && dist < c1.second + c2.second) return 2;
    if(equals(abs(c1.second - c2.second), dist)) return 1;
    else return 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    while(n--){
        double x1, y1, r1, x2, y2, r2; cin>>x1>>y1>>r1>>x2>>y2>>r2;
        Circle c1 = {Point(x1, y1), r1}, c2 = {Point(x2, y2), r2};
        int num = intersection(c1, c2);

        int ans = -1;
        if(num == 4) ans = 0;
        else if(1 <= num) ans = 1;
        else{
            if(r1 < r2) ans = -2;
            else ans = 2;
        }

        cout << ans << endl;
    }

    return 0;
}