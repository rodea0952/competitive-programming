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

    vector<vector<int>> dp(n+1, vector<int>(5, -1));
    dp[0][0] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            if(dp[i][j] == -1) continue;
            if(i - j < 0) continue;

            for(int k=1; k<5 && i+k<=n; k++){
                if(j != k || s.substr(i-j, j) != s.substr(i, k)){
                    dp[i+k][k] = max(dp[i+k][k], dp[i][j] + 1);
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<5; i++){
        chmax(ans, dp[n][i]);
    }

    cout << ans << endl;
}