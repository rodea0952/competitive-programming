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

ll modpow(ll a, ll b, int m){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = modpow(a, b / 2, m);
        return d * d % m;
    }
    else{
        return a * modpow(a, b - 1, m) % m;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, b, k; cin>>n>>b>>k;
    vector<int> c(k);
    for(int i=0; i<k; i++) cin>>c[i];

    vector<ll> pow10(65, 0);
    for(int i=0; i<=62; i++){
        pow10[i] = modpow(10, 1LL << i, b);
    }

    vector<vector<ll>> dp(65, vector<ll>(1010, 0));
    for(int i=0; i<k; i++){
        dp[0][c[i] % b] += 1;
    }

    // dp[1][i], dp[2][i], dp[4][i], ..., dp[2^n][i] を求める
    for(int i=0; i<62; i++){
        for(int j=0; j<b; j++){
            for(int l=0; l<b; l++){
                int nxt = (j * pow10[i] + l) % b;
                dp[i + 1][nxt] += dp[i][j] * dp[i][l];
                dp[i + 1][nxt] %= MOD;
            }
        }
    }

    // 繰り返し二乗法により dp[n][i] を求める
    vector<vector<ll>> ans(65, vector<ll>(1010, 0));
    ans[0][0] = 1;
    for(int i=0; i<62; i++){
        if((n & (1LL << i)) != 0){
            for(int j=0; j<b; j++){
                for(int l=0; l<b; l++){
                    int nxt = (j * pow10[i] + l) % b;
                    ans[i + 1][nxt] += ans[i][j] * dp[i][l];
                    ans[i + 1][nxt] %= MOD;
                }
            }
        }
        else{
            for(int j=0; j<b; j++){
                ans[i + 1][j] = ans[i][j];
            }
        }
    }

    cout << ans[62][0] << endl;

    return 0;
}