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
using P = pair<ll, ll>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct UnionFind{
    vector<int> par;
    vector<int> rank;
    vector<int> sz;
    int uf_size;

private:
    void init(int n = 1){
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

public:
    UnionFind(int n = 1){
        init(n);
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> x(n), y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];

    ll ng = 0, ok = 2000000000;
    while(ok - ng > 1){
        ll mid = (ng + ok) / 2;

        UnionFind uf(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ll cdist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                if(cdist > mid * mid) continue;
                uf.unite(i, j);
            }
        }

        if(uf.same(0, n-1)) ok = mid;
        else ng = mid;
    }

    if(ok % 10 != 0) ok += 10 - ok % 10;
    cout << ok << endl;

    return 0;
}