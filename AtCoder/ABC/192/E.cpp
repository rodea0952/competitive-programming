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

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<long long> dijkstra(int s, vector<vector<T>> &G){
    int n = G.size();
    vector<long long> dist(n, 1e18);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
    que.emplace(0, s);

    while(que.size()){
        long long ccost;
        int cv;
        tie(ccost, cv) = que.top(); que.pop();
        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv;
            long long ncost, k;
            tie(nv, ncost, k) = nxt;
            
            if((ccost + k - 1) / k * k + ncost < dist[nv]){
                dist[nv] = (ccost + k - 1) / k * k + ncost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    return dist;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, x, y; cin>>n>>m>>x>>y; x--, y--;
    vector<vector<T>> G(n);
    for(int i=0; i<m; i++){
        int a, b, t, k; cin>>a>>b>>t>>k; a--, b--;
        G[a].emplace_back(b, t, k);
        G[b].emplace_back(a, t, k);
    }

    auto dist = dijkstra(x, G);

    cout << (dist[y] == INF ? -1 : dist[y]) << endl;

    return 0;
}