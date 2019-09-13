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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, c, v;

vector<vector<int>> dist(60, vector<int>(310, inf));

int dijkstra(int s, vector<vector<T>> &G){
    priority_queue<T, vector<T>, greater<T>> que;
    dist[s][c] = 0;
    que.emplace(0, s, c);

    while(que.size()){
        int ccost, cv, ccoin;
        tie(ccost, cv, ccoin) = que.top(); que.pop();

        if(dist[cv][ccoin] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv, ncost, ntime;
            tie(nv, ncost, ntime) = nxt;
            
            if(ccoin - ncost >= 0){
                if(dist[cv][ccoin] + ntime < dist[nv][ccoin - ncost]){
                    dist[nv][ccoin - ncost] = dist[cv][ccoin] + ntime;
                    que.emplace(dist[nv][ccoin - ncost], nv, ccoin - ncost);
                }
            }
        }
    }

    int ans = inf;
    for(int i=0; i<=c; i++){
        chmin(ans, dist[n-1][i]);
    }

    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>c>>v;
    vector<int> s(v), t(v), y(v), m(v);
    for(int i=0; i<v; i++) cin>>s[i];
    for(int i=0; i<v; i++) cin>>t[i];
    for(int i=0; i<v; i++) cin>>y[i];
    for(int i=0; i<v; i++) cin>>m[i];

    vector<vector<T>> G(n);
    for(int i=0; i<v; i++){
        s[i]--, t[i]--;
        G[s[i]].emplace_back(t[i], y[i], m[i]);
    }

    int ans = dijkstra(0, G);

    cout << (ans == inf ? -1 : ans) << endl;

    return 0;
}