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

vector<int> dijkstra(int s, vector<vector<int>> &G){
    vector<int> dist(200010, -1);
    priority_queue<P> que;
    dist[s] = inf;
    que.emplace(0, s);

    while(que.size()){
        int ccost, cv;
        tie(ccost, cv) = que.top(); que.pop();

        for(auto nv : G[cv]){            
            if(dist[nv] < min(cv, dist[cv])){
                dist[nv] = min(cv, dist[cv]);
                que.emplace(dist[nv], nv);
            }
        }
    }

    vector<int> ans;
    for(int i=0; i<200010; i++){
        if(dist[i] >= i){
            ans.emplace_back(i);
        }
    }

    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, s; cin>>n>>m>>s;
    s--;
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    auto ans = dijkstra(s, G);

    for(auto i : ans) cout << i + 1 << endl;

    return 0;
}