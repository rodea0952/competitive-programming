#include <bits/stdc++.h>
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

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

const int MAX_V=100010;
const int MAX_LOG_V=110;

vector<vector<int>> g(MAX_V);
const int root=0;

int parent[MAX_LOG_V][MAX_V]; // 親を2^k回辿って到達する頂点（根を通り過ぎる場合は-1）
int depth[MAX_V];             // 根からの深さ

void dfs(int v, int p, int d){
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0; i<g[v].size(); i++){
        if(g[v][i]!=p) dfs(g[v][i], v, d+1);
    }
}

void init(int V){
    dfs(root, -1, 0);
    
    for(int k=0; k+1<MAX_LOG_V; k++){
        for(int v=0; v<V; v++){
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    // uとvの深さが同じになるまで親を辿る
    if(depth[u]>depth[v]) swap(u, v);

    for(int k=0; k<MAX_LOG_V; k++){
        if((depth[v]-depth[u])>>k & 1){
            v=parent[k][v];
        }
    }

    if(u==v) return u;

    for(int k=MAX_LOG_V-1; k>=0; k--){
        if(parent[k][u]!=parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n-1; i++){
        int x, y; cin>>x>>y;
        x--, y--;
        g[x].eb(y);
        g[y].eb(x);
    }

    init(n);
    
    int q; cin>>q;
    while(q--){
        int a, b; cin>>a>>b;
        a--, b--;
        int dist_a=depth[a]-depth[lca(a, b)];
        int dist_b=depth[b]-depth[lca(a, b)];
        cout << dist_a+dist_b+1 << endl;
    }
}