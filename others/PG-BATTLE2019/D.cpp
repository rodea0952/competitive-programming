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
using T = tuple<ll, ll, ll>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

ll n, m, t, k;

ll dijkstra(int s, vector<vector<T>> &G){
    vector<ll> dist(100010, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(0, s);

    while(que.size()){
        ll ccost, cv;
        tie(ccost, cv) = que.top(); que.pop();

        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv, ncost, nd;
            tie(nv, ncost, nd) = nxt;

            int time1 = min(t + (nd - k), t - (nd - k));
            int time2 = max(t + (nd - k), t - (nd - k));

            if(nd <= k){
                if(dist[cv] + ncost < dist[nv]){
                    dist[nv] = dist[cv] + ncost;
                    que.emplace(dist[nv], nv);
                }
                continue;
            }

            if(ccost + ncost <= time1 || time2 <= ccost){
                if(dist[cv] + ncost < dist[nv]){
                    dist[nv] = dist[cv] + ncost;
                    que.emplace(dist[nv], nv);
                }
            }   
            else{
                if(time2 + ncost < dist[nv]){
                    dist[nv] = time2 + ncost;
                    que.emplace(dist[nv], nv);
                }
            }
        }
    }

    return dist[n-1];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m>>t>>k;
    vector<vector<T>> G(n);
    for(int i=0; i<m; i++){
        ll a, b, c, d; cin>>a>>b>>c>>d;
        a--, b--;
        G[a].emplace_back(b, c, d);
        G[b].emplace_back(a, c, d);
    }

    ll ans = dijkstra(0, G);

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}