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
    string s, x; cin>>s>>x;

    vector<vector<bool>> dp(n + 1, vector<bool>(7, false));
    dp[n][0] = true;
    int base = 1;
    for(int i=n-1; i>=0; i--){
        int cur = (s[i] - '0') * base % 7;
        base = base * 10 % 7;
        for(int j=0; j<7; j++){
            if(x[i] == 'T') dp[i][j] = dp[i + 1][j] || dp[i + 1][(j + cur) % 7];
            else dp[i][j] = dp[i + 1][j] && dp[i + 1][(j + cur) % 7]; 
        }
    }

    cout << (dp[0][0] ? "Takahashi" : "Aoki") << endl;

    return 0;
}