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

    int n, k; cin>>n>>k;
    vector<int> v;
    for(int i=1; i*i<=n; i++){
        v.emplace_back(i);
        v.emplace_back(n / i);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<int> num;
    num.emplace_back(1);
    for(int i=0; i+1<v.size(); i++){
        num.emplace_back(v[i+1] - v[i]);
    }

    int m = num.size();
    vector<vector<ll>> dp(k+1, vector<ll>(m+1, 0));
    dp[0][0] = 1;

    for(int i=0; i<k; i++){
        vector<ll> sumdp(m+1, 0);
        for(int j=0; j<m; j++){
            sumdp[j+1] = sumdp[j] + dp[i][j];
            sumdp[j+1] %= MOD;
        }

        for(int j=0; j<m; j++){
            dp[i+1][j] = sumdp[m-j] * num[j];
            dp[i+1][j] %= MOD;
        }
    }

    ll ans = 0;
    for(int i=0; i<m; i++){
        ans += dp[k][i];
        ans %= MOD;
    }

    cout << ans << endl;
}