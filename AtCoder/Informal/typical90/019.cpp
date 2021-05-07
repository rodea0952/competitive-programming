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

vector<int> a(410);
vector<vector<int>> dp(410, vector<int>(410, -1));

// [l, r]
int solve(int l, int r){
    if(dp[l][r] != -1) return dp[l][r];
    if(r - l == 0) return inf;
    if(r - l == 1) return dp[l][r] = abs(a[l] - a[r]);

    int ans = solve(l + 1, r - 1) + abs(a[l] - a[r]);
    for(int i=l+1; i<r; i++){
        chmin(ans, solve(l, i) + solve(i + 1, r));
    }
    return dp[l][r] = ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    for(int i=0; i<2*n; i++) cin>>a[i];

    cout << solve(0, 2 * n - 1) << endl;

    return 0;
}