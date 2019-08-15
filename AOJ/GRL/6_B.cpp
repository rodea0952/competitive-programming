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
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

const int MAX_V = 110;

struct edge{
    int to, cap, cost, rev;
};

int V;
vector<vector<edge>> G(MAX_V);
int h[MAX_V];                   // ポテンシャル h(v):=(s-v間の最短距離)
int dist[MAX_V];                // 最短距離
int prevv[MAX_V], preve[MAX_V]; //直前の頂点と辺

// fromからtoへ向かう容量cap, コストcostの辺をグラフに追加する
void add_edge(int from, int to, int cap, int cost){
    G[from].eb((edge){to, cap, cost, (int)G[to].size()});
    G[to].eb((edge){from, 0, -cost, (int)(G[from].size()-1)});
}

// sからtへの流量fの最小費用流を求める
// 流せない場合は-1を返す
int min_cost_flow(int s, int t, int f){
    int res = 0;
    fill(h, h+V, 0);
    while(f > 0){ // dijkstra
        priority_queue<P, vector<P>, greater<P>> que;
        fill(dist, dist+V, 1e9);
        dist[s] = 0;
        que.push(P(0, s));
        while(que.size()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(int i=0; i<G[v].size(); i++){
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }

        if(dist[t] == 1e9){ // これ以上流せない
            return -1;
        }
        for(int v=0; v<V; v++){
            h[v] += dist[v];
        }

        // s-t間最短路に沿って目一杯流す
        int d = f;
        for(int v=t; v!=s; v=prevv[v]){
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * h[t];
        for(int v=t; v!=s; v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    
    return res;
}

int main(){
    int e, f; cin>>V>>e>>f;
    for(int i=0; i<e; i++){
        int s, t, c, d; cin>>s>>t>>c>>d;
        add_edge(s, t, c, d);
    }

    cout << min_cost_flow(0, V - 1, f) << endl;
}