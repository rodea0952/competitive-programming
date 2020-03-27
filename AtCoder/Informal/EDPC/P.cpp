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

vector<vector<ll>> dp(100010, vector<ll>(2, 1));

void dfs(int cv, int pv, vector<vector<int>> &G){
    vector<int> children;
    for(auto nv : G[cv]){
        if(nv == pv) continue;

        dfs(nv, cv, G);
        children.emplace_back(nv);
    }

    for(auto i : children){
        dp[cv][0] *= (dp[i][0] + dp[i][1]);
        dp[cv][0] %= MOD;
        dp[cv][1] *= dp[i][0];
        dp[cv][1] %= MOD;
    }
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        int x, y; cin>>x>>y;
        x--, y--;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    dfs(0, -1, G);

    cout << (dp[0][0] + dp[0][1]) % MOD << endl;

    return 0;
}