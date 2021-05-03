// 小課題 2
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
    vector<int> d(n), c(n), s(n);
    for(int i=0; i<n; i++) cin>>d[i]>>c[i]>>s[i];

    vector<T> dcs(n);
    for(int i=0; i<n; i++) dcs[i] = T(d[i], c[i], s[i]);
    sort(all(dcs));
    for(int i=0; i<n; i++){
        tie(d[i], c[i], s[i]) = dcs[i];
    }

    // dp[i][j] := i 番目の仕事まで見終わり、合計仕事時間が j のときの報酬の最大値
    vector<vector<ll>> dp(5010, vector<ll>(5010, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<=5000; j++){
            // 仕事 i をやらない
            chmax(dp[i + 1][j], dp[i][j]);
            // 仕事 i をやる
            if(j + c[i] <= d[i]) chmax(dp[i + 1][j + c[i]], dp[i][j] + s[i]);
        }
    }

    ll ans = 0;
    for(int i=0; i<=5000; i++) chmax(ans, dp[n][i]);

    cout << ans << endl;

    return 0;
}