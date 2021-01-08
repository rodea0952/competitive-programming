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

    int gx, gy, n, f; cin>>gx>>gy>>n>>f;
    vector<int> x(n), y(n), c(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i]>>c[i];

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(gx + 1, vector<int>(gy + 1, inf)));
    dp[0][0][0] = 0;
    for(int i=0; i<n; i++){
        for(int px=0; px<=gx; px++){
            for(int py=0; py<=gy; py++){
                if(dp[i][px][py] == inf) continue;

                chmin(dp[i + 1][px][py], dp[i][px][py]);

                if(px + x[i] > gx) continue;
                if(py + y[i] > gy) continue;

                chmin(dp[i + 1][px + x[i]][py + y[i]], dp[i][px][py] + c[i]);
            }
        }
    }

    int ans = inf;
    for(int i=0; i<=gx; i++){
        for(int j=0; j<=gy; j++){
            chmin(ans, dp[n][i][j] + (gx + gy - i - j) * f);
        }
    }

    cout << ans << endl;

    return 0;
}