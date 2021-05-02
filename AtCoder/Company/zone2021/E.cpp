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
using P = pair<int, ll>;
using T = tuple<ll, int, int>;

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int r, c; cin>>r>>c;
    vector<vector<int>> a(r, vector<int>(c - 1));
    for(int i=0; i<r; i++){
        for(int j=0; j<c-1; j++) cin>>a[i][j];
    }
    vector<vector<int>> b(r - 1, vector<int>(c));
    for(int i=0; i<r-1; i++){
        for(int j=0; j<c; j++) cin>>b[i][j];
    }

    int sz = 2 * r * c;
    vector<vector<P>> G(sz);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(j + 1 < c) G[i * c + j].emplace_back(i * c + j + 1, a[i][j]);
            if(0 <= j - 1) G[i * c + j].emplace_back(i * c + j - 1, a[i][j - 1]);
            if(i + 1 < r) G[i * c + j].emplace_back((i + 1) * c + j, b[i][j]);
            
            // (r, c) -> (r - i, c) の移動で i + 1 のコストがかかることを以下で実現
            // 2 階に上がるのにコストが 1 かかる
            G[i * c + j].emplace_back(r * c + i * c + j, 1);
            // 1 階に下がるのにはコストがかからない
            G[r * c + i * c + j].emplace_back(i * c + j, 0);
            // 2 階で 1 つ下のマスに行くのにコストが 1 かかる
            if(0 <= i - 1) G[r * c + i * c + j].emplace_back(r * c + (i - 1) * c + j, 1);
        }
    }

    auto dist = dijkstra(0, G);

    cout << dist[r * c - 1] << endl;

    return 0;
}