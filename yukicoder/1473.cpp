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

vector<int> dijkstra(int s, int w, vector<vector<T>> &G){
    int n = G.size();
    vector<int> dist(n, inf);
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);

    while(que.size()){
        int ccost, cv; tie(ccost, cv) = que.top(); que.pop();
        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv, ncost, nw; tie(nv, ncost, nw) = nxt;
            
            if(w <= nw && ccost + ncost < dist[nv]){
                dist[nv] = ccost + ncost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    return dist;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<vector<T>> G(n);
    for(int i=0; i<m; i++){
        int s, t, d; cin>>s>>t>>d; s--, t--;
        G[s].emplace_back(t, 1, d);
        G[t].emplace_back(s, 1, d);
    }

    int ok = 1, ng = inf + 1;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        auto dist = dijkstra(0, mid, G);
        if(dist[n - 1] != inf) ok = mid;
        else ng = mid;
    }

    auto ans = dijkstra(0, ok, G);

    cout << ok << " " << ans[n - 1] << endl;

    return 0;
}