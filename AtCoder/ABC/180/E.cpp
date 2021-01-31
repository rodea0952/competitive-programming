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
    vector<int> x(n), y(n), z(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i]>>z[i];

    auto dist = [&](int i, int j){
        return abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0, z[j] - z[i]);
    };

    vector<vector<int>> dp(n, vector<int>(1 << n, inf));
    dp[0][0] = 0;

    for(int bit=0; bit<(1<<n); bit++){
        for(int ci=0; ci<n; ci++){
            if(dp[ci][bit] == inf) continue;
            for(int ni=0; ni<n; ni++){
                if(bit & (1 << ni)) continue;
                chmin(dp[ni][bit | (1 << ni)], dp[ci][bit] + dist(ci, ni));
            }
        }
    }

    cout << dp[0][(1 << n) - 1] << endl;

    return 0;
}