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

template <typename flow_t, typename cost_t>
struct PrimalDual{
    const cost_t INF;

    struct edge{
        int to;
        flow_t cap;
        cost_t cost;
        int rev;
        bool is_rev;
    };

    vector<vector<edge>> G;
    vector<cost_t> potential, min_cost; // potential[v]:= s-v間の最短距離
    vector<int> prevv, preve;           // 直前の頂点と辺 

    PrimalDual(int V) : G(V), INF(numeric_limits<cost_t>::max()) {}

    void add_edge(int from, int to, flow_t cap, cost_t cost){
        G[from].emplace_back((edge){to, cap, cost, (int)G[to].size(), false});
        G[to].emplace_back((edge){from, 0, -cost, (int)G[from].size()-1, true});
    }

    // s から t への流量 f の最小費用流を求める
    // 流せない場合は -1 を返す
    cost_t min_cost_flow(int s, int t, flow_t f){
        int V = G.size();
        cost_t ret = 0;
        using Pci = pair<cost_t, int>;
        priority_queue<Pci, vector<Pci>, greater<Pci>> que;
        potential.assign(V, 0);
        prevv.assign(V, -1);
        preve.assign(V, -1);

        while(0 < f){
            min_cost.assign(V, INF);
            que.emplace(0, s);
            min_cost[s] = 0;
            while(que.size()){
                cost_t ccost; int cv; tie(ccost, cv) = que.top(); que.pop();
                if(min_cost[cv] < ccost) continue;
                for(int i=0; i<G[cv].size(); i++){
                    edge &e = G[cv][i];
                    cost_t ncost = min_cost[cv] + e.cost + potential[cv] - potential[e.to];
                    if(0 < e.cap && ncost < min_cost[e.to]){
                        min_cost[e.to] = ncost;
                        prevv[e.to] = cv, preve[e.to] = i;
                        que.emplace(min_cost[e.to], e.to);
                    }
                }
            }

            // これ以上流せない
            if(min_cost[t] == INF) return -1;
            
            for(int v=0; v<V; v++) potential[v] += min_cost[v];
            
            // s-t 間最短路に沿って目一杯流す
            flow_t addflow = f;
            for(int v=t; v!=s; v=prevv[v]){
                addflow = min(addflow, G[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for(int v=t; v!=s; v=prevv[v]){
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= addflow;
                G[v][e.rev].cap += addflow;
            }
        }

        return ret;
    }

    void output(){
        for(int i=0; i<G.size(); i++){
            for(auto &e:G[i]){
                if(e.is_rev) continue;
                auto &rev_e = G[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl; 
            }
        }
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<string> s(n);
    for(int i=0; i<n; i++) cin>>s[i];

    map<P, int> piece;
    int idx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j] == 'o'){
                piece[P(i, j)] = idx++;
            }
        }
    }

    int L = piece.size(), R = n * m;
    vector<vector<int>> dist(L, vector<int>(R, -1));
    for(auto cp : piece){
        int i = cp.second;
        int y = cp.first.first, x = cp.first.second;
        queue<P> que;
        que.emplace(y, x);
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[y][x] = 0;
        while(que.size()){
            int cy, cx; tie(cy, cx) = que.front(); que.pop();
            for(int j=0; j<2; j++){
                int ny = cy + dy[j], nx = cx + dx[j];
                if(!(ny < n && nx < m)) continue;
                if(s[ny][nx] == '#') continue;
                if(dp[ny][nx] != -1) continue;
                dp[ny][nx] = dp[cy][cx] + 1;
                que.emplace(ny, nx);
            }
        }

        for(int h=0; h<n; h++){
            for(int w=0; w<m; w++){
                dist[i][h * m + w] = dp[h][w];
            }
        }
    }

    PrimalDual<int, int> G(L + R + 2);
    int st = L + R, gl = L + R + 1;
    for(int l=0; l<L; l++) G.add_edge(st, l, 1, 0);
    for(int r=0; r<R; r++) G.add_edge(L + r, gl, 1, 0);

    for(int l=0; l<L; l++){
        for(int r=0; r<R; r++){
            if(dist[l][r] == -1) continue;
            G.add_edge(l, L + r, 1, -dist[l][r]);
        }
    }

    int ans = G.min_cost_flow(st, gl, L);

    cout << -ans << endl;

    return 0;
}