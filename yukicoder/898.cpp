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

vector<ll> sum(100010);
void calc_sum_dfs(int cv, int pv, vector<vector<P>> &G){
    for(auto nxt : G[cv]){
        int nv, cost;
        tie(nv, cost) = nxt;

        if(nv == pv) continue;

        sum[nv] = sum[cv] + cost;
        calc_sum_dfs(nv, cv, G);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> u(n-1), v(n-1), w(n-1);
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        cin>>u[i]>>v[i]>>w[i];
        G[u[i]].emplace_back(v[i]);
        G[v[i]].emplace_back(u[i]);
    }

    LCA lca;
    lca.init(n, G);

    vector<vector<P>> G2(n);
    for(int i=0; i<n-1; i++){
        G2[u[i]].emplace_back(v[i], w[i]);
        G2[v[i]].emplace_back(u[i], w[i]);
    }

    calc_sum_dfs(0, -1, G2);

    int q; cin>>q;
    while(q--){
        int x, y, z; cin>>x>>y>>z;
        ll cur1 = sum[x] + sum[y] - 2 * sum[lca.calc_lca(x, y)];
        ll cur2 = sum[x] + sum[z] - 2 * sum[lca.calc_lca(x, z)];
        ll cur3 = sum[y] + sum[z] - 2 * sum[lca.calc_lca(y, z)];
        cout << (cur1 + cur2 + cur3) / 2 << endl;
    }

    return 0;
}