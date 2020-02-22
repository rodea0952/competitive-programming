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

    string s; cin>>s;
    int n = s.size();

    reverse(s.begin(), s.end());
    s += '0';

    vector<vector<int>> dp(n+2, vector<int>(2, inf));
    dp[0][0] = 0;

    for(int i=0; i<=n; i++){
        int cur = s[i] - '0';

        // 繰り上げる
        chmin(dp[i+1][1], min(dp[i][1] + 10 - (cur + 1), dp[i][0] + 10 - cur));

        // 繰り上げない
        chmin(dp[i+1][0], min(dp[i][1] + (cur + 1), dp[i][0] + cur));
    }

    cout << chmin(dp[n][0], dp[n+1][0]) << endl;

    return 0;
}
