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

#define int long long

using ll = long long;
using P = pair<int, int>;
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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, W; cin>>n>>m>>W;
    vector<int> w(n), v(n);
    for(int i=0; i<n; i++) cin>>w[i]>>v[i];

    UnionFind uf(n);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        uf.unite(a, b);
    }

    vector<P> sum(n, P(0, 0));
    for(int i=0; i<n; i++){
        sum[uf.find(i)].first += w[i];
        sum[uf.find(i)].second += v[i];
    }

    vector<P> wv;
    for(int i=0; i<n; i++){
        if(sum[i].first == 0) continue;
        wv.emplace_back(sum[i]);
    }

    int sz = wv.size();
    vector<vector<int>> dp(sz+1, vector<int>(W+1, 0));
    for(int i=0; i<sz; i++){
        int curw = wv[i].first, curv = wv[i].second;
        for(int j=0; j<=W; j++){
            if(j - curw >= 0) chmax(dp[i+1][j],  dp[i][j-curw] + curv);
            chmax(dp[i+1][j], dp[i][j]);
        }
    }

    cout << dp[sz][W] << endl;

    return 0;
}