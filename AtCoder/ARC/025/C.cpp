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

    int n, m, r, t; cin>>n>>m>>r>>t;
    vector<vector<P>> G(n);
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        a--, b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        auto dist = dijkstra(i, G);
        sort(all(dist));

        vector<double> rabbit(n), turtle(n);
        for(int i=0; i<n; i++){
            rabbit[i] = 1. * dist[i] / r;
            turtle[i] = 1. * dist[i] / t;
        }

        for(int i=1; i<n; i++){
            if(r < t)  ans += (n - (upper_bound(all(rabbit), turtle[i]) - rabbit.begin()) - 1);
            else ans += (n - (upper_bound(all(rabbit), turtle[i]) - rabbit.begin()));
        }
    }

    cout << ans << endl;

    return 0;
}