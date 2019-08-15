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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX_N = 100010;

int par[MAX_N];
int ranks[MAX_N];
int size[MAX_N];
int size_cnt[MAX_N];
int uf_size;

void init(int n){
    uf_size = n;
    for(int i=0; i<n; i++){
        par[i] = i;
        ranks[i] = 0;
        size[i] = 1;
    }
    size_cnt[1] = n;

    return ;
}

int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

bool same(int x, int y){
    return find(x) == find(y);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;
    uf_size--;

    if(ranks[x] < ranks[y]) swap(x, y);
    if(ranks[x] == ranks[y]) ranks[x]++;
    par[y] = x;
    size_cnt[size[x]]--;
    size_cnt[size[y]]--;
    size[x] += size[y];
    size_cnt[size[x]]++;
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, q; cin>>n>>m>>q;
    vector<T> edge;
    for(int i=0; i<m; i++){
        int a, b; ll c; cin>>a>>b>>c;
        a--, b--;
        edge.emplace_back(c, a, b);
    }

    sort(edge.begin(), edge.end());

    init(n);

    vector<ll> need_cost(n+1, INF);
    int lb = 1;
    need_cost[lb] = 0;
    for(int i=0; i<m; i++){
        ll cost; int u, v;
        tie(cost, u, v) = edge[i];

        unite(u, v);

        while(size_cnt[lb] == 0 && lb < n) lb++;

        chmin(need_cost[lb], cost);
    }

    for(int i=n; i>0; i--){
        chmin(need_cost[i-1], need_cost[i]);
    }

    while(q--){
        int que; cin>>que;
        if(n < que || need_cost[que] == INF) cout << "trumpet" << endl;
        else cout << need_cost[que] << endl;
    }
}