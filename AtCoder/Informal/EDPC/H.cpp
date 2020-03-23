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

    int h, w; cin>>h>>w;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin>>s[i];

    vector<vector<ll>> dp(h+1, vector<ll>(w+1, 0));
    dp[1][1] = 1;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j] == '#') continue;
            
            dp[i+1][j+1] += dp[i][j+1] + dp[i+1][j];
            dp[i+1][j+1] %= MOD;
        }
    }

    cout << dp[h][w] << endl;

    return 0;
}