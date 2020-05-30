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

    int n, q; cin>>n>>q;
    vector<int> a(n), b(q);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<q; i++) cin>>b[i];

    // dp[i][j] := i 個目の箱まで操作して、色 1 の球が j 個ある場合の数
    // vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    
    vector<ll> dp(n+1, 0);
    dp[0] = 1;

    for(int i=0; i<n; i++){
        vector<ll> ndp(n+1, 0);
        for(int j=0; j<=n; j++){
            if(0 < j) ndp[j] += dp[j-1] * 1;
            ndp[j] %= MOD;
            ndp[j] += dp[j] * (a[i] - 1);
            ndp[j] %= MOD;
        }
        dp = ndp;
    }

    for(int i=0; i<q; i++){
        cout << dp[b[i]] << endl;
    }

    return 0;
}