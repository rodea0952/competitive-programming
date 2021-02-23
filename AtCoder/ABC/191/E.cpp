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

vector<long long> dijkstra(int s, vector<vector<pair<int, long long>>> &G){
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
            long long ncost;
            tie(nv, ncost) = nxt;
            
            if(ccost + ncost < dist[nv]){
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
    vector<vector<pair<int, ll>>> G(n);
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c; a--, b--;
        G[a].emplace_back(b, c);
    }

    for(int i=0; i<n; i++){
        auto dist = dijkstra(i, G);
        cout << (dist[i] == INF ? -1 : dist[i]) << endl;
    }

    return 0;
}