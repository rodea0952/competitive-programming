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
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i] %= 10;
    }

    vector<vector<int>> dp(n+1, vector<int>(10, -1));
    dp[0][0] = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            if(dp[i][j] < 0) continue;
            
            // 取らない
            chmax(dp[i+1][j], dp[i][j]);

            // 取る
            int nxt = (j + a[i]) % 10;
            chmax(dp[i+1][nxt], dp[i][j] + 1);
        }
    }

    cout << dp[n][0] << endl;

    return 0;
}