#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
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

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

const int MAX_N = 200010;

int par[MAX_N];
int ranks[MAX_N];
int size_UF;

vector<P> edge;
vector<vector<int>> g(MAX_N);
vector<int> p(MAX_N, -1);
vector<bool> visited(MAX_N);

void init(int n){
    size_UF = n;
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
    size_UF--;

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

void kruskal(int n){
    init(n);

    for(int i=0; i<edge.size(); i++){
        int cv, nv;
        tie(cv, nv) = edge[i];
        if(!same(cv, nv)){
            unite(cv, nv);
            g[cv].eb(nv);
            g[nv].eb(cv);
        }
    }
}

bool dfs(int cv){
    visited[cv] = true;
    vector<int> child;
    for(auto nv:g[cv]){
        if(visited[nv]) continue;
        if(dfs(nv)) child.eb(nv);
    }

    int n = child.size();

    if(n == 1){
        p[cv] = child[0];
        p[child[0]] = cv;
        return false;
    }

    for(int i=0; i<n; i++){
        int from = child[i];
        int to = child[(i + 1) % n];
        p[from] = to;
    }

    return true;
}

int main(){
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edge.eb(P(u, v));
    }

    kruskal(n);

    dfs(0);

    if(p[0] == -1){
        int nv = g[0][0];
        int np = p[g[0][0]];

        p[0] = np;
        p[nv] = 0;
    }

    for(int i=0; i<n; i++){
        cout << p[i] + 1 << " \n"[i == n-1];
    }
}