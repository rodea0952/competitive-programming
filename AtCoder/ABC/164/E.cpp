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
using T = tuple<ll, ll, ll>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<ll>> dijkstra(int s, int sil, vector<vector<T>> &G, vector<int> &c, vector<int> &d){
    int n = G.size();
    sil = min(sil, 2500);
    vector<vector<ll>> dist(55, vector<ll>(2510, INF));
    priority_queue<T, vector<T>, greater<T>> que;
    dist[s][sil] = 0;
    que.emplace(0, s, sil);

    set<int> visited;

    while(que.size()){
        ll ctime, cv, csil;
        tie(ctime, cv, csil) = que.top(); que.pop();

        visited.emplace(cv);

        if(visited.size() == n) break;

        if(dist[cv][csil] < ctime) continue;

        for(auto nxt : G[cv]){
            int nv, ncost, ntime;
            tie(nv, ncost, ntime) = nxt;
            
            // i 回両替する
            for(ll i=0; ; i++){

                if(ncost <= csil + i * c[cv] && dist[cv][csil] + i * d[cv] + ntime < dist[nv][min(2500LL, csil + i * c[cv]) - ncost]){
                    dist[nv][min(2500LL, csil + i * c[cv]) - ncost] = dist[cv][csil] + i * d[cv] + ntime;
                    que.emplace(dist[nv][min(2500LL, csil + i * c[cv]) - ncost], nv, min(2500LL, csil + i * c[cv]) - ncost);
                }
            
                if(2500 < csil + i * c[cv]) break;
            }
        }
    }

    return dist;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, s; cin>>n>>m>>s;
    vector<vector<T>> G(n);
    for(int i=0; i<m; i++){
        int u, v, a, b; cin>>u>>v>>a>>b;
        u--, v--;
        G[u].emplace_back(v, a, b);
        G[v].emplace_back(u, a, b);
    }

    vector<int> c(n), d(n);
    for(int i=0; i<n; i++) cin>>c[i]>>d[i];

    vector<vector<ll>> dist = dijkstra(0, s, G, c, d);

    for(int i=1; i<n; i++){
        ll ans = INF;
        for(int j=0; j<2510; j++) chmin(ans, dist[i][j]);
        cout << ans << endl;
    }

    return 0;
}
