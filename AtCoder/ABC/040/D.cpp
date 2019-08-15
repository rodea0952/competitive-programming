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
int urank[100010];

void init(int n){
    for(int i=0; i<n; i++){
        par[i]=i;
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

    if(urank[x] < urank[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
    }
    
    if(urank[x] == urank[y]){
        urank[x]++;
    }
}

int main(){
    int n, m; cin>>n>>m;
    init(n);
    vector<vector<int>> g(100010);
    vector<int> a(m), b(m), y(m);
    vector<T> edge(m);
    for(int i=0; i<m; i++){
        cin>>a[i]>>b[i]>>y[i];
        a[i]--, b[i]--;
        edge[i]=T(y[i], a[i], b[i]);
    }

    sort(edge.begin(), edge.end(), greater<T>());

    int q; cin>>q;
    vector<int> v(q), w(q);
    vector<T> qu(q);
    for(int i=0; i<q; i++){
        cin>>v[i]>>w[i];
        v[i]--;
        qu[i]=T(w[i], v[i], i);
    }

    sort(qu.begin(), qu.end(), greater<T>());

    vector<int> S(100010, 1);
    int qcnt=0, ecnt=0;
    int qw, qv, qi;
    int va, vb, year;
    vector<int> ans(q);
    for(int i=200000; i>=0; i--){
        tie(qw, qv, qi)=qu[qcnt];
        while(qw==i){
            ans[qi]=S[find(qv)];
            qcnt++;
            if(qcnt==q) goto END;
            else tie(qw, qv, qi)=qu[qcnt];
        }

        tie(year, va, vb)=edge[ecnt];
        while(ecnt<m && year==i){
            if(find(va)!=find(vb)){
                int save=S[find(va)];
                S[find(va)]=S[find(va)]+S[find(vb)];
                S[find(vb)]=save+S[find(vb)];
                unite(va, vb);
            }
            ecnt++;
            if(ecnt<m) tie(year, va, vb)=edge[ecnt];
        }
    }
    
    END:;

    for(int i=0; i<q; i++) cout << ans[i] << endl;
}