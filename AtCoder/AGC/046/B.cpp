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

    int a, b, c, d; cin>>a>>b>>c>>d;

    vector<vector<ll>> dp(c + 1, vector<ll>(d + 1, 0));
    dp[a][b] = 1;

    for(int i=a; i<=c; i++){
        for(int j=b; j<=d; j++){
            if(a <= i - 1){
                dp[i][j] += dp[i - 1][j] * j;
                dp[i][j] %= MOD;
            }
            if(b <= j - 1){
                dp[i][j] += dp[i][j - 1] * i;
                dp[i][j] %= MOD;
            }
            if(a <= i - 1 && b <= j - 1){
                dp[i][j] -= dp[i - 1][j - 1] * (i - 1) * (j - 1) % MOD;
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[c][d] << endl;

    return 0;
}