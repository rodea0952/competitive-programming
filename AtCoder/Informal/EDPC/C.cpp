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
    vector<int> a(n), b(n), c(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i]>>c[i];

    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
    for(int i=0; i<n; i++){
        chmax(dp[i+1][0], max(dp[i][1], dp[i][2]) + a[i]);
        chmax(dp[i+1][1], max(dp[i][0], dp[i][2]) + b[i]);
        chmax(dp[i+1][2], max(dp[i][0], dp[i][1]) + c[i]);
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;

    return 0;
}