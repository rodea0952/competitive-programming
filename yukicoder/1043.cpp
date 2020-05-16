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

    int n, m; cin>>n>>m;
    vector<int> v(n), r(m);
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=0; i<m; i++) cin>>r[i];
    int a, b; cin>>a>>b;

    vector<vector<ll>> vdp(n+1, vector<ll>(100010, 0));
    vdp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=100000; j++){
            if(j - v[i] >= 0) vdp[i+1][j] += vdp[i][j-v[i]];
            vdp[i+1][j] %= MOD;
            vdp[i+1][j] += vdp[i][j];
            vdp[i+1][j] %= MOD;
        }
    }

    vector<vector<ll>> rdp(m+1, vector<ll>(100010, 0));
    rdp[0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<=100000; j++){
            if(j - r[i] >= 0) rdp[i+1][j] += rdp[i][j-r[i]];
            rdp[i+1][j] %= MOD;
            rdp[i+1][j] += rdp[i][j];
            rdp[i+1][j] %= MOD;
        }
    }

    vector<ll> rdp_sum(100010, 0);
    for(int i=1; i<=100000; i++){
        rdp_sum[i+1] = rdp_sum[i] + rdp[m][i];
        rdp_sum[i+1] %= MOD;
    }

    ll ans = 0;
    for(int i=1; i<=100000; i++){
        if(vdp[n][i] == 0) continue;

        int lb = (i + b - 1) / b, ub = i / a;
        ans += (rdp_sum[ub+1] - rdp_sum[lb] + MOD) * vdp[n][i];
        ans %= MOD;
    }
    
    cout << ans << endl;

    return 0;
}