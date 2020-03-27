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

constexpr int MOD = 998244353;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, s; cin>>n>>s;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(s+1, 0));
    for(int i=0; i<n; i++) dp[i][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<=s; j++){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;

            if(j - a[i] >= 0){
                dp[i+1][j] += dp[i][j-a[i]];
                dp[i+1][j] %= MOD;
            }
        }
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += dp[i+1][s];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}