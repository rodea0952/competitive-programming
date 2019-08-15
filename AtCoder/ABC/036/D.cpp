#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

vector<vector<int>> adj(100010);
ll f[100010], g[100010];

void dfs(int v, int pv){ // vは始点となる頂点、pvは頂点vの親
    ll product1=1, product2=1;

    for(auto i : adj[v]){
        if(i == pv) continue; // 子から親への遷移を防ぐ
        
        dfs(i, v); // 子へとdfs
        product1*=f[i];
        product1%=MOD;
        product2*=g[i];
        product2%=MOD;        
    }
    g[v]=product1;
    f[v]=(g[v]+product2)%MOD;
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    dfs(0, -1); // 木の根を0とし、頂点の番号として使われていないものをpvとして探索

    cout << f[0] << endl;
}