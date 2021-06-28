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
using T = tuple<ll, ll, ll, ll>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<ll> dijkstra(int s, vector<vector<T>> &G){
    int n = G.size();
    vector<ll> dist(n, INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);

    while(que.size()){
        ll ccost; int cv; tie(ccost, cv) = que.top(); que.pop();
        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            ll nv, ncost, nd, nbest; tie(nv, ncost, nd, nbest) = nxt;
            
            if(nbest < ccost + 1){
                if(ccost + ncost + nd / (ccost + 1) < dist[nv]){
                    dist[nv] = ccost + ncost + nd / (ccost + 1);
                    que.emplace(dist[nv], nv);
                }
            }
            else{
                if(ccost + (nbest - ccost - 1) + ncost + nd / nbest < dist[nv]){
                    dist[nv] = ccost + (nbest - ccost - 1) + ncost + nd / nbest;
                    que.emplace(dist[nv], nv);
                }
            }
        }
    }

    return dist;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<vector<T>> G(n);
    for(int i=0; i<m; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--, b--;
        ll ng = -1, ok = inf;
        while(ok - ng > 1){
            ll mid = (ng + ok) / 2;
            if(d <= mid * mid) ok = mid;
            else ng = mid;
        }
        G[a].emplace_back(b, c, d, ok);
        G[b].emplace_back(a, c, d, ok);
    }

    ll ans = dijkstra(0, G)[n - 1];
    if(ans == INF) ans = -1;

    cout << ans << endl;

    return 0;
}