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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(n, -1));
    vector<P> edge(m);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        G[a][b] = i;
        edge[i] = P(a, b);
    }

    vector<int> dist(n, -1);
    dist[0] = 0;
    vector<P> memo(n);
    queue<int> que;
    que.emplace(0);
    while(que.size()){
        int cv = que.front(); que.pop();
        for(int nv=0; nv<n; nv++){
            if(dist[nv] == -1 && G[cv][nv] != -1){
                dist[nv] = dist[cv] + 1;
                memo[nv] = P(cv, G[cv][nv]);
                que.emplace(nv);
            }
        }
    }

    if(dist[n - 1] == -1){
        for(int i=0; i<m; i++){
            cout << -1 << endl;
        }
        return 0;
    }

    vector<int> shortest_path;
    int cur = n - 1;
    while(cur != 0){
        shortest_path.emplace_back(memo[cur].second);
        cur = memo[cur].first;
    }

    vector<int> ans(m, dist[n - 1]);
    for(auto e : shortest_path){
        G[edge[e].first][edge[e].second] = -1;
        queue<int> que;
        que.emplace(0);
        vector<int> dist(n, -1);
        dist[0] = 0;
        while(que.size()){
            int cv = que.front(); que.pop();
            for(int nv=0; nv<n; nv++){
                if(dist[nv] == -1 && G[cv][nv] != -1){
                    dist[nv] = dist[cv] + 1;
                    que.emplace(nv);
                }
            }
        }
        ans[e] = dist[n - 1];
        G[edge[e].first][edge[e].second] = e;
    }

    for(int i=0; i<m; i++){
        cout << ans[i] << endl;
    }

    return 0;
}