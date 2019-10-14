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

ll modpow(ll a, ll b){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = modpow(a, b/2) % MOD;
        return (d * d) % MOD;
    }
    else{
        return (a * modpow(a, b-1)) % MOD;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, c; cin>>n>>c;
    vector<ll> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    vector<vector<ll>> pre_modpow(410, vector<ll>(410, 0));
    for(int i=0; i<=400; i++){
        for(int j=0; j<=400; j++){
            pre_modpow[i][j] = modpow(i, j);
        }
    }

    vector<vector<ll>> sum(n+1, vector<ll>(c+1, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<=c; j++){
            for(int k=a[i]; k<=b[i]; k++){
                sum[i][j] += pre_modpow[k][j];
                sum[i][j] %= MOD;
            }
        }
    }

    vector<vector<ll>> dp(n+1, vector<ll>(c+1, 0));
    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<=c; j++){
            for(int k=0; k<=j; k++){
                dp[i+1][j] += dp[i][j-k] * sum[i][k];
                dp[i+1][j] %= MOD;
            }
        }
    }

    cout << dp[n][c] << endl;

    return 0;
}