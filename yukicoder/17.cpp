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

vector<vector<ll>> dist(60, vector<ll>(60, inf));
void warshall_floyd(int n){
    for(int i=0; i<n; i++) dist[i][i] = 0;

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> s(n);
    for(int i=0; i<n; i++) cin>>s[i];
    int m; cin>>m;
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        dist[a][b] = dist[b][a] = c;
    }

    warshall_floyd(n);

    ll ans = INF;
    for(int i=1; i<n-1; i++){
        for(int j=1; j<n-1; j++){
            if(i == j) continue;

            // 0 -> i -> j -> n-1
            chmin(ans, dist[0][i] + dist[i][j] + dist[j][n-1] + s[i] + s[j]);
        }
    }

    cout << ans << endl;
    
    return 0;
}