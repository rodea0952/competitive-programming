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

double solve_left(int a, int x, int r, int h){
    double allS = pi * r * r * h / 3;
    double midr = 1. * r * (h - a + x) / h;
    double rightS = pi * midr * midr * (h - a + x) / 3;
    double leftS = allS - rightS;
    return leftS;
}

double solve_right(int b, int x, int r, int h){
    double allS = pi * r * r * h / 3;
    double righth = x + h - b;
    double midr = righth * r / h;
    double rightS = pi * midr * midr * righth / 3;
    return rightS;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q; cin>>n>>q;
    vector<int> x(n), r(n), h(n);
    for(int i=0; i<n; i++) cin>>x[i]>>r[i]>>h[i];

    while(q--){
        int a, b; cin>>a>>b;
        double ans = 0;
        for(int i=0; i<n; i++){
            double cur_ans = pi * r[i] * r[i] * h[i] / 3;
            int lb = x[i], ub = x[i] + h[i];
            if(ub <= a || b <= lb) continue;

            if(lb <= a) cur_ans -= solve_left(a, x[i], r[i], h[i]);
            if(b <= ub) cur_ans -= solve_right(b, x[i], r[i], h[i]);

            ans += cur_ans;
        }

        printf("%.5f\n", ans);
    }

    return 0;
}