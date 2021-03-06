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

ll dp[60][6000][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    ll K; cin>>K;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        int cnt = 0;
        while(0 < a[i]){
            cnt++;
            a[i] /= 2;
        }
        a[i] = cnt;
    }

    dp[0][0][0] = 1;
    K = min(K, 5000LL);
    for(int i=0; i<n; i++){
        for(int j=0; j<=K; j++){
            
            for(int k=0; k<a[i]; k++){
                (dp[i+1][j+k][0] += dp[i][j][0]) %= MOD;
                (dp[i+1][j+k][1] += dp[i][j][1]) %= MOD;
            }

            (dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
        }
    }

    ll ans = 0;
    if(K <= 5000){
        (ans += dp[n][K][0]) %= MOD;
    }

    for(int i=0; i<=K; i++){
        (ans += dp[n][i][1]) %= MOD;
    }

    cout << ans << endl;
}