#pragma GCC optimize("O3")
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
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<ll, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct UnionFind{
    vector<int> par;
    vector<int> rank;
    vector<int> sz;
    int uf_size;

    UnionFind(int n){
        par.resize(n);
        rank.resize(n);
        sz.resize(n);
        uf_size = n;
        for(int i=0; i<n; i++){
            par[i] = i;
            rank[i] = 0;
            sz[i] = 1;
        }
    }

    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }

    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y);
        if(rank[x] == rank[y]) rank[x]++;
        uf_size--;
        par[y] = x;
        sz[x] = sz[x] + sz[y];
        return true;
    }

    int size(int x){
        return sz[find(x)];
    }
};

ll kruskal(int n, vector<T> &edge){
    sort(edge.begin(), edge.end());
    UnionFind uf(n);
    ll res = 0;
    for(auto i : edge){
        ll cost; int cv, nv; tie(cost, cv, nv) = i;
        if(!uf.same(cv, nv)){
            uf.unite(cv, nv);
            res += cost;
        }
    }

    if(uf.uf_size != 1) res = -1;
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<int> c(m), l(m), r(m);
    for(int i=0; i<m; i++) cin>>c[i]>>l[i]>>r[i];

    vector<T> edge(m);
    for(int i=0; i<m; i++){
        edge[i] = T(c[i], l[i] - 1, r[i]);
    }

    cout << kruskal(n + 1, edge) << endl;

    return 0;
}