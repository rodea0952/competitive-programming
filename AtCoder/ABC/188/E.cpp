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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y; x--, y--;
        G[x].emplace_back(y);
    }

    vector<ll> dp(n, INF);
    for(int i=0; i<n; i++){
        for(auto j : G[i]){
            chmin(dp[j], min(dp[i], (ll)a[i]));
        }
    }

    ll ans = -INF;
    for(int i=0; i<n; i++){
        chmax(ans, a[i] - dp[i]);
    }

    cout << ans << endl;

    return 0;
}