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

struct LCA{
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
};

vector<vector<int>> need(100010);
vector<int> dist(100010);
vector<int> cur_num(100010), cur_sum(100010);
map<P, int> res_num, res_sum;

void dfs(int cv, int pv, vector<vector<T>> &edges){
    for(auto c : need[cv]){
        res_num[P(cv, c)] = cur_num[c];
        res_sum[P(cv, c)] = cur_sum[c];
    }

    for(auto nxt : edges[cv]){
        int nv, c, d;
        tie(nv, c, d) = nxt;
        if(pv == nv) continue;

        dist[nv] = dist[cv] + d;
        cur_num[c]++;
        cur_sum[c] += d;
        dfs(nv, cv, edges);
        cur_num[c]--;
        cur_sum[c] -= d;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q; cin>>n>>q;
    vector<vector<T>> edges(n);
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        int a, b, c, d; cin>>a>>b>>c>>d;
        a--, b--, c--;
        edges[a].emplace_back(b, c, d);
        edges[b].emplace_back(a, c, d);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    LCA lca;
    lca.init(n, G);

    vector<int> x(q), y(q), u(q), v(q), l(q);
    for(int i=0; i<q; i++){
        cin>>x[i]>>y[i]>>u[i]>>v[i];
        x[i]--, u[i]--, v[i]--;
        l[i] = lca.calc_lca(u[i], v[i]);

        need[u[i]].emplace_back(x[i]);
        need[v[i]].emplace_back(x[i]);
        need[l[i]].emplace_back(x[i]);        
    }

    dfs(0, -1, edges);

    for(int i=0; i<q; i++){
        int du = dist[u[i]] - res_sum[P(u[i], x[i])] + res_num[P(u[i], x[i])] * y[i];
        int dv = dist[v[i]] - res_sum[P(v[i], x[i])] + res_num[P(v[i], x[i])] * y[i];
        int dl = dist[l[i]] - res_sum[P(l[i], x[i])] + res_num[P(l[i], x[i])] * y[i];
        int ans = du + dv - dl * 2;
        cout << ans << endl;
    }

    return 0;
}