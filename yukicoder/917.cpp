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

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> div;
    for(int i=0; i<n; i++){
        for(int j=1; j*j<=a[i]; j++){
            if(a[i] % j == 0){
                div.emplace_back(j);
                div.emplace_back(a[i] / j);
            }
        }
    }

    div.emplace_back(0);
    sort(div.begin(), div.end());
    div.erase(unique(div.begin(), div.end()), div.end());

    int sz = div.size();
    // dp[i][j] := i 番目までで、j 番目の約数を使うときの通り数
    vector<vector<ll>> dp(n+1, vector<ll>(sz+1, 0));
    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<sz; j++){
            if(dp[i][j] == 0) continue;

            // a[i] を使わない
            dp[i+1][j] += dp[i][j];

            // a[i] を使う
            int num = __gcd(a[i], div[j]);
            int index = lower_bound(div.begin(), div.end(), num) - div.begin();
            dp[i+1][index] += dp[i][j];
        }
    }

    cout << dp[n][1] << endl;

    return 0;
}