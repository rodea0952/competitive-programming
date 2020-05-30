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
using P = pair<int, double>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<double> dijkstra(int s, vector<vector<P>> &G){
    int n = G.size();
    vector<double> dist(n, inf);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(0, s);

    while(que.size()){
        double ccost;
        int cv;
        tie(ccost, cv) = que.top(); que.pop();

        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv;
            double ncost;
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
    int x, y; cin>>x>>y;
    x--, y--;

    vector<double> p(n), q(n);
    for(int i=0; i<n; i++) cin>>p[i]>>q[i];

    vector<vector<P>> G(n);
    for(int i=0; i<m; i++){
        int pp, qq; cin>>pp>>qq;
        pp--, qq--;

        double dist = sqrt((p[pp] - p[qq]) * (p[pp] - p[qq]) + (q[pp] - q[qq]) * (q[pp] - q[qq]));
        G[pp].emplace_back(qq, dist);
        G[qq].emplace_back(pp, dist);
    }

    auto ans = dijkstra(x, G);

    printf("%.10f\n", ans[y]);

    return 0;
}