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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, q; cin>>n>>m>>q;
    vector<string> s(n);
    for(int i=0; i<n; i++) cin>>s[i];

    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    UnionFind uf(n * 7);
    for(int i=0; i<n; i++){
        for(int j=0; j<7; j++){
            if(s[i][j] == '0') continue;

            for(auto nv : G[i]){
                if(s[nv][j] == '1'){
                    uf.unite(i * 7 + j, nv * 7 + j);
                }
            }

            int up = (j + 1) % 7, down = (j - 1 + 7) % 7;
            if(s[i][up] == '1'){
                uf.unite(i * 7 + j, i * 7 + up);
            }
            if(s[i][down] == '1'){
                uf.unite(i * 7 + j, i * 7 + down);
            }
        }
    }

    while(q--){
        int z, x, y; cin>>z>>x>>y;
        x--, y--;
        if(z == 1){
            s[x][y] = '1';
            for(auto nv : G[x]){
                if(s[nv][y] == '1'){
                    uf.unite(x * 7 + y, nv * 7 + y);
                }
            }

            int up = (y + 1) % 7, down = (y - 1 + 7) % 7;
            if(s[x][up] == '1'){
                uf.unite(x * 7 + y, x * 7 + up);
            }
            if(s[x][down] == '1'){
                uf.unite(x * 7 + y, x * 7 + down);
            }
        }
        else{
            cout << uf.size(x * 7) << endl;
        }
    }

    return 0;
}