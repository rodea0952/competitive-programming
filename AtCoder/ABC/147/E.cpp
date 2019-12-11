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
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w; cin>>h>>w;
    vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cin>>a[i][j];
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cin>>b[i][j];
    }

    vector<vector<vector<bool>>> dp(h, vector<vector<bool>>(w, vector<bool>(15000, false)));
    dp[0][0][7500 + abs(a[0][0] - b[0][0])] = true;
    dp[0][0][7500 - abs(a[0][0] - b[0][0])] = true;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            int cur = abs(a[i][j] - b[i][j]);
            if(0 < i){
                for(int k=0; k<15000; k++){
                    int delta = k + cur;
                    if(dp[i-1][j][k] && delta < 15000) dp[i][j][delta] = true;
                    delta = k - cur;
                    if(dp[i-1][j][k] && 0 <= delta) dp[i][j][delta] = true;
                }
            }
            if(0 < j){
                for(int k=0; k<15000; k++){
                    int delta = k + cur;
                    if(dp[i][j-1][k] && delta < 15000) dp[i][j][delta] = true;
                    delta = k - cur;
                    if(dp[i][j-1][k] && 0 <= delta) dp[i][j][delta] = true;
                }
            }
        }
    }

    int ans = inf;
    for(int i=0; i<15000; i++){
        if(dp[h-1][w-1][i]){
            chmin(ans, abs(i - 7500));
        }
    }

    cout << ans << endl;
    
    return 0;
}
