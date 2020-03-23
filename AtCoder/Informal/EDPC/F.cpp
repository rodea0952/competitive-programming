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

    string s, t; cin>>s>>t;
    int n = s.size(), m = t.size();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i] == t[j]){
                chmax(dp[i+1][j+1], dp[i][j] + 1);
            }
            else{
                chmax(dp[i+1][j+1], max(dp[i+1][j], dp[i][j+1]));
            }
        }
    }

    int len = dp[n][m];
    int y = n, x = m;
    string ans = "";
    while(len > 0){
        if(dp[y][x] == dp[y-1][x]){
            y--;
        }
        else if(dp[y][x] == dp[y][x-1]){
            x--;
        }
        else{
            y--, x--;
            len--;
            ans += s[y];
        }
    }

    reverse(all(ans));

    cout << ans << endl;

    return 0;
}