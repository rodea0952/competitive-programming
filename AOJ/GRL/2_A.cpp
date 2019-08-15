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

const int MAX_N = 10010;

vector<T> edge;

int par[MAX_N];
int ranks[MAX_N];
int size_UF;

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

int main(){
    int v, e; cin>>v>>e;
    for(int i=0; i<e; i++){
        int s, t, w; cin>>s>>t>>w;
        edge.push_back(T(w, s, t));
    }

    cout << kruskal(v) << endl;
}