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
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class UnionFind{
public:
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

int kruskal(int n, vector<T> &edge){
    sort(edge.begin(), edge.end());
    UnionFind uf(n);
    int res = 0;
    for(int i=0; i<edge.size(); i++){
        int cost, cv, nv;
        tie(cost, cv, nv) = edge[i];
        if(!uf.same(cv, nv)){
            uf.unite(cv, nv);
            res += cost;
        }
    }

    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int l, r; cin>>l>>r;

    vector<T> edge;
    for(int i=l; i<=r; i++){
        for(int j=i*2; j<=r; j+=i){
            edge.emplace_back(0, i - l, j - l);
        }
    }

    for(int i=l; i<r; i++){
        edge.emplace_back(1, i - l, i + 1 - l);
    }

    cout << kruskal(r - l + 1, edge) << endl;

    return 0;
}