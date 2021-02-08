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

    int a, b, c; cin>>a>>b>>c;

    vector<vector<vector<double>>> dp(101, vector<vector<double>>(101, vector<double>(101, 0)));
    // dp[i][j][k] := 金貨、銀貨、銅貨が i, j, k 枚のときの操作回数の期待値
    for(int i=99; i>=a; i--){
        for(int j=99; j>=b; j--){
            for(int k=99; k>=c; k--){
                dp[i][j][k] += (dp[i + 1][j][k] + 1) * i / (i + j + k);
                dp[i][j][k] += (dp[i][j + 1][k] + 1) * j / (i + j + k);
                dp[i][j][k] += (dp[i][j][k + 1] + 1) * k / (i + j + k);
            }
        }
    }

    cout << fixed << setprecision(10) << dp[a][b][c] << endl;

    return 0;
}