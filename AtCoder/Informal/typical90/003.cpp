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

vector<ll> dijkstra(int s, vector<vector<pair<int, ll>>> &G){
    int n = G.size();
    vector<ll> dist(n, INF);
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(0, s);

    while(que.size()){
        ll ccost; int cv; tie(ccost, cv) = que.top(); que.pop();
        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv; ll ncost; tie(nv, ncost) = nxt;
            
            if(ccost + ncost < dist[nv]){
                dist[nv] = ccost + ncost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    return dist;
}

ll diameter(vector<vector<pair<int, ll>>> &G){
    vector<ll> dist1 = dijkstra(0, G);
    int v1 = max_element(dist1.begin(), dist1.end()) - dist1.begin();
    vector<ll> dist2 = dijkstra(v1, G);
    return *max_element(dist2.begin(), dist2.end());
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<pair<int, ll>>> G(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b; a--, b--;
        G[a].emplace_back(b, 1);
        G[b].emplace_back(a, 1);
    }

    cout << diameter(G) + 1 << endl;

    return 0;
}