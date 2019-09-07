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

    int n, x, y, z; cin>>n>>x>>y>>z;
    int ngbit = 0;
    ngbit |= (1 << (z - 1));
    ngbit |= (1 << (y + z - 1));
    ngbit |= (1 << (x + y + z - 1));

    int sum = x + y + z;
    int mask = (1 << sum) - 1;

    vector<vector<ll>> dp(n+1, vector<ll>((1<<sum), 0));
    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int bit=0; bit<(1<<sum); bit++){
            for(int j=1; j<=10; j++){
                int nbit = mask & ((bit << j) ^ (1 << (j - 1)));
                if((nbit & ngbit) == ngbit) continue;
                dp[i+1][nbit] += dp[i][bit];
                dp[i+1][nbit] %= MOD;
            }
        }
    }

    ll sub = 0;
    for(int bit=0; bit<(1<<sum); bit++){
        sub += dp[n][bit];
        sub %= MOD;
    }

    ll all = 1;
    for(int i=0; i<n; i++){
        all *= 10;
        all %= MOD;
    }

    cout << (all - sub + MOD) % MOD << endl;
}