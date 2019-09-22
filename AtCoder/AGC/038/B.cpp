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

    int n, k; cin>>n>>k;
    vector<int> p(n);
    for(int i=0; i<n; i++) cin>>p[i];

    UnionFind uf(n-k+1);

    // [i, i+K) が元々昇順になっている
    vector<int> v;
    for(int i=0; i<n; i++){
        int cur = -1;
        int cnt = 0;
        while(i < n && cur < p[i]){
            cur = p[i];
            cnt++;
            i++;

            if(k <= cnt){
                v.emplace_back(i - k);
            }
        }

        i--;
    }

    for(int i=0; i+1<v.size(); i++){
        uf.unite(v[i], v[i+1]);
    }

    set<int> num;
    for(int i=0; i<k; i++){
        num.emplace(p[i]);
    }

    for(int i=0; i+k<n; i++){
        int lb = i;
        int ub = i + k;

        num.emplace(p[ub]);

        auto minitr = num.begin();
        auto maxitr = num.end(); maxitr--;

        if(p[lb] == *minitr && p[ub] == *maxitr){
            uf.unite(i, i + 1);
        }

        num.erase(p[lb]);
    }

    cout << uf.uf_size << endl;

    return 0;
}