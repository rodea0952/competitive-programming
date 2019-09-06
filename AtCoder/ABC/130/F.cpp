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

int n;
vector<double> x(100010), y(100010);
vector<char> d(100010);

double solve(double time){
    double xmax = -INF;
    double xmin = INF;
    double ymax = -INF;
    double ymin = INF;

    for(int i=0; i<n; i++){
        if(d[i] == 'R'){
            chmax(xmax, x[i] + time);
            chmin(xmin, x[i] + time);
            chmax(ymax, y[i]);
            chmin(ymin, y[i]);
        }
        else if(d[i] == 'L'){
            chmax(xmax, x[i] - time);
            chmin(xmin, x[i] - time);
            chmax(ymax, y[i]);
            chmin(ymin, y[i]);
        }
        else if(d[i] == 'U'){
            chmax(ymax, y[i] + time);
            chmin(ymin, y[i] + time);
            chmax(xmax, x[i]);
            chmin(xmin, x[i]);
        }
        else{
            chmax(ymax, y[i] - time);
            chmin(ymin, y[i] - time);
            chmax(xmax, x[i]);
            chmin(xmin, x[i]);
        }
    }

    return (xmax - xmin) * (ymax - ymin);
}

double ternary_search(double l, double r){
    double left = l, right = r;

    // calculate minimum value
    for(int i=0; i<500; i++){
        if(solve((left * 2 + right) / 3) < solve((left + right * 2) / 3)){
            right = (left + right * 2) / 3;
        }
        else{
            left = (left * 2 + right) / 3;
        }
    }

    return solve((left + right) * 0.5);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++) cin>>x[i]>>y[i]>>d[i];

    double ans = ternary_search(0, 1e9);

    printf("%.10f\n", ans);
}