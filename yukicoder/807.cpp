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
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}
constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// dist[i][j] := スポット i まで、残りチケット j 個で来るときの最小距離
vector<vector<ll>> dist(100010, vector<ll>(2, INF));

void dijkstra(int s, vector<vector<P>> &G){
    priority_queue<T, vector<T>, greater<T>> que;
    dist[s][1] = dist[s][0] = 0;
    que.emplace(0, s, 1);

    while(que.size()){
        ll ccost, cv, ticket;
        tie(ccost, cv, ticket) = que.top(); que.pop();

        if(dist[cv][ticket] < ccost) continue;

        for(auto nxt : G[cv]){
            ll nv, ncost;
            tie(nv, ncost) = nxt;
            
            if(dist[cv][ticket] + ncost < dist[nv][ticket]){
                dist[nv][ticket] = dist[cv][ticket] + ncost;
                que.emplace(dist[nv][ticket], nv, ticket);
            }

            if(ticket == 1){
                if(dist[cv][1] < dist[nv][0]){
                    dist[nv][0] = dist[cv][1];
                    que.emplace(dist[nv][0], nv, 0);
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<vector<P>> G(n);
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        a--, b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }

    dijkstra(0, G);

    for(int i=0; i<n; i++){
        cout << dist[i][1] + dist[i][0] << endl;
    }

    return 0;
}