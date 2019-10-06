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

int n;

vector<int> dijkstra(int s, vector<vector<P>> &G){
    vector<int> dist(n*n, inf);
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

    int v, ox, oy; cin>>n>>v>>ox>>oy;
    ox--, oy--;
    int l[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>l[i][j];
    }

    int grid2graph[n][n];
    int cnt = 0;
    int o = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == oy && j == ox) o = cnt;
            grid2graph[i][j] = cnt++;
        }
    }

    vector<vector<P>> G(n*n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cy = i, cx = j;
            for(int k=0; k<4; k++){
                int ny = cy + dy[k], nx = cx + dx[k];
                if(!(0 <= ny && ny < n && 0 <= nx && nx < n)) continue;

                int cv = grid2graph[cy][cx], nv = grid2graph[ny][nx];
                G[cv].emplace_back(nv, l[ny][nx]);
                G[nv].emplace_back(cv, l[cy][cx]);
            }
        }
    }

    auto sdist = dijkstra(0, G);

    bool valid = false;
    if(sdist[n*n-1] < v) valid = true;
    if(o != -1){
        auto odist = dijkstra(o, G);
        if(odist[n*n-1] < 2 * (v - sdist[o])) valid = true;
    }

    cout << (valid ? "YES" : "NO") << endl;

    return 0;
}