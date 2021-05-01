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

// ラジアン -> 角度
double todeg(double ang){
    return ang * 180 / pi;
}

double calc_deg(ll ax, ll ay, ll cx, ll cy){
    ll bx = ax, by = -1;
    double A = sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
    double B = sqrt((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy));
    double C = ay - by;
    double theta = todeg(acos((B * B + C * C - A * A) / 2 / B / C));
    return theta;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> x(n), y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];

    // 点 i に対する点 j の角度を求める
    vector<vector<double>> degree(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            double theta = calc_deg(x[i], y[i], x[j], y[j]);
            if(x[i] < x[j]) theta = 360 - theta;
            degree[i].emplace_back(theta);
            degree[i].emplace_back(theta + 360.0);
        }
        sort(all(degree[i]));
    }
    
    double ans = 0.0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            double theta = calc_deg(x[i], y[i], x[j], y[j]);
            if(x[i] < x[j]) theta = 360 - theta;
            auto itr = lower_bound(all(degree[i]), theta + 180.0);
            chmax(ans, min(*itr - theta, 360 - (*itr - theta)));
            itr--;
            chmax(ans, min(*itr - theta, 360 - (*itr - theta)));
        }
    }

    printf("%.10f\n", ans);

    return 0;
}