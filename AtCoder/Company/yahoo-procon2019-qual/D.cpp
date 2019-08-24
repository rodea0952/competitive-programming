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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(5, INF));
    dp[0][0] = 0;

    int cost;
    for(int i=0; i<n; i++){
        cost = a[i];
        dp[i+1][0] = min(dp[i+1][0], dp[i][0] + cost);

        cost = (a[i] == 0 ? 2 : (a[i] % 2));
        dp[i+1][1] = min(dp[i+1][1], min(dp[i][0], dp[i][1]) + cost);

        cost = (a[i] + 1) % 2;
        dp[i+1][2] = min(dp[i+1][2], min({dp[i][0], dp[i][1], dp[i][2]}) + cost);

        cost = (a[i] == 0 ? 2 : (a[i] % 2));
        dp[i+1][3] = min(dp[i+1][3], min({dp[i][0], dp[i][1], dp[i][2], dp[i][3]}) + cost);

        cost = a[i];
        dp[i+1][4] = min(dp[i+1][4], min({dp[i][0], dp[i][1], dp[i][2], dp[i][3], dp[i][4]}) + cost);
    }

    ll ans = INF;
    for(int i=0; i<5; i++){
        chmin(ans, dp[n][i]);
    }

    cout << ans << endl;
}