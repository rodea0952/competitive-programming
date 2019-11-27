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

    int n, l; cin>>n>>l;
    int vs, ds; cin>>vs>>ds;
    vector<T> v;
    v.emplace_back(0, vs, ds);
    for(int i=0; i<n; i++){
        int xi, vi, di; cin>>xi>>vi>>di;
        v.emplace_back(xi, vi, di);
    }
    v.emplace_back(l, 0, 0);
    
    sort(v.begin(), v.end());

    int sz = v.size();
    vector<double> dp(sz, INF);
    dp[0] = 0;
    for(int i=0; i<sz; i++){
        int px, pv, pd;
        tie(px, pv, pd) = v[i];
        for(int j=i+1; j<sz; j++){
            int cx, cv, cd;
            tie(cx, cv, cd) = v[j];

            int dist = cx - px;

            if(pd < dist) break;

            chmin(dp[j], 1. * dist / pv + dp[i]);
        }
    }

    if(dp[sz-1] == INF){
        cout << "impossible" << endl;
    }
    else{
        printf("%.10f\n", dp[sz-1]);
    }

    return 0;
}