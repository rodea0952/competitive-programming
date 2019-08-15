#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100010;
const int MAX_LOG_V = 110;

vector<vector<int>> G(MAX_V);
int root;

int parent[MAX_LOG_V][MAX_V]; // 親を2^k回辿って到達する頂点（根を通り過ぎる場合は-1）
int depth[MAX_V];             // 根からの深さ

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int i=0; i<G[v].size(); i++){
        if(G[v][i] != p) dfs(G[v][i], v, d+1);
    }
}

void init(int V){
    dfs(root, -1, 0);
    
    for(int k=0; k+1<MAX_LOG_V; k++){
        for(int v=0; v<V; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
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

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        for(int j=0; j<k; j++){
            int c; cin>>c;
            G[i].emplace_back(c);
            G[c].emplace_back(i);
        }
    }

    init(n);

    int q; cin>>q;
    while(q--){
        int u, v; cin>>u>>v;
        cout << lca(u, v) << endl;
    }
}