int V;
vector<vector<int>> G(MAX_V);
vector<vector<int>> rG(MAX_V);
vector<int> vs;
vector<bool> used(MAX_V);
vector<int> cmp(MAX_V);

void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v] = true;
    
    for(int i=0; i<G[v].size(); i++){
        if(!used[G[v][i]]) dfs(G[v][i]);
    }

    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;

    for(int i=0; i<rG[v].size(); i++){
        if(!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
}

int scc(){
    for(int i=0; i<MAX_V; i++) used[i] = false;
    vs.clear();
    
    for(int v=0; v<V; v++){
        if(!used[v]) dfs(v);
    }

    for(int i=0; i<MAX_V; i++) used[i] = false;
    int k = 0;

    for(int i=vs.size()-1; i>=0; i--){
        if(!used[vs[i]]) rdfs(vs[i], k++);
    }

    return k;
}