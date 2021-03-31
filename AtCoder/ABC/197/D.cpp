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

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const double pi = acos(-1);

// 角度 -> ラジアン
double torad(double deg){
    return 1. * deg * pi / 180;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    double x0, y0, xn2, yn2; cin>>x0>>y0>>xn2>>yn2;

    double xc = (x0 + xn2) / 2, yc = (y0 + yn2) / 2;
    x0 -= xc, y0 -= yc;

    double nx = cos(torad(360.0 / n)) * x0 - sin(torad(360.0 / n)) * y0;
    double ny = sin(torad(360.0 / n)) * x0 + cos(torad(360.0 / n)) * y0;

    nx += xc, ny += yc;

    cout << fixed << setprecision(10) << nx << " " << ny << endl;

    return 0;
}