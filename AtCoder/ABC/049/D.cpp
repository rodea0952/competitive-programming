#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

class UnionFind{
private:
    //親と木の深さ
    int par[200010];
    int rank[200010];
    
public:
    void init(int n);
    int find(int x);
    void unite(int x, int y);
};

//要素数nで初期化
void UnionFind::init(int n){ 
	for(int i=0; i<n; i++){
		par[i]=i;
        rank[i]=0;
	}
}

//要素xの親を求める
int UnionFind::find(int x){
	if(par[x] == x){
		return x;
	}
	else{ 
		return par[x]=find(par[x]);
	}
}

//xとyの属する集合を併合
void UnionFind::unite(int x, int y){ 
	x=find(x);
	y=find(y);
	if(x == y) return;

	if(rank[x] < rank[y]){
		par[x]=y;
	}
	else{
		par[y]=x;
	}
	if(rank[x] == rank[y]){
		rank[x]++;
	}
}

map<P, int> mp;
UnionFind a, b;

int main(){
    int n, k, l; cin>>n>>k>>l;
    a.init(n), b.init(n);

    for(int i=0; i<k; i++){
        int p, q; cin>>p>>q;
        p--, q--;
        a.unite(p, q);
    }

    for(int i=0; i<l; i++){
        int r, s; cin>>r>>s;
        r--, s--;
        b.unite(r, s);
    }

    for(int i=0; i<n; i++){
        mp[P(a.find(i), b.find(i))]++;
    }
    for(int i=0; i<n; i++){
        cout << mp[P(a.find(i), b.find(i))] << endl;
    }
}