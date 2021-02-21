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

vector<int> dijkstra(int s, vector<vector<P>> &G){
    int n = G.size();
    vector<int> dist(n, inf);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(0, s);

    while(que.size()){
        int ccost, cv;
        tie(ccost, cv) = que.top(); que.pop();

        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv, ncost;
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
    vector<vector<P>> G(n);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b; a--, b--;
        G[a].emplace_back(b, 1);
        G[b].emplace_back(a, 1);
    }

    int k; cin>>k;
    vector<int> c(k);
    for(int i=0; i<k; i++) cin>>c[i], c[i]--;

    vector<vector<ll>> dist(k, vector<ll>(k, INF));
    for(int i=0; i<k; i++){
        auto cur = dijkstra(c[i], G);
        for(int j=i+1; j<k; j++){
            if(cur[c[j]] == inf) continue;
            dist[i][j] = dist[j][i] = cur[c[j]];
        }
    }

    vector<vector<ll>> dp(k, vector<ll>(1 << k, INF));
    for(int i=0; i<k; i++) dp[i][1 << i] = 0;
    for(int bit=0; bit<(1<<k); bit++){
        for(int pre=0; pre<k; pre++){
            if(dp[pre][bit] == INF) continue;
            for(int nxt=0; nxt<k; nxt++){
                if(bit & (1 << nxt)) continue;
                if(dist[pre][nxt] == INF) continue;
                chmin(dp[nxt][bit | (1 << nxt)], dp[pre][bit] + dist[pre][nxt]);
            }
        }
    }

    ll ans = INF;
    for(int i=0; i<k; i++) chmin(ans, dp[i][(1 << k) - 1]);

    cout << (ans == INF ? -1 : ans + 1) << endl;

    return 0;
}