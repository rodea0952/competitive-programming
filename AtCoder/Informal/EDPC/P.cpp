#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<vector<int>> G(100010);
vector<vector<ll>> dp(100010, vector<ll>(2));

const int W = 0;
const int B = 1;

void dfs(int cv, int parent = -1){
    dp[cv][W] = dp[cv][B] = 1;

    for(auto nv : G[cv]){
        if(nv == parent) continue;

        dfs(nv, cv);
        (dp[cv][W] *= dp[nv][W] + dp[nv][B]) %= MOD;
        (dp[cv][B] *= dp[nv][W]) %= MOD;
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    for(int i=0; i<n-1; i++){
        int x, y; cin>>x>>y;
        x--, y--;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    dfs(0);

    cout << (dp[0][W] + dp[0][B]) % MOD << endl;
}