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

vector<int> ans(200010, -1);
vector<int> dp(200010, inf + 10);
void dfs(int cv, int pv, vector<int> &a, vector<vector<int>> &G){
    int idx = lower_bound(dp.begin(), dp.end(), a[cv]) - dp.begin();
    int pre = dp[idx];
    dp[idx] = a[cv];
    ans[cv] = lower_bound(dp.begin(), dp.end(), inf + 10) - dp.begin();
    for(auto nv : G[cv]){
        if(nv == pv) continue;
        dfs(nv, cv, a, G);
    }
    dp[idx] = pre;
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v; u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(0, -1, a, G);

    for(int i=0; i<n; i++){
        cout << ans[i] << endl;
    }

    return 0;
}