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

// 辺を表す構造体（行き先、容量、逆辺の場所）
struct edge{
    int to, cap, rev;
};

vector<vector<edge>> G(MAX_V); 
int level[MAX_V]; // sからの距離
int iter[MAX_V];  // どこまで調べ終わったか

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap){
    G[from].eb((edge){to, cap, (int)G[to].size()});
    G[to].eb((edge){from, 0, (int)(G[from].size()-1)});
}

// sからの最短距離を計算する
void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);

    while(que.size()){
        int v = que.front(); que.pop();
        for(int i=0; i<G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

// 増加パスを探す
int dfs(int v, int t, int f){
    if(v == t) return f;
    for(int &i=iter[v]; i<G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }

    return 0;
}

// sからtへの最大流を求める
int max_flow(int s, int t){
    int flow = 0;
    for(;;){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, 1e9)) > 0){
            flow += f;
        }
    }
}

int main(){
    int v, e; cin>>v>>e;
    for(int i=0; i<e; i++){
        int s, t, c; cin>>s>>t>>c;
        add_edge(s, t, c);
    }

    cout << max_flow(0, v - 1) << endl;

    cout << endl;
    for(int i=0; i<v; i++){
        for(auto j:G[i]){
            cout << "from " << i << " to " << j.to << " cap " << j.cap << " rev " << j.rev << endl;
        }
    }
}