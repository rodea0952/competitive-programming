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

    int n, k; cin>>n>>k;
    vector<vector<int>> v(n, vector<int>(k));
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++) cin>>v[i][j];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    for(int i=0; i<k; i++) dp[1][i + 1] = 1;

    for(int i=1; i<n; i++){
        vector<ll> pdp(k + 1, 0);
        for(int j=0; j<k; j++){
            pdp[j + 1] = pdp[j] + dp[i][j + 1];
            pdp[j + 1] %= MOD;
        }

        for(int j=0; j<k; j++){
            int idx = upper_bound(all(v[i - 1]), v[i][j]) - v[i - 1].begin();
            dp[i + 1][j + 1] += pdp[idx];
            dp[i + 1][j + 1] %= MOD;
        }
    }

    ll ans = 0;
    for(int i=0; i<k; i++){
        ans += dp[n][i + 1];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}