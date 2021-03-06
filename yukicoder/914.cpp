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

    int n, m, k; cin>>n>>m>>k;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
    dp[0][0] = true;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int pre=0; pre<k; pre++){
                if(k < pre + a[i][j]) continue;

                dp[i+1][pre+a[i][j]] = dp[i+1][pre+a[i][j]] | dp[i][pre];
            }
        }
    }

    int ans = inf;
    for(int i=0; i<=k; i++){
        if(dp[n][i]) chmin(ans, k - i);
    }

    cout << (ans == inf ? -1 : ans) << endl;

    return 0;
}