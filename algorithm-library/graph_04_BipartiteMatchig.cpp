int V;
int match[MAX_V];
bool used[MAX_V];
vector<vector<int>> g(MAX_V);
bool dfs(int v){
    used[v] = true;
    for(int i=0; i<g[v].size(); i++){
        int u = g[v][i], w = match[u];

        if(w < 0 || (!used[w] && dfs(w))){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    
    return false;
}

int bipartite_matching(){
    int res = 0;
    memset(match, -1, sizeof(match));

    for(int v=0; v<V; v++){
        if(match[v] < 0){
            memset(used, false, sizeof(used));
            if(dfs(v)){
                res++;
            }
        }
    }

    return res;
}