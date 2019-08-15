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
typedef tuple<int, int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

const int MAX_N = 200010;

int par[MAX_N];
int ranks[MAX_N];
int ufSize;
set<int> ans;

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

vector<T> edge;

void kruskal(int n){
    sort(edge.begin(), edge.end(), greater<T>());
    init(n);
    int res = 0;
    for(int i=0; i<edge.size(); i++){
        int cost, cv, nv, id;
        tie(cost, cv, nv, id) = edge[i];
        if(!same(cv, nv)){
            ans.insert(id+1);
            unite(cv, nv);
            res += cost;
        }
    }

    for(auto i:ans){
        cout << i << endl;
    }
}

int main(){
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        a--, b--;
        edge.eb(T(c, a, b, i));
    }

    kruskal(n);
}