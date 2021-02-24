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
    ll x; cin>>x;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    ll ans = INF;
    for(int k=1; k<=n; k++){
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(k, -INF)));
        dp[0][0][0] = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<=k; j++){
                for(int l=0; l<k; l++){
                    if(dp[i][j][l] < 0) continue;
                    chmax(dp[i + 1][j][l], dp[i][j][l]);
                    if(j != k) chmax(dp[i + 1][j + 1][(l + a[i]) % k], dp[i][j][l] + a[i]);
                }
            }
        }

        if(0 < dp[n][k][x % k]) chmin(ans, (x - dp[n][k][x % k]) / k);
    }

    cout << ans << endl;

    return 0;
}