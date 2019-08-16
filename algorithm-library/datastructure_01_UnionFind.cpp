int par[MAX_N];
int ranks[MAX_N];
int size[MAX_N];
int uf_size;

void init(int n){
    uf_size = n;
    for(int i=0; i<n; i++){
        par[i] = i;
        ranks[i] = 0;
        size[i] = 1;
    }
    
    return ;
}

int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

bool same(int x, int y){
    return find(x) == find(y);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;
    uf_size--;

    if(ranks[x] < ranks[y]) swap(x, y);
    if(ranks[x] == ranks[y]) ranks[x]++;
    par[y] = x;
    size[x] += size[y];
    return ;
}