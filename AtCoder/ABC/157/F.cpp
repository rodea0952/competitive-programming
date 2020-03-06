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
typedef pair<Point, double> Circle;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

// 円の交点
// ラジアン
double arg(Vector p){
    return atan2(p.Y, p.X);
}

Vector polar(double a, double r){
    return Point(cos(r) * a, sin(r) * a);
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

pair<Point, Point> getCrossPoints(Circle c1, Circle c2){
    double d = abs(c1.first - c2.first);
    double a = acos((c1.second * c1.second + d * d - c2.second * c2.second) / (2 * c1.second * d));
    double t = arg(c2.first - c1.first);
    return make_pair(c1.first + polar(c1.second, t + a), c1.first + polar(c1.second, t - a));
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin>>n>>k;
    vector<Circle> ci(n);
    for(int i=0; i<n; i++){
        double x, y, c; cin>>x>>y>>c;
        ci[i] = {Point(x, y), c};
    }

    double ng = 0, ok = inf;
    for(int loop=0; loop<1000; loop++){
        double mid = (ng + ok) / 2;
        vector<Circle> cci(n);
        for(int i=0; i<n; i++){
            double cr = mid / ci[i].second;
            cci[i] = {ci[i].first, cr};
        }

        vector<Point> po;
        for(int i=0; i<n; i++){
            po.emplace_back(cci[i].first);
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int judge = intersection(cci[i], cci[j]);
                if(1 <= judge && judge <= 3){
                    po.emplace_back(getCrossPoints(cci[i], cci[j]).first);
                    po.emplace_back(getCrossPoints(cci[i], cci[j]).second);
                }
            }
        }

        bool valid = false;
        for(auto &i : po){
            int sum = 0;
            for(int j=0; j<n; j++){
                double dist = abs(i - cci[j].first);
                if(dist < cci[j].second + EPS) sum++;
            }

            if(k <= sum) valid = true;
        }

        if(valid) ok = mid;
        else ng = mid;
    }

    printf("%.10f\n", ok);

    return 0;
}