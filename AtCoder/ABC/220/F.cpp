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

int n;
vector<int> sub(200010, 1);
vector<ll> ans(200010);

vector<int> dijkstra(int s, vector<vector<int>> &G){
    int n = G.size();
    vector<int> dist(n, inf);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);

    while(que.size()){
        int ccost, cv; tie(ccost, cv) = que.top(); que.pop();
        if(dist[cv] < ccost) continue;

        for(auto nv : G[cv]){
            if(ccost + 1 < dist[nv]){
                dist[nv] = ccost + 1;
                que.emplace(dist[nv], nv);
            }
        }
    }

    return dist;
}

void dfs1(int cv, int pv, vector<vector<int>> &G){
    for(auto nv : G[cv]){
        if(nv == pv) continue;
        dfs1(nv, cv, G);
        sub[cv] += sub[nv];
    }
    return ;
}

void dfs2(int cv, int pv, vector<vector<int>> &G){
    if(cv != 0) ans[cv] = ans[pv] + n - 2 * sub[cv];
    for(auto nv : G[cv]){
        if(nv == pv) continue;
        dfs2(nv, cv, G);
    }
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    auto dist = dijkstra(0, G);
    for(int i=1; i<n; i++){
        ans[0] += dist[i];
    }

    dfs1(0, -1, G);
    dfs2(0, -1, G);

    for(int i=0; i<n; i++){
        cout << ans[i] << endl;
    }

    return 0;
}