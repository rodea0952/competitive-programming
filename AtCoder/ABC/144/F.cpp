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

    int n, m; cin>>n>>m;
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int s, t; cin>>s>>t;
        s--, t--;
        G[s].emplace_back(t);
    }

    vector<double> dp(n, 0);
    for(int cv=n-2; cv>=0; cv--){
        for(auto nv : G[cv]) dp[cv] += dp[nv];
        dp[cv] /= G[cv].size();
        dp[cv] += 1;
    }

    double ans = dp[0];

    for(int cv=0; cv+1<n; cv++){
        auto dp2 = dp;
        for(int i=0; i<=cv; i++) dp2[i] = 0;

        if(2 <= G[cv].size()){
            vector<double> v;
            for(auto nv : G[cv]) v.emplace_back(dp2[nv]);
            sort(v.begin(), v.end());

            for(int i=0; i+1<v.size(); i++) dp2[cv] += v[i];
            dp2[cv] /= (G[cv].size() - 1);
            dp2[cv] += 1;
        }
        else continue;

        for(int i=cv-1; i>=0; i--){
            for(auto nv : G[i]) dp2[i] += dp2[nv];
            dp2[i] /= G[i].size();
            dp2[i] += 1;
        }

        chmin(ans, dp2[0]);
    }

    printf("%.10f\n", ans);

    return 0;
}