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

int n, m;
ll k;

void dijkstra(int s, vector<vector<T>> &G, vector<ll> &t){
    vector<ll> dist(n, INF); 
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(0, s);

    while(que.size()){
        ll ccost, cv;
        tie(ccost, cv) = que.top();
        que.pop();

        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            ll nv, ncost, ntime;
            tie(nv, ncost, ntime) = nxt;

            ll nntime = (ccost + ntime - 1) / ntime * ntime + ncost + t[nv];
            
            if(nntime < dist[nv]){
                dist[nv] = nntime;
                que.emplace(dist[nv], nv);
            }
        }
    }

    cout << (dist[n-1] > k ? -1 : dist[n-1]) << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m>>k;
    vector<ll> t(n, 0);
    for(int i=1; i<n-1; i++) cin>>t[i];
    vector<vector<T>> G(n);
    for(int i=0; i<m; i++){
        ll a, b, c, d; cin>>a>>b>>c>>d;
        a--, b--;
        G[a].emplace_back(b, c, d);
        G[b].emplace_back(a, c, d);
    }

    dijkstra(0, G, t);
}