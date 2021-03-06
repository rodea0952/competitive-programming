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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> a(6);
    for(int i=0; i<6; i++) cin>>a[i];

    double ans = 0;
    for(int i=a[0]; i<=a[1]; i++){
        double A = 1. / (a[1] - a[0] + 1);
        double B = 1. * (max(0, a[3] - max((i + 1), a[2]) + 1)) / (a[3] - a[2] + 1);
        double C = 1. * (max(0, a[5] - max((i + 1), a[4]) + 1)) / (a[5] - a[4] + 1);

        ans += A * B * C;
    }

    printf("%.10f\n", ans);

    return 0;
}