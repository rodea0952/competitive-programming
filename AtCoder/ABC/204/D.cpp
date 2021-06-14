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
    vector<int> t(n);
    for(int i=0; i<n; i++) cin>>t[i];

    vector<vector<bool>> dp(n + 10, vector<bool>(100010, false));
    dp[0][0] = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<=100000; j++){
            if(!dp[i][j]) continue;
            if(j + t[i] <= 100000) dp[i + 1][j + t[i]] = true;
            dp[i + 1][j] = true;
        }
    }

    int ans = inf, tsum = accumulate(all(t), 0);
    for(int i=0; i<=100000; i++){
        if(!dp[n][i]) continue;
        chmin(ans, max(i, tsum - i));
    }

    cout << ans << endl;

    return 0;
}