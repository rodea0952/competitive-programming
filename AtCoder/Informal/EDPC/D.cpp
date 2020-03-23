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

    int n, W; cin>>n>>W;
    vector<int> w(n), v(n);
    for(int i=0; i<n; i++) cin>>w[i]>>v[i];

    vector<vector<ll>> dp(n+1, vector<ll>(W+1, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<=W; j++){
            chmax(dp[i+1][j], dp[i][j]);
            if(j - w[i] >= 0) chmax(dp[i+1][j], dp[i][j-w[i]] + v[i]);
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}