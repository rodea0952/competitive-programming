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

    int n, m, l; cin>>n>>m>>l;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for(int i=0; i<n; i++) dist[i][i] = 0;
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c; a--, b--;
        dist[a][b] = dist[b][a] = c;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<vector<ll>> pass(n, vector<ll>(n, INF));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dist[i][j] <= l) pass[i][j] = 1;
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                pass[i][j] = min(pass[i][j], pass[i][k] + pass[k][j]);
            }
        }
    }

    int q; cin>>q;
    while(q--){
        int s, t; cin>>s>>t; s--, t--;
        if(pass[s][t] == INF) cout << -1 << endl;
        else cout << pass[s][t] - 1 << endl;
    }

    return 0;
}