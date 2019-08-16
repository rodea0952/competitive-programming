int par[MAX_N];
int ranks[MAX_N];
int ufSize;

void init(int n){
    ufSize = n;
    for(int i=0; i<n; i++){
        par[i] = i;
        ranks[i] = 0;
    }
}

int find(int x){
    if(par[x] == x){
        return x;
    }
    else{
        return par[x] = find(par[x]);
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    ufSize--;

    if(ranks[x] < ranks[y]){
        par[x] = y;
    }
    else{
        par[y] = x;
    }
    
    if(ranks[x] == ranks[y]){
        ranks[x]++;
    }
}

int kruskal(int n){
    sort(edge.begin(), edge.end());
    init(n);
    int res = 0;
    for(int i=0; i<edge.size(); i++){
        int cost, cv, nv;
        tie(cost, cv, nv) = edge[i];
        if(!same(cv, nv)){
            unite(cv, nv);
            res += cost;
        }
    }

    return res;
}