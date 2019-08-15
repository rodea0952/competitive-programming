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
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

const int MAX_N=100010;

int par[MAX_N];
int ranks[MAX_N];
ll usize[MAX_N];
int size_UF;

void init(int n){
    size_UF=n;
    for(int i=0; i<n; i++){
        par[i]=i;
        ranks[i]=0;
        usize[i]=1;
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
    size_UF--;

    int tmp=usize[x];
    usize[x]+=usize[y];
    usize[y]+=tmp;

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

int main(){
    ll n, m; cin>>n>>m;
    init(n);
    vector<int> a(m), b(m);
    for(int i=0; i<m; i++){
        cin>>a[i]>>b[i];
        a[i]--, b[i]--;
    }

    ll sum=n*(n-1)/2;
    vector<ll> ans(m);
    for(int i=m-1; i>=0; i--){
        ans[i]=sum;
        //cout << usize[find(a[i])] << " " << usize[find(b[i])] << endl;
        if(same(a[i], b[i]));
        else sum-=(usize[find(a[i])]*usize[find(b[i])]);
        unite(a[i], b[i]);
    }

    for(int i=0; i<m; i++){
        if(ans[i]<=0) cout << 0 << endl;
        else cout << ans[i] << endl;
    }
}