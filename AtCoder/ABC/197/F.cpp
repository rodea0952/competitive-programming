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

    int n, m; cin>>n>>m;
    vector<vector<P>> G(n);
    for(int i=0; i<m; i++){
        int a, b; char c; cin>>a>>b>>c; a--, b--;
        G[a].emplace_back(b, c - 'a');
        G[b].emplace_back(a, c - 'a');
    }

    // dp[i][j] := 頂点 i と頂点 j にいるときの題意を満たす最小コスト
    vector<vector<int>> dp(n, vector<int>(n, inf));
    dp[0][n - 1] = 0;
    queue<P> que;
    que.emplace(0, n - 1);
    while(que.size()){
        int ca, cb; tie(ca, cb) = que.front(); que.pop();
        for(auto na : G[ca]){
            for(auto nb : G[cb]){
                if(na.second != nb.second) continue;
                if(dp[na.first][nb.first] != inf) continue;
                dp[na.first][nb.first] = dp[ca][cb] + 1;
                que.emplace(na.first, nb.first);
            }
        }
    }

    int ans = inf;
    for(int i=0; i<n; i++){
        chmin(ans, dp[i][i] * 2);
        for(auto j : G[i]){
            chmin(ans, dp[i][j.first] * 2 + 1);
        }
    }

    cout << (ans == inf ? -1 : ans) << endl;

    return 0;
}