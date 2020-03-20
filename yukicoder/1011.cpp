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

    int n, d, k; cin>>n>>d>>k;

    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        vector<ll> dpsum(k+1, 0);
        for(int j=0; j<k; j++){
            dpsum[j + 1] = dpsum[j] + dp[i][j];
            dpsum[j + 1] %= MOD;
        }

        for(int cur=0; cur<=k; cur++){
            dp[i + 1][cur] += (dpsum[cur] - dpsum[max(0, cur - d)] + MOD);
            dp[i + 1][cur] %= MOD;
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}