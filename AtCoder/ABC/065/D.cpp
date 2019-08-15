#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int par[100010];
int ranks[100010];

void init(int n){
    for(int i=0; i<n; i++){
        par[i]=i;
        ranks[i]=0;
    }
}

int find(int x){
    if(par[x] == x){
        return x;
    }
    else{
        return par[x]=find(par[x]);
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

void unite(int x, int y){
    x=find(x);
    y=find(y);
    if(x == y) return;

    if(ranks[x] < ranks[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
    }
    
    if(ranks[x] == ranks[y]){
        ranks[x]++;
    }
}

int kruskal(int n, vector<T> edge){
    sort(edge.begin(), edge.end());
    init(n);
    int res=0;
    for(int i=0; i<2*n-2; i++){
        int cost, cv, nv;
        tie(cost, cv, nv)=edge[i];
        if(!same(cv, nv)){
            unite(cv, nv);
            res+=cost;
        }
    }
    return res;
}

int main(){
    int n; cin>>n;
    vector<P> xsort(n), ysort(n);
    vector<T> edge(2*n-2);
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        xsort[i]=P(x, i);
        ysort[i]=P(y, i);
    }

    sort(xsort.begin(), xsort.end());
    sort(ysort.begin(), ysort.end());

    for(int i=0; i<n-1; i++){
        int cx, cv, nx, nv;
        tie(cx, cv)=xsort[i];
        tie(nx, nv)=xsort[i+1];
        int cost=abs(nx-cx);
        edge[i]=T(cost, cv, nv);
    }
    for(int i=0; i<n-1; i++){
        int cy, cv, ny, nv;
        tie(cy, cv)=ysort[i];
        tie(ny, nv)=ysort[i+1];
        int cost=abs(ny-cy);
        edge[i+n-1]=T(cost, cv, nv);
    }

    cout << kruskal(n, edge) << endl;
}