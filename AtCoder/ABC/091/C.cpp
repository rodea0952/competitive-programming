#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int V;
int match[MAX_V];
bool used[MAX_V];
vector<vector<int>> g(MAX_V);
bool dfs(int v){
    used[v]=true;
    for(int i=0; i<g[v].size(); i++){
        int u=g[v][i], w=match[u];

        if(w < 0 || (!used[w] && dfs(w))){
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}

int bipartite_matching(){
    int res=0;
    memset(match, -1, sizeof(match));

    for(int v=0; v<n; v++){
        if(match[v] < 0){
            memset(used, false, sizeof(used));
            if(dfs(v)){
                res++;
            }
        }
    }
    return res;
}

int main(){
    cin>>n;
    vector<int> a(n), b(n), c(n), d(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];
    for(int i=0; i<n; i++) cin>>c[i]>>d[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i] < c[j] && b[i] < d[j]){
                g[i].push_back(j+1000);
                g[j+1000].push_back(i);
            }
        }
    }

    cout << bipartite_matching() << endl;;
}