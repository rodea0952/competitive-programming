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

class LCA{
public:
    static const int MAX_LOG_V = 30;
    vector<int> parent[MAX_LOG_V]; // 親を2^k回辿って到達する頂点（根を通り過ぎる場合は-1）
    vector<int> depth;

    void init(int V, vector<vector<int>> &G){
        int root = 0;
        for(int i=0; i<MAX_LOG_V; i++) parent[i].resize(V);
        depth.resize(V, -1);

        dfs(root, -1, 0, G);
        
        for(int k=0; k+1<MAX_LOG_V; k++){
            for(int v=0; v<V; v++){
                if(parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }

    void dfs(int v, int p, int d, vector<vector<int>> &G){
        parent[0][v] = p;
        depth[v] = d;
        for(int i=0; i<G[v].size(); i++){
            if(G[v][i] != p) dfs(G[v][i], v, d+1, G);
        }
    }

    int calc_lca(int u, int v){
        // uとvの深さが同じになるまで親を辿る
        if(depth[u] > depth[v]) swap(u, v);

        for(int k=0; k<MAX_LOG_V; k++){
            if((depth[v] - depth[u]) >> k & 1){
                v = parent[k][v];
            }
        }

        if(u == v) return u;

        for(int k=MAX_LOG_V-1; k>=0; k--){
            if(parent[k][u] != parent[k][v]){
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    int dist(int u, int v){
        return depth[u] + depth[v] - 2 * depth[calc_lca(u, v)];
    }

    bool is_in(int u, int v, int a){
        return (dist(u, a) + dist(a, v) == dist(u, v));
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>> G(n);
    vector<int> a(n-1), b(n-1);
    for(int i=0; i<n-1; i++){
        cin>>a[i]>>b[i];
        a[i]--, b[i]--;
        G[a[i]].emplace_back(b[i]);
        G[b[i]].emplace_back(a[i]);
    }

    LCA lca;
    lca.init(n, G);

    int m; cin>>m;
    vector<ll> cons(m, 0);
    // 白くなるべき辺を 1 にする、64 bit で表現
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        for(int j=0; j<n-1; j++){
            if(lca.is_in(u, v, a[j]) && lca.is_in(u, v, b[j])){
                cons[i] |= (1LL << j);
            }
        }
    }

    ll ans = 0;
    for(int bit=0; bit<(1LL<<m); bit++){
        ll cur = 0;
        for(int i=0; i<m; i++){
            if(bit & (1LL << i)){
                cur |= cons[i];
            }
        }

        int need_white = __builtin_popcountll(cur);
        ll sum = (1LL << (n - 1 - need_white));

        if(__builtin_popcount(bit) % 2) ans -= sum;
        else ans += sum;
    }

    cout << ans << endl;

    return 0;
}