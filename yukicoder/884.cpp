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

    vector<vector<int>> dp(n+1, vector<int>(2, inf));
    dp[0][0] = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            int num = s[i] - '0' + j;

            if(num == 0){
                chmin(dp[i+1][0], dp[i][j]);
            }
            else if(num == 1){
                chmin(dp[i+1][0], dp[i][j] + 1);
                chmin(dp[i+1][1], dp[i][j] + 1);
            }
            else{
                chmin(dp[i+1][1], dp[i][j]);
            }
        }
    }

    int ans = min(dp[n][0], dp[n][1] + 1);
    cout << ans << endl;

    return 0;
}