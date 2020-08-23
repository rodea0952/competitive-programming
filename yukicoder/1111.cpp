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

    int n, m, k; cin>>n>>m>>k;
    vector<vector<P>> G(310);
    for(int i=0; i<m; i++){
        int p, q, c; cin>>p>>q>>c;
        p--, q--;
        G[p].emplace_back(q, c);
    }

    vector<vector<vector<ll>>> dp(310, vector<vector<ll>>(310, vector<ll>(310, 0)));
    for(int i=0; i<=300; i++) dp[0][0][i] = 1;

    for(int i=0; i+1<n; i++){
        for(int j=0; j<=k; j++){
            for(int cv=0; cv<=300; cv++){
                for(auto nxt : G[cv]){
                    int nv = nxt.first, cost = nxt.second;
                    if(k < j + cost) continue;
                    dp[i+1][j+cost][nv] += dp[i][j][cv];
                    dp[i+1][j+cost][nv] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    for(int i=0; i<=300; i++){
        ans += dp[n-1][k][i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}