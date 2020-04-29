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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, V, l; cin>>n>>V>>l;
    vector<int> x(n), v(n), w(n);
    for(int i=0; i<n; i++) cin>>x[i]>>v[i]>>w[i];

    vector<int> xgap(n);
    xgap[0] = x[0];
    for(int i=1; i<n; i++){
        xgap[i] = x[i] - x[i-1];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(V+1, INF));
    dp[0][V] = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<=V; j++){
            if(j + xgap[i] <= V && dp[i][j+xgap[i]] != INF){
                // 補給しない
                chmin(dp[i+1][j], dp[i][j+xgap[i]]);

                // 補給する
                chmin(dp[i+1][min(V, j+v[i])], dp[i][j+xgap[i]] + w[i]);
            }
        }
    }

    ll ans = INF;
    for(int i=0; i<=V; i++){
        if(i + (l - x[n-1]) <= V && dp[n][i+(l-x[n-1])] != INF){
            chmin(ans, dp[n][i+(l-x[n-1])]);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}