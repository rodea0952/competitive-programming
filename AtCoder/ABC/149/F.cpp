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

vector<int> children_sum(200010);
ll ans = 0;

ll modpow(ll a, ll b){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = modpow(a, b/2) % MOD;
        return (d * d) % MOD;
    }
    else{
        return (a * modpow(a, b-1)) % MOD;
    }
}

void dfs(int cv, int pv, vector<vector<int>> &G){
    int children_cnt = 1;
    vector<int> v;
    for(auto nv : G[cv]){
        if(nv == pv) continue;
        dfs(nv, cv, G);
        children_cnt += children_sum[nv];
        v.emplace_back(children_sum[nv]);
    }

    v.emplace_back(n - children_cnt);

    // 2^(N-1) - 1 - Σ(2^(v[i]) - 1)
    ll sum = 0;
    for(auto i : v){
        sum += modpow(2, i) - 1;
        sum %= MOD;
    }

    ans += modpow(2, n - 1) - 1 - sum + MOD;
    ans %= MOD;

    children_sum[cv] = children_cnt;
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    dfs(0, -1, G);

    ll all = modpow(2, n);

    cout << ans * modpow(all, MOD - 2) % MOD << endl;

    return 0;
}