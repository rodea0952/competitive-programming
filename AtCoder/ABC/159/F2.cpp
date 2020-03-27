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

ll dp[3010][6010][3];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, s; cin>>n>>s;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    dp[0][0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<=s; j++){
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j][0] %= MOD;
            dp[i+1][j+a[i]][1] += dp[i][j][0] * (i + 1);
            dp[i+1][j+a[i]][1] %= MOD;
            dp[i+1][j+a[i]][2] += dp[i][j][0] * (i + 1) * (n - i);
            dp[i+1][j+a[i]][2] %= MOD;

            dp[i+1][j][1] += dp[i][j][1];
            dp[i+1][j][1] %= MOD;
            dp[i+1][j+a[i]][1] += dp[i][j][1];
            dp[i+1][j+a[i]][1] %= MOD;
            dp[i+1][j+a[i]][2] += dp[i][j][1] * (n - i);
            dp[i+1][j+a[i]][2] %= MOD;

            dp[i+1][j][2] += dp[i][j][2];
            dp[i+1][j][2] %= MOD;
        }
    }

    cout << dp[n][s][2] << endl;

    return 0;
}