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

    int n; cin>>n;
    vector<double> p(n);
    for(int i=0; i<n; i++) cin>>p[i];

    vector<vector<double>> dp(n+1, vector<double>(n+1, 0));
    // dp[i][j] := i 枚目のコインまでで j 回表が出たときの確率
    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(dp[i][j] == 0) continue;
            dp[i+1][j+1] += dp[i][j] * p[i];
            dp[i+1][j] += dp[i][j] * (1 - p[i]);
        }
    }

    double ans = 0;
    for(int i=n/2+1; i<=n; i++){
        ans += dp[n][i];
    }

    printf("%.10f\n", ans);

    return 0;
}