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

constexpr int MOD = 998244353;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct mint{
    ll x;
    constexpr mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}
    constexpr mint operator-() const{
        return mint(-x);
    }
    constexpr mint& operator+=(const mint& a){
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    constexpr mint& operator-=(const mint& a){
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    constexpr mint& operator*=(const mint& a){
        (x *= a.x) %= MOD;
        return *this;
    }
    constexpr mint operator+(const mint& a) const{
        mint res(*this);
        return res += a;
    }
    constexpr mint operator-(const mint& a) const{
        mint res(*this);
        return res -= a;
    }
    constexpr mint operator*(const mint& a) const{
        mint res(*this);
        return res *= a;
    }
    constexpr mint pow(ll t) const{
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime MOD
    constexpr mint inv() const{
        return pow(MOD - 2);
    }
    constexpr mint& operator/=(const mint& a){
        return (*this) *= a.inv();
    }
    constexpr mint operator/(const mint& a) const{
        mint res(*this);
        return res /= a;
    }
};
istream& operator>>(istream& is, mint& a) {return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) {return os << a.x;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m);
    for(int i=0; i<m; i++) cin >> a[i], a[i]--;
    vector<vector<int>> G(n);
    map<pair<int, int>, int> edge_idx;
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v; u--, v--;
        if(u > v) swap(u, v);
        edge_idx[make_pair(u, v)] = i;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<int> edge_cnt(n-1, 0);
    for(int i=0; i+1<m; i++){
        vector<int> pre(n, -1);
        pre[a[i]] = -2;
        queue<int> que;
        que.emplace(a[i]);
        while(que.size()){
            int cv = que.front(); que.pop();
            for(auto nv : G[cv]){
                if(pre[nv] == -1){
                    pre[nv] = cv;
                    que.emplace(nv);
                }
            }
        }

        int cv = a[i+1];
        while(pre[cv] != -2){
            int u = pre[cv], v = cv;
            if(u > v) swap(u, v);
            edge_cnt[edge_idx[make_pair(u, v)]]++;
            cv = pre[cv];
        }
    }

    int edge_sum = accumulate(all(edge_cnt), 0);

    if((edge_sum + k) % 2){
        cout << 0 << endl;
        return 0;
    }

    int target = (0 < k ? (edge_sum + k) / 2 : (edge_sum - k) / 2);
    vector<vector<mint>> dp(n, vector<mint>(target+1, 0));
    dp[0][0] = 1;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<=target; j++){
            dp[i+1][j] += dp[i][j];
            if(j >= edge_cnt[i]) dp[i+1][j] += dp[i][j-edge_cnt[i]];
        }
    }

    cout << dp[n-1][target] << endl;

    return 0;
}