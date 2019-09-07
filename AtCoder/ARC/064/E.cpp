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
using P = pair<double, int>;
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

int n;

double dijkstra(int s, vector<vector<pair<int, double>>> &G){
    vector<double> dist(1010, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(0, s);

    while(que.size()){
        double ccost; int cv;
        tie(ccost, cv) = que.top();
        que.pop();

        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv; double ncost;
            tie(nv, ncost) = nxt;
            
            if(dist[cv] + ncost < dist[nv]){
                dist[nv] = dist[cv] + ncost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    return dist[n+1];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    double xs, ys, xt, yt; cin>>xs>>ys>>xt>>yt;
    cin>>n;
    vector<double> x(n), y(n), r(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i]>>r[i];

    vector<vector<pair<int, double>>> G(n+2);
    for(int i=0; i<n; i++){
        double dist = sqrt(abs(x[i] - xs) * abs(x[i] - xs) + abs(y[i] - ys) * abs(y[i] - ys));
        dist = max(dist - r[i], 0.0);
        G[n].emplace_back(i, dist);
        G[i].emplace_back(n, dist);
    }
    G[n].emplace_back(n+1, sqrt(abs(xt - xs) * abs(xt - xs) + abs(yt - ys) * abs(yt - ys)));

    for(int i=0; i<n; i++){
        double dist = sqrt(abs(x[i] - xt) * abs(x[i] - xt) + abs(y[i] - yt) * abs(y[i] - yt));
        dist = max(dist - r[i], 0.0);
        G[n+1].emplace_back(i, dist);
        G[i].emplace_back(n+1, dist);
    }
    G[n+1].emplace_back(n, sqrt(abs(xt - xs) * abs(xt - xs) + abs(yt - ys) * abs(yt - ys)));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;

            double dist = sqrt(abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]));
            dist = max(dist - r[i] - r[j], 0.0);
            G[i].emplace_back(j, dist);
        }
    }

    double ans = dijkstra(n, G);

    printf("%.10f\n", ans);
}