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
    vector<string> s(5);
    for(int i=0; i<5; i++) cin>>s[i];

    // R := 0, B := 1, W := 2
    vector<vector<int>> cnt(n, vector<int>(3, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            cnt[i][0] += (s[j][i] == 'R');
            cnt[i][1] += (s[j][i] == 'B');
            cnt[i][2] += (s[j][i] == 'W');
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(3, inf));
    dp[1][0] = 5 - cnt[0][0];
    dp[1][1] = 5 - cnt[0][1];
    dp[1][2] = 5 - cnt[0][2];

    for(int i=1; i<n; i++){
        for(int cur=0; cur<=2; cur++){
            for(int pre=0; pre<=2; pre++){
                if(cur == pre) continue;

                chmin(dp[i+1][cur], dp[i][pre] + (5 - cnt[i][cur]));
            }
        }
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;

    return 0;
}