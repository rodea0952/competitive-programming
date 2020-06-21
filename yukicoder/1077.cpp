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
    vector<int> y(n);
    for(int i=0; i<n; i++) cin>>y[i];

    vector<vector<int>> dp(n+1, vector<int>(20010, inf));
    dp[0][0] = 0;
    for(int i=0; i<n; i++){
        vector<int> mi(20010, inf);
        mi[0] = dp[i][0];
        for(int j=1; j<=20005; j++) mi[j] = min(mi[j-1], dp[i][j]);

        for(int j=0; j<=20005; j++){
            chmin(dp[i+1][j], mi[j] + abs(y[i] - j));
        }
    }

    int ans = inf;
    for(int i=0; i<=20005; i++) chmin(ans, dp[n][i]);

    cout << ans << endl;

    return 0;
}