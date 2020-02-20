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

    int n, m; cin>>n>>m;
    vector<int> s(n), t(m);
    for(int i=0; i<n; i++) cin>>s[i];
    for(int i=0; i<m; i++) cin>>t[i];

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    vector<vector<ll>> sum(n+1, vector<ll>(m+1, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i] == t[j]){
                dp[i+1][j+1] = sum[i][j] + 1;
                dp[i+1][j+1] %= MOD;
            }
            
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + dp[i+1][j+1] + MOD;
            sum[i+1][j+1] %= MOD;
        }
    }

    ll ans = (sum[n][m] + 1) % MOD;

    cout << ans << endl;

    return 0;
}