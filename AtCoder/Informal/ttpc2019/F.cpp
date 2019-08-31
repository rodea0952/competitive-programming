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
constexpr long long INF = 1e17;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<ll> dijkstra(int s, vector<vector<P>> &G){
    vector<ll> dist(100010, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(0, s);

    while(que.size()){
        ll ccost, cv;
        tie(ccost, cv) = que.top();
        que.pop();

        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            ll nv, ncost;
            tie(nv, ncost) = nxt;
            
            if(dist[cv] + ncost < dist[nv]){
                dist[nv] = dist[cv] + ncost;
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
    int w, x, y, z; cin>>w>>x>>y>>z;
    w--, x--, y--, z--;
    vector<vector<P>> G(n+2), Gr(n+2);
    for(int i=0; i<m; i++){
        int c, s, t; cin>>c>>s>>t;
        s--, t--;
        G[s].emplace_back(t, c);
        Gr[t].emplace_back(s, c);
    }

    auto distw = dijkstra(w, G);
    auto disty = dijkstra(y, G);
    auto distx = dijkstra(x, Gr);
    auto distz = dijkstra(z, Gr);

    int S = n, T = n + 1;

    for(int i=0; i<n; i++){
        G[S].emplace_back(i, distw[i] + disty[i]);
        G[i].emplace_back(T, distx[i] + distz[i]);
    }

    auto distS = dijkstra(S, G);

    ll ans = min(distw[x] + disty[z], distS[T]);

    if(1e17 <= ans) cout << "Impossible" << endl;
    else cout << ans << endl;
}