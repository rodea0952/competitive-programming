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

vector<vector<ll>> warshall_floyd(int n, vector<vector<ll>> &dist){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, l; cin>>n>>m>>l;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for(int i=0; i<n; i++) dist[i][i] = 0;
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        a--, b--;
        dist[a][b] = dist[b][a] = c;
    }

    auto dist1 = warshall_floyd(n, dist);

    vector<vector<ll>> dist2(n, vector<ll>(n, INF));
    for(int i=0; i<n; i++) dist2[i][i] = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(dist1[i][j] <= l){
                dist2[i][j] = dist2[j][i] = 1;
            }
        }
    }

    auto fidist = warshall_floyd(n, dist2);

    int q; cin>>q;
    while(q--){
        int s, t; cin>>s>>t;
        s--, t--;
        if(fidist[s][t] == INF) cout << -1 << endl;
        else cout << fidist[s][t] - 1 << endl;
    }

    return 0;
}