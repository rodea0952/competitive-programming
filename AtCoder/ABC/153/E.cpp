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

    int h, n; cin>>h>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];

    vector<vector<int>> dp(n+1, vector<int>(h+10001, inf));
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<=h+10000; j++){
            chmin(dp[i+1][j], dp[i][j]);
            if(j - a[i] >= 0) chmin(dp[i+1][j], dp[i+1][j - a[i]] + b[i]);
        }
    }

    int ans = inf;
    for(int i=h; i<=h+10000; i++) chmin(ans, dp[n][i]);

    cout << ans << endl;

    return 0;
}